#include "DatasetParser.h"

std::vector<Model::ParticleDataSet> Model::Parser::DatasetParser::parseTextDataSet(QStringList fileList)
{
	std::vector<Model::ParticleDataSet> returnValue;

	for (auto file_path : fileList)
	{
		QFile file(file_path);
		if (file.open(QFile::OpenModeFlag::ReadWrite)) {
			auto measuringType = parseMeasureingType(file.readLine());
			switch (measuringType) {
			case Conzentration:
			case Kommultative:
				parseConcentration(file);
				break;
			case MassConzentration: break;
			case INVALID: break;
			default:;
			}
		}
	}

	return returnValue;
}

Model::MeasuringType Model::Parser::DatasetParser::parseMeasureingType(QString firstLine)
{
	if (firstLine == "Concentration")
		return  Model::MeasuringType::Conzentration;
	if (firstLine == "Cumulative")
		return  Model::MeasuringType::Kommultative;
	if (firstLine == "MassCon  ug/m")
		return Model::MeasuringType::MassConzentration;

	return INVALID;
}

Model::ParticleDataSet Model::Parser::DatasetParser::parseMassConzentration(QFile& file)
{
	std::string line = "";
	while((line=file.readLine())!="")
	{

	}
}

Model::ParticleDataSet Model::Parser::DatasetParser::parseConcentration(QFile& file)
{
}
