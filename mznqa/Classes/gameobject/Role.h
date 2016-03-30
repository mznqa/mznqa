#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_GAMEOBJECT_ROLE_H_
#define MZNQA_CLASSES_GAMEOBJECT_ROLE_H_

#include <string>
#include <vector>

#include "cocos2d.h"

class Role
{
private:
	Role(){}
	Role(const Role &role);
	Role& operator=(const Role &role);

	// ��̬�� //////////////////////////////////////////////////////////////////////////
	// ����
	std::string name;
	// ����
	std::string describe;
	// ����Ѫ������
	int baseBloodValueMax;
	// ������������
	int baseArmorValueMax;
	// �ȼ�����
	int levelValueMax;
	// ���������
	std::vector<int> experienceTable;
	//////////////////////////////////////////////////////////////////////////

	// ʵʱ�� //////////////////////////////////////////////////////////////////////////
	// Ѫ��
	int bloodValue;
	// ����
	int armorValue;
	// ����
	int levelValue;
	// ����
	int exprienceValue;
	// Ѫ�����޸���ֵ
	int additionalBloodlValueMax;
	// �������޸���ֵ
	int additionalArmorValueMax;
	//////////////////////////////////////////////////////////////////////////

	// ���ȼ�
	void checkLevelValue()
	{
		// ���ȼ�ֵ������δ�ﵽ�ȼ����ޣ�������������
		if (1 <= levelValue  && levelValue < levelValueMax)
		{
			// ������ﵽ����Ҫ��ľ���ֵ
			if (exprienceValue >= experienceTable[levelValue - 1])
			{
				// ��ȥ����ֵ
				exprienceValue -= experienceTable[levelValue - 1];
				updateLevelValue(1);
				// TODO ����������Ϣ
				cocos2d::log("[information] ��ɫ��������ǰ�ȼ���%d", levelValue);
			}
		}
	}

public:
	static Role* Instance();
	~Role();

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
		return baseBloodValueMax + additionalBloodlValueMax;
	}

	// ��ȡ��ǰ��������
	int getArmorValueMax()const
	{
		return baseArmorValueMax + additionalArmorValueMax;
	}

	// ��ȡ�ȼ�����
	int getLevelValueMax()const
	{
		return levelValueMax;
	}

	// ��ȡ������һ�����辭�飬����ɫ����������-1
	int getNextLevelExprience()const
	{
		if (1 <= levelValue && levelValue < levelValueMax)
			return experienceTable[levelValue - 2];
		else
			return -1;
	}

	// ��ȡ���������
	const std::vector<int>& getExprienceTable()const
	{
		return experienceTable;
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
			cocos2d::log("[warning] ����Ϊ��ɫ����Խ��Ѫ��");
		}
	}
	// ����Ѫ��
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

	// ��ȡ����
	int getArmorValue()const
	{
		return armorValue;
	}
	// ���û���
	void setArmorValue(int armorValue)
	{
		if (0 <= armorValue && armorValue <= getArmorValueMax())
			this->armorValue = armorValue;
		else
			cocos2d::log("[warning] ����Ϊ��ɫ����Խ�绤��");
	}
	// ���»���
	void updateArmorValue(int delta)
	{
		int temp = armorValue + delta;
		if (0 <= armorValue && armorValue <= getArmorValueMax())
			armorValue = temp;
		else
			cocos2d::log("[waring] ���Ը��Ļ�����������Խ��");
	}

	// ��ȡ��ǰ�ȼ�
	int getLevleValue()const
	{
		return levelValue;
	}
	// ���þ���ֵ
	void setLevelValue(int levelValue)
	{
		if (1 <= levelValue && levelValue <= levelValueMax)
			this->levelValue = levelValueMax;
		else
			cocos2d::log("[warning] ����Ϊ��ɫ����Խ��ȼ�");
	}
	// ���¾���ֵ
	void updateLevelValue(int delta)
	{
		int temp = this->levelValue + delta;
		if (1 <= temp && temp <= levelValueMax)
			this->levelValue = temp;
		else
			cocos2d::log("[warning] ����Ϊ��ɫ����Խ��ȼ�");
	}

	// ��ȡ����ֵ
	int getExprienceValue()const
	{
		return exprienceValue;
	}
	// ���þ���ֵ
	void setExprienceValue(int exprienceValue)
	{
		if (levelValue >= levelValueMax)
		{
			this->exprienceValue = 0;
			return;
		}
		this->exprienceValue = exprienceValue;
		if (this->exprienceValue < 0)
		{
			this->exprienceValue = 0;
		}
		else
		{
			// ���ݵ�ǰ�����жϻ������������Σ��ͽ��м��������ж�
			for (int i = levelValue + 1; i <= levelValueMax; ++i)
				checkLevelValue();
		}
	}
	// ���¾���ֵ
	void updateExprienceValue(int delta)
	{
		if (levelValue >= levelValueMax)
		{
			this->exprienceValue = 0;
			return;
		}
		this->exprienceValue += delta;
		if (this->exprienceValue < 0)
		{
			this->exprienceValue = 0;
		}
		else
		{
			// ���ݵ�ǰ�����жϻ������������Σ��ͽ��м��������ж�
			for (int i = levelValue + 1; i <= levelValueMax; ++i)
				checkLevelValue();
		}
	}

	// ��ȡ���ӵ�Ѫ������ֵ
	int getAdditionalBloodlValueMax()const
	{
		return additionalBloodlValueMax;
	}
	// ���ø��ӵ�Ѫ������ֵֵ
	void setAdditionalBloodValueMax(int additionalBloodValueMax)
	{
		if (baseBloodValueMax + additionalBloodlValueMax >= 0)
			this->additionalBloodlValueMax = additionalBloodValueMax;
		else
		{
			cocos2d::log("[warning] �������ø��ӵ�Ѫ������Ϊ%d���⽫�ᵼ��ʵ��Ѫ������Ϊ���Ϸ���ֵ", additionalBloodValueMax);
		}
	}
	// ���¸��ӵ�Ѫ������
	void updateAdditionalBloodValueMax(int delta)
	{
		if (baseBloodValueMax + additionalBloodlValueMax + delta >= 0)
			this->additionalBloodlValueMax += delta;
		else
		{
			cocos2d::log("[warning] �������ø��ӵ�Ѫ������Ϊ%d���⽫�ᵼ��ʵ��Ѫ������Ϊ���Ϸ���ֵ", additionalBloodlValueMax + delta);
		}
	}

	// ��ȡ���ӵĻ�������
	int getAdditionalArmorValueMax()const
	{
		return additionalArmorValueMax;
	}
	// ���ø��ӵĻ�������
	void setAdditionalAromrValueMax(int additionalArmorValueMax)
	{
		if (baseArmorValueMax + additionalArmorValueMax >= 0)
			this->additionalArmorValueMax = additionalArmorValueMax;
		else
		{
			cocos2d::log("[warning] �������ø��ӵĻ�������Ϊ%d���⽫�ᵼ��ʵ�ʵĻ�������Ϊ���Ϸ���ֵ", additionalArmorValueMax);
		}
	}
	// ���¸��ӵĻ�������
	void updateAdditionalArmorValueMax(int delta)
	{
		if (baseArmorValueMax + additionalArmorValueMax + delta >= 0)
			this->additionalArmorValueMax += delta;
		else
		{
			cocos2d::log("[warning] �������ø��ӵĻ�������Ϊ%d���⽫�ᵼ��ʵ�ʵĻ�������Ϊ�Ϸ���ֵ", additionalArmorValueMax + delta);
		}
	}

	void test();
};

#endif
