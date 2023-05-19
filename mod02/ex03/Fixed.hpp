#ifndef EX02_FIXED_HPP
#define EX02_FIXED_HPP

#include <iostream>
#include <cmath>
#include <limits.h>

class Fixed {
	
	public:
		Fixed(void);						//constructor
		Fixed(const Fixed &copy);			//copy constructor
		Fixed&operator=(const Fixed &t);	//copy assignment operator
		~Fixed(void);						//destructor

		Fixed(const int integer);
		Fixed(const float floating_point);

		float toFloat (void) const;
		int toInt(void) const;

		int getRawBits(void) const;		//raw value of the fixed-point value
		void setRawBits(int const raw);	//sets the raw value to the fp nbr

		std::ostream&operator<<(std::ostream& os);
		
		//comparison operators
		bool operator<(const Fixed &lt) const;
		bool operator>(const Fixed &mt) const;
		bool operator>=(const Fixed &met) const;
		bool operator<=(const Fixed &let) const;
		bool operator==(const Fixed &eq) const;
		bool operator!=(const Fixed &diff) const;

		//arithmetic operators
		Fixed operator+(const Fixed &plus);
		Fixed operator-(const Fixed &minus);
		Fixed operator*(const Fixed &mult);
		Fixed operator/(const Fixed &div);

		//increment and decrement operators
		Fixed &operator++(void);
		Fixed operator++(int);
		Fixed &operator--(void);
		Fixed operator--(int);

		static Fixed &min(Fixed &fp1, Fixed &fp2);
		static const Fixed &min(Fixed const &fp1, Fixed const &fp2);
		static Fixed &max(Fixed &fp1, Fixed &fp2);
		static const Fixed &max(Fixed const &fp1, Fixed const &fp2);

	private:
		int 				_fixedPoint;
		static const int	_numFractionalBits;
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif // EX02 _FIXED_HPP