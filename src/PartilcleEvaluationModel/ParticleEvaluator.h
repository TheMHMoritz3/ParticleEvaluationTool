//
// Created by moritzh on 21.10.22.
//

#ifndef CONANFILE_PY_PARTICLEEVALUATOR_H
#define CONANFILE_PY_PARTICLEEVALUATOR_H

#include <vector>
#include "ParticleDataSet.h"
#include "EvaluationSettings.h"
#include "EvaluationDataPoint.h"

namespace Model {

    class ParticleEvaluator {
    public:
        ParticleEvaluator()=delete;
        ParticleEvaluator(std::shared_ptr<Model::EvaluationSettings>);
        ~ParticleEvaluator() = default;

        void evaluate(std::vector<ParticleDataSet *>);

        std::vector<EvaluationDataPoint> getEvaluationData();
    private:
        void calculateHighestDate();
        void calculateLowesDate();

        void evaluateOneYear();
        void searchForBestQuantile();

        QDate LowestDate;
        QDate HighestDate;
        long DistanceBetweenDates;

        std::vector<EvaluationDataPoint> EvaluationData;

        std::vector<ParticleDataSet*> DataSet;
        std::shared_ptr<Model::EvaluationSettings> EvalSettings;

        std::vector<std::vector<ParticleDataSet *>> calculateQuantiles(QDate lowestDate);
    };

} // Model

#endif //CONANFILE_PY_PARTICLEEVALUATOR_H
