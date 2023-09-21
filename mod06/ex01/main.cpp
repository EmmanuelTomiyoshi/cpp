#include "Serialization.hpp"

int main(void)
{
	t_Data			*data = new t_Data;
	uintptr_t		serialize;
	t_Data			*deserialize;

	data->number = 1;
	data->number_float = 34.f;
	data->number_double = 28.45;

	serialize = Serialization::serialize(data);
	deserialize = Serialization::deserialize(serialize);

	std::cout << "numbers before serialization: " << data->number << " | " << data->number_float
	<< " | " << data->number_double << std::endl;

	std::cout << "serialize address: " << serialize << std::endl; 
	std::cout << "deserialize address: " << deserialize << std::endl;
	std::cout << "numbers after deserialization: " << deserialize->number << " | " << deserialize->number_float
	<< " | " << deserialize->number_double << std::endl;

	delete data;
}
