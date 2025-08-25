#ifndef CURE_HPP
#define CURE_HPP

#include "iostream"
#include "AMateria.hpp"

class Cure : virtual public AMateria
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
};


#endif