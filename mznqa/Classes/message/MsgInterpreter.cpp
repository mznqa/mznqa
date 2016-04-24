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
	engineMessagePQInstance = EngineMessagePQ::Instance();
	logicMessagePQInstance = LogicMessagePQ::Instance();

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
}

MsgInterpreter::~MsgInterpreter()
{
}

Message<LogicMessagePQ::LMessage> MsgInterpreter::translation(const Message<EngineMessagePQ::EMessage> &eMessage)
{
	Message<LogicMessagePQ::LMessage> msg(msgMap[(EngineMessagePQ::EMessage)(eMessage.messageID)], eMessage.extras);
	return msg;
}