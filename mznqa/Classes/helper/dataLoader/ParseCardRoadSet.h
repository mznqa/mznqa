/*!
 * \file	Classes\helper\dataLoader\ParseCardRoadSet.h
 *
 * \brief	������ ParseCardRoadSet
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_HELPER_DATALOADER_PARSECARDROADSET_H_
#define MZNQA_CLASSES_HELPER_DATALOADER_PARSECARDROADSET_H_

#include <vector>
#include <map>

#include "logic/gameObject/card/CardRoad.h"

/*!
 * \class	ParseCardRoadSet
 *
 * \brief	���ڽ������ο�����
 *
 */
class ParseCardRoadSet
{
private:

	/*!
	 * \fn	ParseCardRoadSet::ParseCardRoadSet()
	 *
	 * \brief	���صĹ��캯��
	 *
	 */
	ParseCardRoadSet()
	{
	}

	/*!
	 * \fn	ParseCardRoadSet::ParseCardRoadSet(const ParseCardRoadSet &parseCardRoadSet);
	 *
	 * \brief	���صĿ������캯��
	 *
	 */
	ParseCardRoadSet(const ParseCardRoadSet &parseCardRoadSet);

	/*!
	 * \fn	ParseCardRoadSet& ParseCardRoadSet::operator=(const ParseCardRoadSet &parseCardRoadSet);
	 *
	 * \brief	���صĿ�����ֵ�����
	 *
	 */
	ParseCardRoadSet& operator=(const ParseCardRoadSet &parseCardRoadSet);
public:

	/*!
	 * \fn	ParseCardRoadSet::~ParseCardRoadSet()
	 *
	 * \brief	��������
	 *
	 */
	~ParseCardRoadSet()
	{
	}

	/*!
	 * \fn	static bool ParseCardRoadSet::parse(const char *const data);
	 *
	 * \brief	ִ�н���
	 *
	 * \param	data	ָ���ļ�����
	 *
	 * \return	���ؽ����ɹ����
	 */
	static bool parse(const char *const data);

	/*! \brief	���������� */
	static std::map<int, CardRoad> bufferCardRoadSet;
};

#endif
