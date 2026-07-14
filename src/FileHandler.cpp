#include "../include/FileHandler.h"
#include <fstream>
#include <sstream>

bool FileHandler::saveToCSV(const std::vector<DataPoint>& data, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) return false;
    
    file << "Timestamp,Price,Volume\n";
    for (const auto& dp : data) {
        file << dp.timestamp << "," << dp.price << "," << dp.volume << "\n";
    }
    file.close();
    return true;
}

std::vector<DataPoint> FileHandler::loadFromCSV(const std::string& filename) {
    std::vector<DataPoint> data;
    std::ifstream file(filename);
    if (!file.is_open()) return data;
    
    std::string line;
    std::getline(file, line); // Skip header
    
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string timestamp, priceStr, volumeStr;
        std::getline(ss, timestamp, ',');
        std::getline(ss, priceStr, ',');
        std::getline(ss, volumeStr, ',');
        
        DataPoint dp;
        dp.timestamp = timestamp;
        dp.price = std::stod(priceStr);
        dp.volume = std::stod(volumeStr);
        data.push_back(dp);
    }
    file.close();
    return data;
}