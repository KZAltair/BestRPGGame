#pragma once
#include <string>

struct player_attributes
{
	std::string className;
	int health;
	int mana;
	int strength;
	int agility;
	int intelligence;
	int speed;
};

class Player
{
public:
	Player() = default;
	Player(player_attributes& attributes);
	player_attributes* GetPlayerAttributes() const;
private:

	player_attributes* pAttributes;
};