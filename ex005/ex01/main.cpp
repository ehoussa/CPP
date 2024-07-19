#include "Bureaucrat.hpp"

int main(void)
{
    try {
        Bureaucrat bureaucrat("br1", 1);
        Form        fr("fro", 15, 13);

        std::cout << bureaucrat << std::endl;

        while (true) {
            bureaucrat.decrementGrade();
            std::cout << bureaucrat << std::endl;
            std::cout << fr << std::endl;
            bureaucrat.signForm(fr);
        }
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}