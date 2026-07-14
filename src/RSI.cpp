#include "../include/RSI.h"

double RSI::calculate(const std::vector<DataPoint>& data, int period) {
    if (data.size() < period + 1) return 50.0;
    
    double gain = 0.0, loss = 0.0;
    
    for (int i = data.size() - period; i < data.size(); ++i) {
        double change = data[i].price - data[i-1].price;
        if (change >= 0) gain += change;
        else loss -= change;
    }
    
    gain /= period;
    loss /= period;
    
    if (loss == 0) return 100.0;
    double rs = gain / loss;
    return 100.0 - (100.0 / (1.0 + rs));
}