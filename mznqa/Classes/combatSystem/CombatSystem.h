/*!
 * \file	Classes\combatSystem\CombatSystem.h
 *
 * \brief	定义类 CombatSystem
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_COMBATSYSTEM_COMBATSYSTEM_H_
#define MZNQA_CLASSES_COMBATSYSTEM_COMBATSYSTEM_H_

#include "combatSystem/EffectPQ.h"
#include "combatSystem/CombatSystemInterface.h"
#include "card/CardBase.h"

/*!
 * \class	CombatSystem
 *
 * \brief	战斗系统
 *
 */
class CombatSystem
{
public:

	/*!
	 * \fn	CombatSystem::CombatSystem();
	 *
	 * \brief	构造函数
	 *
	 */
	CombatSystem();

	/*!
	 * \fn	CombatSystem::~CombatSystem();
	 *
	 * \brief	析构函数
	 *
	 */
	~CombatSystem();

	/*!
	 * \fn	void CombatSystem::dispatchEffectFromCardSkillRole(int cardSkillID);
	 *
	 * \brief	根据给定角色技能卡，分析其效果并推送到效果队列中
	 *
	 * \param	cardSkillID	指定角色技能卡id
	 */
	void dispatchEffectFromCardSkillRole(int cardSkillID);

	/*!
	 * \fn	void CombatSystem::dispatchEffectFromCardSkillMonster(int cardSkillID);
	 *
	 * \brief	根据给定怪物技能卡，分析其效果并推送到效果队列中
	 *
	 * \param	cardSkillID	指定怪物技能卡id
	 */
	void dispatchEffectFromCardSkillMonster(int cardSkillID);

	/*!
	 * \fn	void CombatSystem::executeGlobalOperation();
	 *
	 * \brief	回合内操作：全局操作
	 *
	 */
	void executeGlobalOperation();

	/*!
	 * \fn	void CombatSystem::executeRoleBeforeTheCombatOperation();
	 *
	 * \brief	回合内操作：角色战斗前期操作
	 *
	 */
	void executeRoleBeforeTheCombatOperation();

	/*!
	 * \fn	void CombatSystem::excuteRoleInCombatOperation();
	 *
	 * \brief	回合内操作：角色战斗过程中
	 *
	 */
	void excuteRoleInCombatOperation();

	/*!
	 * \fn	void CombatSystem::excuteRoleAfterCombatOperation();
	 *
	 * \brief	回合内操作：角色战斗后期操作
	 *
	 */
	void excuteRoleAfterCombatOperation();

	/*!
	 * \fn	void CombatSystem::executeMonsterBeforeTheCombatOperator();
	 *
	 * \brief	回合内操作：怪物战斗前期操作
	 *
	 */
	void executeMonsterBeforeTheCombatOperator();

	/*!
	 * \fn	void CombatSystem::excuteMonsterInCombatOperator();
	 *
	 * \brief	回合内操作：怪物战斗过程中
	 *
	 */
	void excuteMonsterInCombatOperator();

	/*!
	 * \fn	void CombatSystem::excuteMonsterAfterCombatOperator();
	 *
	 * \brief	回合内操作：怪物战斗后期操作
	 *
	 */
	void excuteMonsterAfterCombatOperator();

	/*!
	 * \fn	void CombatSystem::excuteCombat();
	 *
	 * \brief	执行一回合战斗
	 *
	 */
	void excuteCombat();

	/*!
	 * \fn	void CombatSystem::setUseCardId(const int roleUseCardId, const int monsterUseCardId);
	 *
	 * \brief	设置用于单回合战斗的双反技能卡
	 *
	 * \param	roleUseCardId   	指定用于单回合战斗的角色技能卡id
	 * \param	monsterUseCardId	指定用于单回合战斗的角色技能卡id
	 */
	void setUseCardId(const int roleUseCardId, const int monsterUseCardId);

	/*！
	 * \fn	void CombatSystem::setHistoryTotalTable(const int round);
	 *
	 * \brief	设置历史效果的总表
	 */
	void setHistoryTotalTable();

	/*!
	 * \fn	bool CombatSystem::judgeEndToCombat();
	 *
	 * \brief	判断是否完成战斗
	 *
	 * \return	返回是否完成战斗
	 */
	bool judgeEndToCombat();

	/*！
	 * \fn	static EffectPQ& CombatSystem::getEffectPQ()
	 *
	 * \brief	获取效果队列集合（包含角色和怪物的效果队列）
	 *
	 * \return	返回效果队列集合
	 */
	static EffectPQ& getEffectPQ()
	{
		return epq;
	}

	/*！
	 * \fn	static int& CombatSystem::getRound()
	 *
	 * \brief	获取战斗回合数
	 *
	 * \return	返回战斗回合数
	 */
	static int& getRound()
	{
		return round;
	}	

	static EffectAffixes& getEffectAffixes()
	{
		return efAffixes;
	}

	//测试单元
	void test();

private:
	/*! \brief	标识回合数 */
	static int round;

	/*! \brief	效果队列集合（包含角色和怪物的效果队列） */
	static EffectPQ epq;

	/*! \brief	角色选定的用于战斗的技能卡 */
	int roleUseCardId = CardBase::invalidID;
	/*! \brief	怪物选定的用于战斗的技能卡 */
	int monsterUseCardId = CardBase::invalidID;

	//当前效果附加属性
	static EffectAffixes efAffixes;
};

#endif // !MZNQA_CLASSES_COMBATSYSTEM_COMBATSYSTEM_H_
