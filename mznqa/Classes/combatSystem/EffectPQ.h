/*!
 * \file	Classes\combatSystem\EffectPQ.h
 *
 * \brief	定义类 EffectAffixes 和类 EffectPQ
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_COMBATSYSTEM_EFFECTPQ_H_
#define MZNQA_CLASSES_COMBATSYSTEM_EFFECTPQ_H_

#include <queue>
#include <functional>
#include <vector>
#include "effect/Effect.h"
#include "card/CardBase.h"

/*!
 * \struct	EffectAffixes
 *
 * \brief	用于推入到效果队列的元素
 *
 */
struct EffectAffixes
{
	/*! \brief	优先级 */
	int level;

	/*! \brief	对应的技能卡id */
	int cardId;

	/*! \brief	指向技能卡 cardId 中的效果的索引 */
	int effectIndex;

	/* \brief	效果的释放者 */
	Effect::Releaser releaser;
	/* \brief	指向技能卡 cardId 中的效果的接收者 */
	Effect::Receiver receiver;
	/* \brief	标识效果在哪个阶段执行 */
	Effect::ExcuteStyle excuteStyle;
	/* \brief	标识效果在第几回合执行 */
	int efRound;

	/*！
	 * \fn	EffectAffixes()
	 *
	 * \brief	默认的构造函数
	 */
	EffectAffixes()
	{

	}

	/*! \brief	无效的优先级 */
	static const int invalidLevelValue = -1;
	/*! \brief	无效的技能卡id */
	static const int invalidCardIdValue = CardBase::invalidID;
	/*! \brief	无效的效果索引 */
	static const int invalidEffectIndexValue = -1;

	/*!
	 * \fn	EffectAffixes(int level, int cardId, int effectIndex)
	 *
	 * \brief	构造函数
	 *
	 * \param	level	   	指定优先级
	 * \param	cardId	   	指定指向的技能卡id
	 * \param	effectIndex	指向指向的效果索引
	 */
	EffectAffixes(int level, int cardId, int effectIndex)
	{
		this->level = level;
		this->cardId = cardId;
		this->effectIndex = effectIndex;
	}

	/*!
	 * \fn	bool operator<(const EffectAffixes &rhs) const
	 *
	 * \brief	<运算符
	 *
	 * \param	rhs	EffectAffixes 实例
	 *
	 * \return	返回优先级的比较结果
	 */
	bool operator<(const EffectAffixes &rhs) const
	{
		return this->level < rhs.level;
	}

	/*!
	 * \fn	bool operator>(const EffectAffixes &rhs) const
	 *
	 * \brief	>运算符
	 *
	 * \param	rhs	EffectAffixes 实例
	 *
	 * \return	返回优先级的比较结果
	 */
	bool operator>(const EffectAffixes &rhs) const
	{
		return this->level > rhs.level;
	}

	/*!
	 * \fn	bool operator== (const EffectAffixes &rhs) const
	 *
	 * \brief	==运算符
	 *
	 * \param	rhs	EffectAffixes 实例
	 *
	 * \return	返回是否相等
	 */
	bool operator == (const EffectAffixes &rhs) const
	{
		return ((this->level == rhs.level) && (this->cardId == rhs.cardId) && (this->effectIndex == rhs.effectIndex));
	}
};

/*!
 * \class	EffectPQ
 *
 * \brief	用于战斗系统的待执行的效果的队列的集合
 *
 */
class EffectPQ
{
private:

	/*! \brief	预定义的空效果 */
	const static EffectAffixes nullEffectAffixes;

	/*! \brief	子队列：角色用效果队列 */
	std::priority_queue<EffectAffixes, std::vector<EffectAffixes>, std::greater<EffectAffixes>> rolePQ;
	/*! \brief	子队列：怪物用效果队列 */
	std::priority_queue<EffectAffixes, std::vector<EffectAffixes>, std::greater<EffectAffixes>> monsterPQ;

public:

