#pragma once
#include "Player.h"
#include "Enemy.h"

class TileMap
{
public:
	TileMap();
	void PrintMap();
	void InitMap();
	bool isMoveValid(const Player& p);
	bool IsCombat() const;
	void SetMapMarker(const Player& p);
	Enemy* GetEnemy(const Player& p);
private:
	static constexpr int rows = 10;
	static constexpr int cols = 10;

	int map[rows][cols];
	Enemy enemy[5];
	enemy_pos pos;
	bool combat = false;
};