#ifndef MZNQA_CLASSES_DATA_REALTIMEDATA_ROLE_H_
#define MZNQA_CLASSES_DATA_REALTIMEDATA_ROLE_H_

class Role
{
private:
	Role(){}
	Role(const Role &role);
	Role& operator=(const Role &role);

	// 血量值
	int bloodValue;
	// 护甲值
	int armorValue;

	// 血量上限
	int bloodMax;
	// 护甲上限
	int armorMax;

public:
	static Role *Instance();
	~Role();

	// 获取血量值
	int getBloodValue();
	// 设置血量值
	void setBloodValue(int bloodValue);
	// 更新血量值
	void updateBloodValue(int delta);

	// 获取护甲值
	int getArmorValue();
	// 设置护甲值
	void setArmorValue(int armorValue);
	// 更新护甲值
	void updateArmorValue(int delta);

	// 获取血量上限
	int getBloodMax();
	// 设置血量上限
	void setBloodMax(int bloodMax);
	// 更新血量上限
	void updateBloodMax(int delta);

	// 获取护甲上限
	int getArmorMax();
	// 设置护甲上限
	void setArmorMax(int armorMax);
	// 更新护甲上限
	void updateArmorMax(int delta);

	void test();
};

#endif