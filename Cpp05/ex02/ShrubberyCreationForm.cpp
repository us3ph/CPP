#include "ShrubberyCreationForm.hpp"
#include "fstream"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Default", 145, 137)
{
  if(_gradeTosign < 145 || _gradeToexcute < 137)
    throw GradeTooHighException();
  if(_gradeTosign > 137 || _gradeToexcute > 137)
    throw GradeTooLowException();
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("Shrubbery creation", 145, 137), _target(target)
{
  if(_gradeTosign < 145 || _gradeToexcute < 137)
    throw GradeTooHighException();
  if(_gradeTosign > 137 || _gradeToexcute > 137)
    throw GradeTooLowException();
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
  if(this != &other)
    AForm::operator=(other);
  return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
  std::ofstream oufile(_target + "_shrubbery"); // output file with output file stream
  if(!oufile)
  {
    std::cerr << "Error: cannot creat output file" << std::endl;
    return;
    /// check if i have to creat exception for this error creat outfile ///////

  std::ifstream oufile
    // oufile.close();
  }
}
