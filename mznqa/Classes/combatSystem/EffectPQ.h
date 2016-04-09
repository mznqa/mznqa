#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_COMBATSYSTEM_EFFECTPQ_H_
#define MZNQA_CLASSES_COMBATSYSTEM_EFFECTPQ_H_

#include <queue>
#include <functional>
#include <vector>

struct EffectEntity
{

	//Ч�����ȼ�
	int level;

	//Ч������ָ��
	int cardId;

	//Ч������
	int effectIndex;
	
	EffectEntity(int level,int cardId,int effectIndex)
	{
		this->level = level;
		this->cardId = cardId;
		this->effectIndex = effectIndex;
	}

	bool operator<(const EffectEntity &rhs) const
	{
		return this->level < rhs.level;
	}

	bool operator>(const EffectEntity &rhs) const
	{
		return this->level > rhs.level;
	}
};



class EffectPQ
{
private:

	//��ɫЧ������
	std::priority_queue<EffectEntity, std::vector<EffectEntity>, std::greater<EffectEntity>> rolePQ;
	//����Ч������
	std::priority_queue<EffectEntity, std::vector<EffectEntity>, std::greater<EffectEntity>> monsterPQ;

public:
	EffectPQ();
	~EffectPQ();
	
	//��ӽ�ɫ����Ч��
	void pushRoleEffect(EffectEntity effect);
	//��ȡ��ɫ��һ������Ч��
	EffectEntity getRoleNextEffect();
	//�жϽ�ɫЧ�������Ƿ�Ϊ��
	bool isRoleEffectPQEmpty();
	//���ɫЧ�����е�ÿ��Ч���ּ�����100
	void decreaseRoleEffectLevel();
	// ���ݸ�����Իغ�����ȡ��ǰ��ɫ������ȼ�
	int getRoleEPQLevelMaxByRound(int relRound);
	//ɾ����ɫ����Ч��
	void popRoleEffect();


	//��ӹ��＼��Ч��
	void pushMonsterEffect(EffectEntity effect);
	//��ȡ������һ������Ч��
	EffectEntity getMonsterNextEffect();
	//�жϹ���Ч�������Ƿ�Ϊ��
	bool isMonsterEffectPQEmpty();
	//�����Ч�����е�ÿ��Ч���ּ�����100
	void decreaseMonsterEffectLevel();
	// ���ݸ�����Իغ�����ȡ��ǰ����������ȼ�
	int getMonsterEPQLevelMaxByRound(int relRound);
	//ɾ�����＼��Ч��
	void popMonsterEffect();

	
};

#endif
