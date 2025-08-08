#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ScavTrap.hpp"

class FragTrap : public ClapTrap
{

public:
    FragTrap();
    FragTrap(const std::string &name);
    FragTrap(const FragTrap &other);
    FragTrap& operator=(const FragTrap &other);
    ~FragTrap();
    void attack(const std::string &other);
    void highFivesGuys(void);
};

#endif