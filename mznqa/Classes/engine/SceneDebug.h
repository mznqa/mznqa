#ifndef MZNQA_CLASSES_ENGINE_SCENEDEBUG_H_
#define MZNQA_CLASSES_ENGINE_SCENEDEBUG_H_

#include "cocos2d.h"

// Debug �������ó���������Ϸ������룬����һ������ĳ���
// �ó���������һ���������������ã���ʱ��ʵ���κ�����
// �뱣�ָó����ɾ�����������κζ�����
class SceneDebug : public cocos2d::Layer
{
private:
	cocos2d::Node *rootNode;
protected:

public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(SceneDebug);
};

#endif	// MZNQA_CLASSES_ENGINE_SCENEDEBUG_H_