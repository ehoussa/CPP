#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
    try {
        AForm*  ptr;
        // AForm*  ptr2;
        Bureaucrat  bureaucrat("br1", 1);
        Intern  frmake;

        // ptr = frmake.makeForm("RobotomyRequestForm", "A");
        // ptr->beSigned(bureaucrat);
        // ptr = frmake.makeForm("PresidentialPardonForm", "B");
        // ptr->beSigned(bureaucrat);
        ptr = frmake.makeForm("ShrubberyCreationForm", "C");
        if (ptr){
            bureaucrat.signForm(*ptr);
            bureaucrat.executeForm(*ptr);
            delete ptr;
        }

    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}