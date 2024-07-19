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
		int                     getRawBits(void) const;
		void                    setRawBits(int const raw);
		float                   toFloat( void ) const;
		int                     toInt( void ) const;
		//
		static Fixed&					min(Fixed& a, Fixed& b);
		static Fixed const&			min(Fixed const& a, Fixed const& b);
		static Fixed&					max(Fixed& a, Fixed& b);
		static Fixed const&			max(Fixed const& a, Fixed const& b);
		// copy assignment operator
		Fixed&                  operator=(const Fixed& assign);
		// The 6 comparison operators
		bool                    operator>(const Fixed& obj) const;
		bool                    operator<(const Fixed& obj) const;
		bool                    operator>=(const Fixed& obj) const;
		bool                    operator<=(const Fixed& obj) const;
		bool                    operator==(const Fixed& obj) const;
		bool                    operator!=(const Fixed& obj) const;
		// The 4 arithmetic operators
		Fixed					operator+(const Fixed& obj) const;
		Fixed					operator-(const Fixed& obj) const;
		Fixed					operator*(const Fixed& obj) const;
		Fixed					operator/(const Fixed& obj) const;
		// The 4 increment/decrement
		Fixed&					operator++(void); //pre-inc ++obj
		Fixed&					operator--(void); //pre-dec --obj
		Fixed					operator++(int); //post-dec obj++
		Fixed					operator--(int); //post-dec obj--
};
		std::ostream&    operator<<(std::ostream& os, const Fixed& obj);

#endif
