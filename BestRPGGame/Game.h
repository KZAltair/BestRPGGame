#pragma once
//all main includes here
#include <iostream>
#include "Player.h"


class Game
{
public:
	void Run();
private:
	void PrintMenu();
	void PrintCharacterSelectionMenu();
	void ViewCharacterStats(const Player& player);
	void PrintGameMenu(const Player& player);
	player_attributes ConstructPlayerAttributes(unsigned int PlayerCharacter);

private:
	bool IsGameRunning = false;
	bool CharacterIsSelected = false;
	unsigned short PlayerCharacter = 0;
	player_attributes pAttr;
};