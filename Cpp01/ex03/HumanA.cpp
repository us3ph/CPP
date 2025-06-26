#include " HumanA.hpp"

// construcor humanA
HumanA::HumanA(const std::string &name, Weapon &weapon) : name(name), weapon(weapon) {}

//attack humanA
void HumanA::attack() const
{
  std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
