#include "Utility.h"
#include "Game.h"

Game::Game()
{
	//TODO(Ivan): Make random position based on obstacles
	map = TileMap();

}

void Game::Run()
{
	PrintMenu();

	while (IsGameRunning)
	{
		if (isGameStarted)
		{
			if (!CharacterIsSelected)
			{
				PrintCharacterSelectionMenu();
				ResetGame();
			}

			if (!player.IsAlive() || !map.isAllEnemiesAlive())
			{
				PrintGameOver();
				//IsGameRunning = false;
			}
			else
			{
				PrintGameMenu(player);
			}
		}
		else
		{

			PrintMenu();
		}
		
	}
}

void Game::PrintGameOver()
{
	system("CLS");
	std::cout << "**************************" << std::endl;
	std::cout << "**       GAME OVER      **" << std::endl;
	std::cout << "**************************" << std::endl;
	CharacterIsSelected = false;
	isGameStarted = false;
	system("pause");
	system("CLS");
	viewMainMenu = true;

}

void Game::PrintMenu()
{
	//TODO(ivan): Infinite loop bug in case of using letters in choice input
		system("CLS");
		unsigned short input = 0;
		std::cout << "**************************" << std::endl;
		std::cout << "**    BEST RPG GAME     **" << std::endl;
		std::cout << "**************************" << std::endl;
		std::cout << std::endl;
		std::cout << "1. START NEW GAME" << std::endl;
		std::cout << "2. EXIT GAME" << std::endl;
		std::cin >> input;

		if (typeid(input) != typeid(int))
		{
			std::cout << "Use number 1 or 2 to select" << std::endl;
		}

		if (input == 1)
		{
			IsGameRunning = true;
			isGameStarted = true;
			viewMainMenu = false;
		}
		else if (input == 2)
		{
			IsGameRunning = false;
			viewMainMenu = false;
		}
		else
		{
			std::cout << "Enter a valid choice 1 or 2" << std::endl;
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
	while (viewStats)
	{
		system("CLS");
		player_attributes pAttr = *player.GetPlayerAttributes();
		std::cout << "**************************" << std::endl;
		std::cout << "**      " << pAttr.className << "      **" << std::endl;
		std::cout << "**************************" << std::endl;
		std::cout << "LEVEL: " << pAttr.Level << std::endl;
		std::cout << "EXPERIENCE: " << pAttr.curExp << std::endl;
		std::cout << "HEALTH: " << pAttr.health << std::endl;
		std::cout << "MANA: " << pAttr.mana << std::endl;
		std::cout << "STRENGTH: " << pAttr.strength << std::endl;
		std::cout << "AGILITY: " << pAttr.agility << std::endl;
		std::cout << "INTELLIGENCE: " << pAttr.intelligence << std::endl;
		std::cout << "SPEED: " << pAttr.speed << std::endl;

		std::cout << std::endl;
		std::cout << "Close(X)";
		char in;
		std::cin >> in;
		if (in == 'X' || in == 'x')
		{
			viewStats = false;
		}
		else
		{
			system("CLS");
		}

	}
}

void Game::PrintGameMenu(Player& player)
{
	system("CLS");
	unsigned char choice;
	player.DisplayStatsBar();
	map.PrintMap();
	std::cout << "VIEW STATS(K)--INVENTORY(I)--TRAVEL(W)--CLEAR SCREEN(C)--QUIT(Q)" << std::endl;
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
				
				if (map.IsCombat())
				{
					Combat();
					Loot();
					map.SetMapMarker(player);
				}
				else
				{
					map.SetMapMarker(player);
					if (player.GetPlayerAttributes()->health < 100)
					{
						player.GetPlayerAttributes()->health += 1;
					}
					
				}
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

				if (map.IsCombat())
				{
					Combat();
					Loot();
					map.SetMapMarker(player);
				}
				else
				{
					map.SetMapMarker(player);
					if (player.GetPlayerAttributes()->health < 100)
					{
						player.GetPlayerAttributes()->health += 1;
					}
				}
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

				if (map.IsCombat())
				{
					Combat();
					Loot();
					map.SetMapMarker(player);
				}
				else
				{
					map.SetMapMarker(player);
					if (player.GetPlayerAttributes()->health < 100)
					{
						player.GetPlayerAttributes()->health += 1;
					}
				}
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

				if (map.IsCombat())
				{
					Combat();
					Loot();
					map.SetMapMarker(player);
				}
				else
				{
					map.SetMapMarker(player);
					if (player.GetPlayerAttributes()->health < 100)
					{
						player.GetPlayerAttributes()->health += 1;
					}
				}
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
	else if (choice == 'I' || choice == 'i')
	{
		player.viewInventory = true;
		player.DisplayInventory();
	}
	else if (choice == 'K' || choice == 'k')
	{
		viewStats = true;
		ViewCharacterStats(player);

	}
	else
	{
		std::cout << "Enter a valid command from main menu." << std::endl;
	}
}

void Game::ResetGame()
{
	map.InitMap();
	pAttr = ConstructPlayerAttributes(PlayerCharacter);
	player = Player(pAttr);
	player.posX = 2;
	player.posY = 1;
	map.SetMapMarker(player);
}

void Game::Loot()
{
	while (Looting)
	{
		char in;
		std::cout << "--LOOT(L)----TRAVEL(T)--" << std::endl;
		std::cin >> in;
		if (in == 'L' || in == 'l')
		{
			std::cout << "You found nothing, but flesh and bones." << std::endl;
		}
		else if (in == 'T' || in == 't')
		{
			Looting = false;
		}
		else
		{
			std::cout << "Invalid command. Try T or L letters." << std::endl;
		}
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
		pAttr.manaSpellCost = 50;
		pAttr.ArmorClass = 30;
		pAttr.MagicResistance = 20;
		pAttr.curExp = 0;
		pAttr.expModifier = 2;
		pAttr.expForNextLevel = pAttr.curExp * pAttr.expModifier + 500;
		pAttr.Level = 1;

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
		pAttr.manaSpellCost = 20;
		pAttr.ArmorClass = 15;
		pAttr.MagicResistance = 40;
		pAttr.curExp = 0;
		pAttr.expModifier = 2;
		pAttr.expForNextLevel = pAttr.curExp * pAttr.expModifier + 500;
		pAttr.Level = 1;

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
		pAttr.manaSpellCost = 40;
		pAttr.ArmorClass = 20;
		pAttr.MagicResistance = 10;
		pAttr.curExp = 0;
		pAttr.expModifier = 2;
		pAttr.expForNextLevel = pAttr.curExp * pAttr.expModifier + 500;
		pAttr.Level = 1;

		return pAttr;

	}break;
	default:
	{
		return pAttr = {};
	}break;
	}
}

