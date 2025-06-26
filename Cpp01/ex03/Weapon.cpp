#include "Weapon.hpp"


Weapon::Weapon(const std::string &type) : type(type) {} // consrtuctor

void Weapon::setType(std::string type)
{
    this->type = type;
}
const std::string &Weapon::getType() const
{
    return this->type;
}

