#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
class HumanA
{
private:
    std::string name;
    Weapon &Weapon;

public:
    HumanA();
    ~HumanA();
    void attack();
};

#endif