#include "Replacer.hpp"

int main(int argc, char **argv)
{
  if(argc != 4)
  {
    std:: cerr << "Error: number of arguments not correct" << std::endl;
    return(1);
  }
  std::string fileName;
  std::string s1;
  std::string s2;

  fileName = argv[1];
  s1 = argv[2];
  s2 = argv[3];

  if(replacer(fileName, s1, s2))
    return(1);
}
