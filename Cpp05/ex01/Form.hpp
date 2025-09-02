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
    Form();
    Form(); // param 
    Form(const Form &other);
    Form& operator=(const Form &other);
    ~Form();
    std::string const& getName() const;
    void getSign() const;
    void getGradeTosign() const;
    void getGradeToexcute() const;
};


#endif