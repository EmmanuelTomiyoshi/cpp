#include "Fixed.hpp"


int main()
{
	Fixed		a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << std::endl << "SUBJECT TESTS" << std::endl;

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;


	Fixed c(3);
	Fixed d(4);
	Fixed e(5);
	Fixed f(6);
	Fixed g(7);
	Fixed n(-1);
	Fixed z(0);

	std::cout << std::endl << "COMPARISON OPERATORS (>, <, >=, <=, == and !=)" << std::endl;

	std::cout << c << " > " << d << "\t=\t" << (c > d) << std::endl; //3 > 4
	std::cout << c << " < " << d << "\t=\t" << (c < d) << std::endl; //3 < 4

	std::cout << c << " >= " << d << "\t=\t" << (c >= d) << std::endl; //3 >= 4
	std::cout << c << " <= " << d << "\t=\t" << (c <= d) << std::endl; //3 <= 4
	std::cout << c << " >= " << c << "\t=\t" << (c >= c) << std::endl; //3 >= 3
	std::cout << c << " <= " << c << "\t=\t" << (c <= c) << std::endl; //3 <= 3

	std::cout << c << " == " << c << "\t=\t" << (c == c) << std::endl; //3 == 3
	std::cout << c << " == " << d << "\t=\t" << (c == d) << std::endl; //3 == 4

	std::cout << c << " != " << c << "\t=\t" << (c != c) << std::endl; //3 != 3
	std::cout << c << " != " << d << "\t=\t" << (c != d) << std::endl; //3 != 4


	std::cout << std::endl << "ARITHMETIC OPERATORS (+, -, * and /)" << std::endl;

	std::cout << c << " + " << d << "\t=\t" << (c + d) << std::endl; // 3 + 4
	std::cout << n << " + " << n << "\t=\t" << (n + n) << std::endl; // (-1) + (-1)
	std::cout << z << " + " << z << "\t=\t" << (z + z) << std::endl; // 0 + 0

	std::cout << c << " - " << d << "\t=\t" << (c - d) << std::endl; // 3 - 4
	std::cout << n << " - " << n << "\t=\t" << (n - n) << std::endl; // (-1) - (-1)
	std::cout << d << " - " << c << "\t=\t" << (d - c) << std::endl; // 4 - 3

	std::cout << c << " * " << d << "\t=\t" << (c * d) << std::endl; // 3 * 4
	std::cout << c << " * " << n << "\t=\t" << (c * n) << std::endl; // 3 * (-1)
	std::cout << n << " * " << n << "\t=\t" << (n * n) << std::endl; // (-1) * (-1)

	std::cout << c << " / " << d << "\t=\t" << (c / d) << std::endl; // 3 / 4
	std::cout << c << " / " << n << "\t=\t" << (c / n) << std::endl; // 3 / (-1)
	std::cout << n << " / " << n << "\t=\t" << (n / n) << std::endl; // (-1) / (-1)
	std::cout << z << " / " << c << "\t=\t" << (z / c) << std::endl; // (-1) / 0
	std::cout << c << " / " << z << "\t=\t" << Fixed(0) << std::endl; // (-1) / 0
	(c / z);


	std::cout << "INCREMENT/DECREMENT OPERATORS (++a, a++, --b and b--)" << std::endl;

	std::cout << "++" << c << "\t\t=\t" << (++c) << std::endl; // ++3
	std::cout << c << "++" << "\t=\t" << (c++) << ", " << c << std::endl; // 3++

	std::cout << "--" << d << "\t\t=\t" << (--d) << std::endl; // --4
	std::cout << d << "--" << "\t=\t" << (d--) << ", " << d << std::endl; // 4--


	std::cout << std::endl << "MIN and MAX" << std::endl;

	std::cout << "min(" << f << ", " << g << ")" << "\t=\t" << e.min(f, g) << std::endl; //6, 7
	std::cout << "min(" << f << ", " << g << ")" << "\t=\t" << e.min(g, f) << std::endl; //6, 7
	std::cout << "min(" << n << ", " << g << ")" << "\t=\t" << e.min(n, f) << std::endl; //-1, 7

	std::cout << "max(" << f << ", " << g << ")" << "\t=\t" << e.max(f, g) << std::endl; //6, 7
	std::cout << "max(" << f << ", " << g << ")" << "\t=\t" << e.max(g, f) << std::endl; //6, 7
	std::cout << "max(" << n << ", " << g << ")" << "\t=\t" << e.max(n, g) << std::endl; //-1, 7

	return 0;
}