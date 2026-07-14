#include "../include/PriceGenerator.h"
#include <random>
#include <chrono>
#include <iomanip>
#include <sstream>

PriceGenerator::PriceGenerator(double startPrice, int numPoints)
    : startPrice_(startPrice), numPoints_(numPoints) {}

double PriceGenerator::randomChange(double maxChange) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dist(-maxChange, maxChange);
    return dist(gen);
}

std::vector<DataPoint> PriceGenerator::generate() {
    std::vector<DataPoint> data;
    double currentPrice = startPrice_;
    
    auto now = std::chrono::system_clock::now();
    
    for (int i = 0; i < numPoints_; ++i) {
        auto timePoint = now - std::chrono::hours(numPoints_ - i);
        auto timeT = std::chrono::system_clock::to_time_t(timePoint);
        
        std::stringstream ss;
        ss << std::put_time(std::localtime(&timeT), "%Y-%m-%d %H:%M:%S");
        std::string timestamp = ss.str();
        
        double change = randomChange(0.05) * currentPrice;
        currentPrice += change;
        if (currentPrice < 0.01) currentPrice = 0.01;
        
        static std::random_device rd2;
        static std::mt19937 gen2(rd2());
        std::uniform_real_distribution<double> volDist(100.0, 1000.0);
        double volume = volDist(gen2);
        
        data.push_back(DataPoint(timestamp, currentPrice, volume));
    }
    return data;
}