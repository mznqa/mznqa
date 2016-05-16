/*!
 * \file	Classes\helper\random\RandomGenerator.h
 *
 * \brief	������ RandomGenerator
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_HELPER_RANDOM_RANDOMGENERATOR_H_
#define MZNQA_CLASSES_HELPER_RANDOM_RANDOMGENERATOR_H_

#include <random>

/*!
 * \class	RandomGenerator
 *
 * \brief	[����]�����������
 *
 */
class RandomGenerator
{
private:

	/*!
	 * \fn	RandomGenerator::RandomGenerator();
	 *
	 * \brief	���صĹ��캯��
	 *
	 */
	RandomGenerator();

	/*!
	 * \fn	RandomGenerator::RandomGenerator(const RandomGenerator &randomGenerator);
	 *
	 * \brief	���صĿ������캯��
	 *
	 */
	RandomGenerator(const RandomGenerator &randomGenerator);

	/*!
	 * \fn	RandomGenerator& RandomGenerator::operator=(const RandomGenerator &randomGenerator);
	 *
	 * \brief	���صĿ�����ֵ�����
	 *
	 */
	RandomGenerator& operator=(const RandomGenerator &randomGenerator);

	/*! \brief	�ڽ������������ */
	static std::default_random_engine randomEngine;

public:

	/*!
	 * \fn	RandomGenerator::~RandomGenerator();
	 *
	 * \brief	��������
	 *
	 */
	~RandomGenerator();

	/*!
	 * \fn	static RandomGenerator* RandomGenerator::Instance();
	 *
	 * \brief	��ȡ����
	 *
	 */
	static RandomGenerator* Instance();

	/*!
	 * \fn	int RandomGenerator::getRandomNumber(int min, int max);
	 *
	 * \brief	��ȡָ����Χ�ڵ������
	 *
	 * \param	min	ָ����Χ��Сֵ
	 * \param	max	ָ����Χ���ֵ
	 *
	 */
	int getRandomNumber(int min, int max);
};

#endif
