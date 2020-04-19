#pragma once
//all main includes here
#include <iostream>
#include <vector>
#include <random>
#include "Player.h"


class Game
{
public:
	Game();
	void Run();
private:
	void PrintMenu();
	void PrintCharacterSelectionMenu();
	void ViewCharacterStats(const Player& player);
	void PrintGameMenu(Player& player);
	player_attributes ConstructPlayerAttributes(unsigned int PlayerCharacter);

private:
	bool IsGameRunning = false;
	bool CharacterIsSelected = false;
	unsigned short PlayerCharacter = 0;
	Player player;
	player_attributes pAttr;
	std::vector<int> map;
	std::mt19937 rng;
};