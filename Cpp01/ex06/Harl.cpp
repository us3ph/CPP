#include "Harl.hpp"

void Harl::debug()
{
    std::cout << "[ DEBUG ]\n" << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info()
{
    std::cout << "[ INFO ]\n" << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning()
{
    std::cout << "[ WARNING ]\n" << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error()
{
    std::cout << "[ ERROR ]\n" << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

int getLevelCode(std::string level) // helper func that return index in leves array
{
  std::string levels[] = {"DEBUG", "INFO", "WARNING","ERROR" };
  for(int i = 0; i < 4; i++)
  {
    if(levels[i] == level)
      return(i);
  }
  return(-1);
}
void Harl::complain(std::string level)
{
  switch(getLevelCode(level))
  {
    case 0:
        debug();
    case 1:
        info();
    case 2:
        warning();
    case 3:
        error();
        break;
    default:
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
  }
}