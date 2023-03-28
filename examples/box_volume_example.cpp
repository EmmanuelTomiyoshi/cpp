#include <iostream>

class Box {
	public:
		double length;
		double breadth;
		double height;

		double getVolume(void);
		void setLength(double len);
		void setBreadth(double bre);
		void setHeight(double hei);
};

double Box::getVolume(void) {
	return length * breadth * height;
}

void Box::setLength(double len) {
	length = len;
}

void Box::setBreadth(double bre) {
	breadth = bre;
}

void Box::setHeight(double hei) {
	height = hei;
}

int main(void)
{
	Box Box1;
	Box Box2;
	double volume = 0.0;

	Box1.setLength(6.0);
	Box1.setBreadth(7.0);
	Box1.setHeight(5.0);

	Box2.setLength(12.0);
	Box2.setBreadth(13.0);
	Box2.setHeight(10.0);

	volume = Box1.getVolume();
	std::cout << "Volume of Box1 : " << volume << std::endl;

	volume = Box2.getVolume();
	std::cout << "Volume of Box2 : " << volume << std::endl;
}

//g++ -Wall -Wextra -Werror -Wno-used -std=c++98 -g -pedantic box_volume_example.cpp -o box_volume