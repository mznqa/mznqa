#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_COMBATSYSTEM_COMBATSYSTEM_H_
#define MZNQA_CLASSES_COMBATSYSTEM_COMBATSYSTEM_H_

#include "combatSystem/EffectPQ.h"


class CombatSystem
{
public:	
	~CombatSystem();

	static CombatSystem* getInstance();

	//ִ��ս���غ��ڵ�ȫ������
	void executeGlobalEffect();


	//ִ�н�ɫ����Ч��
	void executeRoleBeforeTheCombatEffect();
	//ִ�н�ɫս��ʱЧ��
	void excuteRoleInCombatEffect(int cardId);
	//ִ�н�ɫս�����Ч��
	void excuteRoleAfterCombatEffect();


	//ִ�й������Ч��
	void executeMonsterBeforeTheCombatEffect();
	//ִ�й���ս��ʱ��Ч��
	void excuteMonsterInCombatEffect(int cardId);
	//ִ�й���ս�����Ч��
	void excuteMonsterAfterCombatEffect();


	//ִ��ս��
	void excuteCombat(int cardId);

	void test();

private:

	CombatSystem() {};
	CombatSystem & operator =(const CombatSystem &combatSystem);

	//ս���غ���
	static int round;

	//Ч������
	EffectPQ epq;
};


#endif // !MZNQA_CLASSES_COMBATSYSTEM_COMBATSYSTEM_H_

