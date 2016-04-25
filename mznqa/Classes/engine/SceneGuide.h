/*!
 * \file	Classes\engine\SceneGuide.h
 *
 * \brief	������ SceneGuide
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_ENGINE_SCENEGUIDE_H_
#define MZNQA_CLASSES_ENGINE_SCENEGUIDE_H_

#include "cocos2d.h"

/*!
 * \class	SceneGuide
 *
 * \brief	��Ϊ��һ����������������������һ����
 *
 */
class SceneGuide : public cocos2d::Layer
{
private:
	// ����˽���� //////////////////////////////////////////////////////////////////////////
	/*! \brief	���ڴ���ⲿ�����ļ��������Դ */
	cocos2d::Node *rootNode;
	//////////////////////////////////////////////////////////////////////////

	// ������ //////////////////////////////////////////////////////////////////////////
	/*!
	 * \fn	void SceneGuide::updateOnce(float dt);
	 *
	 * \brief	��д���ε�����
	 *
	 */
	void updateOnce(float dt);
	//////////////////////////////////////////////////////////////////////////
public:
	CREATE_FUNC(SceneGuide);
	static cocos2d::Scene* createScene();

	// ���еĳ����������ڷ��� //////////////////////////////////////////////////////////////////////////

	/*!
	 * \fn	virtual bool SceneGuide::init() override;
	 *
	 * \brief	��д������ʼ������
	 *
	 */
	virtual bool init() override;

	/*!
	 * \fn	virtual void SceneGuide::onEnter() override;
	 *
	 * \brief	��д�������뷽��
	 *
	 */
	virtual void onEnter() override;

	/*!
	 * \fn	virtual void SceneGuide::onExit() override;
	 *
	 * \brief	��д�����뿪����
	 *
	 */
	virtual void onExit() override;
	//////////////////////////////////////////////////////////////////////////

	// API //////////////////////////////////////////////////////////////////////////

	/*!
	 * \fn	void SceneGuide::replaceSceneLoadRes();
	 *
	 * \brief	���ڴӵ�ǰ�����л��� SceneLoadRes
	 *
	 */
	void replaceSceneLoadRes();
	//////////////////////////////////////////////////////////////////////////
};

#endif	// MZNQA_CLASSES_ENGINE_SCENEGUIDE_H_