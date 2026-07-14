#include "../include/Analyzer.h"
#include "../include/MovingAverage.h"
#include "../include/RSI.h"
#include "../include/Signal.h"
#include <iostream>
#include <iomanip>

void Analyzer::analyze(const std::vector<DataPoint>& data) {
    if (data.empty()) return;
    
    latestPrice_ = data.back().price;
    sma50_ = MovingAverage::calculate(data, 5);
    rsi14_ = RSI::calculate(data, 14);
    signal_ = Signal::generate(latestPrice_, sma50_, rsi14_);
    
    totalVolume_ = 0.0;
    for (const auto& dp : data) {
        totalVolume_ += dp.volume;
    }
}

void Analyzer::printReport() const {
    std::cout << "\n========================================\n";
    std::cout << "        CRYPTO TRACKER REPORT\n";
    std::cout << "========================================\n";
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Latest Price:       $" << latestPrice_ << "\n";
    std::cout << "50-Period SMA:      $" << sma50_ << "\n";
    std::cout << "RSI (14):           " << rsi14_ << "\n";
    std::cout << "Total Volume:       " << totalVolume_ << "\n";
    std::cout << "\n";
    std::cout << ">>> SIGNAL: " << signal_ << " <<<\n";
    std::cout << "========================================\n";
}