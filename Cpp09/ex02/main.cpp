#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
  if(argc < 2)
  {
    std::cerr << "invalid number of arguments" << std::endl;
    return 1;
  }
  try
  {
    PmergeMe pmergeMe;
    pmergeMe.parseInput(argv);
    pmergeMe.printUnsortedVector();
    pmergeMe.sortVector();
    pmergeMe.sortDeque();
    pmergeMe.printSortedVector();
    pmergeMe.printVectorTime();
    pmergeMe.printDequeTime();
  }
  catch (const std::exception& e)
  {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  }
}