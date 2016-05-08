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
	 * \param	dt	ָ����������ṹ��.
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
	 * \fn	const std::vector<DeltaTable>& DeltaTableHistory::getAllTableRoleByRound(int round);
	 *
	 * \brief	���ݸ����Ļغ�������ȡָ���غ������еĽ�ɫ��ʷЧ����.
	 *
	 * \param	round	ָ���Ļغ���ֵ.
	 *
	 * \return	����ָ���غ������еĽ�ɫ��ʷЧ����.
	 */
	const std::vector<DeltaTable>& getAllTableRoleByRound(int round);

	/*��
	 * \fn	const std::vector<DeltaTable>& DeltaTableHistory::getTableRoleByRoundAndIndex(int round, DeltaTable::RoundLevel index);
	 *
	 * \brief	���ݸ����Ļغ�������������ȡָ�������ڵ����еĽ�ɫ��ʷ��.
	 *
	 * \param	round	ָ���Ļغ���ֵ.
	 * \param	index	ָ��������ֵ.
	 *
	 * \return	����ָ�������ڵ����еĽ�ɫ��ʷЧ����.
	 */
	const std::vector<DeltaTable>& getTableRoleByRoundAndIndex(int round, DeltaTable::RoundLevel index);

	/*��
	 * \fn	const std::vector<DeltaTable>& DeltaTableHistory::getTableRoleInCurrentRound(int round);
	 *
	 * \brief	����ָ���Ļغ�������ȡ��ɫ��ǰ�غϵ���ʷЧ����.
	 *
	 * \param	round	ָ���Ļغ���ֵ.
	 *
	 * \return	���ؽ�ɫ��ǰ�غϵ���ʷЧ����.
	 */
	const std::vector<DeltaTable>& getTableRoleInCurrentRound();

	/*��
	 * \fn	bool DeltaTableHistory::addTableHistoryMonster(DeltaTable deltaTable);
	 *
	 * \brief	����ָ����������ṹ�壬����ӹ���Ч����ʷ.
	 *
	 * \param	dt	ָ����������ṹ��.
	 *
	 * \return	������ӹ���Ч����ʷ�Ƿ�ɹ�.
	 */
	bool addTableHistoryMonster(const DeltaTable& deltaTable);

	/*��
	 * \fn	void DeltaTableHistory::addTotalTableHistoryMonster(int round);
	 *
	 * \brief	���ݸ����Ļغ�������ȡָ���غ������еĹ�����ʷЧ����.
	 *
	 * \param	round	ָ���Ļغ���ֵ.
	 */
	void addTotalTableHistoryMonster(int round);

	/*��
	 * \fn	const std::vector<DeltaTable>& DeltaTableHistory::getAllTableMonsterByRound(int round);
	 *
	 * \brief	���ݸ����Ļغ�������ȡָ���غ������еĹ�����ʷЧ����.
	 *
	 * \param	round	ָ���Ļغ���ֵ.
	 *
	 * \return	����ָ���غ������еĹ�����ʷЧ����.
	 */
	const std::vector<DeltaTable>& getAllTableMonsterByRound(int round);

	/*��
	 * \fn	const std::vector<DeltaTable>& DeltaTableHistory::getTableMonsterByRoundAndIndex(int round, DeltaTable::RoundLevel index);
	 *
	 * \brief	���ݸ����Ļغ�������������ȡָ�������ڵ����еĹ�����ʷ��.
	 *
	 * \param	round	ָ���Ļغ���ֵ.
	 * \param	index	ָ��������ֵ.
	 *
	 * \return	����ָ�������ڵ����еĹ�����ʷЧ����.
	 */
	const std::vector<DeltaTable>& getTableMonsterByRoundAndIndex(int round, DeltaTable::RoundLevel index);

	/*��
	 * \fn	const std::vector<DeltaTable>& DeltaTableHistory::getTableMonsterInCurrentRound();
	 *
	 * \brief	����ָ���Ļغ�������ȡ���ﵱǰ�غϵ���ʷЧ����.
	 *
	 * \return	���ع��ﵱǰ�غϵ���ʷЧ����.
	 *
	 * param	round	ָ���Ļغ���ֵ.
	 */

	const std::vector<DeltaTable>& getTableMonsterInCurrentRound();

	//��ȡһ�������ݵ��±�������ͨ��һ����־
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

	/* \brief	��ʱ���������ڷ��ػ�ȡ����ʷЧ���� */
	std::vector<DeltaTable> tableTemp;
};


#endif // !MZNQA_CLASSES_COMBATSYSTEM_DELTATABLEHISTORY_H_

