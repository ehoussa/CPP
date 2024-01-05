#include "RPN.hpp"

int main(int ac, char **av) {

    try
    {
        if (ac == 1)
            throw "error";

        std::string str(av[1]);
        RPN rpn(str);
        rpn.ft_calcul();
    }
    catch(const char * e)
    {
        std::cerr << e << '\n';
    }
    

    return (0);
}