#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <math.h>

class Fixed
{
    private:
        int value;
        static const int    fractional = 8;
    public:
        Fixed();
        Fixed(int const fnumber);
        Fixed(float const fnumber);
        Fixed(const Fixed& copy);
        ~Fixed();
        Fixed&                  operator=(const Fixed& assign);
        int                     getRawBits(void) const;
        void                    setRawBits(int const raw);
        float                   toFloat( void ) const;
        int                     toInt( void ) const;
        friend std::ostream&    operator<<(std::ostream& os, const Fixed& obj);
};

#endif
