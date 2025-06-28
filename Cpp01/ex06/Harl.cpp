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

void Harl::complain(std::string level)
{
  int code = -1;

  if(level == "DEBUG")
    code = 0;
  else if(level == "INFO")
    code = 1;
  else if(level == "WARNING")
    code = 2;
  else if(level == "ERROR")
    code = 3;
  switch(code)
  {
    case 0:
        debug();
        break;
    case 1:
        info();
        break;
    case 2:
        warning();
        break;
    case 3:
        error();
        break;
    default:
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
  }
}