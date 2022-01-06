#pragma once

#include <QFile>
#include <vector>
#include <QStringList>
#include "ParticleDataSet.h"
#include "MeasuringType.h"


namespace Model
{
	namespace Parser
	{
		class DatasetParser
		{
		public:
			DatasetParser() = delete;
			~DatasetParser() = delete;

			std::vector<ParticleDataSet> parseTextDataSet(QStringList fileList);

		private:
			static MeasuringType parseMeasureingType(QString firstLine);

			static ParticleDataSet parseMassConzentration(QFile& file);
			static ParticleDataSet parseConcentration(QFile& file);
			static ParticleDataSet parseCumulative(QFile& file);
			
		};
	}
}
