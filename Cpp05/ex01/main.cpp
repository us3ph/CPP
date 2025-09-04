#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{

    Form contract("employees contract", 20, 25);
    Bureaucrat boss("boss", 1);
    Bureaucrat manager("manager", 25);
    Bureaucrat intern("intern", 100);
    try
    {
        manager.signForm(contract);
        // boss.signForm(contract);
        // intern.signForm(contract);
    }
    catch(const std::exception& e)
    {
        // std::cerr << e.what() << '\n';
        std::cout << "test" << std::endl; // check what happen here
    }
    
}