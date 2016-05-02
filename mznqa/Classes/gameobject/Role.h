/*!
 * \file	Classes\gameobject\Role.h
 *
 * \brief	������ Role
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_GAMEOBJECT_ROLE_H_
#define MZNQA_CLASSES_GAMEOBJECT_ROLE_H_

#include <string>
#include <vector>

#include "cocos2d.h"

#include "cardController/CardControllerCombat.h"

/*!
 * \class	Role
 *
 * \brief	��������ɫ
 *
 */
class Role
{
private:

	/*!
	 * \fn	Role::Role()
	 *
	 * \brief	���صĹ��캯��
	 *
	 */
	Role(){}

	/*!
	 * \fn	Role::Role(const Role &role);
	 *
	 * \brief	���صĿ������캯��
	 *
	 * \param	role	Role ʵ��
	 */
	Role(const Role &role);

	/*!
	 * \fn	Role& Role::operator=(const Role &role);
	 *
	 * \brief	���صĿ�����ֵ�����
	 *
	 * \param	role	Role ʵ��
	 *
	 * \return	Role ʵ��
	 */
	Role& operator=(const Role &role);

	/*! \brief	��ɫ������ */
	std::string name;
	/*! \brief	��ɫ������ */
	std::string describe;
	/*! \brief	��ɫ�Ļ���Ѫ������ */
	int baseBloodValueMax;
	/*! \brief	��ɫ�Ļ����������� */
	int baseArmorValueMax;
	/*! \brief	��ɫ�ĵȼ����� */
	int levelValueMax;
	/*! \brief	��ɫ��������� */
	std::vector<int> experienceTable;

	/*! \brief	��ɫѪ��ʵʱ�� */
	int bloodValue;
	/*! \brief	��ɫ����ʵʱ�� */
	int armorValue;
	/*! \brief	��ɫ�ȼ�ʵʱ�� */
	int levelValue;
	/*! \brief	��ɫ����ʵʱ�� */
	int exprienceValue;
	/*! \brief	��ɫѪ����������ʵʱ�� */
	int additionalBloodlValueMax;
	/*! \brief	��ɫ���׸�������ʵʱ�� */
	int additionalArmorValueMax;
	/* \brief	��ɫʵʱ������ */
	int handCardCount;
	/* \brief	��ɫÿ�غ��ڿɳ����� */
	int drawCardCount;
	/* \brief	��ɫÿ�غ��ڿɳ����� */
	int discardCount;
	/* \brief	��ɫÿ�غ��ڿɳ��������� */
	int handCardCountMax;
	/*!
	 * \fn	void Role::checkLevelValue()
	 *
	 * \brief	���ݵ�ǰ�ľ���ֵ���¼���
	 *
	 */
	void checkLevelValue();

public:

	/*!
	 * \fn	static Role* Role::Instance();
	 *
	 * \brief	��ȡ����
	 *
	 * \return	���ص���
	 */
	static Role* Instance();

	/*!
	 * \fn	Role::~Role();
	 *
	 * \brief	��������
	 *
	 */
	~Role();

	/*! \brief	ս�������µĿ��ƿ����� */
	CardControllerCombat cardControllerCombat;

	/*!
	 * \fn	const std::string& Role::getName()const
	 *
	 * \brief	��ȡ��ɫ����
	 *
	 * \return	���ؽ�ɫ����
	 */
	const std::string& getName()const
	{
		return name;
	}

	/*!
	 * \fn	const std::string& Role::getDescribe()const
	 *
	 * \brief	��ȡ��ɫ����
	 *
	 * \return	���ؽ�ɫ����
	 */
	const std::string& getDescribe()const
	{
		return describe;
	}

	/*!
	 * \fn	int Role::getBaseBloodValueMax()const
	 *
	 * \brief	��ȡ��ɫ����Ѫ������
	 *
	 * \return	���ؽ�ɫ����Ѫ������
	 */
	int getBaseBloodValueMax()const
	{
		return baseBloodValueMax;
	}

