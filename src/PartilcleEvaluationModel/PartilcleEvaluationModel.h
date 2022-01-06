#pragma once

#include "partilcleevaluationmodel_global.h"
#include "EvaluationSettings.h"
#include "ParticleDataSet.h"

#include <memory>
#include <QAbstractItemModel>

namespace Model {
    class PARTILCLEEVALUATIONMODEL_EXPORT PartilcleEvaluationModel : public QAbstractItemModel
    {
    public:
        PartilcleEvaluationModel(std::shared_ptr<Model::EvaluationSettings>);
        ~PartilcleEvaluationModel() = default;

        QModelIndex index(int row, int column, const QModelIndex& parent) const override;
        QModelIndex parent(const QModelIndex& child) const override;
        int rowCount(const QModelIndex& parent) const override;
        int columnCount(const QModelIndex& parent) const override;
        QVariant data(const QModelIndex& index, int role) const override;

    	QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

        void setParticleDataSet(std::vector<ParticleDataSet> particleData);
    private:

        QVariant getDataFromIndex(QModelIndex) const;
        std::shared_ptr<Model::EvaluationSettings> Settings;
        std::vector<ParticleDataSet> DataSet;
    	
    };
}