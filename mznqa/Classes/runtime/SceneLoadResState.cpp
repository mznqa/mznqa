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
	cocos2d::log("[information] ׼�����볡�� SceneLoadRes ��Ӧ��״̬����...");
	// �����ִ�е���Ϣ���У� //////////////////////////////////////////////////////////////////////////
	// ������Ϣ�����룺��̬���ݣ����ο�������
	LogicMessagePQInstance->pushMessage(Message<LogicMessagePQ::LMessage>(LogicMessagePQ::LMessage_LoadData_StaticData_CardRoadSet));
	// ������Ϣ�����룺��̬���ݣ����ܿ�����
	LogicMessagePQInstance->pushMessage(Message<LogicMessagePQ::LMessage>(LogicMessagePQ::LMessage_LoadData_StaticData_CardSkillSet));
	// ������Ϣ�����룺��̬���ݣ����������ͼ����
	LogicMessagePQInstance->pushMessage(Message<LogicMessagePQ::LMessage>(LogicMessagePQ::LMessage_LoadData_StaticData_MapMainMissionSet));
	// ������Ϣ����ת������SceneLoadRes �� SceneGameMain
	LogicMessagePQInstance->pushMessage(Message<LogicMessagePQ::LMessage>(LogicMessagePQ::LMessage_ReplaceScene_SceneLoadRes2SceneGameMain));
	//////////////////////////////////////////////////////////////////////////
	cocos2d::log("[information] ׼�����볡�� SceneLoadRes ��Ӧ��״̬���ɹ�");
	return true;
}

bool SceneLoadResState::update(SceneLoadRes *scene, double intervalTime)
{
	//cocos2d::log("[information] ��ʼִ�г��� SceneLoadRes ��Ӧ��״̬��...");
	// ��Ϣ����ģ�� //////////////////////////////////////////////////////////////////////////
	// ת����Ϣ
	LogicMessagePQInstance->pushMessage(MsgInterpreterInstance->translation(EngineMessagePQInstance->getNextMessage()));

	// ��ȡ��Ϣ
	Message<LogicMessagePQ::LMessage> msg = LogicMessagePQInstance->getNextMessage();
	// ������Ϣ
	if (msg.messageID == LogicMessagePQ::LMessage_LoadData_StaticData_CardRoadSet)
	{
		cocos2d::log("[information] ��ʼ���뾲̬���ݣ����ο�����...");
		scene->showProgress("��ʼ���뾲̬���ݣ����ο�����...");
		StaticDataLoader::loadStaticDataCardRoadSet();
	}
	else if (msg.messageID == LogicMessagePQ::LMessage_LoadData_StaticData_CardSkillSet)
	{
		cocos2d::log("[information] ��ʼ���뾲̬���ݣ����ܿ�����...");
		scene->showProgress("��ʼ���뾲̬���ݣ����ܿ�����...");
		StaticDataLoader::loadStaticDataCardSkillSet();
	}
	else if (msg.messageID == LogicMessagePQ::LMessage_LoadData_StaticData_MapMainMissionSet)
	{
		cocos2d::log("[information] ��ʼ���뾲̬���ݣ����������ͼ����...");
		scene->showProgress("��ʼ���뾲̬���ݣ����������ͼ����...");
		StaticDataLoader::loadStaticDataMainMissionMapSet();
	}
	else if (msg.messageID == LogicMessagePQ::LMessage_Information_DataLoading_StaticData_CardRoadSetLoadSuccess)
	{
		cocos2d::log("[information] ��ɾ�̬�������룺���ο�����");
		scene->showProgress("��ɾ�̬�������룺���ο�����");
	}
	else if (msg.messageID == LogicMessagePQ::LMessage_Error_DataLoading_StaticData_CardRoadSetLoadFailed)
	{
		cocos2d::log("[error] ���뾲̬���ݳ������ο�����");
		scene->showProgress("���뾲̬���ݳ������ο�����");
	}
	else if (msg.messageID == LogicMessagePQ::LMessage_Information_DataLoading_StaticData_CardSkillSetLoadSuccess)
	{
		cocos2d::log("[information] ��ɾ�̬�������룺���ܿ�����");
		scene->showProgress("��ɾ�̬�������룺���ܿ�����");
	}
	else if (msg.messageID == LogicMessagePQ::LMessage_Error_DataLoading_StaticData_CardSkillSetLoadFailed)
	{
		cocos2d::log("[error] ���뾲̬���ݳ������ܿ�����");
		scene->showProgress("���뾲̬���ݳ������ܿ�����");
	}
	else if (msg.messageID == LogicMessagePQ::LMessage_Information_DataLoading_StaticData_MapMainMissionSetLoadSuccess)
	{
		cocos2d::log("[information] ��ɾ�̬�������룺���������ͼ����");
		scene->showProgress("��ɾ�̬�������룺���������ͼ����");
	}
	else if (msg.messageID == LogicMessagePQ::LMessage_Error_DataLoading_StaticData_CardMapMainMissionSetSetLoadFailed)
	{
		cocos2d::log("[error] ���뾲̬���ݳ������������ͼ����");
		scene->showProgress("���뾲̬���ݳ������������ͼ����");
	}
	else if (msg.messageID == LogicMessagePQ::LMessage_ReplaceScene_SceneLoadRes2SceneGameMain)
	{
		scene->replaceSceneGameMain();
	}
	// δִ�����ƻض���
	else
	{
		LogicMessagePQInstance->pushMessage(msg);
	}
	//////////////////////////////////////////////////////////////////////////

	//cocos2d::log("[information] ִ�г��� SceneLoadRes ��Ӧ��״̬���ɹ�");
	return true;
}

bool SceneLoadResState::exit(SceneLoadRes *Scene)
{
	cocos2d::log("[information] ׼���뿪���� SceneLoadRes ��Ӧ��״̬��...");
	cocos2d::log("[information] �뿪���� SceneLoadRes ��Ӧ��״̬���ɹ�");
	return true;
}