	/*!
	 * \fn	int Role::getBaseArmorValueMax()const
	 *
	 * \brief	��ȡ��ɫ������������
	 *
	 * \return	���ؽ�ɫ������������
	 */
	int getBaseArmorValueMax()const
	{
		return baseArmorValueMax;
	}

	/*!
	 * \fn	int Role::getBloodValueMax()const
	 *
	 * \brief	��ȡ��ɫ��ǰѪ������
	 *
	 * \return	���ؽ�ɫ��ǰѪ������
	 */
	int getBloodValueMax()const
	{
		return baseBloodValueMax + additionalBloodlValueMax;
	}

	/*!
	 * \fn	int Role::getArmorValueMax()const
	 *
	 * \brief	��ȡ��ɫ��ǰ��������
	 *
	 * \return	���ؽ�ɫ��ǰ��������
	 */
	int getArmorValueMax()const
	{
		return baseArmorValueMax + additionalArmorValueMax;
	}

	/*!
	 * \fn	int Role::getLevelValueMax()const
	 *
	 * \brief	��ȡ��ɫ�ȼ�����
	 *
	 * \return	���ؽ�ɫ�ȼ�����
	 */
	int getLevelValueMax()const
	{
		return levelValueMax;
	}

	/*!
	 * \fn	int Role::getNextLevelExprience()const
	 *
	 * \brief	��ȡ��ɫ������һ������ľ���
	 *
	 * \return	���ؽ�ɫ������һ������ľ��飬����ɫ�Ѵﵽ�ȼ������򷵻�-1
	 */
	int getNextLevelExprience()const
	{
		if (1 <= levelValue && levelValue < levelValueMax)
			return experienceTable[levelValue - 2];
		else
			return -1;
	}

	/*!
	 * \fn	const std::vector<int>& Role::getExprienceTable()const
	 *
	 * \brief	��ȡ��ɫ���������
	 *
	 * \return	���ؽ�ɫ���������
	 */
	const std::vector<int>& getExprienceTable()const
	{
		return experienceTable;
	}

	/*!
	 * \fn	int Role::getBloodValue()const
	 *
	 * \brief	��ȡ��ɫ��ǰѪ��
	 *
	 * \return	���ؽ�ɫ��ǰѪ��
	 */
	int getBloodValue()const
	{
		return bloodValue;
	}

	/*!
	 * \fn	void Role::setBloodValue(int bloodValue)
	 *
	 * \brief	���ݸ���ֵΪ��ɫ����Ѫ��
	 *
	 * \param	bloodValue	ָ����Ϊ��ɫ��Ѫ��ֵ
	 */
	void setBloodValue(int bloodValue)
	{
		if (0 <= bloodValue && bloodValue <= getBloodValueMax())
			this->bloodValue = bloodValue;
		else
		{
			cocos2d::log("[warning] ����Ϊ��ɫ����Խ��Ѫ��");
		}
	}

	/*!
	 * \fn	void Role::updateBloodValue(int delta)
	 *
	 * \brief	���ݸ������������½�ɫѪ��
	 *
	 * \param	delta	ָ�������ڸ���Ѫ����������
	 */
	void updateBloodValue(int delta)
	{
		int temp = bloodValue + delta;
		if (0 <= bloodValue && bloodValue <= getBloodValueMax())
			bloodValue = temp;
		else
		{
			cocos2d::log("[waring] ���Ը���Ѫ������Ѫ��Խ��");
		}
	}

	/*!
	 * \fn	int Role::getArmorValue()const
	 *
	 * \brief	��ȡ��ɫ��ǰ����
	 *
	 * \return	���ؽ�ɫ��ǰ����
	 */
	int getArmorValue()const
	{
		return armorValue;
	}

	/*!
	 * \fn	void Role::setArmorValue(int armorValue)
	 *
	 * \brief	����ָ��ֵ���ý�ɫ����
	 *
	 * \param	armorValue	ָ���������ý�ɫ���׵�ֵ
	 */
	void setArmorValue(int armorValue)
	{
		if (0 <= armorValue && armorValue <= getArmorValueMax())
			this->armorValue = armorValue;
		else
			cocos2d::log("[warning] ����Ϊ��ɫ����Խ�绤��");
	}

