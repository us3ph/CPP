#ifndef WEAPONE_HPP
#define WEAPONE_HPP

#include <iostream>

class Weapon
{
private:
    std::string type;
public:
    Weapon(const std::string& type); // constructor

    const std::string& getType() const; // getter for type
    void setType(std::string type); // optional setter
};

#endif