//
// Created by moritzh on 21.10.22.
//

#include "ParticleEvaluator.h"

namespace Model {
    ParticleEvaluator::ParticleEvaluator(std::shared_ptr<Model::EvaluationSettings> settings) {
        EvalSettings = settings;
    }

    void ParticleEvaluator::evaluate(std::vector<ParticleDataSet *> dataSet) {
        DataSet = dataSet;
        calculateHighestDate();
        calculateLowesDate();
        DistanceBetweenDates = LowestDate.daysTo(HighestDate);
        if(DistanceBetweenDates<=365)
            evaluateOneYear();
        else
            searchForBestQuantile();
    }

    void ParticleEvaluator::calculateHighestDate() {
        std::sort(DataSet.begin(),DataSet.end(),[](ParticleDataSet* i, ParticleDataSet* j){
           return i->recordingDate()<j->recordingDate();
        });

        LowestDate = DataSet.front()->recordingDate();
        HighestDate = DataSet.back()->recordingDate();
    }

    void ParticleEvaluator::calculateLowesDate() {
    }

    void ParticleEvaluator::evaluateOneYear() {
        double average100ppm = 0.0;
        unsigned numberOfDays100ppmToHigh = 0;
        double average25ppm = 0.0;
        unsigned numberOfDays25ppmToHigh = 0;

        for(auto datapoint : DataSet)
        {
            average100ppm += datapoint->particleSize100();
            if(datapoint->particleSize100()>EvalSettings->ppm10LawViolationValueDay()) {
                numberOfDays100ppmToHigh++;
            }
            average25ppm += datapoint->particleSize25();
            if(datapoint->particleSize25()>EvalSettings->ppm25LawViolationValueDay()) {
                numberOfDays25ppmToHigh++;
            }
        }

        average100ppm/=DataSet.size();
        average25ppm/=DataSet.size();

        uint8_t reason = 0;
        if (numberOfDays100ppmToHigh>=EvalSettings->numberViolatedDays())
            reason = reason | SueingReason::NUMBER_OF_DAYS_PPM100;
        if (numberOfDays25ppmToHigh>=EvalSettings->numberViolatedDays())
            reason = reason | SueingReason::NUMBER_OF_DAYS_PPM25;
        if ((double) average100ppm>=EvalSettings->ppm10LawViolationValueYear())
            reason = reason | SueingReason::PPM100_TOO_HIGH;
        if ((double) average25ppm>=EvalSettings->ppm25LawViolationValueYear())
            reason = reason | SueingReason::PPM25_TOO_HIGH;

        EvaluationDataPoint evaluationDataPoint(average25ppm,numberOfDays25ppmToHigh,average100ppm,numberOfDays100ppmToHigh, reason, LowestDate, HighestDate);
        EvaluationData.push_back(evaluationDataPoint);
    }

    void ParticleEvaluator::searchForBestQuantile() {
        auto quantiles = calculateQuantiles(LowestDate);
        for (auto quantile : quantiles)
        {
            qDebug()<<"Quantiles Size: "<<quantile.size();
            ParticleEvaluator evaluator(EvalSettings);
            evaluator.evaluateAllOfQuantile(quantile);
            EvaluationData.push_back(evaluator.EvaluationData.at(0));
        }
    }

    std::vector<EvaluationDataPoint> ParticleEvaluator::getEvaluationData() {
        return EvaluationData;
    }

    std::vector<std::vector<ParticleDataSet *>> ParticleEvaluator::calculateQuantiles(QDate) {
        std::vector<std::vector<ParticleDataSet *>> dataset;

        for (int i = 0; i<DataSet.size(); i++)
        {
            QDate newLowestDate = DataSet[i]->recordingDate();
            std::vector<ParticleDataSet *> appendedValue;
            QDate newHighestDate = newLowestDate.addYears(1);
            for (auto datapoint: DataSet) {
                if ((newLowestDate <= datapoint->recordingDate()) && (newHighestDate > datapoint->recordingDate()))
                    appendedValue.push_back(datapoint);
            }
            dataset.push_back(appendedValue);
        }

        return dataset;
    }

    void ParticleEvaluator::evaluateAllOfQuantile(std::vector<ParticleDataSet *> dataSet) {
        DataSet = dataSet;
        calculateHighestDate();
        calculateLowesDate();
        DistanceBetweenDates = LowestDate.daysTo(HighestDate);
        evaluateOneYear();
    }
} // Model