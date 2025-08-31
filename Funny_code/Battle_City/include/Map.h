#pragma once
#include <string>

class Map1D {
public:
    Map1D(int length = 101, int blastRadius = 3)
        : length_(length), blastRadius_(blastRadius) {}

    int length() const { return length_; }
    int blastRadius() const { return blastRadius_; }

    // Render a simple ASCII line with tanks positions.
    std::string render(int px, int qx) const;

    // confine a position into map bounds
    int clampX(int x) const;

private:
    int length_;
    int blastRadius_;
};
