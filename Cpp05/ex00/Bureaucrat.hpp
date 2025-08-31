#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP


#include "iostream"

class Bureaucrat
{
private:
    const std::string _name;
    int _grade;
public:
    class GradeTooHighException : public std::exception  // inherit from bass class  // (std::exception) the base class of all std exceptions
    {
        public:
            virtual const char* what() const throw(); // what() standar way to get a discription of what wrong, its a method in std::exception declared with throw() // throw() this function is exception specification 
    };
    class GradeTooLowException : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };
    Bureaucrat();
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat& operator=(const Bureaucrat &other);
    ~Bureaucrat();
    void getName();
    void getGrade();
    void incrementGrade();
    void decrementGrade();

};

#endif