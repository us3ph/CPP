#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Default") //  constructor chaining Bcs scavTrap uses attributes from ClapTrap Show correct constructor chaining in the output
{
    HitPoints = 100;
    EnergyPoints = 50;
    AttackDamage = 20;

    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) // When constructing a ScavTrap, you must initialize the ClapTrap part correctly, with the name
{
    HitPoints = 100;
    EnergyPoints = 50;
    AttackDamage = 20;

    std::cout << "ScavTrap param constructor created" << std::endl;
}

 ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
 {
    std::cout << "ScavTrap copy constructor called" << std::endl;
    *this = other;
 }

 ScavTrap& ScavTrap::operator=(const ScavTrap &other)
 {
    std::cout << "ScavTrap copy assigment operator called" << std::endl;
    if(this != &other)
        ScavTrap::operator=(other);
    return *this;
 }

 ScavTrap::~ScavTrap()
 {
    std::cout << "ScavTrap destructor called" << std::endl;
 }

 void ScavTrap::attack(const std::string& other)
 {
    if(HitPoints <= 0 || EnergyPoints <= 0)
    {
        std::cout << "ScavTrap " << Name << "cannot attack" << std::endl;
        return;
    }
    std::cout << "ScavTrap " << Name << " attack " << other << " causing " << AttackDamage << " point of damage" << std::endl;
 }

 void ScavTrap::guardGate()
 {
    std::cout << "ScavTrap " << Name << " is now in Gate keeper mode" << std::endl;
 }