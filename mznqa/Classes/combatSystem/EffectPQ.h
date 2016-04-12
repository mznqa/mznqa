#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_COMBATSYSTEM_EFFECTPQ_H_
#define MZNQA_CLASSES_COMBATSYSTEM_EFFECTPQ_H_

#include <queue>
#include <functional>
#include <vector>

struct EffectAffixes
{

	//Ч�����ȼ�
	int level;

	//���ܿ���ID
	int cardId;

	//Ч�������±�
	int effectIndex;

	//��Ч��Ч�����ȼ�ֵ
	static const int invalidLevelValue = -1;
	//��Ч�ļ��ܿ�idֵ
	static const int invalidCardIdValue = -1;
	//��Ч��Ч�������±�ֵ
	static const int invalidEffectIndexValue = -1;
	
	enum EffectLevelInterval
	{
		EffectLevelInterval_Global_Left = 0,
		EffectLevelInterval_Global_Right = 99,
		EffectLevelInterval_Before_Left = 100,
		EffectLevelInterval_Before_Right = 199,
		EffectLevelInterval_In_Left = 200,
		EffectLevelInterval_In_Right = 299,
		EffectLevelInterval_After_Left = 300,
		EffectLevelInterval_After_Right = 399
	};

	//�غ�Ч�����ȼ�ֵ��ÿ�غ�Ч�������е����ȼ�Ӧ���ٸ�ֵ
	static const int roundEffectLevel = 1000;

	//����Ч������Ӧ�ĺ��������ֽ�ֵ
	static const int conditionEffectDivision = 2000;
	
	EffectAffixes(int level,int cardId,int effectIndex)
	{
		this->level = level;
		this->cardId = cardId;
		this->effectIndex = effectIndex;
	}

	bool operator<(const EffectAffixes &rhs) const
	{
		return this->level < rhs.level;
	}

	bool operator>(const EffectAffixes &rhs) const
	{
		return this->level > rhs.level;
	}

	bool operator == (const EffectAffixes &rhs) const
	{
		return ((this->level == rhs.level) && (this->cardId == rhs.cardId) && (this->effectIndex == rhs.effectIndex));
	}
};


class EffectPQ
{
private:

	const static EffectAffixes nullEffectAffixes;

	//��ɫЧ������
	std::priority_queue<EffectAffixes, std::vector<EffectAffixes>, std::greater<EffectAffixes>> rolePQ;
	//����Ч������
	std::priority_queue<EffectAffixes, std::vector<EffectAffixes>, std::greater<EffectAffixes>> monsterPQ;

public:
	

	EffectPQ();
	~EffectPQ();
	
	//���ɫЧ�����У�����һ��Ч����������
	void pushRoleEffectAffixes(EffectAffixes effectAffixes);

	//�жϽ�ɫЧ�������Ƿ�Ϊ��
	bool isRoleEffectPQEmpty();

	//ͨ��Ч�����ȼ����䣬��ȡָ�������ڵĽ�ɫ����Ч����������
	EffectAffixes getRoleEffectAffixesByInterval(EffectAffixes::EffectLevelInterval leftInterval, EffectAffixes::EffectLevelInterval rightInterval);

	//���ɫЧ�����е�ÿ��Ч���������Ե����ȼ�����һ���غ����ȼ�
	void decreaseRoleEffectLevel();

	// ���ݸ�����Իغ��������ȼ����䣬��ȡָ�������ڵĽ�ɫЧ��������ȼ�
	int getRoleEPQLevelMaxByRoundAndInterval(int relRound,EffectAffixes::EffectLevelInterval leftInterval,EffectAffixes::EffectLevelInterval rightInterval);

	//�Խ�ɫЧ�����У�����һ��Ч����������
	void popRoleEffectAffixes();

	//����ָ�����䣬�Խ�ɫЧ�����У�����һ��Ч����������
	void popRoleEffectAffixes(EffectAffixes::EffectLevelInterval leftInterval, EffectAffixes::EffectLevelInterval rightInterval);
	//�Խ�ɫЧ�����У�����ָ����Ч����������
	void popRoleEffectAffixes(EffectAffixes effectAffixes);


	//�����Ч�����У�����һ��Ч����������
	void pushMonsterEffectAffixes(EffectAffixes effectAffixes);

	//�жϹ���Ч�������Ƿ�Ϊ��
	bool isMonsterEffectPQEmpty();

	//ͨ��Ч�����ȼ����䣬��ȡָ�������ڵĹ������Ч����������
	EffectAffixes getMonsterEffectAffixesByInterval(EffectAffixes::EffectLevelInterval leftInterval, EffectAffixes::EffectLevelInterval rightInterval);

	//���ɫЧ�����е�ÿ��Ч���������Ե����ȼ�����һ���غ����ȼ�
	void decreaseMonsterEffectLevel();

	// ���ݸ�����Իغ��������ȼ����䣬��ȡָ�������ڵĹ���Ч��������ȼ�
	int getMonsterEPQLevelMaxByRoundAndInterval(int relRound, EffectAffixes::EffectLevelInterval leftInterval, EffectAffixes::EffectLevelInterval rightInterval);

	//�����Ч�����У�����һ��Ч����������
	void popMonsterEffectAffixes();

	//����ָ�����䣬�Թ���Ч�����У�����һ��Ч����������
	void popMonsterEffectAffixes(EffectAffixes::EffectLevelInterval leftInterval, EffectAffixes::EffectLevelInterval rightInterval);
	//�Թ���Ч�����У�����ָ����Ч����������
	void popMonsterEffectAffixes(EffectAffixes effectAffixes);

	
};

#endif
