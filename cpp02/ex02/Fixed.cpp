#include "Fixed.hpp"

Fixed::Fixed()
{
    value = 0;
}

Fixed::Fixed(int const fnumber)
{
    setRawBits(fnumber << fractional);
}

Fixed::Fixed(float const fnumber)
{
    setRawBits((int)roundf(fnumber * 256));
}

Fixed::Fixed(const Fixed &copy)
{
    *this = copy;
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits() const
{
    return (value);
}

void    Fixed::setRawBits(int const raw)
{
    value = raw;
}

float Fixed::toFloat(void) const
{
    return (((float)getRawBits() / 256));
}

int Fixed::toInt(void) const
{
    return (getRawBits() / 256);
}

std::ostream & operator<<(std::ostream & os, const Fixed & obj)
{
    os << ((float)obj.getRawBits() / 256);
    return (os);
}

// copy assignment operator
Fixed &Fixed::operator=(const Fixed &assign)
{
    setRawBits(assign.getRawBits());
    return (*this);
}

// The 6 comparison operators
bool Fixed::operator>(const Fixed &obj) const
{
    return (getRawBits() > obj.getRawBits());
}

bool Fixed::operator<(const Fixed &obj) const
{
    return (getRawBits() < obj.getRawBits());
}

bool Fixed::operator>=(const Fixed &obj) const
{
    return (getRawBits() >= obj.getRawBits());
}

bool Fixed::operator<=(const Fixed &obj) const
{
    return (getRawBits() <= obj.getRawBits());
}

bool Fixed::operator==(const Fixed &obj) const
{
    return (getRawBits() == obj.getRawBits());
}

bool Fixed::operator!=(const Fixed &obj) const
{
    return (getRawBits() != obj.getRawBits());
}

// The 4 arithmetic operators
Fixed Fixed::operator+(const Fixed & obj) const
{
    Fixed   temp;

    temp.setRawBits(getRawBits() + obj.getRawBits());
    return (temp);
}

Fixed Fixed::operator-(const Fixed &obj) const
{
    Fixed   temp;

    temp.setRawBits(getRawBits() - obj.getRawBits());
    return (temp);
}

Fixed Fixed::operator*(const Fixed &obj) const
{
    Fixed   temp;

    temp.setRawBits((getRawBits() * obj.getRawBits()) >> fractional);
    return (temp);
}

Fixed Fixed::operator/(const Fixed &obj) const
{
    Fixed   temp;

    temp.setRawBits(((getRawBits() << 8) / obj.getRawBits()));
    return (temp);
}

// The 4 increment/decrement
Fixed &Fixed::operator++(void)
{
    setRawBits(value + 1);
    return (*this);
}

Fixed &Fixed::operator--(void)
{
     setRawBits(value - 1);
    return (*this);
}

Fixed   Fixed::operator++(int)
{
    Fixed   temp(*this);

    setRawBits(value + 1);
    return (temp);
}

Fixed Fixed::operator--(int)
{
    Fixed   temp(*this);

    setRawBits(value - 1);
    return (temp);
}

//
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a.getRawBits() < b.getRawBits())
        return (a);
    return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a.getRawBits() > b.getRawBits())
        return (a);
    return (b);
}

Fixed const &Fixed::min(Fixed const& a, Fixed const& b)
{
    if (a.getRawBits() < b.getRawBits())
        return (a);
    return (b);
}

Fixed const &Fixed::max(Fixed const& a, Fixed const& b)
{
    if (a.getRawBits() > b.getRawBits())
        return (a);
    return (b);
}
