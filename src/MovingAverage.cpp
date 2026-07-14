#include "../include/MovingAverage.h"

double MovingAverage::calculate(const std::vector<DataPoint>& data, int period) {
    if (data.size() < period) return 0.0;
    
    double sum = 0.0;
    for (int i = data.size() - period; i < data.size(); ++i) {
        sum += data[i].price;
    }
    return sum / period;
}