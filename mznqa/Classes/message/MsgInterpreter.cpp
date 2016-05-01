/*!
 * \file	Classes\message\MsgInterpreter.cpp
 *
 * \brief	定义类 MsgInterpreter
 */

#pragma execution_character_set("utf-8")

#include "message/MsgInterpreter.h"

MsgInterpreter* MsgInterpreter::Instance()
{
	static MsgInterpreter instance;
	return &instance;
}

MsgInterpreter::MsgInterpreter()
{
	// 消息映射表<EngineMessage, LogicMessage>
	// TODO 将消息映射表补充完整
	EngineMessagePQInstance = EngineMessagePQ::Instance();
	LogicMessagePQInstance = LogicMessagePQ::Instance();

	msgMap.insert(std::pair < EngineMessagePQ::EMessage, LogicMessagePQ::LMessage>(
		EngineMessagePQ::EMessage_None,
		LogicMessagePQ::LMessage_None
		));
	msgMap.insert(std::pair < EngineMessagePQ::EMessage, LogicMessagePQ::LMessage>(
		EngineMessagePQ::EMessage_MapMoveUp,
		LogicMessagePQ::LMessage_MapViewMoveUp
		));
	msgMap.insert(std::pair < EngineMessagePQ::EMessage, LogicMessagePQ::LMessage>(
		EngineMessagePQ::EMessage_MapMoveRight,
		LogicMessagePQ::LMessage_MapViewMoveRight
		));
	msgMap.insert(std::pair < EngineMessagePQ::EMessage, LogicMessagePQ::LMessage>(
		EngineMessagePQ::EMessage_MapMoveDown,
		LogicMessagePQ::LMessage_MapViewMoveDown
		));
	msgMap.insert(std::pair < EngineMessagePQ::EMessage, LogicMessagePQ::LMessage>(
		EngineMessagePQ::EMessage_MapMoveLeft,
		LogicMessagePQ::LMessage_MapViewMoveLeft
		));
	msgMap.insert(std::pair < EngineMessagePQ::EMessage, LogicMessagePQ::LMessage>(
		EngineMessagePQ::EMessage_Information_DataLoading_StaticData_CardRoadSetLoadSuccess,
		LogicMessagePQ::LMessage_Information_DataLoading_StaticData_CardRoadSetLoadSuccess
		));
	msgMap.insert(std::pair < EngineMessagePQ::EMessage, LogicMessagePQ::LMessage>(
		EngineMessagePQ::EMessage_Information_DataLoading_StaticData_CardSkillSetLoadSuccess,
		LogicMessagePQ::LMessage_Information_DataLoading_StaticData_CardSkillSetLoadSuccess
		));
	msgMap.insert(std::pair < EngineMessagePQ::EMessage, LogicMessagePQ::LMessage>(
		EngineMessagePQ::EMessage_Information_DataLoading_StaticData_MapMainMissionSetLoadSuccess,
		LogicMessagePQ::LMessage_Information_DataLoading_StaticData_MapMainMissionSetLoadSuccess
		));
	msgMap.insert(std::pair < EngineMessagePQ::EMessage, LogicMessagePQ::LMessage>(
		EngineMessagePQ::EMessage_Error_DataLoading_StaticData_CardRoadSetLoadFailed,
		LogicMessagePQ::LMessage_Error_DataLoading_StaticData_CardRoadSetLoadFailed
		));
	msgMap.insert(std::pair < EngineMessagePQ::EMessage, LogicMessagePQ::LMessage>(
		EngineMessagePQ::EMessage_Error_DataLoading_StaticData_CardSkillSetLoadFailed,
		LogicMessagePQ::LMessage_Error_DataLoading_StaticData_CardSkillSetLoadFailed
		));
	msgMap.insert(std::pair < EngineMessagePQ::EMessage, LogicMessagePQ::LMessage>(
		EngineMessagePQ::EMessage_Error_DataLoading_StaticData_CardMapMainMissionSetSetLoadFailed,
		LogicMessagePQ::LMessage_Error_DataLoading_StaticData_CardMapMainMissionSetSetLoadFailed
		));
	msgMap.insert(std::pair < EngineMessagePQ::EMessage, LogicMessagePQ::LMessage>(
		EngineMessagePQ::EMessage_SpriteCard_TouchEvent_TouchBegan_TSpriteCardEventIndexT,
		LogicMessagePQ::LMessage_SpriteCard_TouchEvent_TouchBegan_TSpriteCardEventIndexT
		));
	msgMap.insert(std::pair < EngineMessagePQ::EMessage, LogicMessagePQ::LMessage>(
		EngineMessagePQ::EMessage_SpriteCard_TouchEvent_TouchMoved_TSpriteCardEventIndexT,
		LogicMessagePQ::LMessage_SpriteCard_TouchEvent_TouchMoved_TSpriteCardEventIndexT
		));
	msgMap.insert(std::pair < EngineMessagePQ::EMessage, LogicMessagePQ::LMessage>(
		EngineMessagePQ::EMessage_SpriteCard_TouchEvent_TouchEnded_TSpriteCardEventIndexT,
		LogicMessagePQ::LMessage_SpriteCard_TouchEvent_TouchEnded_TSpriteCardEventIndexT
		));
	msgMap.insert(std::pair < EngineMessagePQ::EMessage, LogicMessagePQ::LMessage>(
		EngineMessagePQ::EMessage_SpriteHandCard_TouchEvent_TouchBegan_TSpriteHandCardEventIndexT,
		LogicMessagePQ::LMessage_SpriteHandCard_TouchEvent_TouchBegan_TSpriteHandCardEventIndexT
		));
	msgMap.insert(std::pair < EngineMessagePQ::EMessage, LogicMessagePQ::LMessage>(
		EngineMessagePQ::EMessage_SpriteHandCard_TouchEvent_TouchMoved_TSpriteHandCardEventIndexT,
		LogicMessagePQ::LMessage_SpriteHandCard_TouchEvent_TouchMoved_TSpriteHandCardEventIndexT
		));
	msgMap.insert(std::pair < EngineMessagePQ::EMessage, LogicMessagePQ::LMessage>(
		EngineMessagePQ::EMessage_SpriteHandCard_TouchEvent_TouchEnded_TSpriteHandCardEventIndexT,
		LogicMessagePQ::LMessage_SpriteHandCard_TouchEvent_TouchEnded_TSpriteHandCardEventIndexT
		));
	msgMap.insert(std::pair < EngineMessagePQ::EMessage, LogicMessagePQ::LMessage>(
		EngineMessagePQ::EMessage_RemoveHandCardByIndex_TIntT,
		LogicMessagePQ::LMessage_RemoveHandCardByIndex_TIntT
		));
	msgMap.insert(std::pair < EngineMessagePQ::EMessage, LogicMessagePQ::LMessage>(
		EngineMessagePQ::EMessage_PutCardRoad_TGXYT,
		LogicMessagePQ::LMessage_PutCardRoad_TGXYT
		));
}

MsgInterpreter::~MsgInterpreter()
{
}

Message<LogicMessagePQ::LMessage> MsgInterpreter::translation(const Message<EngineMessagePQ::EMessage> &eMessage)
{
	Message<LogicMessagePQ::LMessage> msg(msgMap[(EngineMessagePQ::EMessage)(eMessage.messageID)], eMessage.extras);
	return msg;
}