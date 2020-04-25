#pragma once
#include <string>
#include <vector>

struct player_attributes
{
	std::string className;
	int health;
	int mana;
	int strength;
	int agility;
	int intelligence;
	int speed;
	int manaSpellCost;
	int MagicResistance;
	int ArmorClass;
	int curExp;
	int expModifier;
	int expForNextLevel;
	int Level;
};

class Player
{
public:
	Player() = default;
	Player(player_attributes& attributes);
	player_attributes* GetPlayerAttributes() const;
	void TakeDamage(int damage);
	int Attack(int armorClass, int magicResistance, int attacktype);
	void AddExperience(class Enemy& e);
	void LevelUp();
	bool IsAlive() const;
	void DisplayStatsBar();
	void DisplayInventory();
	void UseItem(char in);
private:
	void InitInventory();
private:
	player_attributes* pAttributes;
	bool isAlive = false;
public:
	int posX = 0;
	int posY = 0;
	bool viewInventory = false;
private:
	bool levelUpDone = false;
	int statsCounter = 20;
	static constexpr int invSizeX = 10;
	static constexpr int invSizeY = 10;
	int inventory[invSizeX][invSizeY];

};