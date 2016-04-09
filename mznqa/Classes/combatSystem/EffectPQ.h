#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_COMBATSYSTEM_EFFECTPQ_H_
#define MZNQA_CLASSES_COMBATSYSTEM_EFFECTPQ_H_

#include <queue>
#include <functional>
#include <vector>

struct EffectEntity
{

	//效果优先级
	int level;

	//效果函数指针
	int cardId;

	//效果索引
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

	//角色效果队列
	std::priority_queue<EffectEntity, std::vector<EffectEntity>, std::greater<EffectEntity>> rolePQ;
	//怪物效果队列
	std::priority_queue<EffectEntity, std::vector<EffectEntity>, std::greater<EffectEntity>> monsterPQ;

public:
	EffectPQ();
	~EffectPQ();
	
	//添加角色技能效果
	void pushRoleEffect(EffectEntity effect);
	//获取角色下一个技能效果
	EffectEntity getRoleNextEffect();
	//判断角色效果队列是否为空
	bool isRoleEffectPQEmpty();
	//向角色效果队列的每个效果分级减少100
	void decreaseRoleEffectLevel();
	// 根据给定相对回合数获取当前角色最大优先级
	int getRoleEPQLevelMaxByRound(int relRound);
	//删除角色技能效果
	void popRoleEffect();


	//添加怪物技能效果
	void pushMonsterEffect(EffectEntity effect);
	//获取怪物下一个技能效果
	EffectEntity getMonsterNextEffect();
	//判断怪物效果队列是否为空
	bool isMonsterEffectPQEmpty();
	//向怪物效果队列的每个效果分级减少100
	void decreaseMonsterEffectLevel();
	// 根据给定相对回合数获取当前怪物最大优先级
	int getMonsterEPQLevelMaxByRound(int relRound);
	//删除怪物技能效果
	void popMonsterEffect();

	
};

#endif
