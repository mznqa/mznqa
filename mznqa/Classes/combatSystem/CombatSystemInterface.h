#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_COMBATSYSTEM_COMBATSYSTEMINTERFACE_H_
#define MZNQA_CLASSES_COMBATSYSTEM_COMBATSYSTEMINTERFACE_H_

#include "gameobject/Role.h"
#include "gameobject/Monster.h"
#include "combatSystem/DeltaTableHistory.h"
#include "combatSystem/CombatSystem.h"

/*��
 * \class	CombatSystemInterface
 *
 * \brief	ս��ϵͳ�Ľӿڼ���
 *
 */
class CombatSystemInterface
{
public:

	/*��
	 * \fn	CombatSystemInterface::~CombatSystemInterface();
	 *
	 * \brief	��������.
	 *
	 */
	~CombatSystemInterface()
	{

	}

	/*��
	 * \fn	static CombatSystemInterface& CombatSystemInterface::Instance();
	 *
	 * \brief	��ȡ����.
	 *
	 * \return	���ص���.
	 */
	static CombatSystemInterface* Instance();

	/*��
	 * \fn	int CombatSystemInterface::getRoleBlood();
	 *
	 * \brief	��ȡ��ɫ��ǰѪ��
	 *
	 * \return	���ؽ�ɫ��ǰѪ��
	 */
	int getBloodRole();

	/*��
	 * \fn	int CombatSystemInterface::getRoleArmor();
	 *
	 * \brief	��ȡ��ɫ��ǰ����
	 *
	 * \return	���ؽ�ɫ��ǰ����
	 */
	int getArmorRole();

	/*��
	 * \fn	int CombatSystemInterface::getRoleBloodMax();
	 *
	 * \brief	��ȡ��ɫѪ������
	 *
	 * \return	���ؽ�ɫѪ������
	 */
	int getBloodMaxRole();

	/*��
	 * \fn	int CombatSystemInterface::getRoleHandCount();
	 *
	 * \brief	��ȡ��ɫ��ǰ������
	 *
	 * \return	���ؽ�ɫ��ǰ������
	 */
	int getHandCountRole();

	/*��
	 * \fn	void CombatSystemInterface::updateRoleHandCount(int delta);
	 *
	 * \brief	���ݸ����������������½�ɫ��������
	 *
	 * \param	delta	ָ�������ڸ��½�ɫ��������������
	 */
	void updateHandCountRole(int delta);

	/*��
	 * \fn	void CombatSystemInterface::setRoleDiscountCount(int delta);
	 *
	 * \brief	����ָ��ֵ�����ý�ɫ������
	 *
	 * \param	delta	ָ���������ý�ɫ��������ֵ
	 */
	void setDiscountCountRole(int delta);

	/*��
	 * \fn	void CombatSystemInterface::updateRoleDrawCardCount(int delta);
	 *
	 * \brief	���ݸ����������������½�ɫ�ĳ�����
	 *
	 * \param	delta	ָ�������ڸ��½�ɫ��������������
	 */
	void updateDrawCardCountRole(int delta);

	/*��
	 * \fn	void CombatSystemInterface::updateRoleBlood(int delta);
	 *
	 * \brief	���ݸ����������������½�ɫ��Ѫ��
	 *
	 * \param	delta	ָ�������ڸ��½�ɫѪ����������
	 */
	void updateBloodRole(int delta);

	/*��
	 * \fn	void CombatSystemInterface::updateRoleArmor(int delta);
	 *
	 * \brief	���ݸ����������������½�ɫ�Ļ���
	 *
	 * \param	delta	ָ�������ڸ��½�ɫ���׵�������
	 */
	void updateArmorRole(int delta);

	/*��
	 * \fn	int CombatSystemInterface::getMonsterBlood();
	 *
	 * \brief	��ȡ���ﵱǰѪ��
	 *
	 * \return	���ع��ﵱǰѪ��
	 */
	int getBloodMonster();

	/*��
	 * \fn	int CombatSystemInterface::getMonsterArmor();
	 *
	 * \brief	��ȡ���ﵱǰ����
	 *
	 * \return	���ع��ﵱǰ����
	 */
	int getArmorMonster();

	/*��
	 * \fn	int CombatSystemInterface::getMonsterBloodMax();
	 *
	 * \brief	��ȡ����Ѫ������
	 *
	 * \return	���ع���Ѫ������
	 */
	int getBloodMaxMonster();

	/*��
	 * \fn	void CombatSystemInterface::updateMonsterBlood(int delta);
	 *
	 * \brief	���ݸ����������������¹����Ѫ��
	 *
	 * \param	delta	ָ�������ڸ��¹���Ѫ����������
	 */
	void updateBloodMonster(int delta);

