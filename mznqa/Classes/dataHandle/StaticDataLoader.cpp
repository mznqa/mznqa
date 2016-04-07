/*!
 * \file	Classes\dataHandle\StaticDataLoader.cpp
 *
 * \brief	������ StaticDataLoader
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

	cocos2d::log("[information] ��ʼ�����ļ����ݣ���̬���ݣ����ܿ�����...");
	CharBufferArea::Instance()->createBuffer(
		bufferIndex,
		FileController::Instance()->getCharBufferFromFile(STATIC_DATA_CARDSKILLSET)
		);
	if (CharBufferArea::Instance()->getBufferByIndex(bufferIndex) == nullptr)
		cocos2d::log("[error] ���澲̬���ݣ����ܿ�����ʧ��");
	else
		cocos2d::log("[information] �ɹ����棺��̬���ݣ����ܿ�����");

	//////////////////////////////////////////////////////////////////////////

	cocos2d::log("[information] ��ʼ��������̬���ݣ����ܿ�����...");
	ParserCardSkill parserCardSkill;
	parserCardSkill.parse();
	if (ParserCardSkill::cardSkillSetTemp.empty() == true)
		cocos2d::log("[error] ����ʧ�ܣ���̬���ݣ����ܿ�����");
	else
	{
		CardSet::Instance()->loadCardSkillSet(ParserCardSkill::cardSkillSetTemp);
		cocos2d::log("[information] ��ɽ�������̬���ݣ����ܿ�����");
	}

	//////////////////////////////////////////////////////////////////////////

	cocos2d::log("[information] ��ʼ�ͷŻ��棺��̬���ݣ����ܿ�����...");
	CharBufferArea::Instance()->releaseBufferByIndex(bufferIndex);
	cocos2d::log("[information] �ɹ��ͷŻ��棺��̬���ݣ����ܿ�����");
}