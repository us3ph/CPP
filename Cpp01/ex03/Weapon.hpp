#ifndef WEAPONE_HPP
#define WEAPONE_HPP

#include <iostream>

class Weapon
{
private:
    std::string type;
public:
    Weapon();

    const std::string& getType() const;
    void setType(std::string type);
};

#endif