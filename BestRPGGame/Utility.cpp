#include "Utility.h"

int GenerateRandomNumber(int a, int b)
{
	std::random_device device;
	std::mt19937 rng(device());
	std::uniform_int_distribution<int>tempNum(a, b);
	int Result = tempNum(rng);
	return Result;
}
