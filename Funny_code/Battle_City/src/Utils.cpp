#include "Utils.h"
#include <cmath>
#include <chrono>

namespace util {
double deg2rad(double deg) { return deg * M_PI / 180.0; }
double clamp(double v, double lo, double hi) {
    return v < lo ? lo : (v > hi ? hi : v);
}
int iround(double v) { return static_cast<int>(std::lround(v)); }

std::mt19937& rng() {
    static std::mt19937 gen(
        static_cast<unsigned>(
            std::chrono::high_resolution_clock::now().time_since_epoch().count()));
    return gen;
}

double randDouble(double lo, double hi) {
    std::uniform_real_distribution<double> dist(lo, hi);
    return dist(rng());
}

int randInt(int lo, int hi) {
    std::uniform_int_distribution<int> dist(lo, hi);
    return dist(rng());
}
} // namespace util
