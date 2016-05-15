/*!
* \file		Classes\logic\core\state\CoreStateGameMain.cpp
*
* \brief	定义类 CoreStateGameMain
*/

#pragma execution_character_set("utf-8")

#include "logic/core/state/CoreStateGameMain.h"

CoreStateGameMain::CoreStateGameMain()
{
}

CoreStateGameMain::~CoreStateGameMain()
{
}

CoreStateGameMain* CoreStateGameMain::Instance()
{
	static CoreStateGameMain instance;
	return &instance;
}

bool CoreStateGameMain::enter(CoreController *owner)
{
	BridgeInstance->pushMessage2Interactive(LogicMessagePQ::LogicMessageID_StateChangeDone_CoreStateResLoading_CoreStateGameMain);
	return true;
}
bool CoreStateGameMain::update(CoreController *owner, double intervalTime)
{
	// 消息处理模块 //////////////////////////////////////////////////////////////////////////
	auto msg = LogicMessagePQInstance->getTopMessage();
	if (msg != nullptr)
	{
		switch (msg->getID())
		{
		case LogicMessagePQ::LogicMessageID_MoveMapView_Up:
			MapControllerInstance->viewMoveUp(1);
			BridgeInstance->pushMessage2Interactive(LogicMessagePQ::LogicMessageID_Update_MapViewPosition);
			break;
		case LogicMessagePQ::LogicMessageID_MoveMapView_Right:
			MapControllerInstance->viewMoveRight(1);
			BridgeInstance->pushMessage2Interactive(LogicMessagePQ::LogicMessageID_Update_MapViewPosition);
			break;
		case LogicMessagePQ::LogicMessageID_MoveMapView_Down:
			MapControllerInstance->viewMoveDown(1);
			BridgeInstance->pushMessage2Interactive(LogicMessagePQ::LogicMessageID_Update_MapViewPosition);
			break;
		case LogicMessagePQ::LogicMessageID_MoveMapView_Left:
			MapControllerInstance->viewMoveLeft(1);
			BridgeInstance->pushMessage2Interactive(LogicMessagePQ::LogicMessageID_Update_MapViewPosition);
			break;
		default:
			break;
		}
		LogicMessagePQInstance->popTopMessage();
	}
	//////////////////////////////////////////////////////////////////////////
	return true;
}
bool CoreStateGameMain::exit(CoreController *owner)
{
	return true;
}