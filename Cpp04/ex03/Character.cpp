#include "Character.hpp"

Character::Character()
{
    this->_name = "default";
}

Character::Character(const std::string &name) : _name(name) {}

Character::Character(const Character &other)
{
    *this = other;
}
Character& Character::operator=(const Character &other)
{
    if(this != &other)
        this->_name = other._name;
    return *this;
}

Character::~Character()
{

}

std::string const & Character::getName() const
{
    return this->_name;
}
void Character::equip(AMateria* m)
{
    if(m == NULL)
        return;
    for(int i = 0; i < 4; i++)
    {
        if(arr[i] == NULL);
        {
            arr[i] = m;
            return;
        }
    }
}
void Character::unequip(int idx)
{
    if(idx < 0 || idx >= 4 || arr[idx] == NULL)
        return;
    arr[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if(idx < 0 || idx >= 4)
        return;
    arr[idx] = target.
}