#include "Character.hpp"

Character::Character() : _name("Default")
{
    for(int i = 0; i < 4; i++)
        arr[i] = NULL;
}

Character::Character(const std::string &name) : _name(name)
{
    for(int i = 0; i < 4; i++)
        arr[i] = NULL;
}

Character::Character(const Character &other)
{
    for(int i = 0; i < 4; i++)
    {
        if(other.arr[i] == NULL)
            arr[i] = other.arr[i]->clone(); // for deep copy
        else
            arr[i] = NULL;
    }
}
Character& Character::operator=(const Character &other)
{
    if(this != &other)
    {
        for(int i = 0; i < 4; i++)
            delete other.arr[i]; // delete old materia first;
        for(int i = 0; i < 4; i++)
        {
            if(other.arr[i] == NULL)
                arr[i] = other.arr[i]->clone();
        }
    }
    return *this;
}

Character::~Character()
{
    // delete[] arr;
    for(int i = 0; i < 4; i++)
        delete arr[i];
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
    arr[idx]->use(target);
}