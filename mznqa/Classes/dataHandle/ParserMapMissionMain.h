/*!
 * \file	Classes\dataHandle\ParserMapMissionMain.h
 *
 * \brief	������ ParserMapMissionMain
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_DATAHANDLE_PARSERMAPMISSIONMAIN_H_
#define MZNQA_CLASSES_DATAHANDLE_PARSERMAPMISSIONMAIN_H_

#include <vector>

#include "map/MissionMap.h"

/*!
 * \class	ParserMapMissionMain
 *
 * \brief	���ڽ������������ͼ����
 *
 */
class ParserMapMissionMain
{
private:
public:

	/*!
	 * \fn	ParserMapMissionMain::ParserMapMissionMain()
	 *
	 * \brief	���캯��
	 *
	 */
	ParserMapMissionMain()
	{
	}

	/*!
	 * \fn	ParserMapMissionMain::~ParserMapMissionMain()
	 *
	 * \brief	��������
	 *
	 */
	~ParserMapMissionMain()
	{
	}

	/*!
	 * \fn	void ParserMapMissionMain::parse();
	 *
	 * \brief	����
	 *
	 */
	void parse();

	/*! \brief	������ʱ��ŵ����������ͼ���� */
	static std::vector<MissionMap> mainMissionMapSetTemp;
};

#endif
