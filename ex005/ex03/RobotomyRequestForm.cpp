#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Form", 72, 45) {
    this->target = "default";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &tar) : AForm("Form", 72, 45) {
    this->target = tar;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy) {
    this->target = copy.target;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    if (executor.getGrade() <= AForm::getEcexGrade() && this->getSign()) {
        std::cout << "Loud drill noises" << std::endl;
        static int  i = 0;
        if (i % 2 == 0)
            std::cout << this->target << " has been robotomized successfully" << std::endl;
        else
            std::cout << this->target << " has been robotomized failed" << std::endl;
        i++;
    } else if (!this->getSign())
        std::cout << "RobotomyRequestForm couldn't be executed by " << executor.getName() << " because it wasn't signed" << std::endl;
    else
        throw AForm::CouldntExecute();
}
