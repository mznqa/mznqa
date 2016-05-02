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
	 * \fn	bool DeltaTableHistory::addTableRoleHistory(const DeltaTable& dt);
	 *
	 * \brief	����ָ����������ṹ�壬����ӽ�ɫЧ����ʷ
	 *
	 * \param	dt	ָ����������ṹ��
	 *
	 * \return	������ӽ�ɫЧ����ʷ�Ƿ�ɹ�
	 */
	bool addTableRoleHistory(const DeltaTable& dt);

	/*��
	 * \fn	void DeltaTableHistory::addTotalRoleHistory(int round);
	 *
	 * \brief	����ָ���Ļغ��������ָ���غϵĽ�ɫЧ���ܱ�
	 *
	 * \param	round	ָ���Ļغ���ֵ
	 *
	 */
	void addTotalRoleHistory(int round);

	/*��
	 * \fn	const std::vector<DeltaTable>& DeltaTableHistory::getRoundAllRoleTable(int round);
	 *
	 * \brief	���ݸ����Ļغ�������ȡָ���غ������еĽ�ɫ��ʷЧ����
	 *
	 * \param	round	ָ���Ļغ���ֵ
	 *
	 * \return	����ָ���غ������еĽ�ɫ��ʷЧ����
	 */
	const std::vector<DeltaTable>& getRoundAllRoleTable(int round);

	/*��
	 * \fn	const std::vector<DeltaTable>& DeltaTableHistory::getRoundRoleTable(int round, DeltaTable::RoundLevel index);
	 *
	 * \brief	���ݸ����Ļغ�������������ȡָ�������ڵ����еĽ�ɫ��ʷ��
	 *
	 * \param	round	ָ���Ļغ���ֵ
	 * \param	index	ָ��������ֵ
	 *
	 * \return	����ָ�������ڵ����еĽ�ɫ��ʷЧ����
	 */
	const std::vector<DeltaTable>& getRoundRoleTable(int round, DeltaTable::RoundLevel index);

	/*��
	 * \fn	const std::vector<DeltaTable>& DeltaTableHistory::getCurrentRoundRoleTable(int round);
	 *
	 * \brief	����ָ���Ļغ�������ȡ��ɫ��ǰ�غϵ���ʷЧ����
	 *
	 * \param	round	ָ���Ļغ���ֵ
	 *
	 * \return	���ؽ�ɫ��ǰ�غϵ���ʷЧ����
	 */
	const std::vector<DeltaTable>& getCurrentRoundRoleTable(int round);

	/*��
	 * \fn	bool DeltaTableHistory::addTableMonsterHistory(DeltaTable dt);
	 *
	 * \brief	����ָ����������ṹ�壬����ӹ���Ч����ʷ
	 *
	 * \param	dt	ָ����������ṹ��
	 *
	 * \return	������ӹ���Ч����ʷ�Ƿ�ɹ�
	 */
	bool addTableMonsterHistory(DeltaTable dt);

	/*��
	 * \fn	void DeltaTableHistory::addTotalMonsterHistory(int round);
	 *
	 * \brief	���ݸ����Ļغ�������ȡָ���غ������еĹ�����ʷЧ����
	 *
	 * \param	round	ָ���Ļغ���ֵ
	 */
	void addTotalMonsterHistory(int round);
	
	/*��
	 * \fn	const std::vector<DeltaTable>& DeltaTableHistory::getRoundAllMonsterTable(int round);
	 *
	 * \brief	���ݸ����Ļغ�������ȡָ���غ������еĹ�����ʷЧ����
	 *
	 * \param	round	ָ���Ļغ���ֵ
	 *
	 * \return	����ָ���غ������еĹ�����ʷЧ����
	 */
	const std::vector<DeltaTable>& getRoundAllMonsterTable(int round);

	/*��
	 * \fn	const std::vector<DeltaTable>& DeltaTableHistory::getRoundMonsterTable(int round, DeltaTable::RoundLevel index);
	 *
	 * \brief	���ݸ����Ļغ�������������ȡָ�������ڵ����еĹ�����ʷ��
	 *
	 * \param	round	ָ���Ļغ���ֵ
	 * \param	index	ָ��������ֵ
	 *
	 * \return	����ָ�������ڵ����еĹ�����ʷЧ����
	 */
	const std::vector<DeltaTable>& getRoundMonsterTable(int round, DeltaTable::RoundLevel index);

	/*��
	 * \fn	const std::vector<DeltaTable>& DeltaTableHistory::getCurrentRoundMonsterTable(int round);
	 *
	 * \brief	����ָ���Ļغ�������ȡ���ﵱǰ�غϵ���ʷЧ����
	 *
	 * \param	round	ָ���Ļغ���ֵ
	 *
	 * \return	���ع��ﵱǰ�غϵ���ʷЧ����
	 */
	const std::vector<DeltaTable>& getCurrentRoundMonsterTable(int round);

	/*��
	 * \fn	void DeltaTableHistory::test();
	 *
	 * \brief	���Ե�Ԫ
	 */
	void test();

private:

	/* \brief	��ɫ��ʷ���������ڴ洢��ɫ��ʷЧ�� */
	std::vector<DeltaTable> tableRoleHistory;
	/* \brief	��ɫ�غ����������ڴ洢��ɫ��ʷЧ�����±����� */
	std::vector<DeltaRound> roundRoleHistory;
	/* \brief	��¼��ɫ��ʷ�Ļغ��� */
	int roundNumberRole = 1;

	/* \brief	������ʷ���������ڴ洢������ʷЧ��. */
	std::vector<DeltaTable> tableMonsterHistory;
	/* \brief	����غ����������ڴ洢������ʷЧ�����±����� */
	std::vector<DeltaRound> roundMonsterHistory;
	/* \brief	��¼������ʷ�Ļغ���. */
	int roundNumberMonster = 1;

	/* \brief	��ʱ���������ڷ��ػ�ȡ����ʷЧ���� */
	std::vector<DeltaTable> tableTemp;
};


#endif // !MZNQA_CLASSES_COMBATSYSTEM_DELTATABLEHISTORY_H_

