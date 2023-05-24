#include "AAnimal.hpp"

std::string *readAnimalNames(const std::string &name, const unsigned int count)
{
    std::ifstream file(name.c_str());
    std::string line;
    unsigned int linesRead = 0; //count lines
    unsigned int namesIndex = 0; //access names array

    if (!file.is_open() || file.bad() || file.fail())
    { 
        std::cerr << "Error: failed to open file: " << std::endl << name.c_str() << std::endl;
        file.close();
        return (0);
    }

    while(std::getline(file, line)) //check if count is greater than the number of lines read from file
        linesRead++;

    if (count > linesRead)
    {
        std::cerr << "Count is greater than the number of names from the file" << std::endl;
        file.close();
        return (0);
    }
    file.clear();
    file.seekg(0); //reset file position to the beginning
    
    std::string *names = new std::string[count];
    while (std::getline(file, line) && namesIndex < count)
    {
        //check if it has white spaces or length is 0
        if (line.find_first_not_of(' ') == std::string::npos ||
            line.find_first_of('\t') != std::string::npos ||
            !line.length())
        {
            continue ;
        }
        names[namesIndex] = line;
        namesIndex++;
    }
    file.close();
    return (names);
}
