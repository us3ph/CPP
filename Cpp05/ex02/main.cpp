#include "AForm.hpp"
#include "iostream"

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    std::cout << "=== CREATING FORMS ===" << std::endl;
    
    try {
        // Create different types of forms
        ShrubberyCreationForm shrub("garden");
        RobotomyRequestForm robot("Alice");
        PresidentialPardonForm pardon("Bob");
        
        std::cout << "✓ " << shrub << std::endl;
        std::cout << "✓ " << robot << std::endl;
        std::cout << "✓ " << pardon << std::endl;
        
    } catch (const std::exception& e) {
        std::cout << "✗ Error creating forms: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== CREATING BUREAUCRATS ===" << std::endl;
    
    try {
        Bureaucrat president("President", 1);      // Can do everything
        Bureaucrat manager("Manager", 50);         // Mid-level
        Bureaucrat intern("Intern", 150);          // Lowest level
        
        std::cout << "✓ " << president << std::endl;
        std::cout << "✓ " << manager << std::endl;
        std::cout << "✓ " << intern << std::endl;
        
    } catch (const std::exception& e) {
        std::cout << "✗ Error creating bureaucrats: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== TESTING SHRUBBERY CREATION FORM ===" << std::endl;
    std::cout << "Required: Sign 145, Execute 137" << std::endl;
    
    try {
        ShrubberyCreationForm shrubForm("backyard");
        Bureaucrat gardener("Gardener", 140);      // Can sign and execute
        Bureaucrat newbie("Newbie", 148);          // Cannot sign
        
        std::cout << "\nInitial form: " << shrubForm << std::endl;
        
        // Test signing
        std::cout << "\n--- Gardener trying to sign ---" << std::endl;
        gardener.signForm(shrubForm);
        std::cout << "After signing: " << shrubForm << std::endl;
        
        // Test execution
        std::cout << "\n--- Gardener trying to execute ---" << std::endl;
        gardener.executeForm(shrubForm);
        
        // Test with insufficient grade
        std::cout << "\n--- Newbie trying to sign new form ---" << std::endl;
        ShrubberyCreationForm shrubForm2("frontyard");
        newbie.signForm(shrubForm2);
        
    } catch (const std::exception& e) {
        std::cout << "Unexpected error: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== TESTING ROBOTOMY REQUEST FORM ===" << std::endl;
    std::cout << "Required: Sign 72, Execute 45" << std::endl;
    
    try {
        RobotomyRequestForm robotForm("Charlie");
        Bureaucrat doctor("Doctor", 40);           // Can sign and execute
        Bureaucrat nurse("Nurse", 80);             // Cannot sign
        
        std::cout << "\nInitial form: " << robotForm << std::endl;
        
        // Test signing and execution
        std::cout << "\n--- Doctor trying to sign and execute ---" << std::endl;
        doctor.signForm(robotForm);
        std::cout << "After signing: " << robotForm << std::endl;
        doctor.executeForm(robotForm);
        
        // Test multiple executions (to see 50% randomness)
        std::cout << "\n--- Multiple execution attempts ---" << std::endl;
        for (int i = 0; i < 5; i++) {
            doctor.executeForm(robotForm);
        }
        
        // Test insufficient grade
        std::cout << "\n--- Nurse trying to sign new form ---" << std::endl;
        RobotomyRequestForm robotForm2("David");
        nurse.signForm(robotForm2);
        
    } catch (const std::exception& e) {
        std::cout << "Unexpected error: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== TESTING PRESIDENTIAL PARDON FORM ===" << std::endl;
    std::cout << "Required: Sign 25, Execute 5" << std::endl;
    
    try {
        PresidentialPardonForm pardonForm("Eve");
        Bureaucrat president("President", 1);      // Can do everything
        Bureaucrat vicePresident("VP", 10);        // Can execute but not sign
        Bureaucrat senator("Senator", 30);         // Cannot sign or execute
        
        std::cout << "\nInitial form: " << pardonForm << std::endl;
        
        // Test with president (should work)
        std::cout << "\n--- President trying to sign and execute ---" << std::endl;
        president.signForm(pardonForm);
        std::cout << "After signing: " << pardonForm << std::endl;
        president.executeForm(pardonForm);
        
        // Test with insufficient grades
        std::cout << "\n--- Senator trying to sign new form ---" << std::endl;
        PresidentialPardonForm pardonForm2("Frank");
        senator.signForm(pardonForm2);
        
        // Test execution without signing
        std::cout << "\n--- VP trying to execute unsigned form ---" << std::endl;
        PresidentialPardonForm pardonForm3("Grace");
        vicePresident.executeForm(pardonForm3);
        
    } catch (const std::exception& e) {
        std::cout << "Unexpected error: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== TESTING DIRECT EXECUTE CALLS ===" << std::endl;
    
    try {
        ShrubberyCreationForm testForm("test");
        Bureaucrat worker("Worker", 100);
        
        std::cout << "\n--- Trying to execute unsigned form directly ---" << std::endl;
        testForm.execute(worker);  // Should throw FormNotSignedException
        
    } catch (const std::exception& e) {
        std::cout << "✓ Correctly caught: " << e.what() << std::endl;
    }
    
    try {
        ShrubberyCreationForm testForm2("test2");
        Bureaucrat weakWorker("WeakWorker", 140);
        
        // Sign the form first
        Bureaucrat strongWorker("StrongWorker", 100);
        strongWorker.signForm(testForm2);
        
        std::cout << "\n--- Trying to execute with insufficient grade ---" << std::endl;
        testForm2.execute(weakWorker);  // Should throw GradeTooLowException
        
    } catch (const std::exception& e) {
        std::cout << "✓ Correctly caught: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== TESTING POLYMORPHISM ===" << std::endl;
    
    try {
        // Using base class pointers
        AForm* forms[] = {
            new ShrubberyCreationForm("poly_garden"),
            new RobotomyRequestForm("poly_target"),
            new PresidentialPardonForm("poly_criminal")
        };
        
        Bureaucrat admin("Admin", 1);
        
        for (int i = 0; i < 3; i++) {
            std::cout << "\n--- Testing form " << (i+1) << " ---" << std::endl;
            std::cout << *forms[i] << std::endl;
            admin.signForm(*forms[i]);
            admin.executeForm(*forms[i]);
            delete forms[i];
        }
        
    } catch (const std::exception& e) {
        std::cout << "Error in polymorphism test: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== ALL TESTS COMPLETED ===" << std::endl;
    std::cout << "Check for 'backyard_shrubbery' file in working directory!" << std::endl;
    
    return 0;
}

