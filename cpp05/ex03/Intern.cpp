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
            return (new RobotomyRequestForm(target));
        case 1:
            return (new PresidentialPardonForm(target));
        case 2:
            return (new ShrubberyCreationForm(target));
    }
    return (NULL);
}
