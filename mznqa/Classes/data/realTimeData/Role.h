#ifndef MZNQA_CLASSES_DATA_REALTIMEDATA_ROLE_H_
#define MZNQA_CLASSES_DATA_REALTIMEDATA_ROLE_H_

#include <string>

using namespace std;

class Role
{
private:
	Role(){}
	Role(const Role &role);
	Role& operator=(const Role &role);
	
	string roleName;

	// Ѫ��ֵ
	int bloodValue;
	// ����ֵ
	int armorValue;

	//�ȼ�
	int level;

	// Ѫ������
	int bloodMax;

	// ��������
//	int armorMax;

	//�ȼ�����
	int levelMax;

	//��ǰ����
	int exprienceValue;

	//��������
	int experienceUpgrade[3];

public:
	static Role* Instance();
	~Role();
	
	//��ȡ����
	string getName();

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

	// ��ȡ��������
	//int getArmorMax();
	//// ���û�������
	//void setArmorMax(int armorMax);
	//// ���»�������
	//void updateArmorMax(int delta);

	//��ȡ�ȼ�
	int getLevel();
	//���õȼ�
	void setLevel(int level);
	//���µȼ�
	void updateLevel(int delta);

	//��ȡ�ȼ�����
	int getLevelMax();
	//���õȼ�����
	void setLevelMax(int levelMax);
	//���µȼ�����
	void updateLevelMax(int delta);

	//��ȡ��ǰ����
	int geExperience();
	//���õ�ǰ����
	void setExperience(int experience);
	//���µ�ǰ����
	void updateExperience(int delta);



	void test();
};

#endif