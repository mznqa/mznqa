#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_COMBATSYSTEM_DELTATABLEHISTORY_H_
#define MZNQA_CLASSES_COMBATSYSTEM_DELTATABLEHISTORY_H_

#include <vector>
#include "combatSystem/DeltaTable.h"

/*��
 * \class	DeltaTableHistory
 *
 * \brief	Ч����ʷ��
 *
 */
class DeltaTableHistory
{
public:

	/*��
	 * \fn	DeltaTableHistory::DeltaTableHistory();
	 *
	 * \brief	Ĭ�Ϲ��캯��
	 *
	 */
	DeltaTableHistory();

	/*��
	 * \fn	DeltaTableHistory::~DeltaTableHistory();
	 *
	 * \brief	��������
	 *
	 */
	~DeltaTableHistory();

	/*��
	 * \fn	bool DeltaTableHistory::addTableHistoryRole(const DeltaTable& deltaTable);
	 *
	 * \brief	����ָ����������ṹ�壬����ӽ�ɫЧ����ʷ.
	 *
	 * \param	deltaTable	ָ����������ṹ��.
	 *
	 * \return	������ӽ�ɫЧ����ʷ�Ƿ�ɹ�.
	 */
	bool addTableHistoryRole(const DeltaTable& deltaTable);

	/*��
	 * \fn	void DeltaTableHistory::addTotalTableHistoryRole(int round);
	 *
	 * \brief	����ָ���Ļغ��������ָ���غϵĽ�ɫЧ���ܱ�.
	 *
	 * \param	round	ָ���Ļغ���ֵ.
	 */
	void addTotalTableHistoryRole(int round);

	/*��
	 * \fn	void DeltaTableHistory::syncRoundDeltaTableAndTableHistory(const int round);
	 *
	 * \brief	����ָ���Ļغ���ͬ����ʷ��Ļغ���
	 *
	 * \param	round	ָ���Ļغ���
	 */
	void  syncRoundDeltaTableAndTableHistory(const int round);

	/*��
	 * \fn	void DeltaTableHistory::setTotalTableBaseValue(std::vector<DeltaTable>& dtHistory, DeltaTable& deltaTable, const int beginIndex, const int endIndex);
	 *
	 * \brief	����ָ������ʷ���������ʵ���������ܱ�Ļ���ֵ
	 *
	 * \param	dtHistory 	ָ������ʷ��
	 * \param	deltaTable	ָ����������ʵ��
	 * \param	beginIndex	��ʼ�������ʷ���±�����
	 * \param	endIndex	�����������ʷ���±�����
	 */
	void setTotalTableBaseValue(std::vector<DeltaTable>& dtHistory, DeltaTable& deltaTable, const int beginIndex, const int endIndex);

	/*��
	 * \fn	void DeltaTableHistory::setRoundTableInfo(std::vector<DeltaRound>& roundHistory, std::vector<DeltaTable>& dtHistory, DeltaRound& deltaRound);
	 *
	 * \brief	����ָ���Ļغ�����ʵ����ָ������ʷ��������ָ���Ļغ�������ʷ��
	 *
	 * \param [in,out]	roundHistory	ָ���Ļغ�������ʷ��
	 * \param [in,out]	dtHistory   	ָ������ʷ��
	 * \param [in,out]	deltaRound  	ָ���Ļغ�����ʵ��
	 */
	void setRoundTableInfo(std::vector<DeltaRound>& roundHistory, std::vector<DeltaTable>& dtHistory, DeltaRound& deltaRound);

	/*��
	 * \fn	int DeltaTableHistory::getSettleBaseValue(const int round, const int rowIndex, const int colIndex);
	 *
	 * \brief	����ָ���Ļغ�����������������±�����ȡָ���غϽ�����ָ������ֵ
	 *
	 * \param	round   	ָ���Ļغ���
	 * \param	rowIndex	ָ��������������±�
	 * \param	colIndex	ָ��������������±�
	 *
	 * \return	����ָ���غϽ�����ָ������ֵ
	 */
	int getSettleBaseValue(const int round, const int rowIndex, const int colIndex);

