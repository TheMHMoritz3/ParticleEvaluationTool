#include "ParticleEvaluationController.h"

Model::ParticleEvaluationController::ParticleEvaluationController()
{
	_EvaluationSettings = std::make_shared<Model::EvaluationSettings>();

	_Model = std::make_shared <Model::PartilcleEvaluationModel>(_EvaluationSettings);
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
	
}
