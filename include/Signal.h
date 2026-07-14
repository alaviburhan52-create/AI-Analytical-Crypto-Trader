#pragma once
#include <string>

class Signal {
public:
    static std::string generate(double price, double sma, double rsi);
};