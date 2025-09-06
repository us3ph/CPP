#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"


class Intern
{
private:
    std::string formNames[3];
    AForm* (*formCreators[3])(const std::string& target);
    static AForm* createShrubberyForm(const std::string &target);
    static AForm* creatRobotomyForm(const std::string &target);
    static AForm* createPardonForm(const std::string &target);
public:
    Intern();
    Intern(const Intern &other);
    Intern& operator=(const Intern &ohter);
    ~Intern();
    AForm* makeForm(const std::string &formName, const std::string &target);


};



#endif