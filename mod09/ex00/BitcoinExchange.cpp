#include "BitcoinExchange.hpp"

const std::string BitcoinExchange::_headline[] = { "date", "|", "value" };

BitcoinExchange::BitcoinExchange(void) : _database()
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[BitcoinExchange] constructor called" << std::endl;
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) : _database()
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[BitcoinExchange] copy constructor called" << std::endl;
	}
	*this = copy;
}

BitcoinExchange&BitcoinExchange::operator=(const BitcoinExchange &copy)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[BitcoinExchange] assignment copy operator called" << std::endl;
	}
	if (this != &copy)
	{

	}
	return *this;
}

BitcoinExchange::~BitcoinExchange(void)
{
	if (SHOW_DEFAULT_MESSAGES)
	{
		std::cout << "[BitcoinExchange] destructor called" << std::endl;
	}
}

bool BitcoinExchange::checkDate(const std::string date)
{
	if (date.length() != DATE_LENGTH || (date[4] != '-' || date[7] != '-'))
	{
		std::cout << "Error: " << ERR_DATE_WRONG_FORMAT " " << std::endl;
		return false;
	}
	
	std::string yearStr = date.substr(0, YEAR_CHAR_LENGTH);
	std::string monthStr = date.substr(5, MONTH_CHAR_LENGTH);
	std::string dayStr = date.substr(8, DAY_CHAR_LENGTH);

	int year, month, day;

	year = atoi(yearStr.c_str());
	month = atoi(monthStr.c_str());
	day = atoi(dayStr.c_str());

	//Checks if day and month are within bounds
	if (day < 1 || month < 1 || month > 12)
	{
		std::cout << "Error: " << ERR_DATE_WRONG_BOUND " " << std::endl;
		return false;
	}

	if (month == 2)
	{
		if ((day > 29 && isLeapYear(year)) || (day > 28 && !isLeapYear(year)))
		{
			std::cout << "Error: " << ERR_DATE_WRONG_BOUND " " << std::endl;
			return false;
		}
	}
	else
	{
		//check the day against the month limits
		int daysInMonth[] = {0, 31, isLeapYear(year) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		if (day > daysInMonth[month])
		{
			std::cout << "Error: " << ERR_DATE_WRONG_BOUND " " << std::endl;
			return false;
		}
	}

	//Defines the lower bound date (January 3rd, 2009)
	struct tm btcStart;
	btcStart.tm_year = 109; //Years since 1900 to 2009 (btc creation date)
	btcStart.tm_mon = 0;	//January
	btcStart.tm_mday = 3;  // 3rd day of the month
    btcStart.tm_hour = 0;
    btcStart.tm_min = 0;
    btcStart.tm_sec = 0;
    btcStart.tm_isdst = -1; // Determines daylight saving time, it's irrelevant for this program

	//Defines the current date
	std::time_t currentTime;
	std::time(&currentTime);

	//Parses the input date
	struct tm inputDate;
	inputDate.tm_year = year - 1900;
	inputDate.tm_mon = month - 1;
	inputDate.tm_mday = day;
	inputDate.tm_hour = 0;
    inputDate.tm_min = 0;
    inputDate.tm_sec = 0;
    inputDate.tm_isdst = -1; // Determines daylight saving time, it's irrelevant for this program

    std::time_t inputTime = std::mktime(&inputDate);
    std::time_t btcStartTime = std::mktime(&btcStart);

	if ((inputTime >= btcStartTime && inputTime <= currentTime) == false)
	{
		std::cout << "Error: " << ERR_DATE_WRONG_RANGE " " << std::endl;
		return false;
	}

	return true;
}

void BitcoinExchange::isValidEntry(const std::string line)
{
	const int maxWords = 4;
    int wordCount = 0;
	std::istringstream iss(line);
    std::string words[maxWords];
    std::string word;

    while (iss >> word)
	{
        words[wordCount++] = word;
	}

	if (wordCount != 3)
	{
		std::cout << "Error: " << ERR_BAD_INPUT << " => " << words[0] << std::endl;
	}

	bool date, divisor, value = false;

	date = checkDate(words[0]);
	divisor = words[1].length() == 1 && words[1][0] == '|';
	value = isValidValue(words[2]);

	if (date == false || divisor == false || value == false)
	{
		return ;
	}

	else
	{

		std::map<std::string, double>::iterator it = _database.lower_bound(words[0]);

		if (it != _database.begin())
		{
			--it;
		}
		float value = (std::atof(words[2].c_str())) * it->second;
		std::cout << words[0] << " => " << words[2] << " = " << value << std::endl;
	}

}

void BitcoinExchange::checkHeadline(std::string line)
{
    const int maxWords = 4;
    int wordCount = 0;
	std::istringstream iss(line);
    std::string words[maxWords];
    std::string word;

    while (iss >> word)
	{
        words[wordCount++] = word;
	}

	if (wordCount != 3)	//checks if there are the 3 needed strings
		throw HeadlineIsInvalid();

	for (int i = 0; i < maxWords; ++i)
	{
        if (_headline[i] != words[i]) //if the values differ from "date | value"
            throw HeadlineIsInvalid();
	}
}

void BitcoinExchange::readInputFile(std::string filename)
{
	std::ifstream inputFile(filename.c_str());

	handleFileErrors(inputFile);

	std::string line;
	std::getline(inputFile, line);

	checkHeadline(line);

	while (std::getline(inputFile, line))
	{
		if (line.empty() || isWhitespaceLine(line))
		{
			continue ;
		}
		isValidEntry(line);
	}

	inputFile.close();
}

void BitcoinExchange::readDatabase(std::string database)
{
	std::ifstream inputFile(database.c_str());

	handleFileErrors(inputFile);

	std::string line;
	std::getline(inputFile, line); //just skipping the first line
	
	std::string	key;
	double		value;

	while (std::getline(inputFile, line))
	{
		key = line.substr(0, line.find(","));
		value = std::atof((line.substr(line.find(",") + 1)).c_str());
		this->_database.insert(std::pair<std::string, double>(key, value));
	}

	inputFile.close();
}