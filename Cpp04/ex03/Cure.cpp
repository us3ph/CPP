#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(std::string const &type) : AMateria(type) {}

Cure::Cure(const Cure &other) : AMateria(other){}// call parent copy constructor

Cure& Cure::operator=(const Cure &other)
{
    if(this != &other)
        AMateria::operator=(other);
    return *this;
}

Cure::~Cure()
{
    
}

AMateria* Cure::clone() const
{
    return new Cure(*this); // create new Ice using copy constructor
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}