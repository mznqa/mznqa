#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_COMBATSYSTEM_COMBATSYSTEMINTERFACE_H_
#define MZNQA_CLASSES_COMBATSYSTEM_COMBATSYSTEMINTERFACE_H_

#include "gameobject/Role.h"
#include "gameobject/Monster.h"
#include "combatSystem/DeltaTableHistory.h"
#include "combatSystem/EffectPQ.h"
#include "combatSystem/CombatSystem.h"
#include "Effect/Effect.h"

/*！
 * \class	CombatSystemInterface
 *
 * \brief	战斗系统的接口集合
 *
 */
class CombatSystemInterface
{
public:

	/*！
	 * \fn	CombatSystemInterface::~CombatSystemInterface();
	 *
	 * \brief	析构函数.
	 *
	 */
	~CombatSystemInterface()
	{

	}

	/*！
	 * \fn	static CombatSystemInterface& CombatSystemInterface::Instance();
	 *
	 * \brief	获取单例.
	 *
	 * \return	返回单例.
	 */
	static CombatSystemInterface* Instance();

	/*！
	 * \fn	int CombatSystemInterface::getRoleBlood();
	 *
	 * \brief	获取角色当前血量
	 *
	 * \return	返回角色当前血量
	 */
	int getRoleBlood();

	/*！
	 * \fn	int CombatSystemInterface::getRoleArmor();
	 *
	 * \brief	获取角色当前护甲
	 *
	 * \return	返回角色当前护甲
	 */
	int getRoleArmor();

	/*！
	 * \fn	int CombatSystemInterface::getRoleBloodMax();
	 *
	 * \brief	获取角色血量上限
	 *
	 * \return	返回角色血量上限
	 */
	int getRoleBloodMax();

	/*！
	 * \fn	int CombatSystemInterface::getRoleHandCount();
	 *
	 * \brief	获取角色当前手牌数
	 *
	 * \return	返回角色当前手牌数
	 */
	int getRoleHandCount();

	/*！
	 * \fn	void CombatSystemInterface::updateRoleHandCount(int delta);
	 *
	 * \brief	根据给定的增减量来更新角色的手牌数
	 *
	 * \param	delta	指定将用于更新角色手牌数的增减量
	 */
	void updateRoleHandCount(int delta);

	/*！
	 * \fn	void CombatSystemInterface::setRoleDiscountCount(int delta);
	 *
	 * \brief	根据指定值来设置角色手牌数
	 *
	 * \param	delta	指定用于设置角色手牌数的值
	 */
	void setRoleDiscountCount(int delta);

	/*！
	 * \fn	void CombatSystemInterface::updateRoleDrawCardCount(int delta);
	 *
	 * \brief	根据给定的增减量来更新角色的抽牌数
	 *
	 * \param	delta	指定将用于更新角色抽牌数的增减量
	 */
	void updateRoleDrawCardCount(int delta);

	/*！
	 * \fn	void CombatSystemInterface::updateRoleBlood(int delta);
	 *
	 * \brief	根据给定的增减量来更新角色的血量
	 *
	 * \param	delta	指定将用于更新角色血量的增减量
	 */
	void updateRoleBlood(int delta);

	/*！
	 * \fn	void CombatSystemInterface::updateRoleArmor(int delta);
	 *
	 * \brief	根据给定的增减量来更新角色的护甲
	 *
	 * \param	delta	指定将用于更新角色护甲的增减量
	 */
	void updateRoleArmor(int delta);

	/*！
	 * \fn	int CombatSystemInterface::getMonsterBlood();
	 *
	 * \brief	获取怪物当前血量
	 *
	 * \return	返回怪物当前血量
	 */
	int getMonsterBlood();

	/*！
	 * \fn	int CombatSystemInterface::getMonsterArmor();
	 *
	 * \brief	获取怪物当前护甲
	 *
	 * \return	返回怪物当前护甲
	 */
	int getMonsterArmor();

	/*！
	 * \fn	int CombatSystemInterface::getMonsterBloodMax();
	 *
	 * \brief	获取怪物血量上限
	 *
	 * \return	返回怪物血量上限
	 */
	int getMonsterBloodMax();

	/*！
	 * \fn	void CombatSystemInterface::updateMonsterBlood(int delta);
	 *
	 * \brief	根据给定的增减量来更新怪物的血量
	 *
	 * \param	delta	指定将用于更新怪物血量的增减量
	 */
	void updateMonsterBlood(int delta);

	/*！
	 * \fn	void CombatSystemInterface::updateMonsterArmor(int delta);
	 *
	 * \brief	根据给定的增减量来更新怪物的护甲
	 *
	 * \param	delta	指定将用于更新怪物护甲的增减量
	 */
	void updateMonsterArmor(int delta);

	/*！
	* \fn	DeltaTableHistory& CombatSystemInterface::getDeltaTableHistory();
	*
	* \brief	获取历史效果实例
	*
	* \return	返回历史效果实例
	*/
	DeltaTableHistory& getDeltaTableHistory()
	{
		return dtHistory;
	}

	/*！
	* \fn	std::vector<DeltaTable>& CombatSystemInterface::getRoundRoleDeltaTable()
	*
	* \brief	获取角色当前回合的效果历史向量
	*
	* \return	返回角色当前回合的效果历史向量
	*/
	std::vector<DeltaTable>& getRoundRoleDeltaTable()
	{
		return deltaRole;
	}