	/*!
	 * \enum	EffectLevelInterval
	 *
	 * \brief	分级区间
	 */
	enum EffectLevelInterval
	{
		EffectLevelInterval_Global_Left = 0,	///< 全局-左端点
		EffectLevelInterval_Global_Right = 99,	///< 全局-右端点
		EffectLevelInterval_Before_Left = 100,	///< 战斗前-左端点
		EffectLevelInterval_Before_Right = 199,	///< 战斗前-右端点
		EffectLevelInterval_In_Left = 200,		///< 战斗过程中-左端点
		EffectLevelInterval_In_Right = 299,		///< 战斗过程中-右端点
		EffectLevelInterval_After_Left = 300,	///< 战斗后-左端点
		EffectLevelInterval_After_Right = 399	///< 战斗后-右端点
	};

	/*! \brief	逐回合效果优先级递增值，每回合效果队列中的优先级应减少该值 */
	static const int roundEffectLevel = 1000;

	/*!
	 * \fn	EffectPQ::EffectPQ();
	 *
	 * \brief	构造函数
	 *
	 */
	EffectPQ();

	/*!
	 * \fn	EffectPQ::~EffectPQ();
	 *
	 * \brief	析构函数
	 *
	 */
	~EffectPQ();

	/*!
	 * \fn	void EffectPQ::pushRoleEffectAffixes(EffectAffixes effectAffixes);
	 *
	 * \brief	向角色队列中推送效果
	 *
	 * \param	effectAffixes	待推送的效果实例
	 */
	void pushRoleEffectAffixes(EffectAffixes effectAffixes);

	/*!
	 * \fn	bool EffectPQ::isRoleEffectPQEmpty();
	 *
	 * \brief	判断角色效果队列是否为空
	 *
	 * \return	返回角色效果队列是否为空
	 */
	bool isRoleEffectPQEmpty();

	/*!
	 * \fn	EffectAffixes EffectPQ::getRoleEffectAffixesByInterval(EffectPQ::EffectLevelInterval leftInterval, EffectPQ::EffectLevelInterval rightInterval);
	 *
	 * \brief	从角色队中弹出给定优先级区间内的最小优先级效果实例
	 *
	 * \param	leftInterval 	左优先级区间
	 * \param	rightInterval	右优先级区间
	 *
	 * \return	弹出角色队列中给定优先级区间内的最小优先级效果实例
	 */
	EffectAffixes getRoleEffectAffixesByInterval(EffectPQ::EffectLevelInterval leftInterval, EffectPQ::EffectLevelInterval rightInterval);

	/*!
	 * \fn	void EffectPQ::decreaseRoleEffectLevel();
	 *
	 * \brief	将整个角色队列中的元素逐一递减一个 roundEffectLevel
	 *
	 */
	void decreaseRoleEffectLevel();

	/*!
	 * \fn	int EffectPQ::getRoleEPQLevelMaxByRoundAndInterval(int relRound, EffectPQ::EffectLevelInterval leftInterval, EffectPQ::EffectLevelInterval rightInterval);
	 *
	 * \brief	获取给定相对回合和优先级区间内的当前角色队列中的最大优先级值
	 *
	 * \param	relRound	 	给定相对回合数，0指代当前回合，1则为下回合，以此类推
	 * \param	leftInterval	优先级左端点
	 * \param	rightInterval	优先级右端点
	 *
	 * \return	返回给定相对回合和优先级区间内的当前角色队列中的最大优先级值
	 */
	int getRoleEPQLevelMaxByRoundAndInterval(int relRound, EffectPQ::EffectLevelInterval leftInterval, EffectPQ::EffectLevelInterval rightInterval);

	/*!
	 * \fn	void EffectPQ::popRoleEffectAffixes();
	 *
	 * \brief	弹出整个角色队列中优先级最小的效果
	 *
	 */
	void popRoleEffectAffixes();

	/*!
	 * \fn	void EffectPQ::popRoleEffectAffixes(EffectPQ::EffectLevelInterval leftInterval, EffectPQ::EffectLevelInterval rightInterval);
	 *
	 * \brief	弹出角色队列中给定优先级区间内优先级最小的效果
	 *
	 * \param	leftInterval 	优先级左端点
	 * \param	rightInterval	优先级右端点
	 */
	void popRoleEffectAffixes(EffectPQ::EffectLevelInterval leftInterval, EffectPQ::EffectLevelInterval rightInterval);

