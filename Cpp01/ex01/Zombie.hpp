#ifndef ZOMBIE__HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
private:
    std::string m_name;

public:
    Zombie();                  // default constructor
    Zombie(std::string name); // constructor
    ~Zombie();                // destructor

    void announce();
    void setName(std::string name); // need it after defaut construct
};


#endif