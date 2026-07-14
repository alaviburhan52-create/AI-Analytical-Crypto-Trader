#pragma once
#include "DataPoint.h"
#include <vector>
#include <string>

class FileHandler {
public:
    static bool saveToCSV(const std::vector<DataPoint>& data, const std::string& filename);
    static std::vector<DataPoint> loadFromCSV(const std::string& filename);
};