#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
class HumanB
{
private:
    std::string name;
    Weapon *Weapon;

public:
    HumanB();
    ~HumanB();
    void attack();
    void setWeapon(Weapon&);
};

#endif