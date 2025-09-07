#include "ShrubberyCreationForm.hpp"
#include "fstream"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Default", 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("Shrubbery", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), _target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
     if(this != &other)
          AForm::operator=(other);
     return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

const char* ShrubberyCreationForm::CannotCreatOutputFileException::what() const throw()
{
     return("Failed to create output file");
}

void ShrubberyCreationForm::creatShrubbery(const std::string &target) const
{
     std::ofstream oufile((target + "_shrubbery").c_str());
     if(!oufile)
          throw CannotCreatOutputFileException();
     oufile << "          &&& &&  & &&              \n";
     oufile << "       && &/|&|& ()|/ @,&&          \n";
     oufile << "       &//&||/& /_/)_&/_&()         \n";
     oufile << "     &() &//&|()|/&// '%)_&/_&&     \n";
     oufile << "   &_///_&&_// |& |&&/&__%_/_& &&   \n";
     oufile << "  &&   && & &| &| /& & % <>& /&&    \n";
     oufile << "   <>&_---<>&/&/|&&-&&--%---<>~     \n";
     oufile << "       &&      |||/                 \n";
     oufile << "               |||                  \n";
     oufile << "               |||                  \n";
     oufile << "               |||                  \n";
     oufile << "         , -=-~  .-^-._             \n";
     oufile.close();
  
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
     if(!getSigned())
          throw FormNotSignedException();
     if(executor.getGrade() > getGradeToexcute())
          throw GradeTooLowException();
     try
     {
          creatShrubbery(_target);
     }
     catch(const std::exception& e)
     {
          std::cerr << e.what() << '\n';
     }
}