	/*!
	 * \fn	void Role::updateArmorValue(int delta)
	 *
	 * \brief	���ݸ��������������½�ɫ����
	 *
	 * \param	delta	ָ�������ڸ��»��׵�������
	 */
	void updateArmorValue(int delta)
	{
		int temp = armorValue + delta;
		if (0 <= armorValue && armorValue <= getArmorValueMax())
			armorValue = temp;
		else
			cocos2d::log("[waring] ���Ը��Ļ�����������Խ��");
	}

	/*!
	 * \fn	int Role::getLevleValue()const
	 *
	 * \brief	��ȡ��ɫ��ǰ�ȼ�
	 *
	 * \return	���ؽ�ɫ��ǰ�ȼ�
	 */
	int getLevleValue()const
	{
		return levelValue;
	}

	/*!
	 * \fn	void Role::setLevelValue(int levelValue)
	 *
	 * \brief	���ݸ���ֵ�����ý�ɫ��ǰ�ȼ�
	 *
	 * \param	levelValue	ָ���������õȼ�����
	 */
	void setLevelValue(int levelValue)
	{
		if (1 <= levelValue && levelValue <= levelValueMax)
			this->levelValue = levelValueMax;
		else
			cocos2d::log("[warning] ����Ϊ��ɫ����Խ��ȼ�");
	}

	/*!
	 * \fn	void Role::updateLevelValue(int delta)
	 *
	 * \brief	���ݸ��������������½�ɫ�ĵȼ�
	 *
	 * \param	delta	ָ�����ڸ��µȼ���������
	 */
	void updateLevelValue(int delta)
	{
		int temp = this->levelValue + delta;
		if (1 <= temp && temp <= levelValueMax)
			this->levelValue = temp;
		else
			cocos2d::log("[warning] ����Ϊ��ɫ����Խ��ȼ�");
	}

	/*!
	 * \fn	int Role::getExprienceValue()const
	 *
	 * \brief	��ȡ��ɫ����
	 *
	 * \return	���ؽ�ɫ����
	 */
	int getExprienceValue()const
	{
		return exprienceValue;
	}

	/*!
	 * \fn	void Role::setExprienceValue(int exprienceValue)
	 *
	 * \brief	���ݸ���ֵ�����ý�ɫ��ǰ�ľ���
	 *
	 * \param	exprienceValue	ָ���������ý�ɫ�����ֵ
	 */
	void setExprienceValue(int exprienceValue);

	/*!
	 * \fn	void Role::updateExprienceValue(int delta)
	 *
	 * \brief	���ݸ����������������½�ɫ��
	 *
	 * \author	Yeshiyong
	 * \date	2016/4/6
	 *
	 * \param	delta	The delta.
	 */
	void updateExprienceValue(int delta);

	/*!
	 * \fn	int Role::getAdditionalBloodlValueMax()const
	 *
	 * \brief	��ȡ��ɫ�ĸ���Ѫ������
	 *
	 * \return	���ؽ�ɫ�ĸ���Ѫ������
	 */
	int getAdditionalBloodlValueMax()const
	{
		return additionalBloodlValueMax;
	}

	/*!
	 * \fn	void Role::setAdditionalBloodValueMax(int additionalBloodValueMax)
	 *
	 * \brief	���ݸ���ֵ�����ý�ɫ�ĸ���Ѫ������
	 *
	 * \param	additionalBloodValueMax	ָ���������ý�ɫ����Ѫ�����޵�ֵ
	 */
	void setAdditionalBloodValueMax(int additionalBloodValueMax)
	{
		if (baseBloodValueMax + additionalBloodlValueMax >= 0)
			this->additionalBloodlValueMax = additionalBloodValueMax;
		else
		{
			cocos2d::log("[warning] �������ø��ӵ�Ѫ������Ϊ%d���⽫�ᵼ��ʵ��Ѫ������Ϊ���Ϸ���ֵ", additionalBloodValueMax);
		}
	}

