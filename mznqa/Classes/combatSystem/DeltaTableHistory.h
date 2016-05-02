#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_COMBATSYSTEM_DELTATABLEHISTORY_H_
#define MZNQA_CLASSES_COMBATSYSTEM_DELTATABLEHISTORY_H_

#include <vector>
#include "combatSystem/DeltaTable.h"

/*！
 * \class	DeltaTableHistory
 *
 * \brief	效果历史类
 *
 */
class DeltaTableHistory
{
public:

	/*！
	 * \fn	DeltaTableHistory::DeltaTableHistory();
	 *
	 * \brief	默认构造函数
	 *
	 */
	DeltaTableHistory();

	/*！
	 * \fn	DeltaTableHistory::~DeltaTableHistory();
	 *
	 * \brief	析构函数
	 *
	 */
	~DeltaTableHistory();

	/*！
	 * \fn	bool DeltaTableHistory::addTableRoleHistory(const DeltaTable& dt);
	 *
	 * \brief	根据指定的增量表结构体，来添加角色效果历史
	 *
	 * \param	dt	指定的增量表结构体
	 *
	 * \return	返回添加角色效果历史是否成功
	 */
	bool addTableRoleHistory(const DeltaTable& dt);

	/*！
	 * \fn	void DeltaTableHistory::addTotalRoleHistory(int round);
	 *
	 * \brief	根据指定的回合数，添加指定回合的角色效果总表
	 *
	 * \param	round	指定的回合数值
	 *
	 */
	void addTotalRoleHistory(int round);

	/*！
	 * \fn	const std::vector<DeltaTable>& DeltaTableHistory::getRoundAllRoleTable(int round);
	 *
	 * \brief	根据给定的回合数，获取指定回合内所有的角色历史效果表
	 *
	 * \param	round	指定的回合数值
	 *
	 * \return	返回指定回合内所有的角色历史效果表
	 */
	const std::vector<DeltaTable>& getRoundAllRoleTable(int round);

	/*！
	 * \fn	const std::vector<DeltaTable>& DeltaTableHistory::getRoundRoleTable(int round, DeltaTable::RoundLevel index);
	 *
	 * \brief	根据给定的回合数和索引，获取指定索引内的所有的角色历史表
	 *
	 * \param	round	指定的回合数值
	 * \param	index	指定的索引值
	 *
	 * \return	返回指定索引内的所有的角色历史效果表
	 */
	const std::vector<DeltaTable>& getRoundRoleTable(int round, DeltaTable::RoundLevel index);

	/*！
	 * \fn	const std::vector<DeltaTable>& DeltaTableHistory::getCurrentRoundRoleTable(int round);
	 *
	 * \brief	根据指定的回合数，获取角色当前回合的历史效果表
	 *
	 * \param	round	指定的回合数值
	 *
	 * \return	返回角色当前回合的历史效果表
	 */
	const std::vector<DeltaTable>& getCurrentRoundRoleTable(int round);

	/*！
	 * \fn	bool DeltaTableHistory::addTableMonsterHistory(DeltaTable dt);
	 *
	 * \brief	根据指定的增量表结构体，来添加怪物效果历史
	 *
	 * \param	dt	指定的增量表结构体
	 *
	 * \return	返回添加怪物效果历史是否成功
	 */
	bool addTableMonsterHistory(DeltaTable dt);

	/*！
	 * \fn	void DeltaTableHistory::addTotalMonsterHistory(int round);
	 *
	 * \brief	根据给定的回合数，获取指定回合内所有的怪物历史效果表
	 *
	 * \param	round	指定的回合数值
	 */
	void addTotalMonsterHistory(int round);
	
	/*！
	 * \fn	const std::vector<DeltaTable>& DeltaTableHistory::getRoundAllMonsterTable(int round);
	 *
	 * \brief	根据给定的回合数，获取指定回合内所有的怪物历史效果表
	 *
	 * \param	round	指定的回合数值
	 *
	 * \return	返回指定回合内所有的怪物历史效果表
	 */
	const std::vector<DeltaTable>& getRoundAllMonsterTable(int round);

	/*！
	 * \fn	const std::vector<DeltaTable>& DeltaTableHistory::getRoundMonsterTable(int round, DeltaTable::RoundLevel index);
	 *
	 * \brief	根据给定的回合数和索引，获取指定索引内的所有的怪物历史表
	 *
	 * \param	round	指定的回合数值
	 * \param	index	指定的索引值
	 *
	 * \return	返回指定索引内的所有的怪物历史效果表
	 */
	const std::vector<DeltaTable>& getRoundMonsterTable(int round, DeltaTable::RoundLevel index);

	/*！
	 * \fn	const std::vector<DeltaTable>& DeltaTableHistory::getCurrentRoundMonsterTable(int round);
	 *
	 * \brief	根据指定的回合数，获取怪物当前回合的历史效果表
	 *
	 * \param	round	指定的回合数值
	 *
	 * \return	返回怪物当前回合的历史效果表
	 */
	const std::vector<DeltaTable>& getCurrentRoundMonsterTable(int round);

	/*！
	 * \fn	void DeltaTableHistory::test();
	 *
	 * \brief	测试单元
	 */
	void test();

private:

	/* \brief	角色历史向量，用于存储角色历史效果 */
	std::vector<DeltaTable> tableRoleHistory;
	/* \brief	角色回合向量，用于存储角色历史效果的下标索引 */
	std::vector<DeltaRound> roundRoleHistory;
	/* \brief	记录角色历史的回合数 */
	int roundNumberRole = 1;

	/* \brief	怪物历史向量，用于存储怪物历史效果. */
	std::vector<DeltaTable> tableMonsterHistory;
	/* \brief	怪物回合向量，用于存储怪物历史效果的下标索引 */
	std::vector<DeltaRound> roundMonsterHistory;
	/* \brief	记录怪物历史的回合数. */
	int roundNumberMonster = 1;

	/* \brief	临时向量，用于返回获取的历史效果表 */
	std::vector<DeltaTable> tableTemp;
};


#endif // !MZNQA_CLASSES_COMBATSYSTEM_DELTATABLEHISTORY_H_

