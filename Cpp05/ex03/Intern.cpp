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

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string &formName, const std::string &target)
{
    for(int i = 0; i < 3 ; i++)
    {
        if(formCreator[i].name == target);
            formCreator[i].creatForm
    }
}

static AForm* createShrubberyForm(const std::string &target)
{
    return new ShrubberyCreationForm(target);
}
static AForm* creatRobotomyForm(const std::string &target)
{

}
static AForm* createPardonForm(const std::string &target)
{

}
