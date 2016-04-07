/*!
 * \file	Classes\gameobject\Monster.h
 *
 * \brief	������ Monster
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_GAMEOBJECT_MONSTER_H_
#define MZNQA_CLASSES_GAMEOBJECT_MONSTER_H_

#include <string>

#include "cocos2d.h"

#include "cardController/CardControllerCombat.h"

/*!
 * \class	Monster
 *
 * \brief	����
 *
 */
class Monster
{
private:
	/*! \brief	��������� */
	std::string name;
	/*! \brief	��������� */
	std::string describe;
	/*! \brief	����Ļ���Ѫ������ */
	int baseBloodValueMax;
	/*! \brief	����Ļ����������� */
	int baseArmorValueMax;

	/*! \brief	�����Ѫ��ʵʱ�� */
	int bloodValue;
	/*! \brief	����Ļ���ʵʱ�� */
	int armorValue;
	/*! \brief	����ĸ���Ѫ������ */
	int additionalBloodValueMax;
	/*! \brief	����ĸ��ӻ������� */
	int additionalArmorValueMax;
public:

	/*!
	 * \fn	Monster::Monster();
	 *
	 * \brief	���캯��
	 *
	 */
	Monster();

	/*!
	 * \fn	Monster::~Monster();
	 *
	 * \brief	��������
	 *
	 */
	~Monster();

	/*! \brief	ս�������µĿ��ƹ����� */
	CardControllerCombat cardControllerCombat;

	/*!
	 * \fn	const std::string& Monster::getName()const
	 *
	 * \brief	��ȡ���������
	 *
	 * \return	���ع��������
	 */
	const std::string& getName()const
	{
		return name;
	}

	/*!
	 * \fn	const std::string& Monster::getDescribe()const
	 *
	 * \brief	��ȡ���������
	 *
	 * \return	���ع��������
	 */
	const std::string& getDescribe()const
	{
		return describe;
	}

	/*!
	 * \fn	int Monster::getBaseBloodValueMax()const
	 *
	 * \brief	��ȡ����Ļ���Ѫ������
	 *
	 * \return	���ع���Ļ���Ѫ������
	 */
	int getBaseBloodValueMax()const
	{
		return baseBloodValueMax;
	}

	/*!
	 * \fn	int Monster::getBaseArmorValueMax()const
	 *
	 * \brief	��ȡ����Ļ�����������
	 *
	 * \return	��ȡ����Ļ�����������
	 */
	int getBaseArmorValueMax()const
	{
		return baseArmorValueMax;
	}

	/*!
	 * \fn	int Monster::getBloodValueMax()const
	 *
	 * \brief	��ȡ���ﵱǰ��Ѫ������
	 *
	 * \return	���ع��ﵱǰ��Ѫ������
	 */
	int getBloodValueMax()const
	{
		return baseBloodValueMax + additionalBloodValueMax;
	}

	/*!
	 * \fn	int Monster::getArmorValueMax()const
	 *
	 * \brief	��ȡ���ﵱǰ�Ļ�������
	 *
	 * \return	���ع��ﵱǰ�Ļ�������
	 */
	int getArmorValueMax()const
	{
		return baseArmorValueMax + additionalArmorValueMax;
	}

	/*!
	 * \fn	int Monster::getBloodValue()const
	 *
	 * \brief	��ȡ���ﵱǰ��Ѫ��
	 *
	 * \return	���ع��ﵱǰ��Ѫ��
	 */
	int getBloodValue()const
	{
		return bloodValue;
	}

	/*!
	 * \fn	void Monster::setBloodValue(int bloodValue)
	 *
	 * \brief	���ݸ���ֵ�����ù��ﵱǰ��Ѫ��
	 *
	 * \param	bloodValue	ָ�����������ù��ﵱǰѪ����ֵ
	 */
	void setBloodValue(int bloodValue)
	{
		if (0 <= bloodValue && bloodValue <= getBloodValueMax())
			this->bloodValue = bloodValue;
		else
		{
			cocos2d::log("[warning] ����Ϊ��������Խ��Ѫ��");
		}
	}

	/*!
	 * \fn	void Monster::updateBloodValue(int delta)
	 *
	 * \brief	���ݸ��������������¹��ﵱǰ��Ѫ��
	 *
	 * \param	delta	ָ�������ڸ��¹��ﵱǰѪ����������
	 */
	void updateBloodValue(int delta)
	{
		int temp = bloodValue + delta;
		if (0 <= temp && temp <= getBloodValueMax())
			this->bloodValue = temp;
		else
		{
			cocos2d::log("[warning] ���Ը��¹���Ѫ��������Ѫ��Խ�磬�仯��Ϊ%d, ����ǰѪ��Ϊ%d", delta, bloodValue);
		}
	}

	/*!
	 * \fn	int Monster::getArmorValue()const
	 *
	 * \brief	��ȡ���ﵱǰ����
	 *
	 * \return	���ع��ﵱǰ����
	 */
	int getArmorValue()const
	{
		return armorValue;
	}

