#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_DATA_REALTIMEDATA_ROLE_H_
#define MZNQA_CLASSES_DATA_REALTIMEDATA_ROLE_H_

#include <string>

class Role
{
private:
	Role(){}
	Role(const Role &role);
	Role& operator=(const Role &role);

	// ��ɫ��
	std::string roleName;

	// Ѫ��ֵ
	int bloodValue;
	// ����ֵ
	int armorValue;

	//�ȼ�
	int level;

	// Ѫ������
	int bloodMax;

	//�ȼ�����
	int levelMax;

	//��ǰ����
	int exprienceValue;

	//��������
	int *experienceUpgrade;

	//���õȼ�
	void setLevel(int level);
	//���µȼ�
	void updateLevel(int delta);
	// ���ȼ�
	void checkLevel();

	//���õȼ�����
	//void setLevelMax(int levelMax);

	//���µȼ�����
	//void updateLevelMax(int delta);

	// ������������ȼ�
	void setLevelMaxAndExperienceUpgrade(int levelMax, int *experienceUpgrade);

public:
	static Role* Instance();
	~Role();

	// �ӽ��ȹ����ɫ
	// TODO ����Ӧ�ó��빹���ɫ�����һ����Ϣ���ݶ�
	void makeRole(int curLevel, int curExprience, int levelMax, int *experienceUpgrade);

	//��ȡ����
	std::string getName();

	// ��ȡѪ��ֵ
	int getBloodValue();
	// ����Ѫ��ֵ
	void setBloodValue(int bloodValue);
	// ����Ѫ��ֵ
	void updateBloodValue(int delta);

	// ��ȡ����ֵ
	int getArmorValue();
	// ���û���ֵ
	void setArmorValue(int armorValue);
	// ���»���ֵ
	void updateArmorValue(int delta);

	// ��ȡѪ������
	int getBloodMax();
	// ����Ѫ������
	void setBloodMax(int bloodMax);
	// ����Ѫ������
	void updateBloodMax(int delta);

	//��ȡ�ȼ�
	int getLevel();

	//��ȡ�ȼ�����
	int getLevelMax();

	//��ȡ��ǰ����
	int getExperience();
	//���õ�ǰ����
	void setExperience(int experience);
	//���µ�ǰ����
	void updateExperience(int delta);

	void test();
};

#endif