	/*��
	 * \fn	void CombatSystemInterface::updateMonsterArmor(int delta);
	 *
	 * \brief	���ݸ����������������¹���Ļ���
	 *
	 * \param	delta	ָ�������ڸ��¹��ﻤ�׵�������
	 */
	void updateArmorMonster(int delta);

	/*��
	* \fn	DeltaTableHistory& CombatSystemInterface::getDeltaTableHistory();
	*
	* \brief	��ȡ��ʷЧ��ʵ��
	*
	* \return	������ʷЧ��ʵ��
	*/
	DeltaTableHistory& getDeltaTableHistory()
	{
		return dtHistory;
	}

	/*��
	 * \fn	const std::vector<DeltaTable>& CombatSystemInterface::getDeltaTableRoleInCurrentRound();
	 *
	 * \brief	����ָ���Ļغ�������ȡ��ɫ��ǰ�غϵ�Ч����ʷ����.
	 *
	 * \return	���ؽ�ɫ��ǰ�غϵ�Ч����ʷ����.
	 */
	const std::vector<DeltaTable>& getDeltaTableRoleInCurrentRound();
	
	/*��
	 * \fn	const std::vector<DeltaTable>& CombatSystemInterface::getRoundRoleDeltaTable(int round, DeltaTable::RoundLevel index);
	 *
	 * \brief	����ָ���Ļغ�������������ȡָ�������ڵ����еĽ�ɫЧ����ʷ
	 *
	 * \param	round	ָ���Ļغ���ֵ
	 * \param	index	ָ��������ֵ
	 *
	 * \return	����ָ�������ڵ����н�ɫЧ����ʷ
	 */
	const std::vector<DeltaTable>& getRoundRoleDeltaTable(int round, DeltaTable::RoundLevel index);

	/*��
	 * \fn	const std::vector<DeltaTable>& CombatSystemInterface::getRoundMonsterDeltaTable(int round, DeltaTable::RoundLevel index);
	 *
	 * \brief	����ָ���Ļغ�������������ȡָ�������ڵ����еĹ���Ч����ʷ
	 *
	 * \param	round	ָ���Ļغ���ֵ
	 * \param	index	ָ��������ֵ
	 *
	 * \return	����ָ�������ڵ����й���Ч����ʷ
	 */
	const std::vector<DeltaTable>& getRoundMonsterDeltaTable(int round, DeltaTable::RoundLevel index);

	/*��
	 * \fn	const std::vector<DeltaTable>& CombatSystemInterface::getDeltaTableMonsterInCurrentRound();
	 *
	 * \brief	����ָ���Ļغ�������ȡ���ﵱǰ��ʷЧ������.
	 *
	 * \return	���ع��ﵱǰ��ʷЧ������.
	 *
	 * param	round	ָ���Ļغ���.
	 */
	const std::vector<DeltaTable>& getDeltaTableMonsterInCurrentRound();

	/*��
	 * \fn	const EffectAffixes& CombatSystemInterface::getCurrentEffectAffixes()
	 *
	 * \brief	��ȡ��ǰЧ���ĸ�������
	 *
	 * \return	���ص�ǰ��Ч������
	 */
	const EffectAffixes& getCurrentEffectAffixes();

	/*��
	 * \fn	EffectPQ& CombatSystemInterface::getEffectPQ();
	 *
	 * \brief	��ȡЧ������
	 *
	 * \return	����Ч������
	 */
	EffectPQ& getEffectPQ();

private:

	/*��
	 * \fn	CombatSystemInterface::CombatSystemInterface();
	 *
	 * \brief	���صĹ��캯��.
	 *
	 */
	CombatSystemInterface(){}

	/*��
	 * \fn	CombatSystemInterface::CombatSystemInterface(const CombatSystemInterface& csi);
	 *
	 * \brief	���ƹ��캯��
	 *
	 * \param	csi	CombatSystemInterfaceʵ��
	 */
	CombatSystemInterface(const CombatSystemInterface& csi);

	/*��
	 * \fn	CombatSystemInterface& CombatSystemInterface::operator=(const CombatSystemInterface& csi);
	 *
	 * \brief	=�����
	 *
	 * \param	csi	CombatSystemInterfaceʵ��
	 *
	 * \return	����CombatSystemInterface��������
	 */
	CombatSystemInterface& operator=(const CombatSystemInterface& csi);

	/* \brief	��ɫ����ָ�� */
	Role *const role = Role::Instance();

	//����ս������---������ //////////////////////////////////////////////////////////////////////////
	Monster monster;
	//��ʷЧ��ʵ����������ɫ��ʷЧ��������������ʷЧ������---������/////////////////////////////////////////
	DeltaTableHistory dtHistory;
};


#endif // MZNQA_CLASSES_COMBATSYSTEM_COMBATSYSTEMINTERFACE_H_