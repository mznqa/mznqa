/*!
 * \file	Classes\engine\SceneLoadRes.h
 *
 * \brief	������ SceneLoadRes
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_ENGINE_SCENELOADRES_H_
#define MZNQA_CLASSES_ENGINE_SCENELOADRES_H_

#include <string>

#include "cocos2d.h"
#include "ui/CocosGUI.h"

/*!
 * \class	SceneLoadRes
 *
 * \brief	����ִ����Դ����ĳ���
 *
 */
class SceneLoadRes : public cocos2d::Layer
{
private:
	// �ⲿ�ļ��е�UI���� //////////////////////////////////////////////////////////////////////////
	static const std::string UiNameTextOutput;
	//////////////////////////////////////////////////////////////////////////
	// ����˽���� //////////////////////////////////////////////////////////////////////////
	/*! \brief	���ڴ�Ŵ��ⲿ����ĳ����ļ�����Դ */
	cocos2d::Node *rootNode;
	//////////////////////////////////////////////////////////////////////////

	// ������ //////////////////////////////////////////////////////////////////////////

	/*!
	 * \fn	void SceneLoadRes::update(float dt);
	 *
	 * \brief	��֡��������д
	 *
	 */
	void update(float dt);
	//////////////////////////////////////////////////////////////////////////

public:
	CREATE_FUNC(SceneLoadRes);
	static cocos2d::Scene* createScene();

	// ���������� //////////////////////////////////////////////////////////////////////////
	/*! \brief	���������Ϣ���ı���UI */
	cocos2d::ui::Text *uiTextOutput;
	//////////////////////////////////////////////////////////////////////////

	// ���еĳ����������ڷ��� //////////////////////////////////////////////////////////////////////////
	/*!
	 * \fn	virtual bool SceneLoadRes::init() override;
	 *
	 * \brief	��д������ʼ������
	 *
	 */
	virtual bool init() override;

	/*!
	 * \fn	virtual void SceneLoadRes::onEnter() override;
	 *
	 * \brief	��д�������뷽��
	 *
	 */
	virtual void onEnter() override;

	/*!
	 * \fn	virtual void SceneLoadRes::onExit() override;
	 *
	 * \brief	��д�����뿪����
	 *
	 */
	virtual void onExit() override;
	//////////////////////////////////////////////////////////////////////////

	// API //////////////////////////////////////////////////////////////////////////

	/*!
	 * \fn	void SceneLoadRes::replaceSceneGameMain();
	 *
	 * \brief	���ڴӵ�ǰ�����л��� SceneGameMain
	 *
	 */
	void replaceSceneGameMain();

	/*!
	 * \fn	void SceneLoadRes::showProgress(std::string log);
	 *
	 * \brief	�����Դ����Ľ�����Ϣ
	 *
	 * \param	log	���������Ϣ
	 */
	void showProgress(std::string log);
	//////////////////////////////////////////////////////////////////////////
};

#endif	// MZNQA_CLASSES_ENGINE_SCENELOADRES_H_