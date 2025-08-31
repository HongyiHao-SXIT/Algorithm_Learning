#pragma once
#include <string>

class Tank {
public:
    Tank(std::string name, int x, int hp = 100);

    const std::string& name() const { return name_; }
    int  x()   const { return x_; }
    int  hp()  const { return hp_; }
    bool alive() const { return hp_ > 0; }

    void setX(int nx) { x_ = nx; }
    void damage(int d);

private:
    std::string name_;
    int x_;   // position on [0, 100]
    int hp_;
};
