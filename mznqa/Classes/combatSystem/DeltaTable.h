#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_COMBATSYSTEM_DELTATABLE_H_
#define MZNQA_CLASSES_COMBATSYSTEM_DELTATABLE_H_

#include "card/CardBase.h"
#include "effect/Effect.h"
#include "combatSystem/EffectPQ.h"

/*！
 * \struct	DeltaTable
 *
 * \brief	增量表结构体，记录历史效果
 *
 */
struct DeltaTable
{
	/* \brief	效果所属的卡牌编号 */
	int ID = CardBase::invalidID;
	
	/* \brief	无效值 */
	static const int invalid = -1;

	/*！
	 * \enum	RoundLevel
	 *
	 * \brief	枚举每回合内效果的执行阶段
	 */
	enum RoundLevel
	{ 
		RoundLevel_invalid = invalid,	///< 无效的效果执行段
		RoundLevel_Global = 0,			///< 全局的效果执行段
		RoundLevel_Before = 1,			///< 战斗前的效果执行段
		RoundLevel_In = 2,				///< 战斗时的效果执行段
		RoundLevel_After= 3,			///< 战斗后的效果执行段
		RoundLevel_Total = 4			///< 回合结束结算段
	};

	/* \brief	记录效果的执行阶段 */
	RoundLevel roundLevel = RoundLevel_invalid;

	//效果释放者
	EffectAffixes::Releaser releaser;
	//效果接收者
	Effect::Receiver receiver;
	//设置历史效果信息
	void setEffectHistoryInfo(const EffectAffixes& effectAffixes);
	//设置历史效果基础血量
	void setEffectTableBlood(const int deltaBlood);
	//设置历史效果基础护甲
	void setEffectTableArmor(const int deltaArmor);
	//设置历史效果基础手牌数
	void setEffectTableHandCardCount(const int deltaHandCardCount);
	//设置历史效果基础可抽牌数
	void setEffectTableDrawCardCount(const int deltaDrawCardCount);
	//设置历史效果基础可出牌数
	void setEffectTableDiscardCount(const int deltaDiscardCount);
	//添加历史效果
	void addHistoryEffect();

	enum Flag
	{
		Flag_Invalid = -1,
		Flag_Blood_Role,
		Flag_Blood_Monster,
		Flag_Armor_Role,
		Flag_Armor_Monster,
		Flag_Hand_Role,
		Flag_Draw_Role,
		Flag_Discard_Role
	};
	Flag flag = Flag_Invalid;

	/* \brief	记录效果的释放回合数 */
	int roundNumber = EffectAffixes::invalidEffectRoundValue;

	static const int row = 5,  col = 2;
	/* \brief	记录效果影响基础属性的二维表 */
	int effectTable[row][col];

	/*！
	 * \fn	DeltaTable()
	 *
	 * \brief	构造函数
	 *
	 */
	DeltaTable()
	{
		memset(effectTable, 0, sizeof(int)*row*col);
	}

	/*！
	 * \fn	~DeltaTable()
	 *
	 * \brief	析构函数
	 *
	 */
	~DeltaTable()
	{

	}
};

/*！
 * \struct	DeltaRound
 *
 * \brief	回合结构体，记录每个回合内各阶段的效果历史下标索引
 *
 */
struct DeltaRound
{
	/* \brief	无效的索引值 */
	static const int invalIndex = -1;

	/* \brief	战斗前的下标索引 */
	int before = invalIndex;

	/* \brief	战斗时的下标索引 */
	int in = invalIndex;

	/* \brief	战斗后的下标索引 */
	int after = invalIndex;

	/* \brief	 每回合总表的下标索引 */
	int total = invalIndex;

	/* \brief	回合数 */
	int roundNumber = EffectAffixes::invalidEffectRoundValue;
};



#endif