#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other) : _stack(other._stack) {}

RPN& RPN::operator=(const RPN& other)
{
  if (this != &other)
    _stack = other._stack;
  return *this;
}

RPN::~RPN() {}

// void print_stack(std::stack<int>& s)
// {
//   std::stack<int> temp = s;
//   std::cout << "Stack: ";
//   while (!temp.empty())
//   {
//     std::cout << temp.top() << " ";
//     temp.pop();
//   }
//   std::cout << std::endl;
// }

void RPN::evaluate(const std::string& expression)
{
  std::string token;
  std::stringstream ss(expression);

  int c = 0;
  while(ss >> token)
  {
    if(token.length() != 1 || (!isdigit(token[0]) && token != "+" && token != "-" && token != "*" && token != "/"))
      throw std::runtime_error("");
    if(token == "+" || token == "-" || token == "*" || token == "/")
    {
      if(_stack.size() < 2)
        throw std::runtime_error("");
      int a = _stack.top();
      _stack.pop();
      int b = _stack.top();
      _stack.pop();
      if (token == "-")
       c = b - a;
      else if (token == "+")
        c = b + a;
      else if (token == "*")
        c = b * a;
      else if (token == "/")
        c = b / a;
      _stack.push(c);
    }
    else
      _stack.push(token[0] - '0');
  }
  if (_stack.size() != 1)
    throw std::runtime_error("");
  std::cout << _stack.top() << std::endl;
}