/*!
 * \file	Classes\runtime\SceneLoadResState.h
 *
 * \brief	������ SceneLoadResState
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_RUNTIME_SCENELOADRESSTATE_H_
#define MZNQA_CLASSES_RUNTIME_SCENELOADRESSTATE_H_

#include "cocos2d.h"

#include "runtime/BaseSceneState.h"
#include "engine/SceneLoadRes.h"
#include "message/EngineMessagePQ.h"
#include "message/LogicMessagePQ.h"
#include "message/MsgInterpreter.h"

/*!
 * \class	SceneLoadResState
 *
 * \brief	�������� SceneLoadRes ���׵�״̬��
 *
 */
class SceneLoadResState : public BaseSceneState<SceneLoadRes>
{
private:

	/*!
	 * \fn	SceneLoadResState::SceneLoadResState()
	 *
	 * \brief	���صĹ��캯��
	 *
	 */
	SceneLoadResState(){}

	/*!
	 * \fn	SceneLoadResState::SceneLoadResState(const SceneLoadResState &sceneLoadResState)
	 *
	 * \brief	���صĿ������캯��
	 *
	 * \param	sceneLoadResState	SceneLoadResState ʵ��
	 */
	SceneLoadResState(const SceneLoadResState &sceneLoadResState){}

	/*!
	 * \fn	SceneLoadResState& SceneLoadResState::operator=(const SceneLoadResState &sceneLoadResState)
	 *
	 * \brief	���صĿ������������
	 *
	 * \param	sceneLoadResState	SceneLoadResState ʵ��
	 *
	 * \return	���� SceneLoadResState ʵ��
	 */
	SceneLoadResState& operator=(const SceneLoadResState &sceneLoadResState){}

	// �������� //////////////////////////////////////////////////////////////////////////
	/*! \brief	���� EngineMessagePQ::Instance() �ĳ���ָ�� */
	EngineMessagePQ *const EngineMessagePQInstance = EngineMessagePQ::Instance();
	/*! \brief	���� LogicMessagePQ::Instance() �ĳ���ָ�� */
	LogicMessagePQ *const LogicMessagePQInstance = LogicMessagePQ::Instance();
	/*! \brief	���� MsgInterpreter::Instance() �ĳ���ָ�� */
	MsgInterpreter *const MsgInterpreterInstance = MsgInterpreter::Instance();
	//////////////////////////////////////////////////////////////////////////

public:

	/*!
	 * \fn	SceneLoadResState::~SceneLoadResState();
	 *
	 * \brief	��������
	 *
	 */
	~SceneLoadResState();

	/*!
	 * \fn	static SceneLoadResState* SceneLoadResState::Instance();
	 *
	 * \brief	��ȡ����
	 *
	 * \return	���ص���
	 */
	static SceneLoadResState* Instance();

	/*!
	 * \fn	bool SceneLoadResState::enter(SceneLoadRes *scene);
	 *
	 * \brief	״̬������������״̬��ʱ�Ĳ���
	 *
	 * \param [in,out]	scene	SceneLoadRes ʵ��
	 *
	 * \return	�����Ƿ�ɹ�ִ��
	 */
	bool  enter(SceneLoadRes *scene);

	/*!
	 * \fn	bool SceneLoadResState::update(SceneLoadRes *scene, double intervalTime);
	 *
	 * \brief	״̬�����������ظ�ִ�е�״̬���������
	 *
	 * \param [in,out]	scene	SceneLoadRes ʵ��
	 * \param	intervalTime 	���ϴβ���������������ʱ��
	 *
	 * \return	�����Ƿ�ɹ�ִ��
	 */
	bool update(SceneLoadRes *scene, double intervalTime);

	/*!
	 * \fn	bool SceneLoadResState::exit(SceneLoadRes *Scene);
	 *
	 * \brief	״̬���������뿪״̬��ʱ�Ĳ���
	 *
	 * \param [in,out]	Scene	SceneLoadRes ʵ��
	 *
	 * \return	�����Ƿ�ɹ�ִ��
	 */
	bool exit(SceneLoadRes *Scene);
};

#endif