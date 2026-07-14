#pragma once
#include "DataPoint.h"
#include <vector>

class PriceGenerator {
public:
    PriceGenerator(double startPrice, int numPoints);
    std::vector<DataPoint> generate();
    
private:
    double startPrice_;
    int numPoints_;
    double randomChange(double maxChange);
};