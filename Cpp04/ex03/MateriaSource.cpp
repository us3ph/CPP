#include "MateriaSource.hpp"

  MateriaSource::MateriaSource()
  {
    for(int i = 0; i < 4; i++)
      tmpl[i] = NULL;
  }

  MateriaSource::MateriaSource(const MateriaSource &other)
  {
    for(int i = 0; i < 4; i++)
      tmpl[i] = NULL;
    for(int i = 0; i < 4; i++)
    {
      if(other.tmpl[i])
        tmpl[i] = other.tmpl[i]->clone();
      else
        tmpl[i] = NULL;
    }

  }

  MateriaSource& MateriaSource::operator=(const MateriaSource &other)
  {
    for(int i = 0; i < 4; i++)
    {
      delete tmpl[i];
      tmpl[i] = NULL;
    }
    if(this != &other)
    {
      for(int i = 0 ; i < 4; i++)
      {
        if(other.tmpl[i])
          tmpl[i] = other.tmpl[i]->clone();
      }
    }
    return *this;
  }

  MateriaSource::~MateriaSource()
  {
    for(int i = 0; i < 4; i++)
      delete tmpl[i];
  }

  void MateriaSource::learnMateria(AMateria *materia) //  stores a copy of the materia
  {
    if(!materia)
      return;

    for(int i = 0; i < 4; i++)
    {
      if(tmpl[i] == NULL)
      {
        tmpl[i] = materia->clone();
        delete materia; // should take ownership of the passed materia and delete it after cloning
        return;
      }
    }
  }

  AMateria* MateriaSource::createMateria(std::string const & type) // returns a clone of stored materia matching the type
  {
    for(int i = 0; i < 4; i++)
    {
      if(tmpl[i] && tmpl[i]->getType() == type)
        return tmpl[i]->clone();
    }
    return NULL; // return NULL if not found
  }