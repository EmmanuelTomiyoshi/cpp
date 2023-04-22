#include <iostream>
#include <fstream>
#include <iterator>
#include <filesystem>
#include <sys/cdefs.h>

int main(int argc, char **argv)
{
	//check invalid number of args
	if (argc != 4)
		return (std::cerr << "invalid number of arguments" << std::endl, 1);
	
	std::ifstream file (argv[1]);
	std::ofstream output_file (std::string (std::string (argv[1]) + ".replace").c_str(), std::ios_base::trunc);

	//check file manipulation
	if (!file.is_open())
		return (std::cerr << "Unable to open file. Make sure the input file exists or have the right permissions" << std::endl, 1);
	else if (!output_file.is_open())
		return (std::cerr << "Unable to create file, try again" << std::endl, 1);

	//check if file is empty
	if (bool __attribute__((unused)) isEmpty = file.peek() == EOF)
		return (std::cerr << "File is empty" << std::endl, 1);

	std::string line;
	std::string original = argv[2];
	std::string toreplace = argv[3];
	size_t		original_size;
	bool		last_line = false;

	original_size = original.size();

	while (!file.eof())
	{
		std::getline(file, line);
		size_t found = line.find(original);
		if (found != std::string::npos)
		{
			line.erase(found, original_size);
			line.insert(found, toreplace);
		}
		if (file.eof())
		{
			last_line = true;
		}
		output_file << line;
		if (!last_line)
		{
			output_file << std::endl;	//append the endl only if last_line is false
		}
	}
	file.close();
}