#include "TileMap.h"
#include <iostream>

TileMap::TileMap()
	:
	rng(std::random_device()())
{
	std::uniform_int_distribution<int> locations(0, 1);

	for (int y = 0; y < rows; ++y)
	{
		for (int x = 0; x < cols; ++x)
		{
			map[y][x] = 4;
		}
	}
	for (int y = 1; y < rows - 1; ++y)
	{
		for (int x = 1; x < cols - 1; ++x)
		{
			map[y][x] = locations(rng);
		}
	}
}

void TileMap::PrintMap()
{
	//Printing what's in the map
	for (int y = 0; y < rows; ++y)
	{
		for (int x = 0; x < cols; ++x)
		{
			if (map[y][x] == 0)
			{
				//Not visited
				std::cout << "-";
			}
			else if (map[y][x] == 1)
			{
				//Can't go there
				std::cout << "*";
			}
			else if (map[y][x] == 3)
			{
				//Can't go there
				std::cout << "V";
			}
			else if (map[y][x] == 4)
			{
				//Can't go there
				std::cout << "X";
			}
			
			//For debug purposes
			//std::cout << map[y][x];
		}
		std::cout << std::endl;
	}
}

bool TileMap::isMoveValid(const Player& p)
{
	if (map[p.posY][p.posX] == 4)
	{
		std::cout << "You faced with huge rocky mountains that can't be walked around." << std::endl;
		std::cout << "You think it's better to head towards different direction." << std::endl;
		return false;
	}
	else if (map[p.posY][p.posX] == 1)
	{
		std::cout << "There is a deep hole in front of you. You feel cold air coming out of it." << std::endl;
		std::cout << "By looking around you realize, the only way to go through is head" << std::endl;
		std::cout << "in different direction. Well, at least you can move in other direction." << std::endl;
		return false;
	}
	return true;
}

void TileMap::SetMapMarker(const Player& p)
{
	map[p.posY][p.posX] = 3;
}