	/*��
	 * \fn	int DeltaTableHistory::getAttackValueMonster();
	 *
	 * \brief	��ȡ��ǰ�غϹ���Խ�ɫ���˺�(Ѫ��)ֵ.
	 *
	 * \return	��ȡ��ǰ�غϹ���Խ�ɫ���˺�ֵ
	 */
	int getAttackValueMonster();

	/*��
	 * \fn	int DeltaTableHistory::getAttackValueRole();
	 *
	 * \brief	��ȡ��ǰ�غϽ�ɫ�Թ�����˺�(Ѫ��)ֵ.
	 *
	 * \return	���ص�ǰ�غϽ�ɫ�Թ�����˺�ֵ
	 */
	int getAttackValueRole();

	/*��
	 * \fn	int DeltaTableHistory::getBackBaseValue(const int rowIndex, const int colIndex);
	 *
	 * \brief	����ָ���������±�����ȡָ���Ļظ�����ֵ���磺��Ѫֵ���ؼ�ֵ...)
	 *
	 * \param	rowIndex	ָ�������±�
	 * \param	colIndex	ָ�������±�
	 *
	 * \return	����ָ���Ļظ�����ֵ
	 */
	int getBackBaseValue(const int rowIndex, const int colIndex);

	/*��
	 * \fn	int DeltaTableHistory::getCountBaseValueInInterval(int round,const int baseValueMax, const int leftInterval, const int rightInterval,const int rowIndex,const int colIndex);
	 *
	 * \brief	����ָ���������±�����ȡ��������ָ���Ļغ����ڵ�ָ���Ļ���ֵ��ָ�������ڵĴ���
	 *
	 * \param	round		 	ָ���Ļغ���
	 * \param	baseValueMax 	ָ������ֵ�����ֵ
	 * \param	leftInterval 	ָ����������
	 * \param	rightInterval	ָ����������
	 * \param	rowIndex	 	ָ�������±�
	 * \param	colIndex	 	ָ�������±�
	 *
	 * \return	���ؿ�������ָ���Ļغ����ڵ�ָ���Ļ���ֵ��ָ�������ڵĴ���
	 */
	int getCountBaseValueInInterval(int round,const int baseValueMax, const int leftInterval, const int rightInterval,const int rowIndex,const int colIndex);

	/*��
	 * \fn	bool DeltaTableHistory::checkOutOfRange(const int rowIndex, const int colIndex);
	 *
	 * \brief	����ָ���������±������ָ�����±��Ƿ�Խ��.
	 *
	 * \param	rowIndex	ָ�������±�
	 * \param	colIndex	ָ�������±�
	 *
	 * \return	����ָ�����±��Ƿ�Խ��
	 */
	bool checkOutOfRange(const int rowIndex, const int colIndex);

	/*��
	 * \fn	void DeltaTableHistory::getAllTableRoleByRound(int round, int& beginIndex, int& endIndex);
	 *
	 * \brief	����ָ���Ļغ�������ȡָ���غ������еĽ�ɫЧ����ʷ��ʼ�����ͽ�������
	 *
	 * \param	round		ָ���Ļغ���ֵ.
	 * \param	beginIndex	��Ž�ɫЧ����ʷ�Ŀ�ʼ����
	 * \param	endIndex  	��Ž�ɫЧ����ʷ�Ľ�������
	 */
	void getAllTableRoleByRound(int round, int& beginIndex, int& endIndex);

	/*��
	 * \fn	void DeltaTableHistory::getTableRoleByRoundAndIndex(int round, DeltaTable::RoundLevel index, int& beginIndex, int& endIndex);
	 *
	 * \brief	���ݸ����Ļغ�������������ȡָ�������ڵ����еĽ�ɫЧ����ʷ�Ŀ�ʼ�����ͽ�������
	 *
	 * \param	round	ָ���Ļغ���
	 * \param	index	ָ��������ֵ
	 * \param	beginIndex	��Ž�ɫЧ����ʷ�Ŀ�ʼ����
	 * \param	endIndex  ��Ž�ɫЧ����ʷ�Ľ�������	
	 */
	void getTableRoleByRoundAndIndex(int round, DeltaTable::RoundLevel index, int& beginIndex, int& endIndex);

