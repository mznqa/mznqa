/*!
 * \file	Classes\helper\random\RandomGenerator.h
 *
 * \brief	定义类 RandomGenerator
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_HELPER_RANDOM_RANDOMGENERATOR_H_
#define MZNQA_CLASSES_HELPER_RANDOM_RANDOMGENERATOR_H_

#include <random>

/*!
 * \class	RandomGenerator
 *
 * \brief	[单例]随机数发生器
 *
 */
class RandomGenerator
{
private:

	/*!
	 * \fn	RandomGenerator::RandomGenerator();
	 *
	 * \brief	隐藏的构造函数
	 *
	 */
	RandomGenerator();

	/*!
	 * \fn	RandomGenerator::RandomGenerator(const RandomGenerator &randomGenerator);
	 *
	 * \brief	隐藏的拷贝构造函数
	 *
	 */
	RandomGenerator(const RandomGenerator &randomGenerator);

	/*!
	 * \fn	RandomGenerator& RandomGenerator::operator=(const RandomGenerator &randomGenerator);
	 *
	 * \brief	隐藏的拷贝赋值运算符
	 *
	 */
	RandomGenerator& operator=(const RandomGenerator &randomGenerator);

	/*! \brief	内建随机数发生器 */
	static std::default_random_engine randomEngine;

public:

	/*!
	 * \fn	RandomGenerator::~RandomGenerator();
	 *
	 * \brief	析构函数
	 *
	 */
	~RandomGenerator();

	/*!
	 * \fn	static RandomGenerator* RandomGenerator::Instance();
	 *
	 * \brief	获取单例
	 *
	 */
	static RandomGenerator* Instance();

	/*!
	 * \fn	int RandomGenerator::getRandomNumber(int min, int max);
	 *
	 * \brief	获取指定范围内的随机数
	 *
	 * \param	min	指定范围最小值
	 * \param	max	指定范围最大值
	 *
	 */
	int getRandomNumber(int min, int max);
};

#endif
