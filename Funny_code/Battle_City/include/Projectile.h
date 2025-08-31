#pragma once

struct ShotParams {
    double angle_deg; // 0..90
    double power;     // 0..100 (abstract unit)
};

struct ShotResult {
    double landingX;   // predicted landing x on 1D map
    bool   hit;        // within blast radius
    double error;      // distance to target center
};
