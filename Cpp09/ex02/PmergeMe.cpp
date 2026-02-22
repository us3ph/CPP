#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _vecTime(0), _dequeTime(0) {}
PmergeMe::PmergeMe(const PmergeMe& other) : _vecUnsorted(other._vecUnsorted), _vecSorted(other._vecSorted) {}
PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
  if (this != &other)
  {
    _vecUnsorted = other._vecUnsorted;
    _vecSorted = other._vecSorted;
  }
  return *this;
};

PmergeMe::~PmergeMe() {};

void PmergeMe::printUnsortedVector() const
{
  std::cout << "Before: ";
  for(std::vector<int>::const_iterator it = _vecUnsorted.begin(); it != _vecUnsorted.end(); ++it)
  {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

void PmergeMe::parseInput(char **argv)
{
  std::set<int> uniqueNumbers;

  for(int i = 1; argv[i] != NULL; ++i)
  {
    if(argv[i][0] == '\0')
      throw std::invalid_argument("Empty argument");
    std::stringstream ss(argv[i]);
    int num;
    if (!(ss >> num) || !ss.eof())
      throw std::invalid_argument("Invalid input");
    if(num < 0)
      throw std::invalid_argument("Negative numbers");
    if(uniqueNumbers.find(num) != uniqueNumbers.end())
      throw std::invalid_argument("duplicate numbers");
    uniqueNumbers.insert(num);
    _vecUnsorted.push_back(num);
    _dequeUnsorted.push_back(num);
  }
  if(_vecUnsorted.size() < 2 || _dequeUnsorted.size() < 2)
    throw std::invalid_argument("put at least two numbers");
}

std::vector<int> PmergeMe::fordJohnsonVector(std::vector<int>& seq)
{
  if(seq.size() <= 1)
    return seq;

  if(seq.size() == 2)
  {
    if(seq[0] > seq[1])
      std::swap(seq[0], seq[1]);
    return seq;
  }
  // phase 1: create pairs and sort them
  std::vector<std::pair<int,int> > _vecPairs;
  int straggler = -1;
  bool hasStruggle = false;

  for(size_t i = 0; i + 1 < seq.size(); i += 2)
  {
    if(seq[i] > seq[i + 1])
      _vecPairs.push_back(std::make_pair(seq[i], seq[i + 1]));
    else
      _vecPairs.push_back(std::make_pair(seq[i + 1], seq[i]));
  }

  if(seq.size() % 2 != 0) // means we are at the last pair and there is an odd number of elements, so the last element is the straggler
  {
    straggler = seq.back(); // Handle the straggler
    hasStruggle = true;
  }
  // phase 2 extract the winners and recursively sort them
  std::vector<int> biggers;
  for(std::vector<std::pair<int,int> >::iterator it = _vecPairs.begin(); it != _vecPairs.end(); ++it)
    biggers.push_back(it->first);
  biggers = fordJohnsonVector(biggers); // return sorted biggers
  // RE-LINK: rebuild pairs in sorted winner order
  std::vector<std::pair<int,int> > sortedPairs;
  for(size_t i = 0; i < biggers.size(); ++i) //
  {
    for(size_t j = 0; j < _vecPairs.size(); ++j)
    {
      if(_vecPairs[j].first == biggers[i])
      {
        sortedPairs.push_back(_vecPairs[j]); // find the pair that has this bigger and add it to the sorted pairs
        break;
      }
    }
  }
  // phase 3 build the main chain and insert the losers
  std::vector<int> mainChain;
  mainChain.push_back(sortedPairs[0].second); // the first loser is the second element of the first pair
  for(size_t i = 0; i < sortedPairs.size(); ++i)
    mainChain.push_back(sortedPairs[i].first); // add the biggers to the main chain
  // jacobsthal secuence
  std::vector<size_t> jacobs;
  jacobs.push_back(1);
  jacobs.push_back(3);
  while(jacobs[jacobs.size() - 1] < sortedPairs.size())
  {
    size_t next = jacobs[jacobs.size() - 1] + 2 *jacobs[jacobs.size() - 2];
    jacobs.push_back(next);
  }
  // build insert order
  std::vector<size_t> insertOrder;
  size_t prev = 1;
  for(size_t k = 1; k < jacobs.size(); ++k)
  {
    size_t current = jacobs[k];
    if(current > sortedPairs.size())
      current = sortedPairs.size();
    for(size_t idx = current; idx > prev; --idx)
      insertOrder.push_back(idx -1);
    prev = jacobs[k];
    if(prev >= sortedPairs.size())
      break;
  }
  // binary insertion in jacobs order
  for(size_t i = 0; i < insertOrder.size(); ++i)
  {
    size_t pairIdx = insertOrder[i];
    int toInsert = sortedPairs[pairIdx].second; // the loser to insert
    int boundVal = sortedPairs[pairIdx].first; // the bigger in the pair, which is the upper bound for the loser
    std::vector<int>::iterator boundIt = mainChain.begin();
    while(boundIt != mainChain.end() && *boundIt != boundVal)
      ++boundIt;
    std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), boundIt, toInsert); // find the position to insert the loser
    mainChain.insert(pos, toInsert); // insert the loser in the main chain
  }
  if(hasStruggle)
  {
    std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), straggler); // find the position to insert the straggler
    mainChain.insert(pos, straggler);
  }
  return mainChain;
}

