#pragma once
#include "DataPoint.h"
#include <vector>

class MovingAverage {
public:
    static double calculate(const std::vector<DataPoint>& data, int period);
};