#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap("default")
{
    HitPoints = 100;
    EnergyPoints = 100;
    AttackDamage = 30;
    std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string &name) :ClapTrap(name)
{
    HitPoints = 100;
    EnergyPoints = 100;
    AttackDamage = 30;
    std::cout << "FragTrap param constructor created" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
    *this = other;
}

FragTrap& FragTrap::operator=(const FragTrap &other)
{
    std::cout << "FragTrap copy assigment operator called" << std::endl;
    if(this != &other)
        FragTrap::operator=(other);
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::attack(const std::string &other)
{
    if(HitPoints <= 0 || EnergyPoints <= 0)
    {
        std::cout << "FragTrap " << Name << " cannot attack" << std::endl;
    }
    std::cout << "FragTrap " << Name << " attack " << other << " causing " << AttackDamage << " point of damage" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << Name << " highFivesGuys" << std::endl;
}