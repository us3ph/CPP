#ifndef CURE_HPP
#define CURE_HPP

#include "iostream"
#include "AMateria.hpp"
#include "ICharacter.hpp"


class Cure : public AMateria
{
private:
    std::string _type;
public:
    Cure();
    Cure(std::string const &type);
    Cure(const Cure &other);
    Cure& operator=(const Cure &other);
    ~Cure();
    AMateria* clone() const;
    void use(ICharacter& target);
};


#endif