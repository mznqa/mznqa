/*!
 * \file	Classes\interactive\assets\scene\SceneGameMain.h
 *
 * \brief	������ SceneGameMain
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_INTERACTIVE_ASSETS_SCENE_SCENEGAMEMAIN_H_
#define MZNQA_CLASSES_INTERACTIVE_ASSETS_SCENE_SCENEGAMEMAIN_H_

#include "cocos2d.h"

#include "helper/bridge/Bridge.h"
#include "interactive/assets/layer/LayerMap.h"

/*!
* \class	SceneGameMain
*
* \brief	��Ϸ������
*
*/
class SceneGameMain : public cocos2d::Layer
{
private:
	// �������� //////////////////////////////////////////////////////////////////////////
	Bridge *const BridgeInstance = Bridge::Instance();
	//////////////////////////////////////////////////////////////////////////

	// ����˽���� //////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////

	// ������ //////////////////////////////////////////////////////////////////////////

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