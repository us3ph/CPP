#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Default",25,5) {}
PresidentialPardonForm::PresidentialPardonForm(std::string &target) : AForm("Presidential creation", 25,5), _target(target) {}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other) {}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if(this != &other)
        AForm::operator=(other);
    return *this;
}
PresidentialPardonForm::~PresidentialPardonForm() {}
void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
    if(!getSigned())
        throw FormNotSignedException();
    if(executor.getGrade() > _gradeToexcute)
        throw GradeTooLowException();
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}