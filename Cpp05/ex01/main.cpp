#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    // Bureaucrat test("Neo", 2);

    // std::cout << test << std::endl;
    // try
    // {
    //     test.incrementGrade();
    //     test.incrementGrade();
    //     // test.incrementGrade();
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << std::endl;
    // }

    Form contract("employees contract", 50, 25);
    Bureaucrat boss("boss", 1);
    Bureaucrat manager("manager", 25);
    Bureaucrat intern("intern", 100);
    try
    {
        boss.signForm(contract);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    
}