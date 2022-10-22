//
// Created by moritzh on 21.10.22.
//

#include "EvaluationDataPoint.h"

namespace Model {
    EvaluationDataPoint::EvaluationDataPoint(double average25ppm, unsigned int days25ppm, double average100ppm,
                                             unsigned int days100ppm, uint8_t reason) {
        Reason=reason;
        Average25ppm = average25ppm;
        Average100PPM = average100ppm;
        Days25PPMTooHigh = days25ppm;
        Days100PPMTooHigh = days100ppm;
    }

    uint8_t EvaluationDataPoint::getReason() {
        return Reason;
    }

    double EvaluationDataPoint::getAverage25PPM() {
        return Average25ppm;
    }

    unsigned EvaluationDataPoint::getDays25PPMTooHigh() {
        return Days25PPMTooHigh;
    }

    double EvaluationDataPoint::getAverage100PPM() {
        return Average100PPM;
    }

    unsigned EvaluationDataPoint::getDays100PPMTooHigh() {
        return Days100PPMTooHigh;
    }


} // Model