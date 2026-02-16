#include <iostream>
#include <stack>
#include <sstream>
#include <stdexcept>
#include <vector>

class RPN
{
  private:
  std::stack<int> _stack;
  void split(const std::string& expression, char delimiter, std::vector<std::string>& tokens);

  public:
  RPN();
  RPN(const RPN& other);
  RPN& operator=(const RPN& other);
  ~RPN();
  void evaluate(const std::string& expression);
};