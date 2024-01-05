#ifndef BIT
#define BIT
#include <stack>
#include <iostream>
#include <sstream>

class RPN {
    private:
        std::stack<int> stk;
        std::stringstream exp;
    public:
                RPN();
                RPN(std::string str);
                RPN(RPN const &copy);
        RPN     &operator=(RPN const & assign);
                ~RPN();
        void    ft_calcul();
};

#endif