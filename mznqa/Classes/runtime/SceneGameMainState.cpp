#pragma execution_character_set("utf-8")

#include "runtime/SceneGameMainState.h"


SceneGameMainState::~SceneGameMainState()
{
}

SceneGameMainState* SceneGameMainState::Instance()
{
	static SceneGameMainState instance;
	return &instance;
}

// 进入状态前的操作
bool SceneGameMainState::enter(SceneGameMain *scene)
{
	cocos2d::log("[information] 准备进入场景 SceneGameMain 对应状态机...");
	engineMessagePQInstance = EngineMessagePQ::Instance();
	logicMessagePQInstance = LogicMessagePQ::Instance();
	msgInterpreterInstance = MsgInterpreter::Instance();
	mapViewInstance = MapView::Instance();
	cocos2d::log("[information] 进入场景 SceneGameMain 对应状态机成功");
	return true;
}

// 状态执行时的操作
bool SceneGameMainState::update(SceneGameMain *scene, double intervalTime)
{
	cocos2d::log("[information] 开始执行场景 SceneGameMain 对应的状态机...");
	// 转译消息
	logicMessagePQInstance->pushMessage(msgInterpreterInstance->translation(engineMessagePQInstance->getNextMessage()));

	// 获取消息
	Message<LogicMessagePQ::LMessage> msg = logicMessagePQInstance->getNextMessage();
	// 处理消息
	if (msg.messageID == LogicMessagePQ::LMessage_MapViewMoveUp)
	{
		mapViewInstance->moveUp();
	}
	else if (msg.messageID == LogicMessagePQ::LMessage_MapViewMoveRight)
	{
		mapViewInstance->moveRight();
	}
	else if (msg.messageID == LogicMessagePQ::LMessage_MapViewMoveDown)
	{
		mapViewInstance->moveDown();
	}
	else if (msg.messageID == LogicMessagePQ::LMessage_MapViewMoveLeft)
	{
		mapViewInstance->moveLeft();
	}
	else if (msg.messageID == LogicMessagePQ::LMessage_RefreshMapPosition)
	{
		scene->layerMap->refreshPosition();
	}
	else if (msg.messageID == LogicMessagePQ::LMessage_RefreshRolePosition)
	{
		scene->spriteRole->refreshPosition();
	}
	// 反推
	else
	{
		logicMessagePQInstance->pushMessage(msg);
	}

	cocos2d::log("[information] 当前引擎消息队列中待处理消息个数：%d", engineMessagePQInstance->getMessageCount());
	cocos2d::log("[information] 当前逻辑消息队列中待处理消息个数：%d", logicMessagePQInstance->getMessageCount());

	cocos2d::log("[information] 场景 SceneGameMain 对应的状态机执行完成");
	return true;
}

// 离开状态前的操作
bool SceneGameMainState::exit(SceneGameMain *Scene)
{
	cocos2d::log("[information] 准备离开场景 SceneGameMain 对应状态机...");
	cocos2d::log("[information] 离开场景 SceneGameMain 对应状态机成功");
	return true;
}