void Game::Combat()
{
	while (player.IsAlive() && map.GetEnemy(player)->IsAlive())
	{
		int diceNumber = GenerateRandomNumber(1, 6);
		char in = 0;
		std::cout << "**************************************************" << std::endl;
		std::cout << "              ";
		std::cout << map.GetEnemy(player)->GetAttributes()->name << " "
			<< map.GetEnemy(player)->GetAttributes()->health << std::endl;
		std::cout << "**************************************************" << std::endl;
		player.DisplayStatsBar();
		std::cout << "Attack(A)--Move(W)--Run(D)--SPEAK(S)" << std::endl;
		std::cin >> in;
		if (in == 'A' || in == 'a')
		{
			//Attack logic
			char attackIn = 0;
			std::cout << "ATTACK WITH WEAPON(A)--ATTACK WITH MAGIC(D)" << std::endl;
			std::cin >> attackIn;
			if (attackIn == 'A' || attackIn == 'a')
			{
				int enemyArmorClass = map.GetEnemy(player)->GetAttributes()->armorClass;
				int enemyMagicResistance = map.GetEnemy(player)->GetAttributes()->magicResistance;
				int damage = player.Attack(enemyArmorClass, enemyMagicResistance, 0);
				map.GetEnemy(player)->TakeDamage(damage);
				int enemyDamage = map.GetEnemy(player)->Attack(player.GetPlayerAttributes()->ArmorClass, 
															player.GetPlayerAttributes()->MagicResistance);
				player.TakeDamage(enemyDamage);
			}
			else if (attackIn == 'D' || attackIn == 'd')
			{
				int enemyArmorClass = map.GetEnemy(player)->GetAttributes()->armorClass;
				int enemyMagicResistance = map.GetEnemy(player)->GetAttributes()->magicResistance;
				int damage = player.Attack(enemyArmorClass, enemyMagicResistance, 1);
				map.GetEnemy(player)->TakeDamage(damage);
				int enemyDamage = map.GetEnemy(player)->Attack(player.GetPlayerAttributes()->ArmorClass,
					player.GetPlayerAttributes()->MagicResistance);
				player.TakeDamage(enemyDamage);
			}
		}
		else if (in == 'W' || in == 'w')
		{
			//Move around enemy with speed modifiers
		}
		else if (in == 'D' || in == 'd')
		{
			//Dice to run or take free dagame from enemy
		}
		else if (in == 'S' || in == 's')
		{
			//Speak with enemy for fun outcomes
		}
		else
		{
			std::cout << "Enter a valid command!" << std::endl;
		}
	}
	if (player.IsAlive())
	{
		player.AddExperience(*map.GetEnemy(player));
		Looting = true;
	}
}
