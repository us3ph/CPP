#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : Name("Default"), HitPoints(10), EnergyPoints(10), AttackDamage(0)
{
    std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) : Name(other.Name), HitPoints(other.HitPoints), EnergyPoints(other.EnergyPoints), AttackDamage(other.AttackDamage)
{
    std::cout << "Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
    if(this != &other)
    {
        this->Name = other.Name;
        this->HitPoints = other.HitPoints;
        this->EnergyPoints = other.EnergyPoints;
        this->AttackDamage = other.AttackDamage;
    }
    std::cout <<"copy assigment operator called" << std::endl;
    return *this;
}

ClapTrap::ClapTrap(const std::string &Name) : Name(Name), HitPoints(10), EnergyPoints(10), AttackDamage(0)
{
    std::cout << "ClapTrap " << Name << " created"<< std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << Name << " destroyed" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if( HitPoints <= 0 || EnergyPoints <= 0)
    {
        std::cout << "ClapTrap " << Name << " cannot attack" << std::endl;
        return;
    }

    std::cout << "ClapTrap " << Name << " attacks " << target << " causing " << AttackDamage << " points of damage" << std::endl;
    EnergyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    HitPoints -= amount;
    if(HitPoints < 0)
        HitPoints = 0;
    std::cout << "ClapTap " << Name << " take " << amount << " points of damage " << " HP is now " << HitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if(HitPoints <= 0 || EnergyPoints <= 0)
    {
        std::cout << "Claptrap " << Name << " cannot be repaired" << std::endl;
        return;
    }
    HitPoints += amount;
    EnergyPoints--;
    std::cout << "ClapTrap " << Name << " repairs itself for " << amount << " HP. " << " HP is now " << HitPoints << std:: endl;
}