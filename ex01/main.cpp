
#include <iostream>
#include <string>

class Player
{
	public:
		int	x, y;
		int speed;

	void Move(int xa, int ya)
	{
		x += xa * speed;
		y += ya * speed;
	}
};


int main()
{
	Player	player;

	player.x = 5;
	player.speed = 2;

	std::cout << player.x + player.speed << std::endl;
	player.Move(1, -1);
	std::cout << player.x + player.speed << std::endl;
	//functions inside classes are called methods
}
