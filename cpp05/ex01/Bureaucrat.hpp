#ifndef BUR_HPP
#define BUR_HPP
#include <iostream>
#include "Form.hpp"
class Form;

class Bureaucrat {
    private:
        const std::string name; // add const
        int         grade;
    public:
                        Bureaucrat();
                        Bureaucrat(const Bureaucrat& copy);
                        Bureaucrat(const std::string& name, int grade);
                        ~Bureaucrat();
        Bureaucrat&     operator=(const Bureaucrat& assing);
        std::string     getName() const;
        int             getGrade() const;
        void            incrementGrade();
        void            decrementGrade();
        void            signForm(Form& form);
        /* ---------------- Exception Class 1 ---------------- */
        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw() {
                    return "Grade too high";
                }
        };
        /* ---------------- Exception Class 2 ---------------- */
        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw() {
                    return "Grade too low";
                }
        };
};
        std::ostream&   operator<<(std::ostream& out, const Bureaucrat& obj);

#endif