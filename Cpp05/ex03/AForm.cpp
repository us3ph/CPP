#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Default"), _signed(false), _gradeTosign(150), _gradeToexcute(150)
{
    if(_gradeTosign < 1 || _gradeToexcute < 1)
        throw GradeTooHighException();
    if(_gradeTosign > 150 || _gradeToexcute > 150)
        throw GradeTooLowException();
}

AForm::AForm(const std::string &name, int gradeTosign, int gradeToexcute) : _name(name), _gradeTosign(gradeTosign), _gradeToexcute(gradeToexcute)
{
    if(_gradeTosign < 1 || _gradeToexcute < 1)
        throw GradeTooHighException();
    if(_gradeTosign > 150 || _gradeToexcute > 150)
        throw GradeTooLowException();
    this->_signed = false;
}

AForm::AForm(const AForm &other) : _name(other._name), _signed(other._signed), _gradeTosign(other._gradeTosign), _gradeToexcute(other._gradeToexcute) {}

AForm& AForm::operator=(const AForm &other)
{
    if(this != &other)
    {
        this->_signed = other._signed;
        this->_gradeTosign = other._gradeTosign;
        this->_gradeToexcute = other._gradeToexcute;
    }
    return *this;
}

AForm::~AForm() {}

const char* AForm::GradeTooHighException::what() const throw()
{
    return ("Grade is too high (min is 1)");
}
const char* AForm::GradeTooLowException::what() const throw()
{
    return ("Grade is too low (max is 150)");
}

std::string const& AForm::getName() const
{
    return this->_name;
}

void AForm::beSigned(Bureaucrat& bureaucrat)
{
    if(bureaucrat.getGrade() <= _gradeTosign)
        _signed = true;
    else
        throw GradeTooLowException();
}
int AForm::getGradeTosign() const
{
    return this->_gradeTosign;
}
int AForm::getGradeToexcute() const
{
    return this->_gradeToexcute;
}

 bool AForm::getSigned() const
 {
    return _signed;
 }

std::ostream& operator<<(std::ostream& out, const AForm &AForm)
{
    out << "AForm: " << AForm.getName()
        << ", signed: " << (AForm.getSigned() ? "yes" : "no")
        << ", grade to sign: " << AForm.getGradeTosign()
        << ", grade to execute: " << AForm.getGradeToexcute();
    return out;
}

const char* AForm::FormNotSignedException::what() const throw()
{
  return("Form not signed");
}