	/*!
	 * \fn	void Monster::setArmorValue(int armorValue)
	 *
	 * \brief	���ݸ�����ֵ�����ù��ﵱǰ�Ļ���
	 *
	 * \param	armorValue	ָ�����������ù��ﵱǰ���׵�ֵ
	 */
	void setArmorValue(int armorValue)
	{
		if (0 <= armorValue && armorValue <= getArmorValue())
			this->armorValue = armorValue;
		else
		{
			cocos2d::log("[warning] ����Ϊ��������Խ��Ѫ��");
		}
	}

	/*!
	 * \fn	void Monster::updateArmorValue(int delta)
	 *
	 * \brief	���ݸ��������������¹��ﵱǰ�Ļ���
	 *
	 * \param	delta	ָ�������ڸ��¹��ﵱǰ���׵�������
	 */
	void updateArmorValue(int delta)
	{
		int temp = armorValue + delta;
		if (0 <= temp && temp <= getArmorValue())
			this->armorValue = temp;
		else
		{
			cocos2d::log("[warning] ���Ը��¹���Ļ��ף���������Խ�磬�仯��Ϊ%d������ǰ����Ϊ%d", delta, armorValue);
		}
	}

	/*!
	 * \fn	int Monster::getAdditionalBloodValueMax()const
	 *
	 * \brief	��ȡ���ﵱǰ�ĸ���Ѫ������
	 *
	 * \return	���ع��ﵱǰ�ĸ���Ѫ������
	 */
	int getAdditionalBloodValueMax()const
	{
		return additionalBloodValueMax;
	}

	/*!
	 * \fn	void Monster::setAdditionalBloodValueMax(int additionalBloodValueMax)
	 *
	 * \brief	���ݸ�����ֵ�����ù��ﵱǰ�ĸ���Ѫ������
	 *
	 * \param	additionalBloodValueMax	ָ���������ù��ﵱǰ�ĸ���Ѫ������
	 */
	void setAdditionalBloodValueMax(int additionalBloodValueMax)
	{
		if (baseBloodValueMax + additionalBloodValueMax >= 0)
			this->additionalBloodValueMax = additionalBloodValueMax;
		else
		{
			cocos2d::log("[warning] ����Ϊ�������ø���Ѫ������ʧ�ܣ�������Ѫ�����޲��Ϸ�");
		}
	}

	/*!
	 * \fn	void Monster::updateAdditionalBloodValueMax(int delta)
	 *
	 * \brief	���ݸ����������������¹��ﵱǰ�ĸ���Ѫ������
	 *
	 * \param	delta	ָ�����������ù��ﵱǰ�ĸ���Ѫ�����޵�������
	 */
	void updateAdditionalBloodValueMax(int delta)
	{
		if (baseBloodValueMax + additionalBloodValueMax + delta >= 0)
			this->additionalBloodValueMax += delta;
		else
		{
			cocos2d::log("[warning] ���Ը��¹���ĸ���Ѫ������ʧ�ܣ�������Ѫ�����޲��Ϸ�");
		}
	}

	/*!
	 * \fn	int Monster::getAdditionalArmorValueMax()const
	 *
	 * \brief	��ȡ���ﵱǰ�ĸ��ӻ�������
	 *
	 * \return	���ع��ﵱǰ�ĸ��ӻ�������
	 */
	int getAdditionalArmorValueMax()const
	{
		return additionalBloodValueMax;
	}

	/*!
	 * \fn	void Monster::setAdditionArmorValueMax(int additionalArmorValueMax)
	 *
	 * \brief	���ݸ�����ֵ�����ù��ﵱǰ�ĸ��ӻ�������
	 *
	 * \param	additionalArmorValueMax	ָ�����������ù��ﵱǰ�ĸ��ӻ������޵�ֵ
	 */
	void setAdditionArmorValueMax(int additionalArmorValueMax)
	{
		if (baseArmorValueMax + additionalArmorValueMax >= 0)
			this->additionalArmorValueMax = additionalArmorValueMax;
		else
		{
			cocos2d::log("[warning] ����Ϊ�������ø��ӵĻ�������ʧ�ܣ������»������޲��Ϸ�");
		}
	}

	/*!
	 * \fn	void Monster::updateAdditionalArmorValueMax(int delta)
	 *
	 * \brief	���ݸ����������������¹��ﵱǰ�ĸ��ӻ�������
	 *
	 * \param	delta	ָ�������ڸ��¹��ﵱǰ�ĸ��ӻ������޵�������
	 */
	void updateAdditionalArmorValueMax(int delta)
	{
		if (baseArmorValueMax + additionalArmorValueMax + delta >= 0)
			this->additionalArmorValueMax += delta;
		else
		{
			cocos2d::log("[warning] ���Ը��¹���ĸ��ӻ�������ʧ�ܣ������»������޲��Ϸ�");
		}
	}
};

#endif
