#include "Intern.hpp"

Intern::Intern() {}
Intern::Intern(const Intern &other)
{
    (void)other;
}

Intern& Intern::operator=(const Intern &other)
{
    (void)other;
    return *this;
}

Intern::~Intern()
{
}

AForm* (*Intern::formCreators[3])(const std::string& target) =
{
    &Intern::createShrubberyForm,
    &Intern::creatRobotomyForm,
    &Intern::createPardonForm
};
AForm* Intern::makeForm(const std::string &formName, const std::string &target)
{
    std::string formNames[3] = {"Shrubbery creation","Robotomy creation","Pardon creation"};

    for(int i = 0; i < 3 ; i++)
    {
        if(formNames[i] == formName)
        {
            std::cout << "Intern creates " << formName << std::endl;
            return formCreators[i](target);
        }
    }
    throw FormNotFoundException();
    return NULL;
}

AForm* Intern::createShrubberyForm(const std::string &target)
{
    return new ShrubberyCreationForm(target);
}
AForm* Intern::creatRobotomyForm(const std::string &target)
{
    return new RobotomyRequestForm(target);
}
AForm* Intern::createPardonForm(const std::string &target)
{
    return new PresidentialPardonForm(target);
}

const char* Intern::FormNotFoundException::what() const throw()
{
    return "Form not found";
}