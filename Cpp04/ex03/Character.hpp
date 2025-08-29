#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

//  Character class acts as a middleman it takes the slot num and target
// finds the right materia and tells that materia to act on the target

typedef struct s_arr
{
    AMateria *m;
    struct s_arr *next;
} t_arr;

static t_arr *inven;
static t_arr *rm;
class Character : public ICharacter
{
private:
    std::string _name;
    AMateria *arr[4];  // inventory of materia
public:
    Character();
    Character(const std::string &name);
    Character(const Character &other);
    Character& operator=(const Character &other);
    ~Character();
    
    virtual std::string const & getName() const;
    virtual void equip(AMateria* m);
    virtual void use(int idx, ICharacter& target);
    virtual void unequip(int idx);
};

void delete_lists();
#endif