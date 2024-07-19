#include "AForm.hpp"

AForm::AForm() : name("default"), sign_grade(150), exec_grade(150) {
    this->sign = false;
}

AForm::AForm(AForm const& copy) : name(copy.name), sign_grade(copy.sign_grade), exec_grade(copy.exec_grade)  {
    this->sign = copy.sign;
}

AForm::AForm(const std::string &name1, const int signgrade, const int execgrade) : name(name1), sign_grade(signgrade), exec_grade(execgrade) {
    if (this->sign_grade > 150 || this->exec_grade > 150)
        throw AForm::GradeTooLowException();
    if (this->sign_grade < 1 || this->exec_grade < 1)
        throw AForm::GradeTooHighException();
    this->sign = false;
}

AForm::~AForm() {}

AForm &AForm::operator=(const AForm &assign) {
    this->sign = assign.sign;
    return (*this);
}

std::string AForm::getName() const {
    return (this->name);
}

bool AForm::getSign() const {
    return (this->sign);
}

int AForm::getSignGrade() const {
    return (this->sign_grade);
}

int AForm::getEcexGrade() const {
    return (this->exec_grade);
}

void AForm::beSigned(const Bureaucrat &bur) {
    if (bur.getGrade() <= this->sign_grade) {
        this->sign = true;
    } else
        throw AForm::CouldntSign();
}

std::ostream &operator<<(std::ostream &out, const AForm &obj) {
    out << "name : " << obj.getName() << ", sign : " << obj.getSign() << ", sign_grade " << obj.getSignGrade() << ", exec_grade " << obj.getEcexGrade() << std::endl;
    return (out);
}
