#pragma once
#include <string>

struct enemy_attributes
{
	std::string name;
	int health;
	int mana;
	int strength;
	int agility;
	int intelligence;
	int speed;
	int manaSpellCost;
	int armorClass;
	int magicResistance;
};

struct enemy_pos
{
	int x;
	int y;
};

class Enemy
{
public:
	Enemy() = default;
	Enemy(const enemy_pos& pos);
	enemy_attributes* GetAttributes();
	int Attack(int armorClass, int magicResistance);
	void GenerateAttributes();
	enemy_pos GetEnemyPos() const;
	void TakeDamage(int damage);
	bool IsAlive() const;
private:
	enemy_attributes eAttributes;
	enemy_pos pos;
	int damage = 0;
	bool isAlive = false;
};