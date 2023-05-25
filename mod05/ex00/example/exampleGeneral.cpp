#include <iostream>

void test1(std::string name)
{
	try
	{
		if (name == "dog")
		{
			throw std::exception(); //from here...
		}
		else
		{
			std::cout << "the name is not dog" << std::endl;
		}
	}
	catch (std::exception &e)
	{
		std::cout << "the name should be dog" << std::endl; //...it goes here
	}
}

void test2(std::string name)
{
	if (name == "cat")
	{
		throw std::exception();
	}
	else
	{
		std::cout << "the name is not cat" << std::endl;
	}
}

void test3(std::string name)
{
	try
	{
		test2(name);
	}
	catch (std::exception &e) //catch exception by reference
	{
		std::cout << "test3: the name is not a cat" << std::endl;
	}
}

void test4(std::string name)
{
	class RandomException: public std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				return ("Problem exists between keyboard and chair");
			}
	};
	try
	{
		test3(name);
	}
	catch (RandomException &e) //specific catch
	{
		std::cout << "test4 (specific) the name is not a cat" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "test4 (specific) the name is not a cat" << std::endl;
	}
}

int main(void)
{
	try
	{
		test3("cat");
	}
	catch (const std::exception &e)
	{
		std::cout << "An exception occured: " << e.what() << std::endl;
	}
}
