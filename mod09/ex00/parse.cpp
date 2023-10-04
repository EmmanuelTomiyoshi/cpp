#include "BitcoinExchange.hpp"

const std::string headline[] = { "date", "|", "value" };


bool isHeadlineValid(const std::string vec1[], const std::string vec2[], int size)
{
    for (int i = 0; i < size; ++i)
	{
        if (vec1[i] != vec2[i])
            return false;
    }
    return true;
}

bool parse(std::string filename)
{
	std::ifstream inputFile(filename.c_str());

	if (!inputFile.is_open())
	{
		std::cerr << "Failed to open the file." << std::endl;
		return false;
	}

	std::string line;
	if (!std::getline(inputFile, line))
	{
		std::cout << "File is empty" << std::endl;
		return false;
	}

	std::istringstream iss(line);
    const int maxWords = 100;
    std::string words[maxWords];
    std::string word;
    int wordCount = 0;

    while (iss >> word)
	{
        if (wordCount < maxWords)
		{
            words[wordCount] = word;
            wordCount++;
        } else {
            std::cout << "Maximum word count exceeded. Some words were not stored." << std::endl;
            break;
        }
    }
	bool isEqual = (wordCount == sizeof(headline) / sizeof(headline[0])) &&
                isHeadlineValid(headline, words, wordCount);

	if (isEqual)
		std::cout << "Yes" << std::endl;
	else
		std::cout << "No" << std::endl;

	inputFile.close();

	return true;
}