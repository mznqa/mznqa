#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_COMBATSYSTEM_COMBATSYSTEMINTERFACE_H_
#define MZNQA_CLASSES_COMBATSYSTEM_COMBATSYSTEMINTERFACE_H_

#include "gameobject/Role.h"
#include "gameobject/Monster.h"
#include "combatSystem/DeltaTableHistory.h"
#include "combatSystem/CombatSystem.h"

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
	 * \fn	int CombatSystemInterface::getBloodRole();
	 *
	 * \brief	获取角色当前血量.
	 *
	 * \return	返回角色当前血量.
	 */
	int getBloodRole();

	/*！
	 * \fn	int CombatSystemInterface::getArmorRole();
	 *
	 * \brief	获取角色当前护甲.
	 *
	 * \return	返回角色当前护甲.
	 */
	int getArmorRole();

	/*！
	 * \fn	int CombatSystemInterface::getBloodMaxRole();
	 *
	 * \brief	获取角色血量上限.
	 *
	 * \return	返回角色血量上限.
	 */
	int getBloodMaxRole();

	/*！
	 * \fn	int CombatSystemInterface::getHandCountRole();
	 *
	 * \brief	获取角色当前手牌数.
	 *
	 * \return	返回角色当前手牌数.
	 */
	int getHandCountRole();

	/*！
	 * \fn	void CombatSystemInterface::updateHandCountRole(int delta);
	 *
	 * \brief	根据给定的增减量来更新角色的手牌数.
	 *
	 * \param	delta	指定将用于更新角色手牌数的增减量.
	 */
	void updateHandCountRole(int delta);

	/*！
	 * \fn	void CombatSystemInterface::setDiscountCountRole(int delta);
	 *
	 * \brief	根据指定值来设置角色手牌数.
	 *
	 * \param	delta	指定用于设置角色手牌数的值.
	 */
	void setDiscountCountRole(int delta);

	/*！
	 * \fn	void CombatSystemInterface::updateDrawCardCountRole(int delta);
	 *
	 * \brief	根据给定的增减量来更新角色的抽牌数.
	 *
	 * \param	delta	指定将用于更新角色抽牌数的增减量.
	 */
	void updateDrawCardCountRole(int delta);

	/*！
	 * \fn	void CombatSystemInterface::updateBloodRole(int delta);
	 *
	 * \brief	根据给定的增减量来更新角色的血量.
	 *
	 * \param	delta	指定将用于更新角色血量的增减量.
	 */
	void updateBloodRole(int delta);

	/*！
	 * \fn	void CombatSystemInterface::updateArmorRole(int delta);
	 *
	 * \brief	根据给定的增减量来更新角色的护甲.
	 *
	 * \param	delta	指定将用于更新角色护甲的增减量.
	 */
	void updateArmorRole(int delta);

	/*！
	 * \fn	int CombatSystemInterface::getBloodMonster();
	 *
	 * \brief	获取怪物当前血量.
	 *
	 * \return	返回怪物当前血量.
	 */
	int getBloodMonster();

	/*！
	 * \fn	int CombatSystemInterface::getArmorMonster();
	 *
	 * \brief	获取怪物当前护甲.
	 *
	 * \return	返回怪物当前护甲.
	 */
	int getArmorMonster();

	/*！
	 * \fn	int CombatSystemInterface::getBloodMaxMonster();
	 *
	 * \brief	获取怪物血量上限.
	 *
	 * \return	返回怪物血量上限.
	 */
	int getBloodMaxMonster();

	/*！
	 * \fn	void CombatSystemInterface::updateBloodMonster(int delta);
	 *
	 * \brief	根据给定的增减量来更新怪物的血量.
	 *
	 * \param	delta	指定将用于更新怪物血量的增减量.
	 */
	void updateBloodMonster(int delta);

	/*！
	 * \fn	void CombatSystemInterface::updateArmorMonster(int delta);
	 *
	 * \brief	根据给定的增减量来更新怪物的护甲.
	 *
	 * \param	delta	指定将用于更新怪物护甲的增减量.
	 */
	void updateArmorMonster(int delta);

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
	 * \fn	const EffectAffixes& CombatSystemInterface::getCurrentEffectAffixes()
	 *
	 * \brief	获取当前效果的附加属性
	 *
	 * \return	返回当前的效果属性
	 */
	const EffectAffixes& getCurrentEffectAffixes();

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
	 * \fn	CombatSystemInterface& CombatSystemInterface::operator=(const CombatSystemInterface& csi);
	 *
	 * \brief	=运算符
	 *
	 * \param	csi	CombatSystemInterface实例
	 *
	 * \return	返回CombatSystemInterface自身引用
	 */
	CombatSystemInterface& operator=(const CombatSystemInterface& csi);

	/* \brief	角色对象常指针 */
	Role *const role = Role::Instance();

	//怪物战斗对象---测试用 //////////////////////////////////////////////////////////////////////////
	Monster monster;
	//历史效果实例，包含角色历史效果向量，怪物历史效果向量---测试用/////////////////////////////////////////
	DeltaTableHistory dtHistory;
};


#endif // MZNQA_CLASSES_COMBATSYSTEM_COMBATSYSTEMINTERFACE_H_