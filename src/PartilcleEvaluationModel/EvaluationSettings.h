#pragma once

#include "partilcleevaluationmodel_global.h"

namespace Model {
	class PARTILCLEEVALUATIONMODEL_EXPORT EvaluationSettings
	{
	public:
		EvaluationSettings();
		~EvaluationSettings() = default;

		double ppm10LawViolationValueDay();
		void setPpm10LawViolationPerDay(double);
		double ppm10LawViolationValueYear();
		void setPpm10LawViolationPerYear(double);

		double ppm25LawViolationValueDay();
		void setPpm25LawViolationPerDay(double);
		double ppm25LawViolationValueYear();
		void setPpm25LawViolationPerYear(double);

		double ppm10WHOViolationValueDay();
		void setPpm10WHOViolationPerDay(double);
		double ppm10WHOViolationValueYear();
		void setPpm10WHOViolationPerYear(double);

		double ppm25WHOViolationValueDay();
		void setPpm25WHOViolationPerDay(double);
		double ppm25WHOViolationValueYear();
		void setPpm25WHOViolationPerYear(double);

		unsigned numberViolatedDays();
		void setNumberOfViolatedDays(unsigned);

		bool areSettingsAvailable();

		void updateSettings();
	private:
		void readSettings();
		double Ppm10LawViolationPerDay = 0.0;
		double Ppm10LawViolationPerYear = 0.0;

		double Ppm25LawViolationPerDay = 0.0;
		double Ppm25LawViolationPerYear = 0.0;

		double Ppm10WHOViolationPerDay = 0.0;
		double Ppm10WHOViolationPerYear = 0.0;

		double Ppm25WHOViolationPerDay = 0.0;
		double Ppm25WHOViolationPerYear = 0.0;

		unsigned NumberOfViolatedDays = 0;

		bool AreSettingsAvailable = false;
	};
}
