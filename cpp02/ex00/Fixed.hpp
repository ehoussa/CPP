#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed
{
    private:
        int value;
        static const int    number = 8;
    public:
        Fixed();
        Fixed(Fixed& copy);  
        ~Fixed();
        Fixed&  operator=(Fixed& assign);
        int     getRawBits(void); 
        void    setRawBits(int const raw);
};

#endif
