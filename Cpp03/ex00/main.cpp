#include "ClapTrap.hpp"

int main()
{
    ClapTrap bot("astro");
    ClapTrap enemy("enemy");
    bot.attack("enemy");
    enemy.takeDamage(5);
    enemy.attack("astro");
    bot.takeDamage(5);
    bot.beRepaired(3);
}