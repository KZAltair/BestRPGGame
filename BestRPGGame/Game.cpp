#include "Game.h"

Game::Game()
{
	//TODO(Ivan): Make random position based on obstacles

}

void Game::Run()
{
	
	PrintMenu();

	while (IsGameRunning)
	{
		if (!CharacterIsSelected)
		{
			PrintCharacterSelectionMenu();
			pAttr = ConstructPlayerAttributes(PlayerCharacter);
			player = Player(pAttr);
			player.posX = 2;
			player.posY = 1;
			map.SetMapMarker(player);
		}
		
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

void Game::PrintGameMenu(Player& player)
{
	unsigned char choice;
	std::cout << "VIEW STATS(C)--TRAVEL(W)--MAP(M)--CLEAR SCREEN(C)--QUIT(Q)" << std::endl;
	std::cin >> choice;

	if (choice == 'Q' || choice == 'q')
	{
		IsGameRunning = false;
	}
	else if (choice == 'C' || choice == 'c')
	{
		system("CLS");
	}
	else if (choice == 'W' || choice == 'w')
	{
		//Movement by the map code
		char in = 0;
		std::cout << "WEST(A)--NORTH(W)--EAST(D)--SOUTH(S)" << std::endl;
		std::cin >> in;
		if (in == 'A' || in == 'a')
		{
			player.posX -= 1;
			if (map.isMoveValid(player))
			{
				map.SetMapMarker(player);
			}
			else
			{
				player.posX += 1;
			}
		}
		else if (in == 'W' || in == 'w')
		{
			player.posY -= 1;
			if (map.isMoveValid(player))
			{
				map.SetMapMarker(player);
			}
			else
			{
				player.posX += 1;
			}
		}
		else if (in == 'D' || in == 'd')
		{
			player.posX += 1;
			if (map.isMoveValid(player))
			{
				map.SetMapMarker(player);
			}
			else
			{
				player.posX -= 1;
			}
		}
		else if (in == 'S' || in == 's')
		{
			player.posY += 1;
			if (map.isMoveValid(player))
			{
				map.SetMapMarker(player);
			}
			else
			{
				player.posX -= 1;
			}
		}
		else
		{
			std::cout << "Enter a valid command..." << std::endl;
		}
	}
	else if (choice == 'C' || choice == 'c')
	{
		ViewCharacterStats(player);
	}
	else if (choice == 'M' || choice == 'm')
	{
		map.PrintMap();
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
