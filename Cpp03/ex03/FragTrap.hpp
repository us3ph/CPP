#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ScavTrap.hpp"

class FragTrap : virtual public ClapTrap // change it to virtual bsc to unsure there is only one shared ClapTrap subobject
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