	/*!
	 * \fn	void EffectPQ::popRoleEffectAffixes(EffectAffixes effectAffixes);
	 *
	 * \brief	给定角色队列中的某一效果，并将其弹出
	 *
	 * \param	effectAffixes	指定角色队列中的某一效果
	 */
	void popRoleEffectAffixes(EffectAffixes effectAffixes);

	/*!
	 * \fn	void EffectPQ::pushMonsterEffectAffixes(EffectAffixes effectAffixes);
	 *
	 * \brief	向怪物队列中推送效果
	 *
	 * \param	effectAffixes	待推送的效果实例
	 */
	void pushMonsterEffectAffixes(EffectAffixes effectAffixes);

	/*!
	 * \fn	bool EffectPQ::isMonsterEffectPQEmpty();
	 *
	 * \brief	判断怪物效果队列是否为空
	 *
	 * \return	返回怪物效果队列是否为空
	 */
	bool isMonsterEffectPQEmpty();

	/*!
	 * \fn	EffectAffixes EffectPQ::getMonsterEffectAffixesByInterval(EffectPQ::EffectLevelInterval leftInterval, EffectPQ::EffectLevelInterval rightInterval);
	 *
	 * \brief	从怪物队中弹出给定优先级区间内的最小优先级效果实例
	 *
	 * \param	leftInterval 	左优先级区间
	 * \param	rightInterval	右优先级区间
	 *
	 * \return	弹出角色队列中给定优先级区间内的最小优先级效果实例
	 */
	EffectAffixes getMonsterEffectAffixesByInterval(EffectPQ::EffectLevelInterval leftInterval, EffectPQ::EffectLevelInterval rightInterval);

	/*!
	 * \fn	void EffectPQ::decreaseMonsterEffectLevel();
	 *
	 * \brief	将整个怪物队列中的元素逐一递减一个 roundEffectLevel
	 *
	 */
	void decreaseMonsterEffectLevel();

	/*!
	 * \fn	int EffectPQ::getMonsterEPQLevelMaxByRoundAndInterval(int relRound, EffectPQ::EffectLevelInterval leftInterval, EffectPQ::EffectLevelInterval rightInterval);
	 *
	 * \brief	获取给定相对回合和优先级区间内的当前怪物队列中的最大优先级值
	 *
	 * \param	relRound	 	给定相对回合数，0指代当前回合，1则为下回合，以此类推
	 * \param	leftInterval	优先级左端点
	 * \param	rightInterval	优先级右端点
	 *
	 * \return	返回给定相对回合和优先级区间内的当前怪物队列中的最大优先级值
	 */
	int getMonsterEPQLevelMaxByRoundAndInterval(int relRound, EffectPQ::EffectLevelInterval leftInterval, EffectPQ::EffectLevelInterval rightInterval);

	/*!
	 * \fn	void EffectPQ::popMonsterEffectAffixes();
	 *
	 * \brief	弹出整个角色队列中优先级最小的效果
	 *
	 */
	void popMonsterEffectAffixes();

	/*!
	 * \fn	void EffectPQ::popMonsterEffectAffixes(EffectPQ::EffectLevelInterval leftInterval, EffectPQ::EffectLevelInterval rightInterval);
	 *
	 * \brief	弹出怪物队列中给定优先级区间内优先级最小的效果
	 *
	 * \param	leftInterval 	优先级左端点
	 * \param	rightInterval	优先级右端点
	 */
	void popMonsterEffectAffixes(EffectPQ::EffectLevelInterval leftInterval, EffectPQ::EffectLevelInterval rightInterval);

	/*!
	 * \fn	void EffectPQ::popMonsterEffectAffixes(EffectAffixes effectAffixes);
	 *
	 * \brief	给定怪物队列中的某一效果，并将其弹出
	 *
	 * \param	effectAffixes	指定怪物队列中的某一效果
	 */
	void popMonsterEffectAffixes(EffectAffixes effectAffixes);
};

#endif
