#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    std::string costumer("bob", 1);
    std::string Form1 = "Shrubbery creation";
    std::string From2 = "Robotomy creation";
    std::string Form3 = "Pardon creation";
    // std::string Form4 = "fake form";

    try
    {
        Intern intern;
        intern.makeForm(Form3, costumer);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}