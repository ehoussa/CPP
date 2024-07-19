#ifndef PRE_HPP
#define PRE_HPP
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm {
    private:
        std::string target;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string& tar);
        PresidentialPardonForm(const PresidentialPardonForm& copy);
        PresidentialPardonForm&  operator=(const PresidentialPardonForm& assign);
        ~PresidentialPardonForm();
        void    execute(Bureaucrat const & executor) const;
};

#endif
