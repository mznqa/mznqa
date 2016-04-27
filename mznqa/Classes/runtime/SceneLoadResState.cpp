#pragma execution_character_set("utf-8")

#include "runtime/SceneLoadResState.h"

#include <cstdio>

#include "json/filereadstream.h"
#include "json/document.h"

#include "dataHandle/StaticDataLoader.h"

SceneLoadResState::~SceneLoadResState()
{
}

SceneLoadResState* SceneLoadResState::Instance()
{
	static SceneLoadResState instance;
	return &instance;
}

bool SceneLoadResState::enter(SceneLoadRes *scene)
{
	cocos2d::log("[information] 准备进入场景 SceneLoadRes 对应的状态机中...");
	// 推入待执行的消息队列： //////////////////////////////////////////////////////////////////////////
	// 发送消息：载入：静态数据：地形卡卡集合
	LogicMessagePQInstance->pushMessage(Message<LogicMessagePQ::LMessage>(LogicMessagePQ::LMessage_LoadData_StaticData_CardRoadSet));
	// 发送消息：载入：静态数据：技能卡集合
	LogicMessagePQInstance->pushMessage(Message<LogicMessagePQ::LMessage>(LogicMessagePQ::LMessage_LoadData_StaticData_CardSkillSet));
	// 发送消息：载入：静态数据：主线任务地图集合
	LogicMessagePQInstance->pushMessage(Message<LogicMessagePQ::LMessage>(LogicMessagePQ::LMessage_LoadData_StaticData_MapMainMissionSet));
	// 发送消息：跳转场景：SceneLoadRes 到 SceneGameMain
	LogicMessagePQInstance->pushMessage(Message<LogicMessagePQ::LMessage>(LogicMessagePQ::LMessage_ReplaceScene_SceneLoadRes2SceneGameMain));
	//////////////////////////////////////////////////////////////////////////
	cocos2d::log("[information] 准备进入场景 SceneLoadRes 对应的状态机成功");
	return true;
}

bool SceneLoadResState::update(SceneLoadRes *scene, double intervalTime)
{
	//cocos2d::log("[information] 开始执行场景 SceneLoadRes 对应的状态机...");
	// 消息处理模块 //////////////////////////////////////////////////////////////////////////
	// 转译消息
	LogicMessagePQInstance->pushMessage(MsgInterpreterInstance->translation(EngineMessagePQInstance->getNextMessage()));

	// 获取消息
	Message<LogicMessagePQ::LMessage> msg = LogicMessagePQInstance->getNextMessage();
	// 处理消息
	if (msg.messageID == LogicMessagePQ::LMessage_LoadData_StaticData_CardRoadSet)
	{
		cocos2d::log("[information] 开始载入静态数据：地形卡集合...");
		scene->showProgress("开始载入静态数据：地形卡集合...");
		StaticDataLoader::loadStaticDataCardRoadSet();
	}
	else if (msg.messageID == LogicMessagePQ::LMessage_LoadData_StaticData_CardSkillSet)
	{
		cocos2d::log("[information] 开始载入静态数据：技能卡集合...");
		scene->showProgress("开始载入静态数据：技能卡集合...");
		StaticDataLoader::loadStaticDataCardSkillSet();
	}
	else if (msg.messageID == LogicMessagePQ::LMessage_LoadData_StaticData_MapMainMissionSet)
	{
		cocos2d::log("[information] 开始载入静态数据：主线任务地图集合...");
		scene->showProgress("开始载入静态数据：主线任务地图集合...");
		StaticDataLoader::loadStaticDataMainMissionMapSet();
	}
	else if (msg.messageID == LogicMessagePQ::LMessage_Information_DataLoading_StaticData_CardRoadSetLoadSuccess)
	{
		cocos2d::log("[information] 完成静态数据载入：地形卡集合");
		scene->showProgress("完成静态数据载入：地形卡集合");
	}
	else if (msg.messageID == LogicMessagePQ::LMessage_Error_DataLoading_StaticData_CardRoadSetLoadFailed)
	{
		cocos2d::log("[error] 载入静态数据出错：地形卡集合");
		scene->showProgress("载入静态数据出错：地形卡集合");
	}
	else if (msg.messageID == LogicMessagePQ::LMessage_Information_DataLoading_StaticData_CardSkillSetLoadSuccess)
	{
		cocos2d::log("[information] 完成静态数据载入：技能卡集合");
		scene->showProgress("完成静态数据载入：技能卡集合");
	}
	else if (msg.messageID == LogicMessagePQ::LMessage_Error_DataLoading_StaticData_CardSkillSetLoadFailed)
	{
		cocos2d::log("[error] 载入静态数据出错：技能卡集合");
		scene->showProgress("载入静态数据出错：技能卡集合");
	}
	else if (msg.messageID == LogicMessagePQ::LMessage_Information_DataLoading_StaticData_MapMainMissionSetLoadSuccess)
	{
		cocos2d::log("[information] 完成静态数据载入：主线任务地图集合");
		scene->showProgress("完成静态数据载入：主线任务地图集合");
	}
	else if (msg.messageID == LogicMessagePQ::LMessage_Error_DataLoading_StaticData_CardMapMainMissionSetSetLoadFailed)
	{
		cocos2d::log("[error] 载入静态数据出错：主线任务地图集合");
		scene->showProgress("载入静态数据出错：主线任务地图集合");
	}
	else if (msg.messageID == LogicMessagePQ::LMessage_ReplaceScene_SceneLoadRes2SceneGameMain)
	{
		scene->replaceSceneGameMain();
	}
	// 未执行则反推回队列
	else
	{
		LogicMessagePQInstance->pushMessage(msg);
	}
	//////////////////////////////////////////////////////////////////////////

	//cocos2d::log("[information] 执行场景 SceneLoadRes 对应的状态机成功");
	return true;
}

bool SceneLoadResState::exit(SceneLoadRes *Scene)
{
	cocos2d::log("[information] 准备离开场景 SceneLoadRes 对应的状态机...");
	cocos2d::log("[information] 离开场景 SceneLoadRes 对应的状态机成功");
	return true;
}