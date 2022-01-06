#pragma once

#include "partilcleevaluationmodel_global.h"
#include <memory>
#include "PartilcleEvaluationModel.h"

namespace Model {
	class PARTILCLEEVALUATIONMODEL_EXPORT ParticleEvaluationController
	{
	public:
		ParticleEvaluationController();
		~ParticleEvaluationController() = default;

		std::shared_ptr<PartilcleEvaluationModel> getModel();
		std::shared_ptr<EvaluationSettings> getSettings();

		void importData(QStringList data);
		
	private:
		std::shared_ptr<PartilcleEvaluationModel> _Model;
		std::shared_ptr<Model::EvaluationSettings> _EvaluationSettings;
	};
}
