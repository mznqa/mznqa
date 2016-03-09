#ifndef MZNQA_CLASSES_ENGINE_SCENELOADRES_H_
#define MZNQA_CLASSES_ENGINE_SCENELOADRES_H_

#include "cocos2d.h"

// �ó�����������Դ��������ʾ
class SceneLoadRes : public cocos2d::Layer
{
private:
	// ����˽���� //////////////////////////////////////////////////////////////////////////

	// ���ڴ�Ŵ��ⲿ����ĳ����ļ�����Դ
	cocos2d::Node *rootNode;
	//////////////////////////////////////////////////////////////////////////
protected:

public:
	CREATE_FUNC(SceneLoadRes);
	static cocos2d::Scene* createScene();

	// ���еĳ����������ڷ��� //////////////////////////////////////////////////////////////////////////
	// ��д������ʼ������
	virtual bool init();

	// ��д��������ʱ�ķ���
	virtual void onEnter();

	// ��д�����뿪ʱ�ķ���
	virtual void onExit();
	//////////////////////////////////////////////////////////////////////////
};

#endif	// MZNQA_CLASSES_ENGINE_SCENELOADRES_H_