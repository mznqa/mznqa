#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_COMBATSYSTEM_EFFECTPQ_H_
#define MZNQA_CLASSES_COMBATSYSTEM_EFFECTPQ_H_

#include <queue>

#include "combatSystem/EffectEntity.h"

class EffectPQ
{
private:

	// ��ɫ�ã�Ч������
	std::priority_queue<EffectEntity, std::vector<EffectEntity>, std::less<EffectEntity>> rolePQ;

	// �����ã�Ч������
	std::priority_queue<EffectEntity, std::vector<EffectEntity>, std::less<EffectEntity>> monsterPQ;

public:
	EffectPQ();
	~EffectPQ();

	// ���ɫЧ��������������Ч��
	void pushRoleEffect(EffectEntity effect);
	// ��ȡһ����ɫ��ִ�е�Ч��
	EffectEntity getRoleNextEffect();
	// �жϽ�ɫЧ�������Ƿ�Ϊ��
	bool isRoleEffectPQEmpty();
	// ��ս�ɫЧ������
	void clearRoleEffectPQ();

	// �����Ч��������������Ч��
	void pushMonsterEffect(EffectEntity effect);
	// ��ȡһ�������ִ��Ч��
	EffectEntity getMonsterNextEffect();
	// �жϹ����Ч�������Ƿ�Ϊ��
	bool isMonsterEffectPQEmpty();
	// ��չ�����Ϣ����
	void clearMonsterEffectPQ();

	void test();
};

#endif
