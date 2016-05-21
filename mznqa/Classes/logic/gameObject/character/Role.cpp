/*!
 * \file	Classes\logic\gameObject\character\Role.cpp
 *
 * \brief	定义类 Role
 */

#pragma execution_character_set("utf-8")

#include "logic/gameObject/character/Role.h"

#include "logic/message/LogicMessagePQ.h"
#include "helper/bridge/Bridge.h"

bool Role::drawCard()
{
	int index = cardControllerExplore.drawCardAndReturnIndex();
	if (index == -1)
	{
		if (cardControllerExplore.isFullHolder())
			Bridge::Instance()->pushMessage2Interactive(LogicMessagePQ::LogicMessageID_Explore_DrawCradFail_Role_HandCardFull);
		else if (cardControllerExplore.isEmptyPool())
			Bridge::Instance()->pushMessage2Interactive(LogicMessagePQ::LogicMessageID_Explore_DrawCradFail_Role_CardPoolEmpty);

		return false;
	}

	// 发送抽牌成功消息
	Bridge::Instance()->pushMessage2Interactive(LogicMessagePQ::LogicMessageID_Explore_DrawCradSucc_Role_TintT, index);

	return true;
}

CardControllerExplore& Role::getCardControllerExplore()
{
	return cardControllerExplore;
}