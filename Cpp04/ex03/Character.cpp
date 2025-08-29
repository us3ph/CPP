#include "Character.hpp"

Character::Character() : _name("Default")
{
    for(int i = 0; i < 4; i++)
        arr[i] = NULL;
    inven = NULL;
    rm = NULL;
}

Character::Character(const std::string &name) : _name(name)
{
    for(int i = 0; i < 4; i++)
        arr[i] = NULL;
    inven = NULL;
    rm = NULL;
}

Character::Character(const Character &other) : _name(other._name)
{
    for(int i = 0; i < 4; i++)
        arr[i] = NULL;
    for(int i = 0; i < 4; i++)
    {
        if(other.arr[i] != NULL)
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
        {
            delete arr[i];
            arr[i] = NULL;
        }
        _name = other._name;
        for(int i = 0; i < 4; i++)
        {
            if(other.arr[i] != NULL)
                arr[i] = other.arr[i]->clone();
        }
    }
    return *this;
}

Character::~Character()
{
    while(inven)
    {
        t_arr *tmp = inven;
        inven = inven->next;
        delete tmp->m; // delete materia that was unequipped
        delete tmp; // delete linked list node
    }
    while(rm)
    {
        t_arr *tmp = rm;
        rm = rm->next;
        delete tmp;
    }
    for(int i = 0; i < 4; i++)
        delete arr[i]; // delete materias still in inventory
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
        if(arr[i] == m) // avoid dublicate
            return;
    }
    for(int i = 0; i < 4; i++)
    {
        if(arr[i] == NULL)
        {
            arr[i] = m->clone(); // clone instead of sharing
            t_arr *new_node = new t_arr;
            new_node->m = arr[i];
            new_node->next = rm; // oint to old head
            rm = new_node; // update head
            return;
        }
    }
    delete m;
}
void Character::unequip(int idx)
{
    if(idx < 0 || idx >= 4 || arr[idx] == NULL)
        return;

    t_arr *new_node = new t_arr;
    new_node->m = arr[idx]; // add unequiped materia to rm list and delete it in distructor
    new_node->next = inven;
    inven = new_node;

    arr[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if(idx < 0 || idx >= 4 || arr[idx] == NULL)
        return;
    arr[idx]->use(target);
}

// void remove_node(t_arr*& head, AMateria *materia)
// {
//     if(!head)
//         return;
//     if(head->m == materia)
//     {
//         t_arr *tmp = head;
//         head = head->next;
//         delete tmp;
//         return;
//     }
//     t_arr *current = head;
//     while(current->next && current->next->m != materia)
//         current = current->next;
//     if(current->next && current->next->m == materia)
//     {
//         t_arr *tmp;

//         tmp = current->next;
//         current->next = tmp->next;
//         delete tmp;
//     }
// }