#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{

    try
    {
        Form contract1("employees contract", 20, 25);
        Form contract2("employees contract", 20, 25);
        Form contract3("employees contract", 20, 25);
        Bureaucrat boss("boss", 1);
        Bureaucrat manager("manager", 20);
        Bureaucrat intern("intern", 100);

        manager.signForm(contract1);
        boss.signForm(contract2);
        intern.signForm(contract3);

    }
    catch(const std::exception& e)
    {
        // std::cerr << e.what() << '\n';
        std::cout << "test" << std::endl; // check what happen here
        // return;
    }
    
}