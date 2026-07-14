#include "../include/DataPoint.h"

DataPoint::DataPoint(std::string ts, double p, double v)
    : timestamp(ts), price(p), volume(v) {}