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
	 * \fn	bool DeltaTableHistory::addTableHistoryRole(const DeltaTable& deltaTable);
	 *
	 * \brief	根据指定的增量表结构体，来添加角色效果历史.
	 *
	 * \param	deltaTable	指定的增量表结构体.
	 *
	 * \return	返回添加角色效果历史是否成功.
	 */
	bool addTableHistoryRole(const DeltaTable& deltaTable);

	/*！
	 * \fn	void DeltaTableHistory::addTotalTableHistoryRole(int round);
	 *
	 * \brief	根据指定的回合数，添加指定回合的角色效果总表.
	 *
	 * \param	round	指定的回合数值.
	 */
	void addTotalTableHistoryRole(int round);

	/*！
	 * \fn	void DeltaTableHistory::syncRoundDeltaTableAndTableHistory(const int round);
	 *
	 * \brief	根据指定的回合数同步历史表的回合数
	 *
	 * \param	round	指定的回合数
	 */
	void  syncRoundDeltaTableAndTableHistory(const int round);

	/*！
	 * \fn	void DeltaTableHistory::setTotalTableBaseValue(std::vector<DeltaTable>& dtHistory, DeltaTable& deltaTable, const int beginIndex, const int endIndex);
	 *
	 * \brief	根据指定的历史表和增量表实例来设置总表的基础值
	 *
	 * \param	dtHistory 	指定的历史表
	 * \param	deltaTable	指定的增量表实例
	 * \param	beginIndex	开始计算的历史表下标索引
	 * \param	endIndex	结束计算的历史表下标索引
	 */
	void setTotalTableBaseValue(std::vector<DeltaTable>& dtHistory, DeltaTable& deltaTable, const int beginIndex, const int endIndex);

	/*！
	 * \fn	void DeltaTableHistory::setRoundTableInfo(std::vector<DeltaRound>& roundHistory, std::vector<DeltaTable>& dtHistory, DeltaRound& deltaRound);
	 *
	 * \brief	根据指定的回合索引实例和指定的历史表来设置指定的回合索引历史表
	 *
	 * \param [in,out]	roundHistory	指定的回合索引历史表
	 * \param [in,out]	dtHistory   	指定的历史表
	 * \param [in,out]	deltaRound  	指定的回合索引实例
	 */
	void setRoundTableInfo(std::vector<DeltaRound>& roundHistory, std::vector<DeltaTable>& dtHistory, DeltaRound& deltaRound);

	/*！
	 * \fn	int DeltaTableHistory::getSettleBaseValue(const int round, const int rowIndex, const int colIndex);
	 *
	 * \brief	根据指定的回合数和增量表的行列下标来获取指定回合结算后的指定基础值
	 *
	 * \param	round   	指定的回合数
	 * \param	rowIndex	指定的增量表的行下标
	 * \param	colIndex	指定的增量表的列下标
	 *
	 * \return	返回指定回合结算后的指定基础值
	 */
	int getSettleBaseValue(const int round, const int rowIndex, const int colIndex);

	/*！
	 * \fn	int DeltaTableHistory::getAttackValueMonster();
	 *
	 * \brief	获取当前回合怪物对角色的伤害(血量)值.
	 *
	 * \return	获取当前回合怪物对角色的伤害值
	 */
	int getAttackValueMonster();

	/*！
	 * \fn	int DeltaTableHistory::getAttackValueRole();
	 *
	 * \brief	获取当前回合角色对怪物的伤害(血量)值.
	 *
	 * \return	返回当前回合角色对怪物的伤害值
	 */
	int getAttackValueRole();

	/*！
	 * \fn	int DeltaTableHistory::getBackBaseValue(const int rowIndex, const int colIndex);
	 *
	 * \brief	根据指定的行列下标来获取指定的回复基础值（如：回血值，回甲值...)
	 *
	 * \param	rowIndex	指定的行下标
	 * \param	colIndex	指定的列下标
	 *
	 * \return	返回指定的回复基础值
	 */
	int getBackBaseValue(const int rowIndex, const int colIndex);

	/*！
	 * \fn	int DeltaTableHistory::getCountBaseValueInInterval(int round,const int baseValueMax, const int leftInterval, const int rightInterval,const int rowIndex,const int colIndex);
	 *
	 * \brief	根据指定的行列下标来获取开局起至指定的回合数内的指定的基础值在指定区间内的次数
	 *
	 * \param	round		 	指定的回合数
	 * \param	baseValueMax 	指定基础值的最大值
	 * \param	leftInterval 	指定的左区间
	 * \param	rightInterval	指定的右区间
	 * \param	rowIndex	 	指定的行下标
	 * \param	colIndex	 	指定的列下标
	 *
	 * \return	返回开局起至指定的回合数内的指定的基础值在指定区间内的次数
	 */
	int getCountBaseValueInInterval(int round,const int baseValueMax, const int leftInterval, const int rightInterval,const int rowIndex,const int colIndex);

	/*！
	 * \fn	bool DeltaTableHistory::checkOutOfRange(const int rowIndex, const int colIndex);
	 *
	 * \brief	根据指定的行列下标来检查指定的下标是否越界.
	 *
	 * \param	rowIndex	指定的行下标
	 * \param	colIndex	指定的列下标
	 *
	 * \return	返回指定的下标是否越界
	 */
	bool checkOutOfRange(const int rowIndex, const int colIndex);

	/*！
	 * \fn	void DeltaTableHistory::getAllTableRoleByRound(int round, int& beginIndex, int& endIndex);
	 *
	 * \brief	根据指定的回合数来获取指定回合内所有的角色效果历史开始索引和结束索引
	 *
	 * \param	round		指定的回合数值.
	 * \param	beginIndex	存放角色效果历史的开始索引
	 * \param	endIndex  	存放角色效果历史的结束索引
	 */
	void getAllTableRoleByRound(int round, int& beginIndex, int& endIndex);

	/*！
	 * \fn	void DeltaTableHistory::getTableRoleByRoundAndIndex(int round, DeltaTable::RoundLevel index, int& beginIndex, int& endIndex);
	 *
	 * \brief	根据给定的回合数和索引来获取指定索引内的所有的角色效果历史的开始索引和结束索引
	 *
	 * \param	round	指定的回合数
	 * \param	index	指定的索引值
	 * \param	beginIndex	存放角色效果历史的开始索引
	 * \param	endIndex  存放角色效果历史的结束索引	
	 */
	void getTableRoleByRoundAndIndex(int round, DeltaTable::RoundLevel index, int& beginIndex, int& endIndex);

	/*！
	 * \fn	bool DeltaTableHistory::addTableHistoryMonster(const DeltaTable& deltaTable);
	 *
	 * \brief	根据指定的增量表结构体来添加怪物效果历史.
	 *
	 * \param	deltaTable	指定的增量表结构体.
	 *
	 * \return	返回添加怪物效果历史是否成功.
	 */
	bool addTableHistoryMonster(const DeltaTable& deltaTable);

	/*！
	 * \fn	void DeltaTableHistory::addTotalTableHistoryMonster(int round);
	 *
	 * \brief	根据给定的回合数来添加怪物历史总表
	 *
	 * \param	round	指定的回合数值
	 */
	void addTotalTableHistoryMonster(int round);

	/*！
	 * \fn	void DeltaTableHistory::getAllTableMonsterByRound(int round,int& beginIndex,int& endIndex);
	 *
	 * \brief	根据给定的回合数，获取指定回合内所有的怪物效果历史表的开始索引和结束索引
	 *
	 * \param	round		指定的回合数值.
	 * \param	beginIndex	存放怪物效果历史的开始索引
	 * \param	endIndex  	存放怪物效果历史的结束索引
	 */
	void getAllTableMonsterByRound(int round,int& beginIndex,int& endIndex);

	/*！
	 * \fn	void DeltaTableHistory::getTableMonsterByRoundAndIndex(int round, DeltaTable::RoundLevel index, int& beginIndex, int& endIndex);
	 *
	 * \brief	根据给定的回合数和索引，获取指定索引内的所有的怪物历史表.
	 *
	 * \param	round		指定的回合数值.
	 * \param	index		指定的索引值
	 * \param	beginIndex	存放指定索引内怪物历史的开始索引
	 * \param	endIndex  	存放指定索引内怪物历史的结束索引
	 */
	void getTableMonsterByRoundAndIndex(int round, DeltaTable::RoundLevel index, int& beginIndex, int& endIndex);

	/*！
	 * \fn	void DeltaTableHistory::getIndexByFlag(int& rowIndex, int& colIndex, DeltaTable::Flag flag);
	 *
	 * \brief	根据指定的枚举标志来获取一个有数据的下标索引
	 *
	 * \param	rowIndex	存放有数据的行下标
	 * \param	colIndex	存放有数据的列下标
	 * \param	flag		指定的枚举标志
	 */
	void getIndexByFlag(int& rowIndex, int& colIndex, DeltaTable::Flag flag);
	
	/*！
	 * \fn	void DeltaTableHistory::test();
	 *
	 * \brief	测试单元
	 */
	void test();

private:

	/* \brief	角色历史向量，用于存储角色历史效果 */
	std::vector<DeltaTable> tableHistoryRole;
	/* \brief	角色回合向量，用于存储角色历史效果的下标索引 */
	std::vector<DeltaRound> roundHistoryRole;
	/* \brief	记录角色历史的回合数 */
	int roundNumberRole = 1;

	/* \brief	怪物历史向量，用于存储怪物历史效果. */
	std::vector<DeltaTable> tableHistoryMonster;
	/* \brief	怪物回合向量，用于存储怪物历史效果的下标索引 */
	std::vector<DeltaRound> roundHistoryMonster;
	/* \brief	记录怪物历史的回合数. */
	int roundNumberMonster = 1;
};


#endif // !MZNQA_CLASSES_COMBATSYSTEM_DELTATABLEHISTORY_H_

