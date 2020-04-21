#include "TileMap.h"
#include <iostream>
#include "Utility.h"

TileMap::TileMap()
{

	
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
			else if (map[y][x] == 5)
			{
				//Can't go there
				std::cout << "E";
			}
			
			//For debug purposes
			//std::cout << map[y][x];
		}
		std::cout << std::endl;
	}
}

void TileMap::InitMap()
{
	//Generate map borders
	for (int y = 0; y < rows; ++y)
	{
		for (int x = 0; x < cols; ++x)
		{
			map[y][x] = 4;
		}
	}
	//Generate map contents
	for (int y = 1; y < rows - 1; ++y)
	{
		for (int x = 1; x < cols - 1; ++x)
		{
			int location = GenerateRandomNumber(0, 0);
			if (location == 1 && x % 4 == 0 && y % 4 == 0)
			{
				map[y][x] = location;
			}
			else
			{
				map[y][x] = location;
			}

		}
	}

	//Generate enemies
	for (int i = 0; i < numEnemiesOnMap; ++i)
	{
		pos.x = GenerateRandomNumber(1, cols - 2);
		pos.y = GenerateRandomNumber(1, rows - 2);
		enemy[i] = Enemy(pos);
		map[pos.y][pos.x] = 5;
	}
}

bool TileMap::isMoveValid(const Player& p)
{
	combat = false;
	system("CLS");
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
	else if (map[p.posY][p.posX] == 5)
	{
		std::cout << GetEnemy(p)->GetAttributes()->name 
			<< " saw you and approach to slit your throat!" << std::endl;
		std::cout << "PREPARE FOR BATTLE!" << std::endl;
		combat = true;
		return true;
	}
	return true;
}

bool TileMap::IsCombat() const
{
	return combat;
}

void TileMap::SetMapMarker(const Player& p)
{
	map[p.posY][p.posX] = 3;
}

Enemy* TileMap::GetEnemy(const Player& p)
{
	//TODO(ivan): possibly there is a simpler way
	int rightEnemyIndex = 0;
	for (int i = 0; i < 5; ++i)
	{
		if (p.posX == enemy[i].GetEnemyPos().x && p.posY == enemy[i].GetEnemyPos().y)
		{
			rightEnemyIndex = i;
		}
	}
	return &enemy[rightEnemyIndex];
}

bool TileMap::isAllEnemiesAlive() const
{
	int count = 0;
	for (int i = 0; i < numEnemiesOnMap; ++i)
	{
		if (enemy[i].IsAlive())
		{
			count++;
		}
	}
	if (count <= 0)
	{
		return false;
	}
	return true;
}
