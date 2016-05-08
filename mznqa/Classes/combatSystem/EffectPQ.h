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
#include <array>
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

	/*！
	* \enum	Releaser
	*
	* \brief	枚举效果的释放者
	*/
	enum Releaser
	{
		Releaser_Monster = 0,	///< 怪物
		Releaser_Role = 1		///< 角色
	};

	/* \brief	效果的释放者 */
	Releaser releaser;
	/* \brief	指向技能卡 cardId 中的效果的接收者 */
	Effect::Receiver receiver;
	/* \brief	标识效果在哪个阶段执行 */
	Effect::ExcuteStyle excuteStyle;
	/* \brief	标识效果在第几回合执行 */
	int efRound = invalidEffectRoundValue;
	
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
	/* \brief	无效的效果回合数 */
	static const int invalidEffectRoundValue = -1;

	/*！
	 * \fn	EffectAffixes(int level, int cardId, int effectIndex, Releaser releaser, Effect::Receiver receiver, Effect::ExcuteStyle excuteStyle, int efRound)
	 *
	 * \brief	构造函数.
	 *
	 * \param	level	   	指定优先级
	 * \param	cardId	   	指定指向的技能卡id
	 * \param	effectIndex	指定指向的效果索引
	 * \param	releaser   	指定指向的效果释放者
	 * \param	receiver   	指定指向的效果接收者
	 * \param	excuteStyle	指定指向的效果执行段
	 * \param	efRound	   	指定指向的效果回合数
	 */
	EffectAffixes(int level, int cardId, int effectIndex, Releaser releaser, Effect::Receiver receiver, Effect::ExcuteStyle excuteStyle, int efRound)
	{
		this->level = level;
		this->cardId = cardId;
		this->effectIndex = effectIndex;
		this->releaser = releaser;
		this->receiver = receiver;
		this->excuteStyle = excuteStyle;
		this->efRound = efRound;
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
		return ((this->level == rhs.level) && 
				(this->cardId == rhs.cardId) && 
				(this->effectIndex == rhs.effectIndex) &&
				(this->releaser == rhs.releaser) && 
				(this->receiver == rhs.receiver) &&
				(this->excuteStyle == rhs.excuteStyle) &&
				(this->efRound == rhs.efRound));
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
public:
	//效果队列下标索引
	enum EffectQueueIndex
	{
		EffectQueueIndex_Global = 0,
		EffectQueueIndex_Before = 1,
		EffectQueueIndex_In = 2,
		EffectQueueIndex_After = 3		
	};
	//每回合最大的队列个数
	static const int queueSizeMax = 4;

	//构造函数
	EffectPQ();
	//析构函数
	~EffectPQ();
	//根据指定的相对回合数和下标索引，向角色队列添加效果附加属性
	void pushEffectAffixesRole(EffectAffixes& effectAffixes, const int relRound, const int index);

	//根据效果的执行阶段，获取角色当前回合该阶段的效果附加属性实例
	const EffectAffixes& getEffectAffixesRole(EffectQueueIndex effectQueueIndex);

	//根据指定的相对回合数和下标索引，获取角色指定索引内的最大的优先级
	int getEPQLevelMaxRoleByRoundAndIndex(const int relRound, const int index);

	//根据指定的相对回合数和下标索引，弹出角色指定索引内最小优先级的效果附加属性实例
	void popEffectAffixesRole(const int relRound, const int index);

	//角色每回合的效果向后推移
	void decreaseRoundEffectRole();


	//根据指定的相对回合数和下标索引，向怪物队列添加效果附加属性
	void pushEffectAffixesMonster(EffectAffixes& effectAffixes, const int relRound, const int index);
	//根据效果的执行阶段，获取怪物当前回合该阶段的效果附加属性实例
	const EffectAffixes& getEffectAffixesMonster(EffectQueueIndex effectQueueIndex);
	//根据指定的相对回合数和下标索引，获取怪物指定索引内的最大的优先级
	int getEPQLevelMaxMonsterByRoundAndIndex(const int relRound, const int index);

	//根据指定的相对回合数和下标索引，弹出怪物指定索引内最小优先级的效果附加属性实例
	void popEffectAffixesMonster(const int relRound, const int index);

	//怪物每回合的效果向后推移
	void decreaseRoundEffectMonster();
	
	//根据直效果的执行阶段，获取队列的索引
	const int getIndexByExcuteStyle(Effect::ExcuteStyle excuteStyle);

	//检查指定参数是否越界
	bool checkOutOfRange(const int& relRound, const int& index);
	
private:

	//角色效果队列
	std::vector<std::array<std::priority_queue<int, std::vector<EffectAffixes>, std::greater<EffectAffixes>>, queueSizeMax>> rolePQ;
	//怪物效果队列
	std::vector<std::array<std::priority_queue<int, std::vector<EffectAffixes>, std::greater<EffectAffixes>>, queueSizeMax>> monsterPQ;
	//预定义的空效果
	const static EffectAffixes nullEffectAffixes;
};


#endif
