#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_CARDPARSER_CARDPARSERSKILL_H_
#define MZNQA_CLASSES_CARDPARSER_CARDPARSERSKILL_H_

#include <queue>

#include "combatSystem/EffectPQ.h"

class CardParserSkill
{
private:
	int jsonBufferIndex;
public:
	enum GameEntity{ GameEntity_Role, GameEntity_Monster };

	CardParserSkill();
	~CardParserSkill();

	// 创建技能卡数据缓冲区
	int createCardSkillJsonBuffer();

	// 解析技能卡，获取效果集合
	std::priority_queue<EffectEntity, std::vector<EffectEntity>, std::greater<EffectEntity>> parseEffect(int cardID);

	void test();
};

#endif
