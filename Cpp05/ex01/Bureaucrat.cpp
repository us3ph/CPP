#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
    if(_grade < 1)
        throw GradeTooHighException();
    if(_grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
    if(grade < 1)
        throw GradeTooHighException();
    if(grade > 150)
        throw GradeTooLowException();
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
    if(this != &other)
        this->_grade = other._grade;
    return *this;
}
Bureaucrat::~Bureaucrat() {}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return("Grade is too high min is 1");
}
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return("Grade is too high max is 150");
}

std::string const& Bureaucrat::getName() const
{
    return this->_name;
}

int Bureaucrat::getGrade() const
{
    return this->_grade;
}

void Bureaucrat::incrementGrade()
{
    if(_grade <= 0)
        throw GradeTooHighException();
    _grade--;

}

void Bureaucrat::decrementGrade()
{
    if(_grade >= 150)
        throw GradeTooLowException();
    _grade++;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat &bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return out;
}

void Bureaucrat::signForm(Form &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << _name << " signed " << form << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << _name << " couldn't sign " << form << " because " << e.what() << std::endl;      
    }
    


}