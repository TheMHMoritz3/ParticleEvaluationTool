#pragma once

#include "partilcleevaluationmodel_global.h"
#include <memory>
#include "PartilcleEvaluationModel.h"
#include <QStandardItemModel>

namespace Model {
	class PARTILCLEEVALUATIONMODEL_EXPORT ParticleEvaluationController
	{
	public:
		ParticleEvaluationController();
		~ParticleEvaluationController() = default;

		std::shared_ptr<PartilcleEvaluationModel> getModel();
		std::shared_ptr<EvaluationSettings> getSettings();

		void importData(QStringList data);

        QStandardItemModel* getEvaluation();
        void evaluate();
		
	private:
		std::shared_ptr<PartilcleEvaluationModel> _Model;
		std::shared_ptr<Model::EvaluationSettings> _EvaluationSettings;
        QStandardItemModel* EvaluationResults = new QStandardItemModel();
	};
}
