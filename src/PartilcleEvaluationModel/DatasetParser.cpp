#include "DatasetParser.h"
#include "StringUtitlities.h"
#include <QDebug>

std::vector<Model::ParticleDataSet*> Model::Parser::DatasetParser::parseTextDataSet(QStringList fileList)
{
	std::vector<Model::ParticleDataSet*> returnValue;

	for (auto file_path : fileList)
	{
		QFile file(file_path);
        Model::ParticleDataSet* dataSet = new ParticleDataSet();
		if (file.open(QFile::OpenModeFlag::ReadWrite)) {
			auto measuringType = parseMeasureingType(file.readLine().toStdString());
			dataSet->setRecordingDate(parseDate(file_path));
			switch (measuringType) {
//			case Conzentration:
//                dataSet = parseConcentration(file, dataSet);
//				returnValue.push_back(dataSet);
//                break;
//			case Kommultative:
//				dataSet = parseCumulative(file, dataSet);
//				returnValue.push_back(dataSet);
//				break;
			case MassConzentration:
                dataSet = parseMassConzentration(file, dataSet);
				returnValue.push_back(dataSet);
                break;
			case INVALID:
            default:
                break;
			}
		}
		
	}

	return returnValue;
}

Model::MeasuringType Model::Parser::DatasetParser::parseMeasureingType(std::string firstLine)
{
	if (Model::Utilities::StringUtitlities::contains(firstLine, "Concentration"))
		return  Model::MeasuringType::Conzentration;
	if (Model::Utilities::StringUtitlities::contains(firstLine, "Cumulative"))
		return  Model::MeasuringType::Kommultative;
	if (Model::Utilities::StringUtitlities::contains(firstLine, "MassCon  ug/m"))
		return Model::MeasuringType::MassConzentration;

	return INVALID;
}

Model::ParticleDataSet* Model::Parser::DatasetParser::parseMassConzentration(QFile& file, ParticleDataSet* input)
{
	input->setMeasuringType(Model::MassConzentration);
	std::string line = "";
	while((line=file.readLine())!="")
	{
		if(Model::Utilities::StringUtitlities::contains(line,"2.5um")){
            auto strings = Model::Utilities::StringUtitlities::splitStrings(':',line);
			std::string dataValueString = strings[1];
			input->setParticleSize25(std::stoi(Model::Utilities::StringUtitlities::removeWhitespace(dataValueString)));
        }
		if(Model::Utilities::StringUtitlities::contains(line,"10 um")){
            auto strings = Model::Utilities::StringUtitlities::splitStrings(':',line);
			std::string dataValueString = strings[1];
			input->setParticleSize100(std::stoi(Model::Utilities::StringUtitlities::removeWhitespace(dataValueString)));
        }
	}
    return input;
}

Model::ParticleDataSet* Model::Parser::DatasetParser::parseConcentration(QFile& file, Model::ParticleDataSet* input)
{
    std::string line = "";
	input->setMeasuringType(Model::Conzentration);
    while((line=file.readLine())!="")
    {
		if(Model::Utilities::StringUtitlities::contains(line,"2.5um")){
            auto strings = Model::Utilities::StringUtitlities::splitStrings(':',line);
			std::string dataValueString = strings[1];
			input->setParticleSize25(std::stoi(Model::Utilities::StringUtitlities::removeWhitespace(dataValueString)));
        }
		if(Model::Utilities::StringUtitlities::contains(line,"10 um")){
            auto strings = Model::Utilities::StringUtitlities::splitStrings(':',line);
			std::string dataValueString = strings[1];
			input->setParticleSize100(std::stoi(Model::Utilities::StringUtitlities::removeWhitespace(dataValueString)));
        }
    }
    return input;
}

Model::ParticleDataSet* Model::Parser::DatasetParser::parseCumulative(QFile &file, Model::ParticleDataSet* input) {
    return input;
}

QDate* Model::Parser::DatasetParser::parseDate(QString filepath) {
#ifdef __linux
	std::vector<std::string> pathparts = Model::Utilities::StringUtitlities::splitStrings('/', filepath.toStdString());
	std::string filename = pathparts.at(pathparts.size()-1);
	std::vector<std::string> filenamePaths = Model::Utilities::StringUtitlities::splitStrings('.', filename);
	std::vector<std::string> datePaths = Model::Utilities::StringUtitlities::splitStrings(' ', filenamePaths[0]);
	std::vector<std::string> date = Model::Utilities::StringUtitlities::splitStrings('-', filenamePaths[0]);
	return new QDate(std::stoi(date[2]),std::stoi(date[0]),std::stoi(date[1]));
#else
	std::vector<std::string> pathparts = Model::Utilities::StringUtitlities::splitStrings('/', filepath.toStdString());
	std::string filename = pathparts.at(pathparts.size() - 1);
	std::vector<std::string> filenamePaths = Model::Utilities::StringUtitlities::splitStrings('.', filename);
	std::vector<std::string> datePaths = Model::Utilities::StringUtitlities::splitStrings(' ', filenamePaths[0]);
	std::vector<std::string> date = Model::Utilities::StringUtitlities::splitStrings('-', filenamePaths[0]);
	return new QDate(std::stoi(date[2]), std::stoi(date[0]), std::stoi(date[1]));
#endif
}