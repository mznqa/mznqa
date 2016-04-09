#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_COMBATSYSTEM_COMBATSYSTEM_H_
#define MZNQA_CLASSES_COMBATSYSTEM_COMBATSYSTEM_H_

#include "combatSystem/EffectPQ.h"


class CombatSystem
{
public:	
	CombatSystem();
	~CombatSystem();

	
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
	void excuteCombat(int roleUseCardId, int monsterUseCardId);

	//��ӽ�ɫʹ�õļ��ܿ�ID
	void pushRoleUseCardId(int useCardId);

	//��ӹ���ʹ�õļ��ܿ�ID
	void pushMonsterUseCardId(int useCardId);

	//ɾ����ɫʹ�õļ��ܿ�ID
	void popRoleUseCardId();

	//ɾ������ʹ�õļ��ܿ�ID
	void popMonsterUseCardId();


	void test();

private:
	//ս���غ���
	static int round;

	//Ч������
	EffectPQ epq;

	//��Ž�ɫҪʹ�õļ��ܿ���id
	std::queue<int> roleUseCardId;

	//��Ź���Ҫʹ�õļ��ܿ�id
	std::queue<int> monsterUseCardId;
};


#endif // !MZNQA_CLASSES_COMBATSYSTEM_COMBATSYSTEM_H_

