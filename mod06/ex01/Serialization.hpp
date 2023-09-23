#ifndef EX01_Serialization_HPP
#define EX01_Serialization_HPP

#include <iostream>
#include <string>
#include <stdint.h>

#include "colors.hpp"

typedef struct Data
{
	int		number;
	float	number_float;
	double	number_double;
}	t_Data;

class Serialization {

	public:
		static uintptr_t	serialize(Data *ptr);
		static Data 		*deserialize(uintptr_t raw);

	private:
};

#endif // EX01_Serialization_HPP