/*!
 * \file	Classes\helper\dataLoader\ParseMissionMapMain.h
 *
 * \brief	定义类 ParseMissionMapMain
 */
#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_HELPER_DATALOADER_PARSEMISSIONMAPMAIN_H_
#define MZNQA_CLASSES_HELPER_DATALOADER_PARSEMISSIONMAPMAIN_H_

#include <vector>

#include "logic/gameObject/map/MapNode.h"

/*!
 * \class	ParseMissionMapMain
 *
 * \brief	由于解析主线地图
 *
 */
class ParseMissionMapMain
{
private:

	/*!
	 * \fn	ParseMissionMapMain::ParseMissionMapMain();
	 *
	 * \brief	隐藏的构造函数
	 *
	 */
	ParseMissionMapMain();

	/*!
	 * \fn	ParseMissionMapMain::ParseMissionMapMain(const ParseMissionMapMain &parseMissionMapMain);
	 *
	 * \brief	隐藏的拷贝构造函数
	 *
	 */
	ParseMissionMapMain(const ParseMissionMapMain &parseMissionMapMain);

	/*!
	 * \fn	ParseMissionMapMain& ParseMissionMapMain::operator=(const ParseMissionMapMain &parseMissionMapMain);
	 *
	 * \brief	隐藏的拷贝赋值运算符
	 *
	 */
	ParseMissionMapMain& operator=(const ParseMissionMapMain &parseMissionMapMain);
public:

	/*!
	 * \fn	ParseMissionMapMain::~ParseMissionMapMain();
	 *
	 * \brief	析构函数
	 *
	 */
	~ParseMissionMapMain();

	/*!
	 * \fn	static bool ParseMissionMapMain::parse(const char *const data);
	 *
	 * \brief	执行解析
	 *
	 * \param	data	指定文件缓存
	 *
	 * \return	返回是否解析成功
	 */
	static bool parse(const char *const data);

	/*! \brief	暂存解析结果 */
	static std::vector<MapNode> bufferMapNodeSet;
	/*! \brief	暂存解析结果 */
	static std::vector<std::vector<int>> bufferGraph;
};

#endif