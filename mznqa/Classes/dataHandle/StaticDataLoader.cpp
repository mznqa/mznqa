/*!
 * \file	Classes\dataHandle\StaticDataLoader.cpp
 *
 * \brief	定义类 StaticDataLoader
 */

#pragma execution_character_set("utf-8")

#include "dataHandle/StaticDataLoader.h"

#include "cocos2d.h"

#include "engine/FileController.h"
#include "dataHandle/CharBufferArea.h"
#include "dataHandle/ParserCardSkill.h"
#include "filePath/DataFilePath.h"
#include "staticData/CardSet.h"

void StaticDataLoader::loadStaticDataCardSkillSet()
{
	CharBufferArea::BufferIndex bufferIndex = CharBufferArea::BufferIndex_Static_CardSkillSet;

	cocos2d::log("[information] 开始缓存文件数据：静态数据：技能卡集合...");
	CharBufferArea::Instance()->createBuffer(
		bufferIndex,
		FileController::Instance()->getCharBufferFromFile(STATIC_DATA_CARDSKILLSET)
		);
	if (CharBufferArea::Instance()->getBufferByIndex(bufferIndex) == nullptr)
		cocos2d::log("[error] 缓存静态数据：技能卡集合失败");
	else
		cocos2d::log("[information] 成功缓存：静态数据：技能卡集合");

	//////////////////////////////////////////////////////////////////////////

	cocos2d::log("[information] 开始解析：静态数据：技能卡集合...");
	ParserCardSkill parserCardSkill;
	parserCardSkill.parse();
	if (ParserCardSkill::cardSkillSetTemp.empty() == true)
		cocos2d::log("[error] 解析失败：静态数据：技能卡集合");
	else
	{
		CardSet::Instance()->loadCardSkillSet(ParserCardSkill::cardSkillSetTemp);
		cocos2d::log("[information] 完成解析：静态数据：技能卡集合");
	}

	//////////////////////////////////////////////////////////////////////////

	cocos2d::log("[information] 开始释放缓存：静态数据：技能卡集合...");
	CharBufferArea::Instance()->releaseBufferByIndex(bufferIndex);
	cocos2d::log("[information] 成功释放缓存：静态数据：技能卡集合");
}