#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Form", 145, 137) {
    this->target = "default";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &tar) : AForm("Form", 145, 137) {
    this->target = tar;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy) {
    this->target = copy.target;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &assign) {
    AForm::operator=(assign);
    
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    std::ofstream   out;
    std::string     name;

    name = this->target + "_shrubbery";
    if (executor.getGrade() <= AForm::getEcexGrade() && this->getSign()) {
        out.open(name.c_str());
        out << "    oxoxoo    ooxoo" << std::endl;
        out << "  ooxoxo oo  oxoxooo" << std::endl;
        out << " oooo xxoxoo ooo ooox" << std::endl;
        out << " oxo o oxoxo  xoxxoxo" << std::endl;
        out << "  oxo xooxoooo o ooo" << std::endl;
        out << "    oooooo\\  /o/o" << std::endl;
        out << "        \\  \\/ /" << std::endl;
        out << "         |   /" << std::endl;
        out << "         |  |" << std::endl;
        out << "         | D|" << std::endl;
        out << "         |  |" << std::endl;
        out << "         |  |" << std::endl;
        out << "  ______/____\\____" << std::endl;
        out.close();
    } else
        throw AForm::CouldntExecute();
}
