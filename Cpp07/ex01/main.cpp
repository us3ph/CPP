#include "iter.hpp"


void printInt(int &n)
{
    std::cout << n << std::endl;
}
void printString(std::string &str)
{
    std::cout << str << std::endl;
}
void upperCase(std::string &str)
{
    for(size_t i = 0; i < str.length(); i++)
    {
        str[i] = toupper(str[i]);
    }
}

void doubeValue(int &n) 
{
    n = n * 2;
}

int main()
{
    int numbers[] = {1,2,3};
    std::string words[] = {"test", "test1", "test2"};
    std::string letters[] = {"a","b", "c", "d"};

    std::cout << "testing regular functions\n";
    iter(numbers, 3, doubeValue);
    iter(numbers, 3, printInt);

    std::cout << "testing template functions\n";
    iter(numbers, 3, increment<int>);
    iter(numbers, 3, print<int>);
    iter(words, 3 , print<std::string>);
    
    iter(letters, 4, upperCase);
    iter(letters, 4, print<std::string>);
}