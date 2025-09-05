#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
  const std::string _target;
  bool _signed;
  int _gradeTosign;
  int _gradeToexcute;
public:
  class CannotCreatOutputFileException : public std::exception
  {
    public:
        virtual const char* what() const throw();
  };
  ShrubberyCreationForm();
  ShrubberyCreationForm(const std::string &target);
  ShrubberyCreationForm(const ShrubberyCreationForm &other);
  ShrubberyCreationForm& operator=(const ShrubberyCreationForm &other);
  ~ShrubberyCreationForm();
  void execute(const Bureaucrat& executor) const;
  void creatShrubbery(const std::string &target) const;
};


#endif