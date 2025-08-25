#include "AMateria.hpp"

AMateria::AMateria()
{
    _type = "default";
}

AMateria::AMateria(std::string const &type) : _type(type) {}

AMateria::AMateria(const AMateria &other)
{
    *this = other;
}
AMateria& AMateria::operator=(const AMateria &other)
{
    if(this != &other)
        this->_type = other._type;
    return *this;
}

AMateria::~AMateria() {}

std::string const& AMateria::getType() const
{
    return this->_type;
}

void AMateria::use(ICharacter& target)
{
    std::cout << "check " << std::endl;
}