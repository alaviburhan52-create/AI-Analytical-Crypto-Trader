#pragma once
#include "DataPoint.h"
#include <vector>
#include <string>

class Analyzer {
public:
    void analyze(const std::vector<DataPoint>& data);
    void printReport() const;
    
private:
    double latestPrice_;
    double sma50_;
    double rsi14_;
    std::string signal_;
    double totalVolume_;
};