#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <utility>
#include <sstream>
#include <deque>
#include <set>
#include <sys/time.h>
#include <iomanip>


class PmergeMe
{
  private:
  std::vector<int> _vecUnsorted;
  std::deque<int> _dequeUnsorted;

  std::vector<int> _vecSorted;
  std::deque<int> _dequeSorted;

  double _vecTime;
  double _dequeTime;

  public:
  PmergeMe();
  PmergeMe(const PmergeMe& other);
  PmergeMe& operator=(const PmergeMe& other);
  ~PmergeMe();

  void parseInput(char **argv);

  std::vector<int> fordJohnsonVector(std::vector<int>& seq);
  std::deque<int> fordJohnsonDeque(std::deque<int>& seq);

  void sortVector();
  void sortDeque();

  void printUnsortedVector() const;

  void printSortedVector() const;
  void printSortedDeque() const;

  void printDequeTime() const;
  void printVectorTime() const;
};

#endif