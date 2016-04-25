/*!
 * \file	Classes\engine\SceneDebug.h
 *
 * \brief	������ SceneDebug
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_ENGINE_SCENEDEBUG_H_
#define MZNQA_CLASSES_ENGINE_SCENEDEBUG_H_

#include "cocos2d.h"

/*!
 * \class	SceneDebug
 *
 * \brief	���õĳ����������������� SceneGuide
 *
 */
class SceneDebug : public cocos2d::Layer
{
private:
	// ����˽���� //////////////////////////////////////////////////////////////////////////
	/*! \brief	���ⲿ�ļ�����ĳ����ļ�����ŵ�λ�� */
	cocos2d::Node *rootNode;
	//////////////////////////////////////////////////////////////////////////
public:
	CREATE_FUNC(SceneDebug);
	static cocos2d::Scene* createScene();

	// ���еĳ����������ڷ��� //////////////////////////////////////////////////////////////////////////

	/*!
	 * \fn	virtual bool SceneDebug::init() override;
	 *
	 * \brief	��д������ʼ������
	 *
	 */
	virtual bool init() override;

	/*!
	 * \fn	virtual void SceneDebug::onEnter() override;
	 *
	 * \brief	��д�������뷽��
	 *
	 */
	virtual void onEnter() override;

	/*!
	 * \fn	virtual void SceneDebug::onExit() override;
	 *
	 * \brief	��д�����뿪����
	 *
	 */
	virtual void onExit() override;
	//////////////////////////////////////////////////////////////////////////
};

#endif	// MZNQA_CLASSES_ENGINE_SCENEDEBUG_H_