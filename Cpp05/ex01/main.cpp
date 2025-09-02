#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat test("Neo", 2);

    std::cout << test << std::endl;
    try
    {
        test.incrementGrade();
        test.incrementGrade();
        // test.incrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    
}