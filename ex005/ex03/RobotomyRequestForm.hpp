#ifndef ROB_HPP
#define ROB_HPP
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm {
    private:
        std::string target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string& tar);
        RobotomyRequestForm(const RobotomyRequestForm& copy);
        RobotomyRequestForm&  operator=(const RobotomyRequestForm& assign);
        ~RobotomyRequestForm();
        void    execute(Bureaucrat const & executor) const;
};

#endif
