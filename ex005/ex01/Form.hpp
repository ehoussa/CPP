#ifndef FOR_HPP
#define FOR_HPP
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;
class Form {
    private:
        const std::string name;
        bool        sign;
        const int   sign_grade;
        const int   exec_grade;
    public:
                        Form();
                        Form(const Form& copy);
                        Form(const std::string& name, const int sign_grade, const int exec_grade);
                        ~Form();
        Form&           operator=(const Form& assign);
        std::string     getName() const;
        bool            getSign() const;
        int             getSignGrade() const;
        int             getEcexGrade() const;
        void            beSigned(const Bureaucrat& bur);
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
        /* ---------------- Exception Class 3 ---------------- */
        class CouldntSign : public std::exception {
            public:
                const char* what() const throw() {
                    return "the bureaucrat’s grade is not high enough";
                }
        };
};
        std::ostream&   operator<<(std::ostream& out, const Form& obj);

#endif