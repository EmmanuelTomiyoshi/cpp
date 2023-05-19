#ifndef EX00_FIXED_HPP
#define EX00_FIXED_HPP

#include <iostream>

class Fixed {
	
	public:
		Fixed( void );						//default constructor
		Fixed(const Fixed &copy);			//copy constructor
		Fixed&operator=(const Fixed &copy);	//copy assignment operator
		~Fixed( void );						//desctructor

		int getRawBits( void ) const;
		void setRawBits( int const raw );
	private:
		int 				_fixedPoint;
		static const int	_numFractionalBits;
};

#endif // EX00_FIXED_HPP