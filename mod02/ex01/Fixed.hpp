#ifndef EX01_FIXED_HPP
#define EX01_FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	
	public:
		Fixed( void );						//constructor
		Fixed(const Fixed &copy);			//copy constructor
		Fixed&operator=(const Fixed &t);	//copy assignment operator
		~Fixed( void );						//destructor

		Fixed(const int integer);
		Fixed(const float floating_point);

		float toFloat ( void ) const;
		int toInt( void ) const;

		int getRawBits( void ) const;
		void setRawBits( int const raw );

		std::ostream&operator<<(std::ostream& os);
		/*we could use friend here, but it is prohibited
		/friend std::ostream&operator<<(std::ostream& os, const Fixed &obj);*/

	private:
		int 				_fixedPoint;
		static const int	_numFractionalBits;
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif // EX01_FIXED_HPP