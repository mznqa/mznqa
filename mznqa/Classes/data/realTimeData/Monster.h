#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_DATA_REALTIMEDATA_MONSTER_H_
#define MZNQA_CLASSES_DATA_REALTIMEDATA_MONSTER_H_

#include <string>

#include "baseClass/CombatCardPool.h"
#include "baseClass/HandCard.h"

class Monster
{
public:
	Monster();
	~Monster();

	//��ȡ����
	std::string getName();

	//��ȡ��ǰѪ��
	int getBloodValue();

	//���õ�ǰѪ��
	void setBloodValue(int bloodValue);

	//���µ�ǰѪ��
	void updateBloodValue(int delta);

	//��ȡ����
	int getArrmorValue();

	//���û���
	void setArrmorValue(int arrmorValue);

	//���»���
	void updateArrmorValue(int delta);

	//��ȡ�����ֵ
	int getExperienceValue();

	//���þ����ֵ
	void setExperienceValue(int experienceValue);

	//��ȡѪ������
	int getBloodMax();

	//����Ѫ������
	void setBloodMax(int bloodMax);

	//����Ѫ������
	void updateBloodMax(int delta);

	// ս�������µĿ���
	CombatCardPool combatCardPool;
	// ս�������µ�����
	HandCard combatHandCard = HandCard(5);

private:

	//��������
	std::string monsterName;

	//Ѫ��
	int bloodValue;

	//����
	int armorValue;

	//�����ֵ
	int experienceValue;

	//Ѫ������
	int bloodMax;
};

#endif