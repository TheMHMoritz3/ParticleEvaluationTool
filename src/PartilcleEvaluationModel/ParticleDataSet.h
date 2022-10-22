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
		
		int particleSize03() const;
		void setParticleSize03(int number);
		
		int particleSize05() const;
		void setParticleSize05(int number);

		int particleSize25() const;
		void setParticleSize25(int number);
		
		int particleSize50() const;
		void setParticleSize50(int number);
		
		int particleSize100() const;
		void setParticleSize100(int number);
		
		double tempretureA() const;
		void setTempretureA(double temp);
		
		double humidity() const;
		void setHumidity(double humidity);
		
		double tempretureDP() const;
		void setTempretureDP(double temp);
		
		double tempretureWP() const;
		void setTempretureWP(double temp);
		
		QDate recordingDate();
		void setRecordingDate(QDate* date);

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

		QDate* RecordingDate=nullptr;
	};
}

