#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
  if(N <= 0)
    return nullptr;

  Zombie *horde;
  horde = new Zombie[N]; // this array of objects
  for(int i = 0; i < N; i++)
  {
    horde[i].setName(name);
  }
  return horde;

}
