#ifndef EX00_SCALARCONVERTER_HPP
#define EX00_SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <stdlib.h>
#include <limits>
#include "colors.hpp"

#define SHOW_DEFAULT_MESSAGES 1

typedef enum e_scalarTypes
{
	UNKNOWN,
	CHAR,
	INT,
	FLOAT,
	DOUBLE
} t_scalarTypes;

class ScalarConverter {

	public:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &copy);
		ScalarConverter&operator=(const ScalarConverter &copy);
		~ScalarConverter(void);

		void convert(const std::string &type);

		void toChar(const std::string &type);
		void toInt(const std::string &type);
		void toFloat(const std::string &type);
		void toDouble(const std::string &type);

		void displayChar(void) const;
		void displayInt(void) const;
		void displayFloat(void) const;
		void displayDouble(void) const;

		std::ostream&operator<<(std::ostream &os);

	private:
		char	_typeChar;
		int		_typeInt;
		float	_typeFloat;
		double	_typeDouble;

};

std::ostream &operator<<(std::ostream& os, const ScalarConverter& scalarConverter);
t_scalarTypes parse(const std::string &type);

#endif // EX00_SCALARCONVERTER_HPP