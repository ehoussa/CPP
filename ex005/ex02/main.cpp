#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    try {
        Bureaucrat  bureaucrat("br1", 1);
        RobotomyRequestForm ro("home"); 
        ShrubberyCreationForm sh("home2"); 
        PresidentialPardonForm pr("home3"); 

        bureaucrat.signForm(ro);
        bureaucrat.signForm(sh);
        bureaucrat.signForm(pr);
        while (true) {
            bureaucrat.decrementGrade();
            bureaucrat.executeForm(ro);
        }
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}