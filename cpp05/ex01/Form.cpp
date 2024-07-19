#include "Form.hpp"

Form::Form() : name("default"), sign_grade(150), exec_grade(150) {
    this->sign = false;
}

Form::Form(Form const& copy) : name(copy.name), sign_grade(copy.sign_grade), exec_grade(copy.exec_grade)  {
    this->sign = copy.sign;
}

Form::Form(const std::string &name1, const int signgrade, const int execgrade) : name(name1), sign_grade(signgrade), exec_grade(execgrade) {
    if (this->sign_grade > 150 || this->exec_grade > 150)
        throw Form::GradeTooLowException();
    if (this->sign_grade < 1 || this->exec_grade < 1)
        throw Form::GradeTooHighException();
}

Form::~Form() {}

Form &Form::operator=(const Form &assign) {
    this->sign = assign.sign;
    return (*this);
}

std::string Form::getName() const {
    return (this->name);
}

bool Form::getSign() const {
    return (this->sign);
}

int Form::getSignGrade() const {
    return (this->sign_grade);
}

int Form::getEcexGrade() const {
    return (this->exec_grade);
}

void Form::beSigned(const Bureaucrat &bur) {
    if (bur.getGrade() <= this->sign_grade) {
        // bur.getGrade();
        this->sign = true;
    } else
        throw Form::CouldntSign();
}

std::ostream &operator<<(std::ostream &out, const Form &obj) {
    out << "name : " << obj.getName() << ", sign : " << obj.getSign() << ", sign_grade " << obj.getSignGrade() << ", exec_grade " << obj.getEcexGrade() << std::endl;
    return (out);
}
