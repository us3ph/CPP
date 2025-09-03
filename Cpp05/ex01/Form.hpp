#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
private:
    const std::string _name;
    bool _signed;
    int _gradeTosign;
    int _gradeToexcute;
public:
    class GradeTooHighException : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
        public:
            virtual const char* what() const throw(); 
    };
    Form();
    Form(const std::string &name, int gradeTosign, int gradeToexcute); // param 
    Form(const Form &other);
    Form& operator=(const Form &other);
    ~Form();
    std::string const& getName() const;
    void beSigned(Bureaucrat& bureaucrat);
    int getGradeTosign() const;
    int getGradeToexcute() const;
};

std::ostream& operator<<(std::ostream& out, const Form);

#endif