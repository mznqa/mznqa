/*!
 * \file	Classes\dataHandle\ParserMapArchives.h
 *
 * \brief	������ ParserMapArchives
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_DATAHANDLE_PARSERMAPARCHIVES_H_
#define MZNQA_CLASSES_DATAHANDLE_PARSERMAPARCHIVES_H_

#include "map/MapNode.h"

/*!
 * \class	ParserMapArchives
 *
 * \brief	���ڽ�����ͼ�浵����
 *
 */
class ParserMapArchives
{
private:
public:

	/*!
	 * \fn	ParserMapArchives::ParserMapArchives();
	 *
	 * \brief	���캯��
	 *
	 */
	ParserMapArchives();

	/*!
	 * \fn	ParserMapArchives::~ParserMapArchives();
	 *
	 * \brief	��������
	 *
	 */
	~ParserMapArchives();

	/*!
	 * \fn	void ParserMapArchives::parse();
	 *
	 * \brief	����
	 *
	 */
	void parse();

	/*! \brief	�ݴ�ȫ�ֵ�ͼ���� */
	static std::vector<MapNode> globalMapArchivesTemp;
};

#endif
