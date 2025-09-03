#include "Form.hpp"

Form::Form() : _name("Default"), _signed(false), _gradeTosign(150), _gradeToexcute(150)
{
    if(_gradeTosign < 1 || _gradeToexcute < 1)
        throw GradeTooHighException();
    if(_gradeTosign > 150 || _gradeToexcute > 150)
        throw GradeTooLowException();
}

Form::Form(const std::string &name, int gradeTosign, int gradeToexcute) : _name(name)
{
    if(_gradeTosign < 1 || _gradeToexcute < 1)
        throw GradeTooHighException();
    if(_gradeTosign > 150 || _gradeToexcute > 150)
        throw GradeTooLowException();
    this->_signed = false;
    _gradeTosign = gradeTosign;
    _gradeToexcute = gradeToexcute;
}

Form::Form(const Form &other) : _name(other._name), _signed(other._signed), _gradeTosign(other._gradeTosign), _gradeToexcute(other._gradeToexcute) {}

Form& Form::operator=(const Form &other)
{
    if(this != &other)
    {
        this->_signed = other._signed;
        this->_gradeTosign = other._gradeTosign;
        this->_gradeToexcute = other._gradeToexcute;
    }
    return *this;
}

Form::~Form()
{

}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("Grade is too high min is 1");
}
const char* Form::GradeTooLowException::what() const throw()
{
    return ("Grade is too low max is 150");
} 

std::string const& Form::getName() const
{
    return this->_name;
}

void Form::beSigned(Bureaucrat& bureaucrat)
{
    if(bureaucrat.getGrade() <= _gradeTosign)
        _signed = true;
    else
        throw GradeTooLowException();
}
int Form::getGradeTosign() const
{
    return this->_gradeTosign;
}
int Form::getGradeToexcute() const
{
    return this->_gradeToexcute;
}

 bool Form::getSigned() const
 {
    return _signed;
 }

std::ostream& operator<<(std::ostream& out, const Form &form)
{
    out << "Form: " << form.getName() 
        << ", signed: " << (form.getSigned() ? "yes" : "no")
        << ", grade to sign: " << form.getGradeTosign()
        << ", grade to execute: " << form.getGradeToexcute();
    return out;
}