#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Form", 25, 5) {
    this->target = "default";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &tar) : AForm("Form", 25, 5) {
    this->target = tar;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy) {
    this->target = copy.target;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
    if (executor.getGrade() <= AForm::getEcexGrade() && this->getSign()) {
        std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
    } else
        throw AForm::CouldntExecute();
}