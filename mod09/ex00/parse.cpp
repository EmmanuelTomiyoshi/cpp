#include "BitcoinExchange.hpp"

const std::string headline[] = { "date", "|", "value" };

bool isWhitespaceLine(const std::string &line)
{
	for (std::string::const_iterator it = line.begin(); it != line.end(); ++it)
	{
		if (!std::isspace(*it))
			return false;
	}
	return true;
}

bool checkHeadline(std::string line)
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
		return false;

	for (int i = 0; i < maxWords; ++i)
	{
        if (headline[i] != words[i])
            return false;
	}

	return true;
}

bool isLeapYear(unsigned int year)
{
	//Leap years are divisible by 4
	//There is an exception: Years divisible by 100 are not leap years, unless they are divisible by 400
	return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

bool isValidDate(const std::string date)
{
	if (date.length() != 10)
		throw std::invalid_argument ("Invalid date format");
	
	std::string yearStr = date.substr(0, 4);
	std::string monthStr = date.substr(5, 2);
	std::string dayStr = date.substr(8, 2);

	int year, month, day;

	year = atoi(yearStr.c_str());
	month = atoi(monthStr.c_str());
	day = atoi(dayStr.c_str());

	//Checks if day and month are within bounds
	if (day < 1 || month < 1 || month > 12)
		throw std::out_of_range("Date components out of range");

	if (month == 2)
	{
		if ((day > 29 && isLeapYear(year)) || (day > 28 && !isLeapYear(year)))
			throw std::out_of_range("Day is out of range for the given month and year");
	}
	else
	{
		//check the day against the month limits
		int daysInMonth[] = {0, 31, isLeapYear(year) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		if (day > daysInMonth[month])
			throw std::out_of_range("Day is out of range for the given month and year");
	}

	//Defines the lower bound date (January 3rd, 2009)
	struct tm btcStart;
	btcStart.tm_year = 109; //Years since 1900 to 2009 (btc creation date)
	btcStart.tm_mon = 0;	//January
	btcStart.tm_mday = 3;  // 3rd day of the month
    btcStart.tm_hour = 0;
    btcStart.tm_min = 0;
    btcStart.tm_sec = 0;
    btcStart.tm_isdst = -1; // Determine daylight saving time, it's irrelevant for this program

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
    inputDate.tm_isdst = -1; // Determine daylight saving time, it's irrelevant for this program

    std::time_t inputTime = std::mktime(&inputDate);
    std::time_t btcStartTime = std::mktime(&btcStart);

	if ((inputTime >= btcStartTime && inputTime <= currentTime) == false)
		throw std::out_of_range("Date is out of range");

	return true;
}

bool isValidValue(const std::string value)
{
	char *endptr;
	double number = strtod(value.c_str(), &endptr);

	if (*endptr != '\0')
		return false; //conversion failed
	
	return (number >= 0.0 && number <= 1000.0);
}

bool isValidEntry(const std::string line)
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
		return false;

	bool date, divisor, value = false;

	date = isValidDate(words[0]); //change to iterator "begin()", later
	divisor = words[1].length() == 1 && words[1][0] == '|';
	value = isValidValue(words[2]);

	if (date == false || divisor == false || value == false)
		throw std::invalid_argument ("invalid arguments");

	return true;
}

bool parse(std::string filename)
{
	std::ifstream inputFile(filename.c_str());

	if (!inputFile.is_open())
		throw std::invalid_argument("Failed to open the file.");

	if (inputFile.peek() == std::ifstream::traits_type::eof())
		throw std::length_error("File is empty");

	std::string line;
	std::getline(inputFile, line);

	if (!checkHeadline(line))
		throw std::invalid_argument("The first line of the file is incorrect. Usage: \"date | value\"");

	size_t linePos = 2;
	while (std::getline(inputFile, line))
	{
		if (line.empty() || isWhitespaceLine(line))
		{
			linePos++;
			continue ;
		}
		if (!isValidEntry(line))
		{
			std::stringstream errorMsg;
			errorMsg << "The data at line " << linePos << " is invalid";
			throw std::invalid_argument(errorMsg.str());
		}
		linePos++;
	}

	inputFile.close();

	return true;
}