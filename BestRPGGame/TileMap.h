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
	bool isAllEnemiesAlive() const;
private:
	static constexpr int rows = 10;
	static constexpr int cols = 20;

	int map[rows][cols];
	static constexpr int numEnemiesOnMap = 10;
	Enemy enemy[numEnemiesOnMap];
	enemy_pos pos;
	bool combat = false;
	
};