#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_COMBATSYSTEM_COMBATSYSTEM_H_
#define MZNQA_CLASSES_COMBATSYSTEM_COMBATSYSTEM_H_

#include "combatSystem/EffectPQ.h"


class CombatSystem
{
public:	
	CombatSystem();
	~CombatSystem();

	
	//ִ��ÿ�غ��ڵ�ȫ�ֲ���
	void executeGlobalOperation();


	//ִ�н�ɫս��ǰ����
	void executeRoleBeforeTheCombatOperation();
	//ִ�н�ɫս��ʱ����
	void excuteRoleInCombatOperation(int cardId);
	//ִ�н�ɫս�������
	void excuteRoleAfterCombatOperation();


	//ִ�й���ս��ǰ����
	void executeMonsterBeforeTheCombatOperator();
	//ִ�й���ս��ʱ����
	void excuteMonsterInCombatOperator(int cardId);
	//ִ�й���ս�������
	void excuteMonsterAfterCombatOperator();

	//ִ��ս��
	void excuteCombat();

	//����ʹ�ÿ���id
	void setUseCardId(const int roleUseCardId, const int monsterUseCardId);

	//�ж��Ƿ����ս��
	bool judgeEndToCombat();

	//���Ե�Ԫ
	void test();

private:
	//ս���غ���
	static int round;

	//Ч������
	EffectPQ epq;

	//��Ž�ɫҪʹ�õļ��ܿ���id
	int roleUseCardId;

	//��Ź���Ҫʹ�õļ��ܿ�id
	int monsterUseCardId;
};


#endif // !MZNQA_CLASSES_COMBATSYSTEM_COMBATSYSTEM_H_

