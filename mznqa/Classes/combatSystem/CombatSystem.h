/*!
 * \file	Classes\combatSystem\CombatSystem.h
 *
 * \brief	������ CombatSystem
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
 * \brief	ս��ϵͳ
 *
 */
class CombatSystem
{
public:

	/*!
	 * \fn	CombatSystem::CombatSystem();
	 *
	 * \brief	���캯��
	 *
	 */
	CombatSystem();

	/*!
	 * \fn	CombatSystem::~CombatSystem();
	 *
	 * \brief	��������
	 *
	 */
	~CombatSystem();

	/*!
	 * \fn	void CombatSystem::dispatchEffectFromCardSkillRole(int cardSkillID);
	 *
	 * \brief	���ݸ�����ɫ���ܿ���������Ч�������͵�Ч��������
	 *
	 * \param	cardSkillID	ָ����ɫ���ܿ�id
	 */
	void dispatchEffectFromCardSkillRole(int cardSkillID);

	/*!
	 * \fn	void CombatSystem::dispatchEffectFromCardSkillMonster(int cardSkillID);
	 *
	 * \brief	���ݸ������＼�ܿ���������Ч�������͵�Ч��������
	 *
	 * \param	cardSkillID	ָ�����＼�ܿ�id
	 */
	void dispatchEffectFromCardSkillMonster(int cardSkillID);

	/*!
	 * \fn	void CombatSystem::executeGlobalOperation();
	 *
	 * \brief	�غ��ڲ�����ȫ�ֲ���
	 *
	 */
	void executeGlobalOperation();

	/*!
	 * \fn	void CombatSystem::executeRoleBeforeTheCombatOperation();
	 *
	 * \brief	�غ��ڲ�������ɫս��ǰ�ڲ���
	 *
	 */
	void executeRoleBeforeTheCombatOperation();

	/*!
	 * \fn	void CombatSystem::excuteRoleInCombatOperation();
	 *
	 * \brief	�غ��ڲ�������ɫս��������
	 *
	 */
	void excuteRoleInCombatOperation();

	/*!
	 * \fn	void CombatSystem::excuteRoleAfterCombatOperation();
	 *
	 * \brief	�غ��ڲ�������ɫս�����ڲ���
	 *
	 */
	void excuteRoleAfterCombatOperation();

	/*!
	 * \fn	void CombatSystem::executeMonsterBeforeTheCombatOperator();
	 *
	 * \brief	�غ��ڲ���������ս��ǰ�ڲ���
	 *
	 */
	void executeMonsterBeforeTheCombatOperator();

	/*!
	 * \fn	void CombatSystem::excuteMonsterInCombatOperator();
	 *
	 * \brief	�غ��ڲ���������ս��������
	 *
	 */
	void excuteMonsterInCombatOperator();

	/*!
	 * \fn	void CombatSystem::excuteMonsterAfterCombatOperator();
	 *
	 * \brief	�غ��ڲ���������ս�����ڲ���
	 *
	 */
	void excuteMonsterAfterCombatOperator();

	/*!
	 * \fn	void CombatSystem::excuteCombat();
	 *
	 * \brief	ִ��һ�غ�ս��
	 *
	 */
	void excuteCombat();

	/*!
	 * \fn	void CombatSystem::setUseCardId(const int roleUseCardId, const int monsterUseCardId);
	 *
	 * \brief	�������ڵ��غ�ս����˫�����ܿ�
	 *
	 * \param	roleUseCardId   	ָ�����ڵ��غ�ս���Ľ�ɫ���ܿ�id
	 * \param	monsterUseCardId	ָ�����ڵ��غ�ս���Ľ�ɫ���ܿ�id
	 */
	void setUseCardId(const int roleUseCardId, const int monsterUseCardId);

	/*��
	 * \fn	void CombatSystem::setHistoryTotalTable(const int round);
	 *
	 * \brief	������ʷЧ�����ܱ�
	 */
	void setHistoryTotalTable();

	/*!
	 * \fn	bool CombatSystem::judgeEndToCombat();
	 *
	 * \brief	�ж��Ƿ����ս��
	 *
	 * \return	�����Ƿ����ս��
	 */
	bool judgeEndToCombat();

	/*��
	 * \fn	static EffectPQ& CombatSystem::getEffectPQ()
	 *
	 * \brief	��ȡЧ�����м��ϣ�������ɫ�͹����Ч�����У�
	 *
	 * \return	����Ч�����м���
	 */
	static EffectPQ& getEffectPQ()
	{
		return epq;
	}

	/*��
	 * \fn	static int& CombatSystem::getRound()
	 *
	 * \brief	��ȡս���غ���
	 *
	 * \return	����ս���غ���
	 */
	static int& getRound()
	{
		return round;
	}	

	static EffectAffixes& getEffectAffixes()
	{
		return efAffixes;
	}

	//���Ե�Ԫ
	void test();

private:
	/*! \brief	��ʶ�غ��� */
	static int round;

	/*! \brief	Ч�����м��ϣ�������ɫ�͹����Ч�����У� */
	static EffectPQ epq;

	/*! \brief	��ɫѡ��������ս���ļ��ܿ� */
	int roleUseCardId = CardBase::invalidID;
	/*! \brief	����ѡ��������ս���ļ��ܿ� */
	int monsterUseCardId = CardBase::invalidID;

	//��ǰЧ����������
	static EffectAffixes efAffixes;
};

#endif // !MZNQA_CLASSES_COMBATSYSTEM_COMBATSYSTEM_H_
