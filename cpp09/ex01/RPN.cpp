#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(std::string str) {
    this->exp.str(str);
}

RPN::RPN(RPN const &copy)
{
    (void)copy;
}

RPN &RPN::operator=(RPN const &assign)
{
    (void)assign;
    return (*this);
}

RPN::~RPN()
{
}

void RPN::ft_calcul() {
    int     n1, n2;
    char    c;
    while (exp >> c) {
        if (std::string("+-*/0123456789").find(c) == std::string::npos)
            throw("Error");
        if (std::string("0123456789").find(c) != std::string::npos)
            this->stk.push(int(c) - 48);
        else {
            if (this->stk.size() < 2)
               throw("Error");
            n1 = this->stk.top();
            this->stk.pop();
            n2 = this->stk.top();
            this->stk.pop();
            if (c == '+')
                this->stk.push(n1 + n2);
            else if (c == '-')
                this->stk.push(n2 - n1);
            else if (c == '/')
                this->stk.push(n2 / n1);
            else
                this->stk.push(n2 * n1);
        }
    }
    if (this->stk.size() != 1)
        throw("Error");
    std::cout << this->stk.top() << std::endl;
}
