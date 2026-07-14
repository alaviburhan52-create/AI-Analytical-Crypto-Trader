#pragma once
#include <string>

struct DataPoint {
    std::string timestamp;
    double price;
    double volume;
    
    DataPoint(std::string ts = "", double p = 0.0, double v = 0.0);
};