	/*��
	 * \fn	bool DeltaTableHistory::addTableHistoryMonster(const DeltaTable& deltaTable);
	 *
	 * \brief	����ָ����������ṹ������ӹ���Ч����ʷ.
	 *
	 * \param	deltaTable	ָ����������ṹ��.
	 *
	 * \return	������ӹ���Ч����ʷ�Ƿ�ɹ�.
	 */
	bool addTableHistoryMonster(const DeltaTable& deltaTable);

	/*��
	 * \fn	void DeltaTableHistory::addTotalTableHistoryMonster(int round);
	 *
	 * \brief	���ݸ����Ļغ�������ӹ�����ʷ�ܱ�
	 *
	 * \param	round	ָ���Ļغ���ֵ
	 */
	void addTotalTableHistoryMonster(int round);

	/*��
	 * \fn	void DeltaTableHistory::getAllTableMonsterByRound(int round,int& beginIndex,int& endIndex);
	 *
	 * \brief	���ݸ����Ļغ�������ȡָ���غ������еĹ���Ч����ʷ��Ŀ�ʼ�����ͽ�������
	 *
	 * \param	round		ָ���Ļغ���ֵ.
	 * \param	beginIndex	��Ź���Ч����ʷ�Ŀ�ʼ����
	 * \param	endIndex  	��Ź���Ч����ʷ�Ľ�������
	 */
	void getAllTableMonsterByRound(int round,int& beginIndex,int& endIndex);

	/*��
	 * \fn	void DeltaTableHistory::getTableMonsterByRoundAndIndex(int round, DeltaTable::RoundLevel index, int& beginIndex, int& endIndex);
	 *
	 * \brief	���ݸ����Ļغ�������������ȡָ�������ڵ����еĹ�����ʷ��.
	 *
	 * \param	round		ָ���Ļغ���ֵ.
	 * \param	index		ָ��������ֵ
	 * \param	beginIndex	���ָ�������ڹ�����ʷ�Ŀ�ʼ����
	 * \param	endIndex  	���ָ�������ڹ�����ʷ�Ľ�������
	 */
	void getTableMonsterByRoundAndIndex(int round, DeltaTable::RoundLevel index, int& beginIndex, int& endIndex);

	/*��
	 * \fn	void DeltaTableHistory::getIndexByFlag(int& rowIndex, int& colIndex, DeltaTable::Flag flag);
	 *
	 * \brief	����ָ����ö�ٱ�־����ȡһ�������ݵ��±�����
	 *
	 * \param	rowIndex	��������ݵ����±�
	 * \param	colIndex	��������ݵ����±�
	 * \param	flag		ָ����ö�ٱ�־
	 */
	void getIndexByFlag(int& rowIndex, int& colIndex, DeltaTable::Flag flag);
	
	/*��
	 * \fn	void DeltaTableHistory::test();
	 *
	 * \brief	���Ե�Ԫ
	 */
	void test();

private:

	/* \brief	��ɫ��ʷ���������ڴ洢��ɫ��ʷЧ�� */
	std::vector<DeltaTable> tableHistoryRole;
	/* \brief	��ɫ�غ����������ڴ洢��ɫ��ʷЧ�����±����� */
	std::vector<DeltaRound> roundHistoryRole;
	/* \brief	��¼��ɫ��ʷ�Ļغ��� */
	int roundNumberRole = 1;

	/* \brief	������ʷ���������ڴ洢������ʷЧ��. */
	std::vector<DeltaTable> tableHistoryMonster;
	/* \brief	����غ����������ڴ洢������ʷЧ�����±����� */
	std::vector<DeltaRound> roundHistoryMonster;
	/* \brief	��¼������ʷ�Ļغ���. */
	int roundNumberMonster = 1;
};


#endif // !MZNQA_CLASSES_COMBATSYSTEM_DELTATABLEHISTORY_H_

