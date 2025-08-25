#include "Ice.hpp"


Ice::Ice()
{
    this->_type = "ice";
}

Ice::Ice(std::string const &type)
{
    this->_type = type;
}

Ice::Ice(const Ice &other)
{
    *this = other;
}

Ice& Ice::operator=(const Ice &other)
{
    if(this != &other)
        this->_type = other._type;
    return *this;
}

Ice::~Ice()
{
    
}

AMateria* Ice::clone() const
{
    AMateria *m = new Ice(*this);
    return m;
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target << " *" << std::endl;
}
