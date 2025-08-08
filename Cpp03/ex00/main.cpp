#include "ClapTrap.hpp"

int main()
{
    ClapTrap bot("yass");
    bot.attack("enemy");
    bot.attack("enemy");
    bot.attack("enemy");
    bot.takeDamage(5);
    bot.beRepaired(3);
}