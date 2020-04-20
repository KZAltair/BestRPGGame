#pragma once
#include <random>
#include "Player.h"

class TileMap
{
public:
	TileMap();
	void PrintMap();
	bool isMoveValid(const Player& p);
	void SetMapMarker(const Player& p);

private:
	std::mt19937 rng;
	static constexpr int rows = 10;
	static constexpr int cols = 10;

	int map[rows][cols];
};