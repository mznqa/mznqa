#ifndef MZNQA_CLASSES_DATA_REALTIMEDATA_ROLE_H_
#define MZNQA_CLASSES_DATA_REALTIMEDATA_ROLE_H_

class Role
{
private:
	Role(){}
	Role(const Role &role);
	Role& operator=(const Role &role);

	// Ѫ��ֵ
	int bloodValue;
	// ����ֵ
	int armorValue;

	// Ѫ������
	int bloodMax;
	// ��������
	int armorMax;

public:
	static Role *Instance();
	~Role();

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
	int getArmorMax();
	// ���û�������
	void setArmorMax(int armorMax);
	// ���»�������
	void updateArmorMax(int delta);

	void test();
};

#endif