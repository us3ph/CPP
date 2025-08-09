#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"

class DiamondTrap : virtual public FragTrap, virtual public ScavTrap // if someone inherits from both ScavTrap and FragTrap, make sure they share the same single ClapTrap base object
{
private:
    std::string Name;
public:
    DiamondTrap();
    DiamondTrap(const std::string &name);
    DiamondTrap(const DiamondTrap &other);
    DiamondTrap& operator=(const DiamondTrap &other);
    ~DiamondTrap();
    void attack(const std::string& other);
    void whoAmI();
};

#endif