#include "Player.h"
#include <iostream>
#include "Utility.h"
#include "Enemy.h"

Player::Player(player_attributes& attributes)
	:
	pAttributes(&attributes),
	isAlive(true)
{
}

player_attributes* Player::GetPlayerAttributes() const
{
	return pAttributes;
}

void Player::TakeDamage(int damage)
{
	if (isAlive)
	{
		pAttributes->health -= damage;
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
		damage = ((pAttributes->agility + pAttributes->strength) * diceNumber) - armorClass;
	}
	else if (attacktype == 1)
	{
		if (pAttributes->mana < pAttributes->manaSpellCost)
		{
			std::cout << "Insufficient mana." << std::endl;
		}
		else
		{
			damage = ((pAttributes->intelligence + pAttributes->speed) * diceNumber) - magicResistance;
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
			pAttributes->health += 10;
			levelUpDone = true;
		}
		else if (in == 2)
		{
			pAttributes->intelligence += 1;
			pAttributes->MagicResistance += 5;
			pAttributes->mana += 5;
			pAttributes->health += 10;
			levelUpDone = true;
		}
		else if (in == 3)
		{
			pAttributes->agility += 1;
			pAttributes->speed += 4;
			pAttributes->health += 10;
			levelUpDone = true;
		}
		else if (in == 4)
		{
			pAttributes->health += 20;
			levelUpDone = true;
		}
		else if (in == 5)
		{
			pAttributes->mana += 20;
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


