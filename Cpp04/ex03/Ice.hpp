#ifndef ICE_HPP
#define ICE_HPP

#include "iostream"
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{
private:
    std::string _type;
public:
    Ice();
    Ice(std::string const &type);
    Ice(const Ice &other);
    Ice& operator=(const Ice &other);
    ~Ice();
    AMateria* clone() const;
    void use(ICharacter& target);
};


#endif
