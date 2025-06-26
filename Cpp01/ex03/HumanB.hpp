#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include "HumanB.hpp"

class HumanB
{
private:
    std::string name;
    Weapon *weapon;

public:
HumanB(const std::string &name);
void setWeapon(Weapon &Weapon);
void attack();
};

#endif