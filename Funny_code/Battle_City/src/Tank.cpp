#include "Tank.h"
#include <algorithm>

Tank::Tank(std::string name, int x, int hp) : name_(std::move(name)), x_(x), hp_(hp) {}

void Tank::damage(int d) {
    hp_ = std::max(0, hp_ - std::max(0, d));
}
