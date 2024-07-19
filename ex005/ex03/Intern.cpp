#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &src) {
    (void)src;
}

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &intern) {
    (void)intern;
    return (*this);
}

AForm *Intern::makeForm(std::string name, std::string target) {
    std::string formName[] = {
        "RobotomyRequestForm",
        "PresidentialPardonForm",
        "ShrubberyCreationForm",
    };
    int i;
    for (i = 0; i < 3; i++)
        if (formName[i] == name)
            break;
    switch (i) {
        case 0:
            std::cout << "Intern creates " << name << std::endl;
            return (new RobotomyRequestForm(target));
        case 1:
            std::cout << "Intern creates " << name << std::endl;
            return (new PresidentialPardonForm(target));
        case 2:
            std::cout << "Intern creates " << name << std::endl;
            return (new ShrubberyCreationForm(target));
    }
    std::cout << "Intern couldn't create " << name << " form" << std::endl;
    return (NULL);
}
