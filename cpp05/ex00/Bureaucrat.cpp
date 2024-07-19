#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default") {
    this->grade = 150;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : name(copy.name) {
    this->grade = copy.grade;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name) {
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade = grade;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &assing) {
    this->grade = assing.grade;
    return (*this);
}

std::string Bureaucrat::getName() const {
    return std::string(this->name);
}

int Bureaucrat::getGrade() const {
    return (this->grade);
}

void Bureaucrat::incrementGrade() {
    if (this->grade == 1)
        throw Bureaucrat::GradeTooHighException();
    this->grade--;
}

void Bureaucrat::decrementGrade() {
    if (this->grade == 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade++;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj) {
    out << obj.getName() << ", bureaucrat grade " << obj.getGrade() << "." << std::endl;
    return (out);
}
