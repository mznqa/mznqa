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

// ����״̬ǰ�Ĳ���
bool SceneGameMainState::enter(SceneGameMain *scene)
{
	cocos2d::log("[information] ׼�����볡�� SceneGameMain ��Ӧ״̬��...");
	engineMessagePQInstance = EngineMessagePQ::Instance();
	logicMessagePQInstance = LogicMessagePQ::Instance();
	msgInterpreterInstance = MsgInterpreter::Instance();
	mapViewInstance = MapView::Instance();
	cocos2d::log("[information] ���볡�� SceneGameMain ��Ӧ״̬���ɹ�");
	return true;
}

// ״ִ̬��ʱ�Ĳ���
bool SceneGameMainState::update(SceneGameMain *scene, double intervalTime)
{
	cocos2d::log("[information] ��ʼִ�г��� SceneGameMain ��Ӧ��״̬��...");
	// ת����Ϣ
	logicMessagePQInstance->pushMessage(msgInterpreterInstance->translation(engineMessagePQInstance->getNextMessage()));

	// ��ȡ��Ϣ
	Message<LogicMessagePQ::LMessage> msg = logicMessagePQInstance->getNextMessage();
	// ������Ϣ
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
	// ����
	else
	{
		logicMessagePQInstance->pushMessage(msg);
	}

	cocos2d::log("[information] ��ǰ������Ϣ�����д�������Ϣ������%d", engineMessagePQInstance->getMessageCount());
	cocos2d::log("[information] ��ǰ�߼���Ϣ�����д�������Ϣ������%d", logicMessagePQInstance->getMessageCount());

	cocos2d::log("[information] ���� SceneGameMain ��Ӧ��״̬��ִ�����");
	return true;
}

// �뿪״̬ǰ�Ĳ���
bool SceneGameMainState::exit(SceneGameMain *Scene)
{
	cocos2d::log("[information] ׼���뿪���� SceneGameMain ��Ӧ״̬��...");
	cocos2d::log("[information] �뿪���� SceneGameMain ��Ӧ״̬���ɹ�");
	return true;
}