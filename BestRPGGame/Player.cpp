#include "Player.h"

Player::Player(player_attributes& attributes)
	:
	pAttributes(&attributes)
{
}

player_attributes* Player::GetPlayerAttributes() const
{
	return pAttributes;
}


