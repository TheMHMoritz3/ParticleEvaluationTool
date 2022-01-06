#pragma once

#include <QDate>
#include "MeasuringType.h"


namespace Model
{
	class ParticleDataSet
	{
	public:
		ParticleDataSet() = default;
		~ParticleDataSet() = default;

		MeasuringType measuringType();
		void setMeasuringType(MeasuringType type);
		
		int particleSize03();
		void setParticleSize03(int number);
		
		int particleSize05();
		void setParticleSize05(int number);

		int particleSize25();
		void setParticleSize25(int number);
		
		int particleSize50();
		void setParticleSize50(int number);
		
		int particleSize100();
		void setParticleSize100(int number);
		
		double tempretureA();
		void setTempretureA(double temp);
		
		double humidity();
		void setHumidity(double humidity);
		
		double tempretureDP();
		void setTempretureDP(double temp);
		
		double tempretureWP();
		void setTempretureWP(double temp);
		
		QDate recordingDate();
		void setRecordingDate(QDate date);

	private:
		MeasuringType _MeasuringType = INVALID;

		int NumberParticleSize03 = 0;
		int NumberParticleSize05 = 0;
		int NumberParticleSize25 = 0;
		int NumberParticleSize50 = 0;
		int NumberParticleSize100 = 0;

		double TempA = 0.0;
		double Humidity = 0.0;
		double TempWP = 0.0;
		double TempDP = 0.0;

		QDate RecordingDate = QDate::currentDate();
	};
}

