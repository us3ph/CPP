#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{    
    AForm* forms[4] = {NULL, NULL, NULL, NULL};
    try
    {
        Intern intern;
        Bureaucrat boss("boss", 150);
        forms[0] = intern.makeForm("Shrubbery", "Bender");
        forms[1] = intern.makeForm("Robotomy", "home");
        forms[2] = intern.makeForm("Pardon","criminal");
        // forms[3] = intern.makeForm("invalid form", "test");
        for(int i = 0; i < 1; i++)
        {
            if(forms[i])
            {
                boss.signForm(*forms[i]);
                boss.executeForm(*forms[i]);
            }
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    for(int i = 0; i < 4; i++)
    {
        delete forms[i];
    }
}