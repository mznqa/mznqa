#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_GAMEOBJECT_MONSTER_H_
#define MZNQA_CLASSES_GAMEOBJECT_MONSTER_H_

#include <string>

#include "cocos2d.h"

#include "cardController/CardControllerCombat.h"

class Monster
{
private:
	// ��̬�� //////////////////////////////////////////////////////////////////////////
	// ����
	std::string name;
	// ����
	std::string describe;
	// Ѫ������
	int baseBloodValueMax;
	// ��������
	int baseArmorValueMax;
	//////////////////////////////////////////////////////////////////////////

	// ʵʱ�� //////////////////////////////////////////////////////////////////////////
	// Ѫ��
	int bloodValue;
	// ����
	int armorValue;
	// ���ӵ�Ѫ������ֵ
	int additionalBloodValueMax;
	// ���ӵĻ�������ֵ
	int additionalArmorValueMax;
	//////////////////////////////////////////////////////////////////////////
public:
	Monster();
	~Monster();

	// ���ƹ����� //////////////////////////////////////////////////////////////////////////
	// ս�������µĿ��ƹ�����
	CardControllerCombat cardControllerCombat;
	//////////////////////////////////////////////////////////////////////////

	// ��ȡ����
	const std::string& getName()const
	{
		return name;
	}

	// ��ȡ����
	const std::string& getDescribe()const
	{
		return describe;
	}

	// ��ȡ����Ѫ������
	int getBaseBloodValueMax()const
	{
		return baseBloodValueMax;
	}

	// ��ȡ������������
	int getBaseArmorValueMax()const
	{
		return baseArmorValueMax;
	}

	// ��ȡ��ǰѪ������
	int getBloodValueMax()const
	{
		return baseBloodValueMax + additionalBloodValueMax;
	}

	// ��ȡ��ǰ��������
	int getArmorValueMax()const
	{
		return baseArmorValueMax + additionalArmorValueMax;
	}

	// ��ȡѪ��
	int getBloodValue()const
	{
		return bloodValue;
	}
	// ����Ѫ��
	void setBloodValue(int bloodValue)
	{
		if (0 <= bloodValue && bloodValue <= getBloodValueMax())
			this->bloodValue = bloodValue;
		else
		{
			cocos2d::log("[warning] ����Ϊ��������Խ��Ѫ��");
		}
	}
	// ����Ѫ��
	void updateBloodValue(int delta)
	{
		int temp = bloodValue + delta;
		if (0 <= temp && temp <= getBloodValueMax())
			this->bloodValue = temp;
		else
		{
			cocos2d::log("[warning] ���Ը��¹���Ѫ��������Ѫ��Խ�磬�仯��Ϊ%d, ����ǰѪ��Ϊ", delta, bloodValue);
		}
	}

	// ��ȡ����ֵ
	int getArmorValue()const
	{
		return armorValue;
	}
	// ���û���ֵ
	void setArmorValue(int armorValue)
	{
		if (0 <= armorValue && armorValue <= getArmorValue())
			this->armorValue = armorValue;
		else
		{
			cocos2d::log("[warning] ����Ϊ��������Խ��Ѫ��");
		}
	}
	// ���»���ֵ
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

	// ��ȡ���ӵ�Ѫ������ֵ
	int getAdditionalBloodValueMax()const
	{
		return additionalBloodValueMax;
	}
	// ���ø��ӵ�Ѫ������ֵ
	void getAdditionalBloodValueMax(int additionalBloodValueMax)
	{
		if (baseBloodValueMax + additionalBloodValueMax >= 0)
			this->additionalBloodValueMax = additionalBloodValueMax;
		else
		{
			cocos2d::log("[warning] ����Ϊ�������ø���Ѫ������ʧ�ܣ�������Ѫ�����޲��Ϸ�");
		}
	}
	// ���¸��ӵ�Ѫ������ֵ
	void updateAdditionalBloodValueMax(int delta)
	{
		if (baseBloodValueMax + additionalBloodValueMax + delta >= 0)
			this->additionalBloodValueMax += delta;
		else
		{
			cocos2d::log("[warning] ���Ը��¹���ĸ���Ѫ������ʧ�ܣ�������Ѫ�����޲��Ϸ�");
		}
	}

	// ��ȡ���ӵĻ�������
	int getAdditionalArmorValueMax()const
	{
		return additionalBloodValueMax;
	}
	// ���ø��ӵĻ�������
	void getAdditionArmorValueMax(int additionalArmorValueMax)
	{
		if (baseArmorValueMax + additionalArmorValueMax >= 0)
			this->additionalArmorValueMax = additionalArmorValueMax;
		else
		{
			cocos2d::log("[warning] ����Ϊ�������ø��ӵĻ�������ʧ�ܣ������»������޲��Ϸ�");
		}
	}
	// ���¸��ӵĻ�������
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