std::deque<int> PmergeMe::fordJohnsonDeque(std::deque<int>& seq)
{
    if(seq.size() <= 1)
    return seq;

  if(seq.size() == 2)
  {
    if(seq[0] > seq[1])
      std::swap(seq[0], seq[1]);
    return seq;
  }
  // phase 1: create pairs and sort them
  std::deque<std::pair<int,int> > _vecPairs;
  int straggler = -1;
  bool hasStruggle = false;

  for(size_t i = 0; i + 1 < seq.size(); i += 2)
  {
    if(seq[i] > seq[i + 1])
      _vecPairs.push_back(std::make_pair(seq[i], seq[i + 1]));
    else
      _vecPairs.push_back(std::make_pair(seq[i + 1], seq[i]));
  }

  if(seq.size() % 2 != 0) // means we are at the last pair and there is an odd number of elements, so the last element is the straggler
  {
    straggler = seq.back(); // Handle the straggler
    hasStruggle = true;
  }
  // phase 2 extract the winners and recursively sort them
  std::deque<int> biggers;
  for(std::deque<std::pair<int,int> >::iterator it = _vecPairs.begin(); it != _vecPairs.end(); ++it)
    biggers.push_back(it->first);
  biggers = fordJohnsonDeque(biggers); // return sorted biggers
  // RE-LINK: rebuild pairs in sorted winner order
  std::deque<std::pair<int,int> > sortedPairs;
  for(size_t i = 0; i < biggers.size(); ++i) //
  {
    for(size_t j = 0; j < _vecPairs.size(); ++j)
    {
      if(_vecPairs[j].first == biggers[i])
      {
        sortedPairs.push_back(_vecPairs[j]); // find the pair that has this bigger and add it to the sorted pairs
        break;
      }
    }
  }
  // phase 3 build the main chain and insert the losers
  std::deque<int> mainChain;
  mainChain.push_back(sortedPairs[0].second); // the first loser is the second element of the first pair
  for(size_t i = 0; i < sortedPairs.size(); ++i)
    mainChain.push_back(sortedPairs[i].first); // add the biggers to the main chain
  // jacobsthal secuence
  std::deque<size_t> jacobs;
  jacobs.push_back(1);
  jacobs.push_back(3);
  while(jacobs[jacobs.size() - 1] < sortedPairs.size())
  {
    size_t next = jacobs[jacobs.size() - 1] + 2 *jacobs[jacobs.size() - 2];
    jacobs.push_back(next);
  }
  // build insert order
  std::deque<size_t> insertOrder;
  size_t prev = 1;
  for(size_t k = 1; k < jacobs.size(); ++k)
  {
    size_t current = jacobs[k];
    if(current > sortedPairs.size())
      current = sortedPairs.size();
    for(size_t idx = current; idx > prev; --idx)
      insertOrder.push_back(idx -1);
    prev = jacobs[k];
    if(prev >= sortedPairs.size())
      break;
  }
  // binary insertion in jacobs order
  for(size_t i = 0; i < insertOrder.size(); ++i)
  {
    size_t pairIdx = insertOrder[i];
    int toInsert = sortedPairs[pairIdx].second; // the loser to insert
    int boundVal = sortedPairs[pairIdx].first; // the bigger in the pair, which is the upper bound for the loser
    std::deque<int>::iterator boundIt = mainChain.begin();
    while(boundIt != mainChain.end() && *boundIt != boundVal)
      ++boundIt;
    std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), boundIt, toInsert); // find the position to insert the loser
    mainChain.insert(pos, toInsert); // insert the loser in the main chain
  }
  if(hasStruggle)
  {
    std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), straggler); // find the position to insert the straggler
    mainChain.insert(pos, straggler);
  }
  return mainChain;
}
void PmergeMe::printSortedVector() const
{
  std::cout<< "After: ";
  for(std::vector<int>::const_iterator it = _vecSorted.begin(); it != _vecSorted.end(); ++it)
  {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

void PmergeMe::printSortedDeque() const
{
  for(std::deque<int>::const_iterator it = _dequeSorted.begin(); it != _dequeSorted.end(); ++it)
    std::cout << *it << " ";
  std::cout << std::endl;
}

void PmergeMe::sortVector()
{
  struct timeval start, end;
  gettimeofday(&start, NULL);
  _vecSorted = fordJohnsonVector(_vecUnsorted);
  gettimeofday(&end, NULL);
  _vecTime = ((end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec)) / 1000000.0;
}

void PmergeMe::sortDeque()
{
  struct timeval start, end;
  gettimeofday(&start, NULL);
  _dequeSorted = fordJohnsonDeque(_dequeUnsorted);
  gettimeofday(&end, NULL);
  _dequeTime = ((end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec)) / 1000000.0;
}

void PmergeMe::printVectorTime() const
{
  std::cout << "Time to process a range of " << _vecSorted.size()
            << " elements with std::vector : "
            << std::fixed << std::setprecision(5) << _vecTime << " s" << std::endl;
}

void PmergeMe::printDequeTime() const
{
  std::cout << "Time to process a range of " << _dequeSorted.size()
            << " elements with std::deque  : "
            << std::fixed << std::setprecision(5) << _dequeTime << " s" << std::endl;
}