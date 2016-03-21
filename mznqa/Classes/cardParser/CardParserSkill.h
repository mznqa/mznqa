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

	// �������ܿ����ݻ�����
	int createCardSkillJsonBuffer();

	// �������ܿ���������Ч�����������Ч��������
	void parseAndPushEffect(EffectPQ &effectPQ, int cardID);

	void test();
};

#endif
