#ifndef MZNQA_CLASSES_ENGINE_SCENEGUIDE_H_
#define MZNQA_CLASSES_ENGINE_SCENEGUIDE_H_

#include "cocos2d.h"

// �ó���������������ȷ��ʼ���������׵�״̬������ʱ����Ҫ�������ݣ����޸ģ�
class SceneGuide : public cocos2d::Layer
{
private:
	// ���ڴ���ⲿ�����ļ��������Դ
	cocos2d::Node *rootNode;

	void updateOnce(float dt);
protected:

public:
	static cocos2d::Scene* createScene();

	// ��д�����ĳ�ʼ������
	virtual bool init();

	// ��д�����Ľ��뷽��
	virtual void onEnter();

	// ��д�������뿪����
	virtual void onExit();

	CREATE_FUNC(SceneGuide);
};

#endif	// MZNQA_CLASSES_ENGINE_SCENEGUIDE_H_