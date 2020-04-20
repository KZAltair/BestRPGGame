#pragma once
//all main includes here
#include <iostream>
#include <vector>
#include "Player.h"
#include "TileMap.h"


class Game
{
public:
	Game();
	void Run();
private:
	void PrintMenu();
	void PrintGameOver();
	void PrintCharacterSelectionMenu();
	void ViewCharacterStats(const Player& player);
	void PrintGameMenu(Player& player);
	player_attributes ConstructPlayerAttributes(unsigned int PlayerCharacter);
	void Combat();

private:
	bool IsGameRunning = false;
	bool CharacterIsSelected = false;
	unsigned short PlayerCharacter = 0;
	Player player;
	player_attributes pAttr;
	TileMap map;
};