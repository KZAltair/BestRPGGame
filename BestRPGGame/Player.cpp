#include "Player.h"
#include <iostream>
#include "Utility.h"

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

bool Player::IsAlive() const
{
	return isAlive;
}


