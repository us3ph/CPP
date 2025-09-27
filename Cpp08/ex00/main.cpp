#include "easyfind.hpp"

int main()
{
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(40);
    vec.push_back(90);
    vec.push_back(15);
    try
    {
       std::vector<int>::iterator it =  easyfind(vec, 40);
       std::cout << "found " << *it << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}