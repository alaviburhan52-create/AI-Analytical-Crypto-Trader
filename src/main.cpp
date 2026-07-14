#include "../include/PriceGenerator.h"
#include "../include/Analyzer.h"
#include "../include/FileHandler.h"
#include <iostream>

int main() {
    std::cout << "=== Crypto Tracker ===\n";
    std::cout << "Generating price data...\n";
    
    PriceGenerator generator(50000.0, 30);
    std::vector<DataPoint> data = generator.generate();
    
    std::cout << "Saving to data/prices.csv...\n";
    FileHandler::saveToCSV(data, "data/prices.csv");
    
    std::cout << "Analyzing data...\n";
    Analyzer analyzer;
    analyzer.analyze(data);
    analyzer.printReport();
    
    std::cout << "\nDone! Check data/prices.csv for the full history.\n";
    return 0;
}