#include "../include/Signal.h"

std::string Signal::generate(double price, double sma, double rsi) {
    if (rsi < 30 && price < sma) return "BUY";
    if (rsi > 70 && price > sma) return "SELL";
    return "HOLD";
}