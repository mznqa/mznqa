/*!
 * \file	Classes\runtime\SceneGuideState.h
 *
 * \brief	������ SceneGuideState
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_RUNTIME_SCENEGUIDESTATE_H_
#define MZNQA_CLASSES_RUNTIME_SCENEGUIDESTATE_H_

#include "cocos2d.h"

#include "runtime/BaseSceneState.h"
#include "engine/SceneGuide.h"

/*!
 * \class	SceneGuideState
 *
 * \brief	�������� SceneGuide ���׵�״̬��
 *
 */
class SceneGuideState : public BaseSceneState<SceneGuide>
{
private:

	/*!
	 * \fn	SceneGuideState::SceneGuideState()
	 *
	 * \brief	���صĹ��캯��
	 *
	 */
	SceneGuideState(){}

	/*!
	 * \fn	SceneGuideState::SceneGuideState(const SceneGuideState &sceneGuideState)
	 *
	 * \brief	���صĿ������캯��
	 *
	 * \param	sceneGuideState	SceneGuideState ʵ��
	 */
	SceneGuideState(const SceneGuideState &sceneGuideState){}

	/*!
	 * \fn	SceneGuideState& SceneGuideState::operator=(const SceneGuideState &sceneGuideState)
	 *
	 * \brief	���صĿ�����ֵ�����
	 *
	 * \param	sceneGuideState	SceneGuideState ʵ��
	 *
	 * \return	���� SceneGuideState ʵ��
	 */
	SceneGuideState& operator=(const SceneGuideState &sceneGuideState){}
public:

	/*!
	 * \fn	SceneGuideState::~SceneGuideState();
	 *
	 * \brief	��������
	 *
	 */
	~SceneGuideState();

	/*!
	 * \fn	static SceneGuideState* SceneGuideState::Instance();
	 *
	 * \brief	��ȡ����
	 *
	 * \return	���ص���
	 */
	static SceneGuideState* Instance();

	/*!
	 * \fn	bool SceneGuideState::enter(SceneGuide *scene);
	 *
	 * \brief	״̬������������״̬��ʱ�Ĳ���
	 *
	 * \param [in,out]	scene	SceneGuide ʵ��
	 *
	 * \return	�����Ƿ�ɹ�ִ��
	 */
	bool enter(SceneGuide *scene);

	/*!
	 * \fn	bool SceneGuideState::update(SceneGuide *scene, double intervalTime);
	 *
	 * \brief	״̬�����������ظ�ִ�е�״̬���������
	 *
	 * \param [in,out]	scene	SceneGuide ʵ��
	 * \param	intervalTime 	���ϴβ���������������ʱ��
	 *
	 * \return	�����Ƿ�ɹ�ִ��
	 */
	bool update(SceneGuide *scene, double intervalTime);

	/*!
	 * \fn	bool SceneGuideState::exit(SceneGuide *Scene);
	 *
	 * \brief	״̬���������뿪״̬��ʱ�Ĳ���
	 *
	 * \param [in,out]	Scene	SceneGuide ʵ��
	 *
	 * \return	�����Ƿ�ɹ�ִ��
	 */
	bool exit(SceneGuide *Scene);
};

#endif