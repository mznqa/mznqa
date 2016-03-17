#ifndef MZNQA_CLASSES_DATA_REALTIMEDATA_MONSTER_H_
#define MZNQA_CLASSES_DATA_REALTIMEDATA_MONSTER_H_

#include <string>

using namespace std;

class Monster
{
public:
	Monster();
	~Monster();
	
	//��ȡ����
	string getName();

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


private:

	//��������
	string monsterName;

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