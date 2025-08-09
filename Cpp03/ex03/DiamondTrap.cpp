#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : FragTrap("default"), ScavTrap("default")
{   
    std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
    std::cout << "DiamondTrap param constructor called" << std::endl;
    HitPoints = FragTrap::HitPoints;
    EnergyPoints = ScavTrap::EnergyPoints;
    AttackDamage = FragTrap::AttackDamage;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &other)
{
   std::cout << "copy assigment operator called" << std::endl;
   if(this != &other)
        DiamondTrap::operator=(other);
    return *this; 
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
   ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "I am DiamondTrap " << ClapTrap::Name << " and my ClapTrap name is " << ClapTrap::Name << std::endl;
}
