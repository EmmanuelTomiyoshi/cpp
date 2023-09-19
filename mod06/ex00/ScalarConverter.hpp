#ifndef EX00_SCALARCONVERTER_HPP
#define EX00_SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <sstream>
#include <limits.h>
#include <cfloat>
#include <cctype>
#include <cmath>
#include "colors.hpp"

#define SHOW_DEFAULT_MESSAGES 0

typedef struct s_convert
{
	char		_typeChar;
	int			_typeInt;
	float		_typeFloat;
	double		_typeDouble;


	long long	_tempNum;	//check extreme values (min and max)
} t_convert;

typedef enum e_scalarTypes
{
	UNKNOWN = 1,
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDO_FLOAT,
	PSEUDO_DOUBLE
} t_scalarTypes;

class ScalarConverter {

	public:
		static void	convert(std::string type);

	private:
		ScalarConverter(){};
};

t_scalarTypes parse(std::string type);
void toPseudos(const std::string type, t_convert &convert);
void toChar(const std::string type, t_convert &convert);
void toInt(const std::string type, t_convert &convert);
void toFloat(const std::string type, t_convert &convert);
void toDouble(const std::string type, t_convert &convert);
void displayTypes(t_convert &convert);

#endif // EX00_SCALARCONVERTER_HPP