#include "Enemy.h"
#include <iostream>
#include "Utility.h"

Enemy::Enemy(const enemy_pos& pos)
	:
	pos(pos),
	isAlive(true)
{
	GenerateAttributes();
}

enemy_attributes* Enemy::GetAttributes()
{
	return &eAttributes;
}

int Enemy::Attack(int armorClass, int magicResistance)
{
	int attackType = GenerateRandomNumber(0, 1);
	int diceNumber = GenerateRandomNumber(1, 6);

	if (attackType == 0)
	{
		if ((((eAttributes.agility + eAttributes.strength) * diceNumber) - armorClass) <= 0)
		{
			damage = 0;
		}
		else
		{
			damage = ((eAttributes.agility + eAttributes.strength) * diceNumber) - armorClass;
		}
		
		std::cout << "Regular attack by " << damage << std::endl;
	}
	else if (attackType == 1 && eAttributes.mana > eAttributes.manaSpellCost)
	{
		if ((((eAttributes.intelligence + eAttributes.speed) * diceNumber) - magicResistance) <= 0)
		{
			damage = 0;
		}
		else
		{
			damage = ((eAttributes.intelligence + eAttributes.speed) * diceNumber) - magicResistance;
		}
		
		if (eAttributes.mana > 0)
		{
			eAttributes.mana -= eAttributes.manaSpellCost;
		}
		std::cout << "Magic attack by " << damage << std::endl;
	}

	return damage;
}

void Enemy::GenerateAttributes()
{
	int enemytype = GenerateRandomNumber(0, 1);
	if (enemytype == 0)
	{
		eAttributes.name = "RottedRat";
		eAttributes.agility = 7;
		eAttributes.health = 30;
		eAttributes.intelligence = 2;
		eAttributes.mana = 10;
		eAttributes.manaSpellCost = 10;
		eAttributes.speed = 50;
		eAttributes.strength = 2;
		eAttributes.armorClass = 10;
		eAttributes.magicResistance = 10;
		eAttributes.levelModifier = 2;
		eAttributes.exp = 20 * eAttributes.levelModifier;
		isAlive = true;
	}
	else if (enemytype == 1)
	{
		eAttributes.name = "Bandit";
		eAttributes.agility = 5;
		eAttributes.health = 70;
		eAttributes.intelligence = 5;
		eAttributes.mana = 40;
		eAttributes.manaSpellCost = 20;
		eAttributes.speed = 10;
		eAttributes.strength = 6;
		eAttributes.armorClass = 10;
		eAttributes.magicResistance = 20;
		eAttributes.levelModifier = 3;
		eAttributes.exp = 50 * eAttributes.levelModifier;
		isAlive = true;
	}
}

enemy_pos Enemy::GetEnemyPos() const
{
	return pos;
}

void Enemy::TakeDamage(int damage)
{
		if (isAlive)
		{
			eAttributes.health -= damage;
			std::cout << eAttributes.name << " was hit by " << damage << " damage" << std::endl;
			if (eAttributes.health < 0)
			{
				std::cout << eAttributes.name << " screams fall down to the ground bleeding" << std::endl;
				std::cout << eAttributes.name << " is dead." << std::endl;
				isAlive = false;
			}
		}
}

bool Enemy::IsAlive() const
{
	return isAlive;
}

int Enemy::GenerateLoot()
{
	return GenerateRandomNumber(1,3);
}
