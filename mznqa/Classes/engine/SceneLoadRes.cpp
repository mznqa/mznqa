#pragma execution_character_set("utf-8")

#include "engine/SceneLoadRes.h"

#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include "filePath/SceneFilePath.h"
#include "runtime/SceneLoadResState.h"
#include "engine/SceneGameMain.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* SceneLoadRes::createScene()
{
	auto scene = Scene::create();

	auto layer = SceneLoadRes::create();

	scene->addChild(layer);

	return scene;
}

// ��������ʱ�ĳ�ʼ������
bool SceneLoadRes::init()
{
	log("[information] ���� SceneLoadRes ������...");

	if (!Layer::init())
	{
		return false;
	}

	rootNode = CSLoader::createNode(FILE_PATH_SCENE_LOADRES);

	addChild(rootNode);

	// ��ӵ��ε����������������� init() ���������
	this->scheduleOnce(schedule_selector(SceneLoadRes::updateOnce), 1.0f);

	log("[information] ���� SceneLoadRes �����ɹ�");

	return true;
}

// ���볡��ʱ�Ĳ���
void SceneLoadRes::onEnter()
{
	log("[information] ׼�����볡�� SceneLoadRes ��...");
	// ���ȣ����û��෽��
	Layer::onEnter();
	// ���ó���״̬����
	SceneLoadResState::Instance()->enter(this);

	log("[information] ���볡�� SceneLoadRes �ɹ�");
}

// �뿪����ʱ�Ĳ���
void SceneLoadRes::onExit()
{
	log("[information] ׼���뿪���� SceneLoadRes ��...");
	// ���ȣ����û��෽��
	Layer::onExit();
	// ���ó���״̬����
	SceneLoadResState::Instance()->exit(this);
	log("[information] �뿪���� SceneLoadRes �ɹ�");
}

// ���ε�����
void SceneLoadRes::updateOnce(float dt)
{
	log("[information] ���� SceneLoadRes �����ĵ��ε�����...");
	// ���ó���״̬�������������Ǿ����ϴε��õļ��ʱ�䣬���������ǵ��ε��ȣ��������⴫��1.0f��
	SceneLoadResState::Instance()->update(this, 1.0f);
	log("[information] �뿪 SceneLoadRes �����ĵ��ε�����");
}

void SceneLoadRes::replaceSceneGameMain()
{
	log("[information] ׼���� SceneLoadRes �����л��� SceneGameMain ����...");
	Director::getInstance()->replaceScene(SceneGameMain::createScene());
	log("[information] �� SceneLoadRes �����л��� SceneGameMain ����׼���ɹ�");
}