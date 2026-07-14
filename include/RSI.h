#pragma once
#include "DataPoint.h"
#include <vector>

class RSI {
public:
    static double calculate(const std::vector<DataPoint>& data, int period = 14);
};