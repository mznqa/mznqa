#pragma execution_character_set("utf-8")

#include "EffectPQ.h"
#include "staticData/CardSet.h"

const EffectAffixes EffectPQ::nullEffectAffixes = EffectAffixes(EffectAffixes::invalidLevelValue, EffectAffixes::invalidCardIdValue, EffectAffixes::invalidEffectIndexValue, EffectAffixes::Releaser::Releaser_Role, Effect::Receiver::Receiver_Other, Effect::ExcuteStyle::ExcuteStyle_In, EffectAffixes::invalidEffectRoundValue);

EffectPQ::EffectPQ()
{

}

EffectPQ::~EffectPQ()
{

}

void EffectPQ::pushEffectAffixesRole(EffectAffixes& effectAffixes,const int relRound,const int index)
{
	if (!checkOutOfRange(relRound,index))
	{
		return;
	}
	while (relRound + 1 > rolePQ.size())
	{
		std::array<std::priority_queue<int, std::vector<EffectAffixes>, std::greater<EffectAffixes>>, queueSizeMax > arrQueue;
		rolePQ.push_back(arrQueue);
	}
	rolePQ.at(relRound).at(index).push(effectAffixes);
	
	return;
}

const EffectAffixes& EffectPQ::getEffectAffixesRole(EffectQueueIndex effectQueueIndex)
{
	if (rolePQ.empty() || rolePQ.at(0).at(effectQueueIndex).empty())
	{
		return nullEffectAffixes;
	}
	cocos2d::log("[information] 成功获取一个角色效果(%d,%d,%s)",
		rolePQ.at(0).at(effectQueueIndex).top().cardId,
		rolePQ.at(0).at(effectQueueIndex).top().effectIndex,
		CardSet::Instance()->getCardSkillByID(rolePQ.at(0).at(effectQueueIndex).top().cardId)->getEffectSet().at(rolePQ.at(0).at(effectQueueIndex).top().effectIndex).getDescribe().c_str()
		);
	return rolePQ.at(0).at(effectQueueIndex).top();
}

int EffectPQ::getEPQLevelMaxRoleByRoundAndIndex(const int relRound, const int index)
{
	if (!checkOutOfRange(relRound,index))
	{
		return EffectAffixes::invalidLevelValue;
	}
	if (relRound + 1 > rolePQ.size())
	{
		return EffectAffixes::invalidLevelValue;
	}
	int result = 0;
	std::queue<EffectAffixes> temp;
	while (!rolePQ.at(relRound).at(index).empty())
	{
		result = rolePQ.at(relRound).at(index).top().level;
		temp.push(rolePQ.at(relRound).at(index).top());
		rolePQ.at(relRound).at(index).pop();
	}
	while (!temp.empty())
	{
		rolePQ.at(relRound).at(index).push(temp.front());
		temp.pop();
	}
	return result;
}

void EffectPQ::popEffectAffixesRole(const int relRound, const int index)
{
	if (!checkOutOfRange(relRound,index))
	{
		return;
	}
	if (relRound + 1 > rolePQ.size())
	{
		return;
	}
	rolePQ.at(relRound).at(index).pop();
}

void EffectPQ::decreaseRoundEffectRole()
{
	if (rolePQ.empty())
	{
		return;
	}
	int roundSize = rolePQ.size();
	if (roundSize == 1)
	{
		rolePQ.pop_back();
		return;
	}
	int swapIndex = 0;
	while (swapIndex + 1 < roundSize)
	{
		rolePQ.at(swapIndex).swap(rolePQ.at(swapIndex + 1));
		++swapIndex;
	}
	rolePQ.pop_back();
}

void EffectPQ::pushEffectAffixesMonster(EffectAffixes& effectAffixes, const int relRound, const int index)
{
	
	if (!checkOutOfRange(relRound, index))
	{
		return;
	}
	while (relRound + 1 > monsterPQ.size())
	{
		std::array<std::priority_queue<int, std::vector<EffectAffixes>, std::greater<EffectAffixes>>, queueSizeMax > arrQueue;
		monsterPQ.push_back(arrQueue);
	}
	monsterPQ.at(relRound).at(index).push(effectAffixes);

	return;
}

const EffectAffixes& EffectPQ::getEffectAffixesMonster(EffectQueueIndex effectQueueIndex)
{
	if (monsterPQ.empty() || monsterPQ.at(0).at(effectQueueIndex).empty())
	{
		return nullEffectAffixes;
	}
	cocos2d::log("[information] 成功获取一个怪物效果(%d,%d,%s)",
		monsterPQ.at(0).at(effectQueueIndex).top().cardId,
		monsterPQ.at(0).at(effectQueueIndex).top().effectIndex,
		CardSet::Instance()->getCardSkillByID(monsterPQ.at(0).at(effectQueueIndex).top().cardId)->getEffectSet().at(monsterPQ.at(0).at(effectQueueIndex).top().effectIndex).getDescribe().c_str()
		);
	return monsterPQ.at(0).at(effectQueueIndex).top();
}

int EffectPQ::getEPQLevelMaxMonsterByRoundAndIndex(const int relRound, const int index)
{
	if (!checkOutOfRange(relRound, index))
	{
		return EffectAffixes::invalidLevelValue;
	}
	if (relRound + 1 > monsterPQ.size())
	{
		return EffectAffixes::invalidLevelValue;
	}
	int result = 0;
	std::queue<EffectAffixes> temp;
	while (!monsterPQ.at(relRound).at(index).empty())
	{
		result = monsterPQ.at(relRound).at(index).top().level;
		temp.push(monsterPQ.at(relRound).at(index).top());
		monsterPQ.at(relRound).at(index).pop();
	}
	while (!temp.empty())
	{
		monsterPQ.at(relRound).at(index).push(temp.front());
		temp.pop();
	}
	return result;
}

void EffectPQ::popEffectAffixesMonster(const int relRound, const int index)
{
	if (!checkOutOfRange(relRound, index))
	{
		return;
	}
	if (relRound + 1 > monsterPQ.size())
	{
		return;
	}
	monsterPQ.at(relRound).at(index).pop();
}

void EffectPQ::decreaseRoundEffectMonster()
{
	if (monsterPQ.empty())
	{
		return;
	}
	int roundSize = monsterPQ.size();
	if (roundSize == 1)
	{
		monsterPQ.pop_back();
		return;
	}
	int swapIndex = 0;
	while (swapIndex + 1 < roundSize)
	{
		monsterPQ.at(swapIndex).swap(monsterPQ.at(swapIndex + 1));
		++swapIndex;
	}
	monsterPQ.pop_back();
}

const int EffectPQ::getIndexByExcuteStyle(Effect::ExcuteStyle excuteStyle)
{
	int index = -1;
	switch (excuteStyle)
	{
	case Effect::ExcuteStyle::ExcuteStyle_Before:
		index = 1;
		break;
	case Effect::ExcuteStyle::ExcuteStyle_In:
		index = 2;
		break;
	case Effect::ExcuteStyle::ExcuteStyle_After:
		index = 3;
		break;
	}
	return index;
}

bool EffectPQ::checkOutOfRange(const int& relRound, const int& index)
{
	if (relRound < 0 || (index < 0 && index >= queueSizeMax))
	{
		cocos2d::log("[error] 指定的相对回合数 %d 错误或指定的索引 %d 越界,请检查！");
		return false;
	}
	return true;
}