	/*！
	 * \fn	void CombatSystemInterface::setCurentRoundRoleDeltaTable(int round);
	 *
	 * \brief	根据给定的回合数来设置怪物当前角色效果历史向量
	 *
	 * \param	round	给定的回合数值
	 */
	void setCurentRoundRoleDeltaTable(int round);

	/*！
	 * \fn	void CombatSystemInterface::setCurrentRoundMonsterDeltaTable(int round);
	 *
	 * \brief	根据给定的回合数来设置怪物当前怪物效果历史向量
	 *
	 * \param	round	给定的回合数值
	 */
	void setCurrentRoundMonsterDeltaTable(int round);

	/*！
	 * \fn	const std::vector<DeltaTable>& CombatSystemInterface::getRoundRoleDeltaTable(int round, DeltaTable::RoundLevel index);
	 *
	 * \brief	根据指定的回合数和索引，获取指定索引内的所有的角色效果历史
	 *
	 * \param	round	指定的回合数值
	 * \param	index	指定的索引值
	 *
	 * \return	返回指定索引内的所有角色效果历史
	 */
	const std::vector<DeltaTable>& getRoundRoleDeltaTable(int round, DeltaTable::RoundLevel index);

	/*！
	 * \fn	const std::vector<DeltaTable>& CombatSystemInterface::getRoundMonsterDeltaTable(int round, DeltaTable::RoundLevel index);
	 *
	 * \brief	根据指定的回合数和索引，获取指定索引内的所有的怪物效果历史
	 *
	 * \param	round	指定的回合数值
	 * \param	index	指定的索引值
	 *
	 * \return	返回指定索引内的所有怪物效果历史
	 */
	const std::vector<DeltaTable>& getRoundMonsterDeltaTable(int round, DeltaTable::RoundLevel index);

	/*！
	 * \fn	std::vector<DeltaTable>& CombatSystemInterface::getRoundMonsterDeltaTable()
	 *
	 * \brief	获取怪物当前历史效果向量
	 *
	 * \return	返回怪物当前历史效果向量
	 */
	std::vector<DeltaTable>& getRoundMonsterDeltaTable()
	{
		return deltaMonster;
	}

	/*！
	 * \fn	void CombatSystemInterface::setEffectArgs(const std::vector<int>& args)
	 *
	 * \brief	根据给定的参数来设置当前的效果参数
	 *
	 * \param	args	指定将用于设置当前效果参数的向量值
	 */
	void setEffectArgs(const std::vector<int>& args)
	{
		this->efArgs = args;
	}

	/*！
	 * \fn	const std::vector<int>& CombatSystemInterface::getEffectArgs() const
	 *
	 * \brief	获取当前效果的参数
	 *
	 * \return	返回当前效果的参数
	 */
	const std::vector<int>& getEffectArgs() const
	{
		return efArgs;
	}

	/*！
	 * \fn	void CombatSystemInterface::setEffectAffixes(const EffectAffixes& ea)
	 *
	 * \brief	根据给定的效果附加属性来设置当前效果的附加属性
	 *
	 * \param	ea	指定的效果附加属性
	 */
	void setEffectAffixes(const EffectAffixes& ea)
	{
		this->effectAffixes = ea;
	}

	/*！
	 * \fn	const EffectAffixes& CombatSystemInterface::getEffectAffixes() const
	 *
	 * \brief	获取当前效果附加属性
	 *
	 * \return	返回当前效果附加属性
	 */
	const EffectAffixes& getEffectAffixes() const
	{
		return effectAffixes;
	}

	/*！
	 * \fn	EffectPQ& CombatSystemInterface::getEffectPQ();
	 *
	 * \brief	获取效果队列
	 *
	 * \return	返回效果队列
	 */
	EffectPQ& getEffectPQ();

private:

	/*！
	 * \fn	CombatSystemInterface::CombatSystemInterface();
	 *
	 * \brief	隐藏的构造函数.
	 *
	 */
	CombatSystemInterface(){}

	/*！
	 * \fn	CombatSystemInterface::CombatSystemInterface(const CombatSystemInterface& csi);
	 *
	 * \brief	复制构造函数
	 *
	 * \param	csi	CombatSystemInterface实例
	 */
	CombatSystemInterface(const CombatSystemInterface& csi);

	/*！
	 * \fn	CombatSystemInterface CombatSystemInterface::operator=(const CombatSystemInterface& csi);
	 *
	 * \brief	=运算符
	 *
	 * \param	csi	CombatSystemInterface实例
	 *
	 * \return	A shallow copy of this object.
	 */
	CombatSystemInterface operator=(const CombatSystemInterface& csi);

	/* \brief	怪物战斗对象. */
	Monster monster;
	/* \brief	历史效果实例，包含角色历史效果向量，怪物历史效果向量 */
	DeltaTableHistory dtHistory;
	/* \brief	角色当前回合的历史效果向量 */
	std::vector<DeltaTable> deltaRole;
	/* \brief	怪物当前回合的历史效果向量 */
	std::vector<DeltaTable> deltaMonster;	
	/* \brief	参数向量，当前效果函数参数 */
	std::vector<int> efArgs;
	/* \brief	当前效果的附加属性 */
	EffectAffixes effectAffixes;
};


#endif // MZNQA_CLASSES_COMBATSYSTEM_COMBATSYSTEMINTERFACE_H_