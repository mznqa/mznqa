/*!
 * \file	Classes\interactive\assets\scene\SceneResLoading.h
 *
 * \brief	������ SceneResLoading
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_INTERACTIVE_ASSETS_SCENERESLOADING_H_
#define MZNQA_CLASSES_INTERACTIVE_ASSETS_SCENERESLOADING_H_

#include "cocos2d.h"

/*!
 * \class	SceneResLoading
 *
 * \brief	����������Դ�ĳ���
 *
 */
class SceneResLoading : public cocos2d::Layer
{
private:
	// ����˽���� //////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////

	// ������ //////////////////////////////////////////////////////////////////////////

	/*!
	* \fn	void SceneResLoading::update(float dt);
	*
	* \brief	��֡������
	*
	*/
	void update(float dt);
	//////////////////////////////////////////////////////////////////////////
public:
	CREATE_FUNC(SceneResLoading);
	static cocos2d::Scene* createScene();

	// ���еĳ����������ڷ��� //////////////////////////////////////////////////////////////////////////

	/*!
	* \fn	virtual bool SceneResLoading::init() override;
	*
	* \brief	��д������ʼ������
	*
	*/
	virtual bool init() override;

	/*!
	* \fn	virtual void SceneResLoading::onEnter() override;
	*
	* \brief	��д�������뷽��
	*
	*/
	virtual void onEnter() override;

	/*!
	* \fn	virtual void SceneResLoading::onExit() override;
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