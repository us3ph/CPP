#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(0) {}
Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
    *this = other;
}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
    if(this != &other)
    {
        this->_grade = other._grade;
        this->_name = other._name;
    }
    return *this;
}
Bureaucrat::~Bureaucrat() {}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return("Grade is too high max is 150");
}
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return("Grade is too low min is 1");
}