	/*!
	 * \fn	void Role::updateAdditionalBloodValueMax(int delta)
	 *
	 * \brief	���ݸ��������������½�ɫ�ĸ���Ѫ������
	 *
	 * \param	delta	ָ�������ڸ��½�ɫ�ĸ���Ѫ�����޵�������
	 */
	void updateAdditionalBloodValueMax(int delta)
	{
		if (baseBloodValueMax + additionalBloodlValueMax + delta >= 0)
			this->additionalBloodlValueMax += delta;
		else
		{
			cocos2d::log("[warning] �������ø��ӵ�Ѫ������Ϊ%d���⽫�ᵼ��ʵ��Ѫ������Ϊ���Ϸ���ֵ", additionalBloodlValueMax + delta);
		}
	}

	/*!
	 * \fn	int Role::getAdditionalArmorValueMax()const
	 *
	 * \brief	��ȡ��ɫ���ӵĻ�������
	 *
	 * \return	���ؽ�ɫ���ӵĻ�������
	 */
	int getAdditionalArmorValueMax()const
	{
		return additionalArmorValueMax;
	}

	/*!
	 * \fn	void Role::setAdditionalAromrValueMax(int additionalArmorValueMax)
	 *
	 * \brief	���ݸ�����ֵ�����ý�ɫ�ĸ��ӻ�������
	 *
	 * \param	additionalArmorValueMax	ָ�����������ý�ɫ�ĸ��ӻ������޵�ֵ
	 */

	void setAdditionalAromrValueMax(int additionalArmorValueMax)
	{
		if (baseArmorValueMax + additionalArmorValueMax >= 0)
			this->additionalArmorValueMax = additionalArmorValueMax;
		else
		{
			cocos2d::log("[warning] �������ø��ӵĻ�������Ϊ%d���⽫�ᵼ��ʵ�ʵĻ�������Ϊ���Ϸ���ֵ", additionalArmorValueMax);
		}
	}

	/*!
	 * \fn	void Role::updateAdditionalArmorValueMax(int delta)
	 *
	 * \brief	���ݸ����������������½�ɫ�ĸ��Ӹ�������
	 *
	 * \param	delta	ָ�������ڸ��½�ɫ�ĸ��ӻ������޵�ֵ
	 */
	void updateAdditionalArmorValueMax(int delta)
	{
		if (baseArmorValueMax + additionalArmorValueMax + delta >= 0)
			this->additionalArmorValueMax += delta;
		else
		{
			cocos2d::log("[warning] �������ø��ӵĻ�������Ϊ%d���⽫�ᵼ��ʵ�ʵĻ�������Ϊ�Ϸ���ֵ", additionalArmorValueMax + delta);
		}
	}

	/*��
	 * \fn	int Role::getHandCardCount()
	 *
	 * \brief	��ȡ��ɫ��ǰ������
	 *
	 * \return	���ؽ�ɫ��ǰ������
	 */
	int getHandCardCount()
	{
		return handCardCount;
	}

	/*��
	 * \fn	void Role::setHandCardCount(int handCardCount)
	 *
	 * \brief	���ݸ�����ֵ�����ý�ɫ������
	 *
	 * \param	handCardCount	ָ�����������ý�ɫ��������ֵ
	 */

	void setHandCardCount(int handCardCount)
	{
		if (handCardCount < this->handCardCountMax && handCardCount >= 0)
		{
			this->handCardCount = handCardCount;
		}
		else
		{
			cocos2d::log("[warning] ����������������Ϊ%d,�⽫����ʵ�ʵ���������Ϊ���Ϸ���ֵ", handCardCount);
		}
	}

	/*��
	 * \fn	void Role::updateHandCount(int delta)
	 *
	 * \brief	���ݸ����������������½�ɫ��������
	 *
	 * \param	delta	ָ�������ڸ��½�ɫ����������ֵ
	 */
	void updateHandCount(int delta)
	{
		int temp = this->handCardCount + delta;
		if (temp <= this->handCardCountMax )
		{
			this->handCardCount = temp;
		}
		else
		{
			cocos2d::log("[warning] ����������������Ϊ%d,�⽫����ʵ�ʵ���������Ϊ���Ϸ���ֵ", handCardCount);
		}
	}

