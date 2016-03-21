#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_CARDPARSER_CARDPARSERSKILL_H_
#define MZNQA_CLASSES_CARDPARSER_CARDPARSERSKILL_H_

#include "combatSystem/EffectPQ.h"

class CardParserSkill
{
private:
	int jsonBufferIndex;
public:
	CardParserSkill();
	~CardParserSkill();

	// 创建技能卡数据缓冲区
	int createCardSkillJsonBuffer();

	// 解析技能卡，分析其效果并将其加入效果队列中
	void parseAndPushEffect(EffectPQ &effectPQ, int cardID);

	void test();
};

#endif
