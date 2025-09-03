#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP


#include "iostream"
#include "Form.hpp"

class Form;
class Bureaucrat
{
private:
    const std::string _name;
    int _grade;
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
    Bureaucrat();
    Bureaucrat(const std::string name, int grade);
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat& operator=(const Bureaucrat &other);
    ~Bureaucrat();
    std::string const& getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();
    void signForm(Form &form); // implement it
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat bureaucrat);

#endif