#include "PartilcleEvaluationModel.h"

namespace Model {
	PartilcleEvaluationModel::PartilcleEvaluationModel(std::shared_ptr<Model::EvaluationSettings> settings)
	{
		Settings = settings;
	}

	QModelIndex PartilcleEvaluationModel::index(int row, int column, const QModelIndex& parent) const
	{
		return createIndex(row,column);
	}

	QModelIndex PartilcleEvaluationModel::parent(const QModelIndex& child) const
	{
		return QModelIndex();
	}

	int PartilcleEvaluationModel::rowCount(const QModelIndex& parent) const
	{
		return DataSet.size();
	}

	int PartilcleEvaluationModel::columnCount(const QModelIndex& parent) const
	{
		return 10;
	}

	QVariant PartilcleEvaluationModel::data(const QModelIndex& index, int role) const
	{
		switch (role)
		{
		case Qt::ItemDataRole::DisplayRole:
			return getDataFromIndex(index);
			
		case Qt::BackgroundRole:
			default:
				return QVariant();
		}
		
	}

	QVariant PartilcleEvaluationModel::headerData(int section, Qt::Orientation orientation, int role) const
	{
		if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
			switch (section) {
			case 0:
				return QString(tr("0.3 µm"));
			case 1:
				return QString(tr("0.5 µm"));
			case 2:
				return QString(tr("2.5 µm"));
			case 3:
				return QString(tr("5.0 µm"));
			case 4:
				return QString(tr("10 µm"));
			case 5:
				return QString(tr("AT [°C]"));
			case 6:
				return QString(tr("Humidity [%]"));
			case 7:
				return QString(tr("DP [°C]"));
			case 8:
				return QString(tr("WP [°C]"));
			case 9:
				return QString(tr("date"));
			}
		}
		return QVariant();
	}

	void PartilcleEvaluationModel::setParticleDataSet(std::vector<ParticleDataSet> particleData)
	{
		DataSet = particleData;
		emit dataChanged(createIndex(0,0), createIndex(9,DataSet.size()-1), { Qt::DisplayRole });
	}

	QVariant PartilcleEvaluationModel::getDataFromIndex(QModelIndex index) const
	{
		return QVariant(QString("(%1, %2)").arg(index.column()).arg(index.row()));
	}
}
