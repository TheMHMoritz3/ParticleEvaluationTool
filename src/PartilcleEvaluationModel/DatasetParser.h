#pragma once

#include <QFile>
#include <vector>
#include <string>
#include <QStringList>
#include <QDate>
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

			static std::vector<ParticleDataSet*> parseTextDataSet(QStringList fileList);

		private:
			static MeasuringType parseMeasureingType(std::string firstLine);

			static ParticleDataSet* parseMassConzentration(QFile& file, ParticleDataSet* input);
			static ParticleDataSet* parseConcentration(QFile& file, ParticleDataSet* input);
			static ParticleDataSet* parseCumulative(QFile& file, ParticleDataSet* input);
			
			static QDate* parseDate(QString filepath);
		};
	}
}
