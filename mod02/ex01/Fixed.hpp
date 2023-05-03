#ifndef EX00_FIXED_HPP
#define EX00_FIXED_HPP

#include <iostream>

class Fixed {
	
	public:
		Fixed( void );						//default constructor
		Fixed(const Fixed &copy);			//copy constructor
		Fixed&operator=(const Fixed &t);	//copy assignment operator
		~Fixed( void );						//desctructor

		int getRawBits( void ) const;		//raw value of the fixed-point value
		void setRawBits( int const raw );	//sets the raw value to the fp nbr
	private:
		int 				_fixedPoint;
		static const int	_numFractionalBits;
};

#endif // EX00_FIXED_HPP