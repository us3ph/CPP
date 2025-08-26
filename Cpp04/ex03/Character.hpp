#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
class Character : public ICharacter
{
private:
    std::string _name;
    AMateria *arr[4];
public:
    Character();
    Character(const std::string &name);
    Character(const Character &other);
    Character& operator=(const Character &other);
    ~Character();

    virtual std::string const & getName() const;
    virtual void equip(AMateria* m);
    virtual void unequip(int idx);
    virtual void use(int idx, ICharacter& target);
};

#endif