/*!
 * \file	Classes\engine\SceneGameMain.h
 *
 * \brief	������ SceneGameMain
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_ENGINE_SCENEGAMEMAIN_H_
#define MZNQA_CLASSES_ENGINE_SCENEGAMEMAIN_H_

#include "cocos2d.h"

#include "engine/LayerMap.h"
#include "engine/SpriteRole.h"

/*!
 * \class	SceneGameMain
 *
 * \brief	��Ϸ������
 *
 */
class SceneGameMain : public cocos2d::Layer
{
private:
	// ����˽���� //////////////////////////////////////////////////////////////////////////
	/*! \brief	���ڴ�Ŵ��ⲿ����ĳ����ļ�����Դ */
	cocos2d::Node *rootNode;
	//////////////////////////////////////////////////////////////////////////

	// ������ //////////////////////////////////////////////////////////////////////////

	/*!
	 * \fn	void SceneGameMain::update(float dt);
	 *
	 * \brief	��д��֡������
	 *
	 */
	void update(float dt);
	//////////////////////////////////////////////////////////////////////////
public:
	CREATE_FUNC(SceneGameMain);
	static cocos2d::Scene* createScene();

	// ���������� //////////////////////////////////////////////////////////////////////////
	/*! \brief	��ͼ�� */
	LayerMap *layerMap;
	/*! \brief	��ɫ���� */
	SpriteRole	*spriteRole;
	//////////////////////////////////////////////////////////////////////////

	// ���еĳ����������ڷ��� //////////////////////////////////////////////////////////////////////////

	/*!
	 * \fn	virtual bool SceneGameMain::init() override;
	 *
	 * \brief	��д������ʼ������
	 *
	 */
	virtual bool init() override;

	/*!
	 * \fn	virtual void SceneGameMain::onEnter() override;
	 *
	 * \brief	��д�������뷽��
	 *
	 */
	virtual void onEnter() override;

	/*!
	 * \fn	virtual void SceneGameMain::onExit() override;
	 *
	 * \brief	��д�����뿪����
	 *
	 */
	virtual void onExit() override;
	//////////////////////////////////////////////////////////////////////////
};

#endif	// MZNQA_CLASSES_ENGINE_SCENEGAMEMAIN_H_