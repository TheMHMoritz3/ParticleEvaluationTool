#include "ParticleEvaluationController.h"
#include "ParticleEvaluator.h"
#include "DatasetParser.h"

Model::ParticleEvaluationController::ParticleEvaluationController()
{
	_EvaluationSettings = std::make_shared<Model::EvaluationSettings>();

	_Model = std::make_shared <Model::PartilcleEvaluationModel>(_EvaluationSettings);
    QStringList headerData;
    headerData.append(QObject::tr("Is Suable"));
    headerData.append(QObject::tr("Reason"));
    headerData.append(QObject::tr("Average 2.5 ppm"));
    headerData.append(QObject::tr("Days of 2.5 ppm too high"));
    headerData.append(QObject::tr("Average 10 ppm"));
    headerData.append(QObject::tr("Days of 10 ppm too high"));
    EvaluationResults->setHorizontalHeaderLabels(headerData);
}

std::shared_ptr<Model::PartilcleEvaluationModel> Model::ParticleEvaluationController::getModel()
{
	return _Model;
}

std::shared_ptr<Model::EvaluationSettings> Model::ParticleEvaluationController::getSettings()
{
	return _EvaluationSettings;
}

void Model::ParticleEvaluationController::importData(QStringList data)
{
	_Model->setParticleDataSet(Parser::DatasetParser::parseTextDataSet(data));
}

QStandardItemModel *Model::ParticleEvaluationController::getEvaluation() {
    return EvaluationResults;
}

void Model::ParticleEvaluationController::evaluate() {
    ParticleEvaluator evaluator(_EvaluationSettings);
    evaluator.evaluate(_Model->getData());
    auto evaluationResults = evaluator.getEvaluationData();

    for(auto evaluationPoint : evaluationResults)
    {
        QList<QStandardItem*> newRow;
        newRow.append(new QStandardItem(QObject::tr("%1").arg(evaluationPoint.getReason()!=0)));
        QString resultString = "";
        resultString += QObject::tr("Reasons are: \r\n");
        if(evaluationPoint.getReason()& Model::PPM25_TOO_HIGH)
            resultString += QObject::tr("- Average 2.5 PPM is too High\r\n");
        if(evaluationPoint.getReason()& Model::PPM100_TOO_HIGH)
            resultString += QObject::tr("- Average 10 PPM is too High\r\n");
        if(evaluationPoint.getReason()& Model::NUMBER_OF_DAYS_PPM25)
            resultString += QObject::tr("- Number of days for 25 PPM is too High\r\n");
        if(evaluationPoint.getReason()& Model::NUMBER_OF_DAYS_PPM100)
            resultString += QObject::tr("- Number of days for 25 PPM is too High\r\n");
        newRow.append(new QStandardItem(resultString));
        newRow.append(new QStandardItem(QObject::tr("%1").arg(evaluationPoint.getAverage25PPM())));
        newRow.append(new QStandardItem(QObject::tr("%1").arg(evaluationPoint.getDays25PPMTooHigh())));
        newRow.append(new QStandardItem(QObject::tr("%1").arg(evaluationPoint.getAverage100PPM())));
        newRow.append(new QStandardItem(QObject::tr("%1").arg(evaluationPoint.getDays100PPMTooHigh())));
        EvaluationResults->appendRow(newRow);
    }
}
