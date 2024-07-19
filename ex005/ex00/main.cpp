#include "Bureaucrat.hpp"

int main(void)
{
    try {
        Bureaucrat bureaucrat("bure", 1);

        std::cout << bureaucrat << std::endl;

        // bureaucrat.incrementGrade();
        while (true) {
            bureaucrat.decrementGrade();
        }
        std::cout << bureaucrat << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}