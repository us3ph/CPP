#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    
    // Create bureaucrats with different grades
    Bureaucrat president("President", 1);
    Bureaucrat manager("Manager", 50);
    Bureaucrat intern("Intern", 150);
    
    std::cout << "=== BUREAUCRATS ===" << std::endl;
    std::cout << president << std::endl;
    std::cout << manager << std::endl;
    std::cout << intern << std::endl;
    ////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "\n>>>>>>>> TESTING SHRUBBERY FORM (sign: 145, exec: 137) <<<<<<<<<<" << std::endl;
    try {
        ShrubberyCreationForm shrub("garden");
        std::cout << shrub << std::endl;
        
        std::cout << "\n--- Manager signing and executing ---" << std::endl;
        manager.signForm(shrub);
        manager.executeForm(shrub);
        
        //////////// Test intern failure ///////////

        ShrubberyCreationForm shrub2("home");
        intern.signForm(shrub2);  // Should fail (150 > 145)
        
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    /////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "\n>>>>>>>> TESTING ROBOTOMY FORM (sign: 72, exec: 45) <<<<<<<<<<" << std::endl;
    try {
        RobotomyRequestForm robot("Alice");
        std::cout << robot << std::endl;
        
        // Manager can sign (50 < 72) but cannot execute (50 > 45)
        std::cout << "\n--- Manager signing robotomy form ---" << std::endl;
        manager.signForm(robot);
        manager.executeForm(robot);
        
        // President can execute
        std::cout << "\n--- President executing robotomy ---" << std::endl;
        president.executeForm(robot);   // to see randomness
        president.executeForm(robot);
        president.executeForm(robot);
        president.executeForm(robot);
        
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    //////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "\n>>>>>>>>>>>> TESTING PRESIDENTIAL PARDON (sign: 25, exec: 5) <<<<<<<<<<<<<" << std::endl;
    try {
        PresidentialPardonForm pardon("Bob");
        std::cout << pardon << std::endl;
        
        // Only president can sign and execute this form
        std::cout << "\n--- Manager trying to sign (should fail) ---" << std::endl;
        manager.signForm(pardon);  // Should fail (50 > 25)
        
        std::cout << "\n--- President signing and executing ---" << std::endl;
        president.signForm(pardon);
        president.executeForm(pardon);
        
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    //////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "\n>>>>>>>>> TESTING UNSIGNED FORM EXECUTION  <<<<<<<<" << std::endl;
    
    ShrubberyCreationForm unsignedForm("test");
    std::cout << "\n--- Trying to execute unsigned form ---" << std::endl;
    president.executeForm(unsignedForm);  // Should fail - not signed
        
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    std::cout << "\n>>>>>>>>>> TESTING POLYMORPHISM <<<<<<<<" << std::endl;
    try {
        // Array of different forms using base class pointers
        AForm* forms[3];
        forms[0] = new ShrubberyCreationForm("poly_test");
        forms[1] = new RobotomyRequestForm("poly_target");
        forms[2] = new PresidentialPardonForm("poly_criminal");
        
        // President signs and executes all forms
        for (int i = 0; i < 3; i++) {
            std::cout << "\n--- Form " << (i+1) << " ---" << std::endl;
            std::cout << *forms[i] << std::endl;
            president.signForm(*forms[i]);
            president.executeForm(*forms[i]);
        }
        
        for (int i = 0; i < 3; i++) {
            delete forms[i];
        }
        
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    /////////////////////////////////////////////////////////////////////////////////////////////////////
    return 0;
}