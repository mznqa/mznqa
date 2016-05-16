/*!
 * \file	Classes\helper\random\RandomGenerator.cpp
 *
 * \brief	∂®“Â¿‡ RandomGenerator
 */
#pragma execution_character_set("utf-8")

#include "helper/random/RandomGenerator.h"

#include <ctime>

std::default_random_engine RandomGenerator::randomEngine;

RandomGenerator::RandomGenerator()
{
	randomEngine.seed(time(NULL));
}

RandomGenerator::~RandomGenerator()
{
}

RandomGenerator* RandomGenerator::Instance()
{
	static RandomGenerator instance;
	return &instance;
}

int RandomGenerator::getRandomNumber(int min, int max)
{
	int findMin, findMax;
	if (min < max)
	{
		findMin = min;
		findMax = max;
	}
	else if (min == max)
		return min;
	else if (min > max)
	{
		findMin = max;
		findMax = min;
	}

	std::uniform_int_distribution<int> distribution(findMin, findMax);
	return distribution(randomEngine);
}