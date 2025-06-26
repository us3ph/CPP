#include "HumanB.hpp"

// constructor humanb
HumanB::HumanB(const std::string &name) : name(name), weapon(nullptr) {}

void HumanB::setWeapon(Weapon &wpn)
{
  weapon = &wpn;
}

// attack humanb
void HumanB::attack()
{
  std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}