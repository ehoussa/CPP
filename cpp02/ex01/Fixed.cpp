#include "Fixed.hpp"

Fixed::Fixed()
{
    value = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const fnumber) //this
{
    std::cout << "Int constructor called" << std::endl;
    setRawBits(fnumber << 8);
}

Fixed::Fixed(float const fnumber) //this
{
    std::cout << "Float constructor called" << std::endl;
    setRawBits((int)roundf(fnumber * 256));
}

Fixed::Fixed(const Fixed &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
    //std::cout << "getRawBits member function called" << std::endl;
    return (value);
}

void    Fixed::setRawBits(int const raw)
{
    value = raw;
}

float Fixed::toFloat(void) const //this
{
    return (((float)getRawBits() / 256));
}

int Fixed::toInt(void) const //this
{
    return (getRawBits() / 256);
}

std::ostream & operator<<(std::ostream & os, const Fixed & obj)
{
    //os << obj.toFloat();
    os << ((float)obj.getRawBits() / 256);
    return (os);
}

Fixed &Fixed::operator=(const Fixed &assign)
{
    std::cout << "Copy assignment operator called" << std::endl;
    setRawBits(assign.getRawBits());
    return (*this);
}
