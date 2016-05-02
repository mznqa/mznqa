#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_COMBATSYSTEM_COMBATSYSTEMINTERFACE_H_
#define MZNQA_CLASSES_COMBATSYSTEM_COMBATSYSTEMINTERFACE_H_

#include "gameobject/Role.h"
#include "gameobject/Monster.h"
#include "combatSystem/DeltaTableHistory.h"
#include "combatSystem/EffectPQ.h"
#include "combatSystem/CombatSystem.h"
#include "Effect/Effect.h"

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
	int getRoleBlood();

	/*��
	 * \fn	int CombatSystemInterface::getRoleArmor();
	 *
	 * \brief	��ȡ��ɫ��ǰ����
	 *
	 * \return	���ؽ�ɫ��ǰ����
	 */
	int getRoleArmor();

	/*��
	 * \fn	int CombatSystemInterface::getRoleBloodMax();
	 *
	 * \brief	��ȡ��ɫѪ������
	 *
	 * \return	���ؽ�ɫѪ������
	 */
	int getRoleBloodMax();

	/*��
	 * \fn	int CombatSystemInterface::getRoleHandCount();
	 *
	 * \brief	��ȡ��ɫ��ǰ������
	 *
	 * \return	���ؽ�ɫ��ǰ������
	 */
	int getRoleHandCount();

	/*��
	 * \fn	void CombatSystemInterface::updateRoleHandCount(int delta);
	 *
	 * \brief	���ݸ����������������½�ɫ��������
	 *
	 * \param	delta	ָ�������ڸ��½�ɫ��������������
	 */
	void updateRoleHandCount(int delta);

	/*��
	 * \fn	void CombatSystemInterface::setRoleDiscountCount(int delta);
	 *
	 * \brief	����ָ��ֵ�����ý�ɫ������
	 *
	 * \param	delta	ָ���������ý�ɫ��������ֵ
	 */
	void setRoleDiscountCount(int delta);

	/*��
	 * \fn	void CombatSystemInterface::updateRoleDrawCardCount(int delta);
	 *
	 * \brief	���ݸ����������������½�ɫ�ĳ�����
	 *
	 * \param	delta	ָ�������ڸ��½�ɫ��������������
	 */
	void updateRoleDrawCardCount(int delta);

	/*��
	 * \fn	void CombatSystemInterface::updateRoleBlood(int delta);
	 *
	 * \brief	���ݸ����������������½�ɫ��Ѫ��
	 *
	 * \param	delta	ָ�������ڸ��½�ɫѪ����������
	 */
	void updateRoleBlood(int delta);

	/*��
	 * \fn	void CombatSystemInterface::updateRoleArmor(int delta);
	 *
	 * \brief	���ݸ����������������½�ɫ�Ļ���
	 *
	 * \param	delta	ָ�������ڸ��½�ɫ���׵�������
	 */
	void updateRoleArmor(int delta);

	/*��
	 * \fn	int CombatSystemInterface::getMonsterBlood();
	 *
	 * \brief	��ȡ���ﵱǰѪ��
	 *
	 * \return	���ع��ﵱǰѪ��
	 */
	int getMonsterBlood();

	/*��
	 * \fn	int CombatSystemInterface::getMonsterArmor();
	 *
	 * \brief	��ȡ���ﵱǰ����
	 *
	 * \return	���ع��ﵱǰ����
	 */
	int getMonsterArmor();

	/*��
	 * \fn	int CombatSystemInterface::getMonsterBloodMax();
	 *
	 * \brief	��ȡ����Ѫ������
	 *
	 * \return	���ع���Ѫ������
	 */
	int getMonsterBloodMax();

	/*��
	 * \fn	void CombatSystemInterface::updateMonsterBlood(int delta);
	 *
	 * \brief	���ݸ����������������¹����Ѫ��
	 *
	 * \param	delta	ָ�������ڸ��¹���Ѫ����������
	 */
	void updateMonsterBlood(int delta);

	/*��
	 * \fn	void CombatSystemInterface::updateMonsterArmor(int delta);
	 *
	 * \brief	���ݸ����������������¹���Ļ���
	 *
	 * \param	delta	ָ�������ڸ��¹��ﻤ�׵�������
	 */
	void updateMonsterArmor(int delta);

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
	* \fn	std::vector<DeltaTable>& CombatSystemInterface::getRoundRoleDeltaTable()
	*
	* \brief	��ȡ��ɫ��ǰ�غϵ�Ч����ʷ����
	*
	* \return	���ؽ�ɫ��ǰ�غϵ�Ч����ʷ����
	*/
	std::vector<DeltaTable>& getRoundRoleDeltaTable()
	{
		return deltaRole;
	}

	/*��
	 * \fn	void CombatSystemInterface::setCurentRoundRoleDeltaTable(int round);
	 *
	 * \brief	���ݸ����Ļغ��������ù��ﵱǰ��ɫЧ����ʷ����
	 *
	 * \param	round	�����Ļغ���ֵ
	 */
	void setCurentRoundRoleDeltaTable(int round);

	/*��
	 * \fn	void CombatSystemInterface::setCurrentRoundMonsterDeltaTable(int round);
	 *
	 * \brief	���ݸ����Ļغ��������ù��ﵱǰ����Ч����ʷ����
	 *
	 * \param	round	�����Ļغ���ֵ
	 */
	void setCurrentRoundMonsterDeltaTable(int round);

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
	 * \fn	std::vector<DeltaTable>& CombatSystemInterface::getRoundMonsterDeltaTable()
	 *
	 * \brief	��ȡ���ﵱǰ��ʷЧ������
	 *
	 * \return	���ع��ﵱǰ��ʷЧ������
	 */
	std::vector<DeltaTable>& getRoundMonsterDeltaTable()
	{
		return deltaMonster;
	}

	/*��
	 * \fn	void CombatSystemInterface::setEffectArgs(const std::vector<int>& args)
	 *
	 * \brief	���ݸ����Ĳ��������õ�ǰ��Ч������
	 *
	 * \param	args	ָ�����������õ�ǰЧ������������ֵ
	 */
	void setEffectArgs(const std::vector<int>& args)
	{
		this->efArgs = args;
	}

	/*��
	 * \fn	const std::vector<int>& CombatSystemInterface::getEffectArgs() const
	 *
	 * \brief	��ȡ��ǰЧ���Ĳ���
	 *
	 * \return	���ص�ǰЧ���Ĳ���
	 */
	const std::vector<int>& getEffectArgs() const
	{
		return efArgs;
	}

	/*��
	 * \fn	void CombatSystemInterface::setEffectAffixes(const EffectAffixes& ea)
	 *
	 * \brief	���ݸ�����Ч���������������õ�ǰЧ���ĸ�������
	 *
	 * \param	ea	ָ����Ч����������
	 */
	void setEffectAffixes(const EffectAffixes& ea)
	{
		this->effectAffixes = ea;
	}

	/*��
	 * \fn	const EffectAffixes& CombatSystemInterface::getEffectAffixes() const
	 *
	 * \brief	��ȡ��ǰЧ����������
	 *
	 * \return	���ص�ǰЧ����������
	 */
	const EffectAffixes& getEffectAffixes() const
	{
		return effectAffixes;
	}

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
	 * \fn	CombatSystemInterface CombatSystemInterface::operator=(const CombatSystemInterface& csi);
	 *
	 * \brief	=�����
	 *
	 * \param	csi	CombatSystemInterfaceʵ��
	 *
	 * \return	A shallow copy of this object.
	 */
	CombatSystemInterface operator=(const CombatSystemInterface& csi);

	/* \brief	����ս������. */
	Monster monster;
	/* \brief	��ʷЧ��ʵ����������ɫ��ʷЧ��������������ʷЧ������ */
	DeltaTableHistory dtHistory;
	/* \brief	��ɫ��ǰ�غϵ���ʷЧ������ */
	std::vector<DeltaTable> deltaRole;
	/* \brief	���ﵱǰ�غϵ���ʷЧ������ */
	std::vector<DeltaTable> deltaMonster;	
	/* \brief	������������ǰЧ���������� */
	std::vector<int> efArgs;
	/* \brief	��ǰЧ���ĸ������� */
	EffectAffixes effectAffixes;
};


#endif // MZNQA_CLASSES_COMBATSYSTEM_COMBATSYSTEMINTERFACE_H_