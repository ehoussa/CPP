#ifndef SHR_HPP
#define SHR_HPP
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm {
    private:
        std::string target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string& tar);
        ShrubberyCreationForm(const ShrubberyCreationForm& copy);
        ShrubberyCreationForm&  operator=(const ShrubberyCreationForm& assign);
        ~ShrubberyCreationForm();
        void    execute(Bureaucrat const & executor) const;
};

#endif
