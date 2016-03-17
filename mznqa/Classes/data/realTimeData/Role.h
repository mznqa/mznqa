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

	// 血量值
	int bloodValue;
	// 护甲值
	int armorValue;

	//等级
	int level;

	// 血量上限
	int bloodMax;

	// 护甲上限
//	int armorMax;

	//等级上限
	int levelMax;

	//当前经验
	int exprienceValue;

	//升级经验
	int experienceUpgrade[3];

public:
	static Role* Instance();
	~Role();
	
	//获取名字
	string getName();

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
	//int getArmorMax();
	//// 设置护甲上限
	//void setArmorMax(int armorMax);
	//// 更新护甲上限
	//void updateArmorMax(int delta);

	//获取等级
	int getLevel();
	//设置等级
	void setLevel(int level);
	//更新等级
	void updateLevel(int delta);

	//获取等级上限
	int getLevelMax();
	//设置等级上限
	void setLevelMax(int levelMax);
	//更新等级上限
	void updateLevelMax(int delta);

	//获取当前经验
	int geExperience();
	//设置当前经验
	void setExperience(int experience);
	//更新当前经验
	void updateExperience(int delta);



	void test();
};

#endif