//
// Created by moritzh on 21.10.22.
//

#ifndef CONANFILE_PY_EVALUATIONDATAPOINT_H
#define CONANFILE_PY_EVALUATIONDATAPOINT_H

#include <cstdint>
#include <QDate>

namespace Model {

    enum SueingReason {
        PPM25_TOO_HIGH = 0x1,
        NUMBER_OF_DAYS_PPM25 = 0x2,
        PPM100_TOO_HIGH = 0x4,
        NUMBER_OF_DAYS_PPM100 = 0x8,
    };

    class EvaluationDataPoint {
    public:
        EvaluationDataPoint()=delete;
        EvaluationDataPoint(double average25ppm, unsigned days25ppm, double average100ppm, unsigned days100ppm, uint8_t reason, QDate sampleBegin, QDate sampleEnd);
        ~EvaluationDataPoint()=default;

        uint8_t getReason();
        double getAverage25PPM();
        unsigned getDays25PPMTooHigh();
        double getAverage100PPM();
        unsigned getDays100PPMTooHigh();
        QDate sampleBegin();
        QDate sampleEnd();

    private:
        double Average25ppm;
        unsigned Days25PPMTooHigh;
        double Average100PPM;
        unsigned Days100PPMTooHigh;

        QDate SampleBegin;
        QDate SampleEnd;

        uint8_t Reason = 0;
    };

} // Model

#endif //CONANFILE_PY_EVALUATIONDATAPOINT_H
