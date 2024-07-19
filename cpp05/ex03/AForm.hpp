#ifndef FOR_HPP
#define FOR_HPP
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm {
    private:
        const std::string   name;
        bool                sign;
        const int           sign_grade;
        const int           exec_grade;
    public:
                        AForm();
                        AForm(const AForm& copy);
                        AForm(const std::string& name, const int signgrade, const int execgrade);
        virtual         ~AForm(); // add virtual
        AForm&          operator=(const AForm& assign);
        std::string     getName() const;
        bool            getSign() const;
        int             getSignGrade() const;
        int             getEcexGrade() const;
        void            beSigned(const Bureaucrat& bur);
        virtual void    execute(Bureaucrat const & executor) const = 0;
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
        /* ---------------- Exception Class 4 ---------------- */
        class CouldntExecute : public std::exception {
            public:
                const char* what() const throw() {
                    return "the grade of the bureaucrat attempting to execute the form is not high enough";
                }
        };
};
        std::ostream&   operator<<(std::ostream& out, const AForm& obj);

#endif
