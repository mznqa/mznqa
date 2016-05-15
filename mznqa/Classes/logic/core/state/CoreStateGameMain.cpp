/*!
* \file		Classes\logic\core\state\CoreStateGameMain.cpp
*
* \brief	定义类 CoreStateGameMain
*/

#pragma execution_character_set("utf-8")

#include "logic/core/state/CoreStateGameMain.h"
#include "logic/message/LogicMessagePQ.h"
#include "logic/controller/MapController.h"
#include "helper/bridge/Bridge.h"

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
	Bridge::Instance()->pushMessage2Interactive(LogicMessagePQ::LogicMessageID_StateChangeDone_CoreStateResLoading_CoreStateGameMain);
	return true;
}
bool CoreStateGameMain::update(CoreController *owner, double intervalTime)
{
	// 消息处理模块 //////////////////////////////////////////////////////////////////////////
	auto msg = LogicMessagePQ::Instance()->getTopMessage();
	if (msg != nullptr)
	{
		switch (msg->getID())
		{
		case LogicMessagePQ::LogicMessageID_MoveMapView_Up:
			MapController::Instance()->viewMoveUp(1);
			Bridge::Instance()->pushMessage2Interactive(LogicMessagePQ::LogicMessageID_Update_MapViewPosition);
			break;
		case LogicMessagePQ::LogicMessageID_MoveMapView_Right:
			MapController::Instance()->viewMoveRight(1);
			Bridge::Instance()->pushMessage2Interactive(LogicMessagePQ::LogicMessageID_Update_MapViewPosition);
			break;
		case LogicMessagePQ::LogicMessageID_MoveMapView_Down:
			MapController::Instance()->viewMoveDown(1);
			Bridge::Instance()->pushMessage2Interactive(LogicMessagePQ::LogicMessageID_Update_MapViewPosition);
			break;
		case LogicMessagePQ::LogicMessageID_MoveMapView_Left:
			MapController::Instance()->viewMoveLeft(1);
			Bridge::Instance()->pushMessage2Interactive(LogicMessagePQ::LogicMessageID_Update_MapViewPosition);
			break;
		default:
			break;
		}
		LogicMessagePQ::Instance()->popTopMessage();
	}
	//////////////////////////////////////////////////////////////////////////
	return true;
}
bool CoreStateGameMain::exit(CoreController *owner)
{
	return true;
}