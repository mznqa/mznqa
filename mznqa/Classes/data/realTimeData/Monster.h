#ifndef MZNQA_CLASSES_DATA_REALTIMEDATA_MONSTER_H_
#define MZNQA_CLASSES_DATA_REALTIMEDATA_MONSTER_H_

#include <string>

using namespace std;

class Monster
{
public:
	Monster();
	~Monster();
	
	//获取名字
	string getName();

	//获取当前血量
	int getBloodValue();

	//设置当前血量
	void setBloodValue(int bloodValue);

	//更新当前血量
	void updateBloodValue(int delta);

	//获取护甲
	int getArrmorValue();

	//设置护甲
	void setArrmorValue(int arrmorValue);

	//更新护甲
	void updateArrmorValue(int delta);

	//获取经验价值
	int getExperienceValue();

	//设置经验价值
	void setExperienceValue(int experienceValue);

	//获取血量上限
	int getBloodMax();

	//设置血量上限
	void setBloodMax(int bloodMax);

	//更新血量上限
	void updateBloodMax(int delta);


private:

	//怪物名字
	string monsterName;

	//血量
	int bloodValue;

	//护甲
	int armorValue;

	//经验价值
	int experienceValue;

	//血量上限
	int bloodMax;


};



#endif