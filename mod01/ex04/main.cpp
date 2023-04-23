#include <iostream>
#include <fstream>
#include <filesystem>

void replace(std::ifstream &file, std::ofstream &output, std::string original, std::string toreplace)
{
	if (original.length() == 0)
	{
		output << file.rdbuf();
		return;
	}

	std::string line;

	while (!file.eof())
	{
		std::getline(file, line);
		size_t pos = 0;
		while ((pos = line.find(original, pos)) != std::string::npos)
		{
			line.erase(pos, original.size());
			line.insert(pos, toreplace);
			pos += toreplace.size();
		}

		output << line;

		if (!file.eof())	//check if it is the last line of the file
		{
			output << std::endl;
		}
	}
}

int main(int argc, char **argv)
{
	//check invalid number of args
	if (argc != 4)
		return (std::cerr << "invalid number of arguments" << std::endl, 1);
	
	std::string filename = argv[1];
	std::string original = argv[2];
	std::string toreplace = argv[3];

	//check file streams
	std::ifstream file (filename.c_str());
	if (!file.is_open())
		return (std::cerr << "Unable to open file. Make sure the input file exists or have the right permissions" << std::endl, 1);

	std::ofstream output_file ((filename + ".replace").c_str(), std::ios_base::trunc);
	if (!output_file.is_open())
		return (std::cerr << "Unable to create file, try again" << std::endl, 1);

	//check if file is empty
	if (bool __attribute__((unused)) isEmpty = file.peek() == EOF)
		return (std::cerr << "File is empty" << std::endl, 1);

	replace(file, output_file, original, toreplace);
	file.close();
}