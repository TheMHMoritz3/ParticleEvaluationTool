#include "EvaluationSettings.h"
#include <QSettings>


namespace Model {
	EvaluationSettings::EvaluationSettings()
	{
		readSettings();
	}

	double EvaluationSettings::ppm10LawViolationValueDay()
	{
		return Ppm10LawViolationPerDay;
	}

	void EvaluationSettings::setPpm10LawViolationPerDay(double ppmValue)
	{
		Ppm10LawViolationPerDay = ppmValue;
	}

	double EvaluationSettings::ppm10LawViolationValueYear()
	{
		return Ppm10LawViolationPerYear;
	}

	void EvaluationSettings::setPpm10LawViolationPerYear(double ppmValue)
	{
		Ppm10LawViolationPerYear = ppmValue;
	}

	double EvaluationSettings::ppm25LawViolationValueDay()
	{
		return Ppm25LawViolationPerDay;
	}

	void EvaluationSettings::setPpm25LawViolationPerDay(double ppmValue)
	{
		Ppm25LawViolationPerDay = ppmValue;
	}

	double EvaluationSettings::ppm25LawViolationValueYear()
	{
		return Ppm25LawViolationPerYear;
	}

	void EvaluationSettings::setPpm25LawViolationPerYear(double ppmValue)
	{
		Ppm25LawViolationPerYear = ppmValue;
	}

	double EvaluationSettings::ppm10WHOViolationValueDay()
	{
		return Ppm10WHOViolationPerDay;
	}

	void EvaluationSettings::setPpm10WHOViolationPerDay(double ppmValue)
	{
		Ppm10WHOViolationPerDay = ppmValue;
	}

	double EvaluationSettings::ppm10WHOViolationValueYear()
	{
		return Ppm10WHOViolationPerYear;
	}

	void EvaluationSettings::setPpm10WHOViolationPerYear(double ppmValue)
	{
		Ppm10WHOViolationPerYear = ppmValue;
	}

	double EvaluationSettings::ppm25WHOViolationValueDay()
	{
		return Ppm25WHOViolationPerDay;
	}

	void EvaluationSettings::setPpm25WHOViolationPerDay(double ppmValue)
	{
		Ppm25WHOViolationPerDay = ppmValue;
	}

	double EvaluationSettings::ppm25WHOViolationValueYear()
	{
		return Ppm25WHOViolationPerYear;
	}

	void EvaluationSettings::setPpm25WHOViolationPerYear(double ppmValue)
	{
		Ppm25WHOViolationPerYear = ppmValue;
	}

	unsigned EvaluationSettings::numberViolatedDays()
	{
		return NumberOfViolatedDays;
	}

	void EvaluationSettings::setNumberOfViolatedDays(unsigned dayNumber)
	{
		NumberOfViolatedDays = dayNumber;
	}

	bool EvaluationSettings::areSettingsAvailable()
	{
		return AreSettingsAvailable;
	}

	void EvaluationSettings::updateSettings()
	{
		QSettings settings;
		settings.beginGroup("Evaluation Settings");

		settings.setValue("NumberOfViolatedDays", NumberOfViolatedDays);
		
		settings.setValue("Ppm25WHOViolationPerYear", Ppm25WHOViolationPerYear);
		settings.setValue("Ppm25WHOViolationPerDay", Ppm25WHOViolationPerDay);
		
		settings.setValue("Ppm10WHOViolationPerYear", Ppm10WHOViolationPerYear);
		settings.setValue("Ppm10WHOViolationPerDay", Ppm10WHOViolationPerDay);
		
		settings.setValue("Ppm25LawViolationPerYear", Ppm25LawViolationPerYear);
		settings.setValue("Ppm25LawViolationPerDay", Ppm25LawViolationPerDay);
		
		settings.setValue("Ppm10LawViolationPerYear", Ppm10LawViolationPerYear);
		settings.setValue("Ppm10LawViolationPerDay", Ppm10LawViolationPerDay);

		settings.endGroup();
	}

	void EvaluationSettings::readSettings()
	{
		QSettings settings;
		settings.beginGroup("Evaluation Settings");
		AreSettingsAvailable = settings.contains("NumberOfViolatedDays");

		if (AreSettingsAvailable)
		{
			NumberOfViolatedDays = settings.value("NumberOfViolatedDays").toUInt();

			Ppm25WHOViolationPerYear = settings.value("Ppm25WHOViolationPerYear").toDouble();
			Ppm25WHOViolationPerDay = settings.value("Ppm25WHOViolationPerDay").toDouble();

			Ppm10WHOViolationPerYear = settings.value("Ppm10WHOViolationPerYear").toDouble();
			Ppm10WHOViolationPerDay = settings.value("Ppm10WHOViolationPerDay").toDouble();

			Ppm25LawViolationPerYear = settings.value("Ppm25LawViolationPerYear").toDouble();
			Ppm25LawViolationPerDay = settings.value("Ppm25LawViolationPerDay").toDouble();

			Ppm10LawViolationPerYear = settings.value("Ppm10LawViolationPerYear").toDouble();
			Ppm10LawViolationPerDay = settings.value("Ppm10LawViolationPerDay").toDouble();
		}

		settings.endGroup();
	}
}