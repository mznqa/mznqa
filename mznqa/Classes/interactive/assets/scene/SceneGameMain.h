/*!
 * \file	Classes\interactive\assets\scene\SceneGameMain.h
 *
 * \brief	������ SceneGameMain
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_INTERACTIVE_ASSETS_SCENE_SCENEGAMEMAIN_H_
#define MZNQA_CLASSES_INTERACTIVE_ASSETS_SCENE_SCENEGAMEMAIN_H_

#include "cocos2d.h"

#include "interactive/assets/layer/LayerMap.h"
#include "interactive/assets/layer/LayerWorkbench.h"
#include "interactive/message/InteractiveMessagePQ.h"

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
	/*! \brief	��ͼ�� */
	LayerMap *layerMap;
	/*! \brief	������ */
	LayerWorkbench *layerWorkbench;

	/*! \brief	�������͵���Ϣ */
	InteractiveMessagePQ::InteractiveMessageID loopMessage;
	//////////////////////////////////////////////////////////////////////////

	// ʱ������� //////////////////////////////////////////////////////////////////////////

	/*!
	 * \fn	void SceneGameMain::addKeyboardEventListener();
	 *
	 * \brief	��Ӱ��������¼�
	 *
	 */
	void addKeyboardEventListener();

	/*!
	 * \fn	void SceneGameMain::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	 *
	 * \brief	��д���������¼�
	 *
	 */
	void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);

	/*!
	 * \fn	void SceneGameMain::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	 *
	 * \brief	��д�����ͷ��¼�
	 *
	 */
	void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	//////////////////////////////////////////////////////////////////////////

	// ������ //////////////////////////////////////////////////////////////////////////

	/*!
	 * \fn	void SceneGameMain::messagePushLoop(float dt);
	 *
	 * \brief	���ڳ���������Ϣ
	 *
	 */
	void messagePushLoop(float dt);
	/*!
	* \fn	void SceneGameMain::update(float dt);
	*
	* \brief	��֡������
	*
	*/
	void update(float dt);
	//////////////////////////////////////////////////////////////////////////
public:
	CREATE_FUNC(SceneGameMain);
	static cocos2d::Scene* createScene();

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

	// �ӿ� //////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
};

#endif