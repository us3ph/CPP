#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap // ScavTrap inherit from ClapTrap
{
private:

  ScavTrap();
  ScavTrap(std::string name);
  ScavTrap(const ScavTrap &other);
  ScavTrap& operator=(const ScavTrap &other);
  ~ScavTrap();

public:
  void attack(const std::string& other);
  void guardGate();
};


#endif
