#include "ParticleDataSet.h"

Model::MeasuringType Model::ParticleDataSet::measuringType()
{
	return _MeasuringType;
}

void Model::ParticleDataSet::setMeasuringType(MeasuringType type)
{
	_MeasuringType = type;
}

int Model::ParticleDataSet::particleSize03() const
{
	return NumberParticleSize03;
}

void Model::ParticleDataSet::setParticleSize03(int number)
{
	NumberParticleSize03 = number;
}

int Model::ParticleDataSet::particleSize05() const
{
	return NumberParticleSize05;
}

void Model::ParticleDataSet::setParticleSize05(int number)
{
	NumberParticleSize05 = number;
}

int Model::ParticleDataSet::particleSize25() const
{
	return NumberParticleSize25;
}

void Model::ParticleDataSet::setParticleSize25(int number)
{
	NumberParticleSize25 = number;
}

int Model::ParticleDataSet::particleSize50() const
{
	return NumberParticleSize50;
}

void Model::ParticleDataSet::setParticleSize50(int number)
{
	NumberParticleSize50 = number;
}

int Model::ParticleDataSet::particleSize100() const
{
	return NumberParticleSize100;
}

void Model::ParticleDataSet::setParticleSize100(int number)
{
	NumberParticleSize100 = number;
}

double Model::ParticleDataSet::tempretureA() const
{
	return TempA;
}

void Model::ParticleDataSet::setTempretureA(double temp)
{
	TempA = temp;
}

double Model::ParticleDataSet::humidity() const
{
	return Humidity;
}

void Model::ParticleDataSet::setHumidity(double humidity)
{
	Humidity = humidity;
}

double Model::ParticleDataSet::tempretureDP() const
{
	return TempDP;
}

void Model::ParticleDataSet::setTempretureDP(double temp)
{
	TempDP = temp;
}

double Model::ParticleDataSet::tempretureWP() const
{
	return TempWP;
}

void Model::ParticleDataSet::setTempretureWP(double temp)
{
	TempWP = temp;
}

QDate Model::ParticleDataSet::recordingDate()
{
	return *RecordingDate;
}

void Model::ParticleDataSet::setRecordingDate(QDate* date)
{
	RecordingDate = date;
}
