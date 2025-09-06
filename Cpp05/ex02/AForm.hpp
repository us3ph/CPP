#ifndef AFORM_HPP
#define AFORM_HPP

#include "iostream"

class Bureaucrat;
class AForm
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
    class FormNotSignedException : public std::exception
    {
        public:
            virtual const char*  what() const throw();
    };
    virtual void execute(const Bureaucrat& executor) const = 0; // pure virual func
    AForm();
    AForm(const std::string &name, int gradeTosign, int gradeToexcute);
    AForm(const AForm &other);
    AForm& operator=(const AForm &other);
    virtual ~AForm();
    std::string const& getName() const;
    void beSigned(Bureaucrat& bureaucrat);
    int getGradeTosign() const;
    int getGradeToexcute() const;
    bool getSigned() const;
};

std::ostream& operator<<(std::ostream& out, const AForm &form);


#endif
