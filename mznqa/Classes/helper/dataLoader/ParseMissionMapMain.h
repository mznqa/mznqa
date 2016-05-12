/*!
 * \file	Classes\helper\dataLoader\ParseMissionMapMain.h
 *
 * \brief	������ ParseMissionMapMain
 */
#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_HELPER_DATALOADER_PARSEMISSIONMAPMAIN_H_
#define MZNQA_CLASSES_HELPER_DATALOADER_PARSEMISSIONMAPMAIN_H_

#include <vector>

#include "logic/gameObject/map/MapNode.h"

/*!
 * \class	ParseMissionMapMain
 *
 * \brief	���ڽ������ߵ�ͼ
 *
 */
class ParseMissionMapMain
{
private:

	/*!
	 * \fn	ParseMissionMapMain::ParseMissionMapMain();
	 *
	 * \brief	���صĹ��캯��
	 *
	 */
	ParseMissionMapMain();

	/*!
	 * \fn	ParseMissionMapMain::ParseMissionMapMain(const ParseMissionMapMain &parseMissionMapMain);
	 *
	 * \brief	���صĿ������캯��
	 *
	 */
	ParseMissionMapMain(const ParseMissionMapMain &parseMissionMapMain);

	/*!
	 * \fn	ParseMissionMapMain& ParseMissionMapMain::operator=(const ParseMissionMapMain &parseMissionMapMain);
	 *
	 * \brief	���صĿ�����ֵ�����
	 *
	 */
	ParseMissionMapMain& operator=(const ParseMissionMapMain &parseMissionMapMain);
public:

	/*!
	 * \fn	ParseMissionMapMain::~ParseMissionMapMain();
	 *
	 * \brief	��������
	 *
	 */
	~ParseMissionMapMain();

	/*!
	 * \fn	static bool ParseMissionMapMain::parse(const char *const data);
	 *
	 * \brief	ִ�н���
	 *
	 * \param	data	ָ���ļ�����
	 *
	 * \return	�����Ƿ�����ɹ�
	 */
	static bool parse(const char *const data);

	/*! \brief	�ݴ������� */
	static std::vector<MapNode> bufferMapNodeSet;
	/*! \brief	�ݴ������� */
	static std::vector<std::vector<int>> bufferGraph;
};

#endif