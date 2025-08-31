#include "Game.h"
#include "Utils.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using std::cout;
using std::cin;
using std::string;

Game::Game()
: wind_(0.0), windFactor_(0.02), map_(101, 3),
  player_("Player", 10, 100),
  enemy_("Enemy AI", 90, 100) {}

void Game::run() {
    cout << "==== Tank Battle (Console) ====\n";
    cout << "Map length: " << map_.length() << ", blast radius: " << map_.blastRadius() << "\n";
    cout << "Rules: Each turn choose angle [5..85] and power [10..100]. Wind affects range.\n";
    cout << "Hit if landing within " << map_.blastRadius() << " of target.\n";
    cout << "First to reduce opponent to 0 HP wins. Good luck!\n\n";

    int round = 1;
    while (player_.alive() && enemy_.alive()) {
        newRoundBanner(round++);
        rollWind();
        printStatus();
        draw();

        playerTurn();
        if (!enemy_.alive()) break;

        enemyTurn();
    }

    cout << "\n===============================\n";
    if (player_.alive()) cout << "You win! 🏆\n";
    else                 cout << "You lost. Try again! 💥\n";
}

void Game::newRoundBanner(int round) const {
    cout << "\n----------- Round " << round << " -----------\n";
}

void Game::rollWind() {
    // wind in [-5, 5], where positive pushes shots to the right (increases range)
    wind_ = util::randDouble(-5.0, 5.0);
}

void Game::printStatus() const {
    cout << std::fixed << std::setprecision(1);
    cout << "Wind: " << wind_ << "  |  "
         << player_.name() << " HP: " << player_.hp() << " @ " << player_.x()
         << "  vs  "
         << enemy_.name()  << " HP: " << enemy_.hp()  << " @ " << enemy_.x()
         << "\n";
}

void Game::draw() const {
    cout << map_.render(player_.x(), enemy_.x()) << "\n";
    cout << "0" << std::setw(map_.length()-3) << "100" << "\n";
}

void Game::playerTurn() {
    ShotParams p{};
    cout << "[Your Turn] Enter angle (5..85 deg): ";
    while (!(cin >> p.angle_deg) || p.angle_deg < 5 || p.angle_deg > 85) {
        cin.clear(); cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid. Angle 5..85: ";
    }
    cout << "Enter power (10..100): ";
    while (!(cin >> p.power) || p.power < 10 || p.power > 100) {
        cin.clear(); cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid. Power 10..100: ";
    }

    auto res = simulateShot(player_.x(), enemy_.x(), p);
    cout << "Your shell landed at x=" << util::iround(res.landingX) << " (error " << std::abs(res.error) << ")\n";
    if (res.hit) {
        cout << "Direct HIT! 💣\n";
        enemy_.damage( util::randInt(25, 35) );
    } else {
        cout << "Miss...\n";
    }
}

void Game::enemyTurn() {
    cout << "[Enemy Turn]\n";
    auto p = enemyChooseParams();
    auto res = simulateShot(enemy_.x(), player_.x(), p);
    cout << "Enemy fires angle=" << std::setprecision(1) << p.angle_deg
         << ", power=" << p.power
         << " -> lands x=" << util::iround(res.landingX)
         << " (error " << std::abs(res.error) << ")\n";
    if (res.hit) {
        cout << "Enemy HIT! 💥\n";
        player_.damage( util::randInt(20, 30) );
    } else {
        cout << "Enemy missed.\n";
    }
    pressEnterToContinue();
}

ShotResult Game::simulateShot(int fromX, int toX, const ShotParams& p) const {
    // Very simplified ballistic model on 1D line:
    // Ideal range R = (v^2 / g) * sin(2θ). We map power -> v as v = power.
    // Wind adds a multiplicative & additive tweak to range.
    double theta = util::deg2rad(p.angle_deg);
    double v = p.power;
    double idealRange = (v * v / gravity_) * std::sin(2.0 * theta);

    // Wind effect: scale and shift the range
    double range = idealRange * (1.0 + windFactor_ * wind_) + wind_;

    // Direction: shot goes from shooter towards target side
    int dir = (toX > fromX) ? 1 : -1;
    double landX = fromX + dir * range;

    // clamp to map
    landX = util::clamp(landX, 0.0, static_cast<double>(map_.length()-1));
    double err = landX - toX;

    ShotResult r;
    r.landingX = landX;
    r.hit = std::abs(err) <= map_.blastRadius();
    r.error = err;
    return r;
}

ShotParams Game::enemyChooseParams() const {
    // Naive heuristic: aim near 45°; set power from distance,
    // then add small randomness and wind compensation.
    double dist = std::abs(enemy_.x() - player_.x());
    ShotParams p;
    p.angle_deg = 45.0 + util::randDouble(-8.0, 8.0);

    // Inverse of range formula (rough): v ≈ sqrt(R * g / sin(2θ))
    double theta = util::deg2rad(p.angle_deg);
    double denom = std::sin(2.0 * theta);
    if (denom < 0.2) denom = 0.2; // avoid extreme angles
    double v = std::sqrt(dist * gravity_ / denom);

    // Wind compensation
    v *= (1.0 - windFactor_ * wind_ * ((player_.x() < enemy_.x()) ? 1 : -1));

    // Clamp into [10, 100] and add tiny randomness
    v = util::clamp(v + util::randDouble(-3.0, 3.0), 10.0, 100.0);
    p.power = v;
    return p;
}

void Game::pressEnterToContinue() {
    cout << "Press ENTER to continue...";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (cin.peek() == '\n') cin.get();
}
