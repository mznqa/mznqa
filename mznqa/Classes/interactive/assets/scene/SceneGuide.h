/*!
 * \file	Classes\interactive\assets\scene\SceneGuide.h
 *
 * \brief	������ SceneGuide
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_INTERACTIVE_ASSETS_SCENE_SCENEGUIDE_H_
#define MZNQA_CLASSES_INTERACTIVE_ASSETS_SCENE_SCENEGUIDE_H_

#include "cocos2d.h"

/*!
* \class	SceneGuide
*
* \brief	��һ������������������һ����
*
*/
class SceneGuide : public cocos2d::Layer
{
private:
	// ����˽���� //////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////

	// ������ //////////////////////////////////////////////////////////////////////////

	/*!
	 * \fn	void SceneGuide::update(float dt);
	 *
	 * \brief	��֡������
	 *
	 */
	void update(float dt);
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

	// �ӿ� //////////////////////////////////////////////////////////////////////////
	/*!
	* \fn	void SceneGuide::replaceSceneResLoading();
	*
	* \brief	���ڴӵ�ǰ�����л��� SceneResLoading
	*
	*/
	void replaceSceneResLoading();
	//////////////////////////////////////////////////////////////////////////
};

#endif