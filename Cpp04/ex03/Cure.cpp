#include "Cure.hpp"

Cure::Cure()
{
    this->_type = "cure";
}

Cure::Cure(std::string const &type)
{
    this->_type = type;
}

Cure::Cure(const Cure &other)
{
    *this = other;
}

Cure& Cure::operator=(const Cure &other)
{
    if(this != &other)
        this->_type = other._type;
    return *this;
}

Cure::~Cure()
{
    
}

AMateria* Cure::clone() const
{
    AMateria *b = new Cure(*this);
    return b;
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target << "’s wounds *" << std::endl;
}