#include "PartilcleEvaluationModel.h"

#include <QDebug>
#include <QObject>
#include <QColor>

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
            return getColorDependedOnValue(index);

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

	void PartilcleEvaluationModel::setParticleDataSet(std::vector<ParticleDataSet*> particleData)
	{
		qDebug()<<particleData.size();
		beginInsertRows(QModelIndex(), 0, particleData.size());
		DataSet = particleData;
		endInsertRows();
		emit dataChanged(createIndex(0,0), createIndex(DataSet.size()-1,9));
	}

	QVariant PartilcleEvaluationModel::getDataFromIndex(QModelIndex index) const
	{
		QString dataString;
		auto valuePoint = DataSet.at(index.row());
		switch (index.column())
		{
		case 0:
		{
			int value = valuePoint->particleSize03();
			dataString = QString(tr("%1").arg(value));
			break;
		}
		case 1:
		{
			int value = valuePoint->particleSize05();
			dataString = QString(tr("%1").arg(value));
			break;
		}
		case 2:
		{
			int value = valuePoint->particleSize25();
			dataString = QString(tr("%1").arg(value));
			break;
		}
		case 3:
		{
			int value = valuePoint->particleSize50();
			dataString = QString(tr("%1").arg(value));
			break;
		}
		case 4:
		{
			int value = valuePoint->particleSize100();
			dataString = QString(tr("%1").arg(value));
			break;
		}
		case 5:
		{
			double value = valuePoint->tempretureA();
			dataString = QString(tr("%1").arg(value));
			break;
		}
		case 6:
		{
			double value = valuePoint->humidity();
			dataString = QString(tr("%1").arg(value));
			break;
		}
		case 7:
		{
			double value = valuePoint->tempretureDP();
			dataString = QString(tr("%1").arg(value));
			break;
		}
		case 8:
		{
			double value = valuePoint->tempretureWP();
			dataString = QString(tr("%1").arg(value));
			break;
		}
		case 9:
		{
			dataString = valuePoint->recordingDate().toString();
			break;
		}
		default:
			dataString = QString("ERROR");
			break;
		}
		return QVariant(dataString);
	}

    std::vector<ParticleDataSet *> PartilcleEvaluationModel::getData() {
        return DataSet;
    }

    QVariant PartilcleEvaluationModel::getColorDependedOnValue(QModelIndex index) const
    {
        QString dataString;
        auto valuePoint = DataSet.at(index.row());
        switch (index.column()) {
            case 2: {
                int value = valuePoint->particleSize25();
                if((value > Settings->ppm25WHOViolationValueDay())&&(value <= Settings->ppm25LawViolationValueDay()))
                    return QVariant(QColor(Qt::yellow));
                if(value > Settings->ppm25LawViolationValueDay())
                    return QVariant(QColor(Qt::red));
                break;
            }
            case 4: {
                int value = valuePoint->particleSize100();
                if((value > Settings->ppm10WHOViolationValueDay())&&(value <= Settings->ppm10LawViolationValueDay()))
                    return QVariant(QColor(Qt::yellow));

                if(value > Settings->ppm10LawViolationValueDay())
                    return QVariant(QColor(Qt::red));
                break;
            }
            default:
                return QVariant();
                break;
        }
        return QVariant();
    }


}
