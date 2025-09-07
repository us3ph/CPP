#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() :AForm("Default",72,45) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("Robotomy", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) :AForm(other), _target(other._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if(this != &other)
    {
        AForm::operator=(other);
    }
    return *this;
}
RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
    if(!getSigned())
        throw FormNotSignedException();
    if(executor.getGrade() > getGradeToexcute())
        throw GradeTooLowException();
    std::cout << "drilling noises" << std::endl;
    if(rand() % 2) // rand() standard C function from <cstdlib> that returns a pseudo-random integer
        std::cout << _target << " has been robotomized successfully" << std::endl;
    else
        std::cout << "the robotomy failed on " << _target << std::endl;
}