	/*��
	 * \fn	int Role::getHandCardCountMax()
	 *
	 * \brief	��ȡ��ɫ��ǰ����������ֵ
	 *
	 * \return	���ؽ�ɫ��ǰ����������ֵ
	 */
	int getHandCardCountMax()
	{
		return handCardCountMax;
	}

	/*��
	 * \fn	int Role::getDrawCardCount()
	 *
	 * \brief	��ȡ��ɫÿ�غ��ڿɳ�����
	 *
	 * \return	���ؽ�ɫÿ�غ��ڿɳ�����
	 */
	int getDrawCardCount()
	{
		return drawCardCount;
	}

	/*��
	 * \fn	void Role::setDrawCardCount(int drawCardCount)
	 *
	 * \brief	���ݸ�����ֵ�����ý�ɫÿ�غ��ڵĿɳ�����
	 *
	 * \param	drawCardCount	ָ�����������ý�ɫÿ�غ��ڵĿɳ�������ֵ
	 */
	void setDrawCardCount(int drawCardCount)
	{
		if (drawCardCount >= 0)
		{
			this->drawCardCount = drawCardCount;
		}
		else
		{
			cocos2d::log("[warning] �������ý�ɫÿ�غ��ڿɳ�����Ϊ%d,�⽫����ʵ�ʵĿɳ�������Ϊ���Ϸ���ֵ", drawCardCount);
		}
	}

	/*��
	 * \fn	void Role::updateDrawCardCount(int delta)
	 *
	 * \brief	���ݸ����������������½�ɫÿ�غ��ڿɳ�����
	 *
	 * \param	delta	ָ�������ڸ��½�ɫÿ�غ��ڿɳ�������ֵ
	 */
	void updateDrawCardCount(int delta)
	{
		int temp = this->drawCardCount + delta;
		if (temp >= 0)
		{
			this->drawCardCount = temp;
		}
		else
		{
			cocos2d::log("[warning] �������ý�ɫÿ�غ��ڿɳ�����Ϊ%d,�⽫����ʵ�ʵĿɳ�������Ϊ���Ϸ���ֵ", drawCardCount);
		}
	}


	/*��
	 * \fn	int Role::getDiscardCount()
	 *
	 * \brief	��ȡ��ɫÿ�غ��ڿɳ�����
	 *
	 * \return	���ؽ�ɫÿ�غ��ڿɳ�����
	 */
	int getDiscardCount()
	{
		return discardCount;
	}

	/*��
	 * \fn	void Role::setDiscardCount(int discardCount)
	 *
	 * \brief	���ݸ�����ֵ���ý�ɫÿ�غ��ڵĿɳ�����
	 *
	 * \param	discardCount	ָ�����������ý�ɫÿ�غ��ڵĿɳ�������ֵ
	 */
	void setDiscardCount(int discardCount)
	{
		if (discardCount >= 0)
		{
			this->discardCount = discardCount;
		}
		else
		{
			cocos2d::log("[warning] �������ý�ɫÿ�غ��ڿɳ�����Ϊ%d,�⽫����ʵ�ʵĿɳ�������Ϊ���Ϸ���ֵ", discardCount);
		}
	}

	/*��
	 * \fn	void Role::updateDiscardCount(int delta)
	 *
	 * \brief	���ݸ����������������½�ɫÿ�غ��ڿɳ�����
	 *
	 * \param	delta	ָ�������ڸ��½�ɫÿ�غ��ڿɳ�������ֵ
	 */
	void updateDiscardCount(int delta)
	{
		int temp = this->discardCount + delta;
		if (temp >= 0)
		{
			this->discardCount = temp;
		}
		else
		{
			cocos2d::log("[warning] �������ý�ɫÿ�غ��ڿɳ�����Ϊ%d,�⽫����ʵ�ʵĿɳ�������Ϊ���Ϸ���ֵ", discardCount);
		}
	}

	void test();
};

#endif
