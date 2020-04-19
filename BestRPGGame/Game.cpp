#include "Game.h"

void Game::Run()
{
	
	PrintMenu();

	while (IsGameRunning)
	{
		if (!CharacterIsSelected)
		{
			PrintCharacterSelectionMenu();
			pAttr = ConstructPlayerAttributes(PlayerCharacter);
		}
		Player player(pAttr);
		PrintGameMenu(player);

	}
}

void Game::PrintMenu()
{
	unsigned short input = 0;
	std::cout << "**************************" << std::endl;
	std::cout << "**    BEST RPG GAME     **" << std::endl;
	std::cout << "**************************" << std::endl;
	std::cout << std::endl;
	std::cout << "1. START NEW GAME" << std::endl;
	std::cout << "2. EXIT GAME" << std::endl;
	std::cin >> input;

	if (input == 1)
	{
		IsGameRunning = true;
	}
	else if (input == 2)
	{
		IsGameRunning = false;
	}
}

void Game::PrintCharacterSelectionMenu()
{
	unsigned short input = 0;
	std::cout << "Choose character class: " << std::endl;
	std::cout << "************************" << std::endl;
	std::cout << "1. Pathfinder ----HP 120--MA 40----" << std::endl;
	std::cout << "2. Sorcerer   ----HP 80--MA 150----" << std::endl;
	std::cout << "3. Rouge      ----HP 100--MA 70----" << std::endl;
	std::cin >> input;
	if (input == 1)
	{
		PlayerCharacter = 1;
		CharacterIsSelected = true;
	}
	else if (input == 2)
	{
		PlayerCharacter = 2;
		CharacterIsSelected = true;
	}
	else if (input == 3)
	{
		PlayerCharacter = 3;
		CharacterIsSelected = true;
	}
	else
	{
		std::cout << "Please, eneter a valid choice" << std::endl;
		CharacterIsSelected = false;
	}
	system("CLS");
}

void Game::ViewCharacterStats(const Player& player)
{
	player_attributes pAttr = *player.GetPlayerAttributes();
	std::cout << "**************************" << std::endl;
	std::cout << "**      " << pAttr.className << "      **" << std::endl;
	std::cout << "**************************" << std::endl;
	std::cout << "HEALTH: " << pAttr.health << std::endl;
	std::cout << "MANA: " << pAttr.mana << std::endl;
	std::cout << "STRENGTH: " << pAttr.strength << std::endl;
	std::cout << "AGILITY: " << pAttr.agility << std::endl;
	std::cout << "INTELLIGENCE: " << pAttr.intelligence << std::endl;
	std::cout << "SPEED: " << pAttr.speed << std::endl;
}

void Game::PrintGameMenu(const Player& player)
{
	unsigned char choice;
	std::cout << "VIEW STATS(C)----MOVE(W)----QUIT(Q)" << std::endl;
	std::cin >> choice;
	if (choice == 'Q' || choice == 'q')
	{
		IsGameRunning = false;
	}
	else if (choice == 'W' || choice == 'w')
	{
		//Movement by the map code
	}
	else if (choice == 'C' || choice == 'c')
	{
		ViewCharacterStats(player);
	}
	else
	{

	}
}

player_attributes Game::ConstructPlayerAttributes(unsigned int PlayerCharacter)
{
	player_attributes pAttr;
	switch (PlayerCharacter)
	{
	case 1:
	{
		pAttr.agility = 6;
		pAttr.className = "Pathfinder";
		pAttr.health = 100;
		pAttr.intelligence = 5;
		pAttr.mana = 50;
		pAttr.speed = 20;
		pAttr.strength = 8;

		return pAttr;
	}break;
	case 2:
	{
		pAttr.agility = 4;
		pAttr.className = "Sorcerer";
		pAttr.health = 100;
		pAttr.intelligence = 8;
		pAttr.mana = 100;
		pAttr.speed = 10;
		pAttr.strength = 5;

		return pAttr;

	}break;
	case 3:
	{
		pAttr.agility = 8;
		pAttr.className = "Rougue";
		pAttr.health = 100;
		pAttr.intelligence = 6;
		pAttr.mana = 70;
		pAttr.speed = 30;
		pAttr.strength = 6;

		return pAttr;

	}break;
	default:
	{
		return pAttr = {};
	}break;
	}
}
