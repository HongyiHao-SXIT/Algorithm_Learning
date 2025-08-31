#include "Map.h"
#include <algorithm>

std::string Map1D::render(int px, int qx) const {
    std::string line(length_, '.');
    px = clampX(px);
    qx = clampX(qx);
    if (px == qx) {
        line[px] = 'X'; // collision point
    } else {
        line[px] = 'P';
        line[qx] = 'E';
    }
    return line;
}

int Map1D::clampX(int x) const {
    return std::max(0, std::min(length_ - 1, x));
}
