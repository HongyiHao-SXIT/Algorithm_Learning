#pragma once
#include <random>

namespace util {
double deg2rad(double deg);
double clamp(double v, double lo, double hi);
int    iround(double v);

// Random helpers (singleton RNG)
std::mt19937& rng();
double randDouble(double lo, double hi);
int    randInt(int lo, int hi);
} // namespace util
