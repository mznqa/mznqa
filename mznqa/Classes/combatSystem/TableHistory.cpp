#pragma execution_character_set("utf-8")

#include "combatSystem/TableHistory.h"

#include <vector>

#include "cocos2d.h"

#include "combatSystem/DeltaTable.h"

TableHistory::TableHistory()
{
}

TableHistory::~TableHistory()
{
}

bool TableHistory::addRoleHistory(int round, DeltaTable dt)
{
	if (round <= 0)
	{
		cocos2d::log("[error]�� ��ӽ�ɫ��ʧ�ܣ�ָ���غ���Ϊ%d", round);
		return false;
	}

	tableRoleHistory[round].push_back(dt);

	cocos2d::log("[information]�� ��ӽ�ɫ��ʷ��ɹ���");
	return true;
}

const std::vector<DeltaTable>& TableHistory::getRoundAllRoleTable(int round)
{
	if (round > 0 && round <= tableRoleHistory.size())
	{
		cocos2d::log("[information]�� �ɹ���ȡ��ɫ�� %d �غ��ڵ����б�", round);
		return tableRoleHistory[round];
	}

	return nullVector;
}

bool TableHistory::addMonsterHistory(int round, DeltaTable dt)
{
	if (round <= 0)
	{
		cocos2d::log("[error]�� ��ӹ����ʧ�ܣ�ָ���غ���Ϊ%d", round);
		return false;
	};

	tableMonsterHistory[round].push_back(dt);

	cocos2d::log("[information]�� ��ӹ����ɹ���");
	return true;
}

const std::vector<DeltaTable>& TableHistory::getRoundAllMonsterTable(int round)
{
	if (round > 0 && round <= tableMonsterHistory.size())
	{
		cocos2d::log("[information]�� �ɹ���ȡ����� %d �غ��ڵ����б�", round);
		return tableMonsterHistory[round];
	}
	
	return nullVector;
}

void TableHistory::test()
{
	DeltaTable dt;
	dt.recver = DeltaTable::GameObject_Monster;
	dt.releaser = DeltaTable::GameObject_Role;
	dt.effectTable[0][1] = -1;
	addRoleHistory(1, dt);
	std::vector<DeltaTable> vtd;
	vtd = getRoundAllRoleTable(1);
	std::vector<DeltaTable>::iterator it;
	for (it = vtd.begin(); it != vtd.end(); it++)
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				cocos2d::log("\t%d", it->effectTable[i][j]);
			}
		}

	}
}
