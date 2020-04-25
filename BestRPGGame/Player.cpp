#include "Player.h"
#include <iostream>
#include "Utility.h"
#include "Enemy.h"

Player::Player(player_attributes& attributes)
	:
	pAttributes(&attributes),
	isAlive(true)
{
	InitInventory();
}

player_attributes* Player::GetPlayerAttributes() const
{
	return pAttributes;
}

void Player::TakeDamage(int damage)
{
	if (isAlive)
	{
		pAttributes->health -= std::abs(damage);
		statsCounter -= damage / 5;
		std::cout << "You was hit by " << damage << " damage" << std::endl;
		if (pAttributes->health < 0)
		{
			std::cout << "You scream out loud, then fall on your knees and exhail" << std::endl;
			std::cout << "last breath from your dead body. Noone ever remember you." << std::endl;
			isAlive = false;
		}
	}
}

int Player::Attack(int armorClass, int magicResistance, int attacktype)
{
	int damage = 0;
	int diceNumber = GenerateRandomNumber(1, 6);

	if (attacktype == 0)
	{
		if ((((pAttributes->agility + pAttributes->strength) * diceNumber) - armorClass) < 0)
		{
			damage = 0;
		}
		else
		{
			damage = ((pAttributes->agility + pAttributes->strength) * diceNumber) - armorClass;
		}

	}
	else if (attacktype == 1)
	{
		if (pAttributes->mana < pAttributes->manaSpellCost)
		{
			std::cout << "Insufficient mana." << std::endl;
		}
		else
		{
			if ((((pAttributes->intelligence + pAttributes->speed) * diceNumber) - magicResistance) < 0)
			{
				damage = 0;
			}
			else
			{
				damage = ((pAttributes->intelligence + pAttributes->speed) * diceNumber) - magicResistance;
			}
			
			if (pAttributes->mana > 0)
			{
				pAttributes->mana -= pAttributes->manaSpellCost;
				std::cout << "You fires magical blades into an enemy!" << std::endl;
			}
		}
		
	}

	return damage;
}

void Player::AddExperience(Enemy& e)
{
	pAttributes->curExp += e.GetAttributes()->exp;
	if (pAttributes->curExp >= pAttributes->expForNextLevel)
	{
		LevelUp();
		levelUpDone = false;
	}
}

void Player::LevelUp()
{
	if (!levelUpDone)
	{
		std::cout << "**************************" << std::endl;
		std::cout << "**      " << pAttributes->className << "      **" << std::endl;
		std::cout << "**************************" << std::endl;
		std::cout << "HEALTH: " << pAttributes->health << std::endl;
		std::cout << "MANA: " << pAttributes->mana << std::endl;
		std::cout << "STRENGTH: " << pAttributes->strength << std::endl;
		std::cout << "AGILITY: " << pAttributes->agility << std::endl;
		std::cout << "INTELLIGENCE: " << pAttributes->intelligence << std::endl;
		std::cout << "SPEED: " << pAttributes->speed << std::endl;
		std::cout << "Manage skills: " << std::endl;
		std::cout << "1. Increase STRENGTH     +1" << std::endl;
		std::cout << "2. Increase INTELLIGENCE +1" << std::endl;
		std::cout << "3. Increase AGILITY      +1" << std::endl;
		std::cout << "4. Increase HEALTH       +20" << std::endl;
		std::cout << "5. Increase MANA         +20" << std::endl;

		pAttributes->Level += 1;

		int in = 0;
		std::cin >> in;
		if (in == 1)
		{
			pAttributes->strength += 1;
			pAttributes->ArmorClass += 4;
			pAttributes->health += 5;
			statsCounter += 1;
			levelUpDone = true;
		}
		else if (in == 2)
		{
			pAttributes->intelligence += 1;
			pAttributes->MagicResistance += 5;
			pAttributes->mana += 5;
			pAttributes->health += 5;
			statsCounter += 1;
			levelUpDone = true;
		}
		else if (in == 3)
		{
			pAttributes->agility += 1;
			pAttributes->speed += 4;
			pAttributes->health += 5;
			statsCounter += 1;
			levelUpDone = true;
		}
		else if (in == 4)
		{
			pAttributes->health += 20;
			statsCounter += 4;
			levelUpDone = true;
		}
		else if (in == 5)
		{
			pAttributes->mana += 20;
			statsCounter += 4;
			levelUpDone = true;
		}
		else
		{
			std::cout << "Invalid command. Try 1,2,3,4,5..." << std::endl;
		}
	}
}

bool Player::IsAlive() const
{
	return isAlive;
}

void Player::DisplayStatsBar()
{
	std::cout << std::endl;
	for (int i = 0; i < statsCounter; ++i)
	{
		std::cout << "*";
	}
	std::cout << std::endl;
	std::cout << "**   HEALTH " << pAttributes->health << "   **" << std::endl;
	for (int i = 0; i < statsCounter; ++i)
	{
		std::cout << "*";
	}
	std::cout << std::endl;
	std::cout << std::endl;
}

void Player::InitInventory()
{
	for (int y = 0; y < invSizeY; ++y)
	{
		for (int x = 0; x < invSizeX; ++x)
		{
			inventory[y][x] = 0;
		}
	}
	for (int y = 1; y < invSizeY - 1; ++y)
	{
		for (int x = 1; x < invSizeX - 1; ++x)
		{
			inventory[y][x] = 1;
		}
	}
	for (int y = 1; y < 2; ++y)
	{
		for (int x = 1; x < 3; ++x)
		{
			int item = GenerateRandomNumber(2, 3);
			inventory[y][x] = item;
		}
	}
	viewInventory = false;
}

void Player::DisplayInventory()
{
	while (viewInventory)
	{
		system("CLS");
		std::cout << "**************************" << std::endl;
		std::cout << "**      " << pAttributes->className << "      **" << std::endl;
		std::cout << "**************************" << std::endl;
		for (int y = 0; y < invSizeY; ++y)
		{
			for (int x = 0; x < invSizeX; ++x)
			{
				if (inventory[y][x] == 0)
				{
					std::cout << "-";
				}
				else if (inventory[y][x] == 1)
				{
					std::cout << " ";
				}
				else if (inventory[y][x] == 2)
				{
					std::cout << "M";
				}
				else if (inventory[y][x] == 3)
				{
					std::cout << "H";
				}
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
		std::cout << "Close(X)";
		char in;
		std::cin >> in;
		if (in == 'X' || in == 'x')
		{
			viewInventory = false;
		}
		else
		{
			UseItem(in);
			system("CLS");
		}
	}
	
}

void Player::UseItem(char in)
{
	for (int y = 0; y < invSizeY; ++y)
	{
		for (int x = 0; x < invSizeX; ++x)
		{
			if (in == 'M' || in == 'm')
			{
				if (inventory[y][x] == 2)
				{
					pAttributes->mana += std::min(50, 100 - pAttributes->mana);
					statsCounter += std::min(50, 100 - pAttributes->mana) / 5;
					inventory[y][x] = 1;
					std::cout << "Used health potion" << std::endl;
					break;
				}
			}
			else if (in == 'H' || in == 'h')
			{
				if (inventory[y][x] == 3)
				{
					pAttributes->health += std::min(50, 100 - pAttributes->health);
					statsCounter += std::min(50, 100 - pAttributes->health) / 5;
					inventory[y][x] = 1;
					std::cout << "Used mana potion" << std::endl;
					break;
				}
			}
			else
			{
				std::cout << "No item found" << std::endl;
			}
		}
	}
}


