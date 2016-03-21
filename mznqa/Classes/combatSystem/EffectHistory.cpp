#pragma execution_character_set("utf-8")

#include "combatSystem/EffectHistory.h"
#include "combatSystem/DeltaTable.h"
#include "cocos2d.h"

EffectHistory::EffectHistory()
{

}

EffectHistory::~EffectHistory()
{

}

bool EffectHistory::effectIsRelease(int effectId)
{
	std::vector <DeltaTable>::const_iterator it;
	for (it = tableHistory.begin();it != tableHistory.end();it++)
	{
		if (it->effectId == effectId)
		{
			cocos2d::log("提示： 该技能已经释放过，查找成功！");
			return true;
		}
	}
	cocos2d::log("提示： 该技能没有释放过，查找失败！");
	return false;
}

bool EffectHistory::addDTHistory(DeltaTable dt)
{
	tableHistory.push_back(dt);
	cocos2d::log("提示： 添加效果历史成功！");
	return true;
}

bool EffectHistory::addTRHiatory(TableRound tr)
{
	tableRound.push_back(tr);
	cocos2d::log("提示： 添加回合结算总表成功！");
	return true;
}

TableRound EffectHistory::getTableRound(int round)
{
	int size = tableRound.size();
	if (round > 0 && round <= size)
	{
		cocos2d::log("提示： 获取结算总表成功！");
		return tableRound[round - 1];
	}
	else
	{
		cocos2d::log("错误： 不存在第 %d 回合", round);
	}


	//std::vector <TableRound>::const_iterator it;
	//for (it = tableRound.begin();it != tableRound.end();it++)
	//{
	//	if (round == it->round)
	//	{
	//		return *it;
	//	}
	//}
}

TableRound EffectHistory::calcTableRound(int round)
{
	TableRound trTemp = { 0 };
	std::vector <DeltaTable>::const_iterator it;
	trTemp.round = round;
	for (it = tableHistory.begin();it != tableHistory.end();it++)
	{
		if (round == it->round)
		{
			for (int i = 0; i < 5; ++i)
			{
				for (int j = 0;j < 2;++j)
				{
					trTemp.deltaTableRound[i][j] += it->effectTable[i][j];
				}
			}
		}
	}
	return trTemp;
}

void EffectHistory::test()
{
	cocos2d::log("+++++++EffectHistory.test()+++++++++");
	DeltaTable dt,dd;
	dt.recver = Role;
	dt.releaser = Monster;
	dt.effectId = 1;
	dt.round = 1;
	dt.effectTable[0][1] = -1;
	addDTHistory(dt);

	dd.recver = Role;
	dd.releaser = Monster;
	dd.effectId = 2;
	dd.round = 1;
	dd.effectTable[0][0] = -1;
	addDTHistory(dd);
	
	TableRound tr = { 0 }, tt = { 0 };

	tr=calcTableRound(1);
	addTRHiatory(tr);
	tt = getTableRound(1);
	cocos2d::log("--------EffectHistory.test()--------");
}
