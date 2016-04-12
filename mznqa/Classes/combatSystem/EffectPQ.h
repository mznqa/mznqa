#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_COMBATSYSTEM_EFFECTPQ_H_
#define MZNQA_CLASSES_COMBATSYSTEM_EFFECTPQ_H_

#include <queue>
#include <functional>
#include <vector>

struct EffectAffixes
{

	//效果优先级
	int level;

	//技能卡的ID
	int cardId;

	//效果索引下标
	int effectIndex;

	//无效的效果优先级值
	static const int invalidLevelValue = -1;
	//无效的技能卡id值
	static const int invalidCardIdValue = -1;
	//无效的效果索引下标值
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

	//回合效果优先级值，每回合效果队列中的优先级应减少该值
	static const int roundEffectLevel = 1000;

	//条件效果所对应的函数索引分界值
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

	//角色效果队列
	std::priority_queue<EffectAffixes, std::vector<EffectAffixes>, std::greater<EffectAffixes>> rolePQ;
	//怪物效果队列
	std::priority_queue<EffectAffixes, std::vector<EffectAffixes>, std::greater<EffectAffixes>> monsterPQ;

public:
	

	EffectPQ();
	~EffectPQ();
	
	//向角色效果队列，推送一个效果附加属性
	void pushRoleEffectAffixes(EffectAffixes effectAffixes);

	//判断角色效果队列是否为空
	bool isRoleEffectPQEmpty();

	//通过效果优先级区间，获取指定区间内的角色可用效果附加属性
	EffectAffixes getRoleEffectAffixesByInterval(EffectAffixes::EffectLevelInterval leftInterval, EffectAffixes::EffectLevelInterval rightInterval);

	//向角色效果队列的每个效果附加属性的优先级减少一个回合优先级
	void decreaseRoleEffectLevel();

	// 根据给定相对回合数和优先级区间，获取指定区间内的角色效果最大优先级
	int getRoleEPQLevelMaxByRoundAndInterval(int relRound,EffectAffixes::EffectLevelInterval leftInterval,EffectAffixes::EffectLevelInterval rightInterval);

	//对角色效果队列，弹出一个效果附加属性
	void popRoleEffectAffixes();

	//根据指定区间，对角色效果队列，弹出一个效果附加属性
	void popRoleEffectAffixes(EffectAffixes::EffectLevelInterval leftInterval, EffectAffixes::EffectLevelInterval rightInterval);
	//对角色效果队列，弹出指定的效果附加属性
	void popRoleEffectAffixes(EffectAffixes effectAffixes);


	//向怪物效果队列，推送一个效果附加属性
	void pushMonsterEffectAffixes(EffectAffixes effectAffixes);

	//判断怪物效果队列是否为空
	bool isMonsterEffectPQEmpty();

	//通过效果优先级区间，获取指定区间内的怪物可用效果附加属性
	EffectAffixes getMonsterEffectAffixesByInterval(EffectAffixes::EffectLevelInterval leftInterval, EffectAffixes::EffectLevelInterval rightInterval);

	//向角色效果队列的每个效果附加属性的优先级减少一个回合优先级
	void decreaseMonsterEffectLevel();

	// 根据给定相对回合数和优先级区间，获取指定区间内的怪物效果最大优先级
	int getMonsterEPQLevelMaxByRoundAndInterval(int relRound, EffectAffixes::EffectLevelInterval leftInterval, EffectAffixes::EffectLevelInterval rightInterval);

	//向怪物效果队列，弹出一个效果附加属性
	void popMonsterEffectAffixes();

	//根据指定区间，对怪物效果队列，弹出一个效果附加属性
	void popMonsterEffectAffixes(EffectAffixes::EffectLevelInterval leftInterval, EffectAffixes::EffectLevelInterval rightInterval);
	//对怪物效果队列，弹出指定的效果附加属性
	void popMonsterEffectAffixes(EffectAffixes effectAffixes);

	
};

#endif
