#pragma once
//all main includes here
#include <iostream>
#include <vector>
#include "Player.h"
#include "TileMap.h"

/*
1. Make levels
2. Improved Combat system
3. Load/Save game
4. Vizual quality with frames and health indicators
5. Dialog system
6. AI
7. Sound
8. Better menu system / possibly better graphics
9. Inventory
10. Restoring stats / rest - done. Rest later.
11. Map and diversity
12. Leveling up / Implemented, but poorly

Bugs
1. Game is not ending once all enemies are dead
2. After level up each new kill is a level up
3. Player can still move on invalid X location
4. Some enemies after 2 kills dies automatically
*/

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
	void ResetGame();
	void Loot();
	player_attributes ConstructPlayerAttributes(unsigned int PlayerCharacter);
	void Combat();

private:
	bool IsGameRunning = false;
	bool isGameStarted = false;
	bool Looting = false;
	bool viewStats = false;
	bool viewMainMenu = true;
	bool CharacterIsSelected = false;
	unsigned short PlayerCharacter = 0;
	Player player;
	player_attributes pAttr;
	TileMap map;
};