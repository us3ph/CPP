#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


class Intern
{
private:
    static AForm* (*formCreators[3])(const std::string& target);
    static AForm* createShrubberyForm(const std::string &target);
    static AForm* creatRobotomyForm(const std::string &target);
    static AForm* createPardonForm(const std::string &target);
public:
    class FormNotFoundException : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };
    Intern();
    Intern(const Intern &other);
    Intern& operator=(const Intern &ohter);
    ~Intern();
    AForm* makeForm(const std::string &formName, const std::string &target);


};



#endif