#include "ClapTrap.hpp"

int main()
{
    ClapTrap bot("yass");
    // ClapTrap bot1(bot);
    // ClapTrap bot2;
    // bot2 = bot;
    bot.attack("enemy");
    bot.attack("enemy");
    bot.attack("enemy");
    bot.takeDamage(5);
    bot.beRepaired(3);
}