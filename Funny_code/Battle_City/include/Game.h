#pragma once
#include "Tank.h"
#include "Projectile.h"
#include "Map.h"
#include <string>

class Game {
public:
    Game();

    void run(); // main loop

private:
    // physics & environment
    double gravity_ = 9.8;
    double wind_;          // meters per second "equivalent" (affects range)
    double windFactor_;    // per-turn factor applied to range
    Map1D map_;

    Tank player_;
    Tank enemy_;

    // helpers
    void newRoundBanner(int round) const;
    void rollWind();
    void printStatus() const;
    void draw() const;
    void playerTurn();
    void enemyTurn();

    ShotResult simulateShot(int fromX, int toX, const ShotParams& p) const;

    // very naive AI
    ShotParams enemyChooseParams() const;

    // IO helpers
    static void pressEnterToContinue();
};
