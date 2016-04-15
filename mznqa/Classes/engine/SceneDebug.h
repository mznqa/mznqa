#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_ENGINE_SCENEDEBUG_H_
#define MZNQA_CLASSES_ENGINE_SCENEDEBUG_H_

#include "cocos2d.h"

// Debug �������ó���������Ϸ������룬����һ������ĳ���
// �ó���������һ���������������ã���ʱ��ʵ���κ�����
// �뱣�ָó����ɾ�����������κζ�����
class SceneDebug : public cocos2d::Layer
{
private:
	// ����˽���� //////////////////////////////////////////////////////////////////////////

	// ���ⲿ�ļ�����ĳ����ļ�����ŵ�λ��
	cocos2d::Node *rootNode;
	//////////////////////////////////////////////////////////////////////////
public:
	CREATE_FUNC(SceneDebug);
	static cocos2d::Scene* createScene();

	// ���еĳ����������ڷ��� //////////////////////////////////////////////////////////////////////////

	// ��д�����ĳ�ʼ������
	virtual bool init() override;

	// ��д��������ʱ�Ĳ���
	virtual void onEnter() override;

	// ��д�����뿪ʱ�Ĳ���
	virtual void onExit() override;
	//////////////////////////////////////////////////////////////////////////
};

#endif	// MZNQA_CLASSES_ENGINE_SCENEDEBUG_H_