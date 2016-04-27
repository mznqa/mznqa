/*!
 * \file	Classes\runtime\SceneGameMainState.h
 *
 * \brief	������ SceneGameMainState
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_RUNTIME_SCENEGAMEMAINSTATE_H_
#define MZNQA_CLASSES_RUNTIME_SCENEGAMEMAINSTATE_H_

#include "cocos2d.h"

#include "runtime/BaseSceneState.h"
#include "engine/SceneGameMain.h"
#include "message/EngineMessagePQ.h"
#include "message/LogicMessagePQ.h"
#include "message/MsgInterpreter.h"
#include "map/MapView.h"
#include "staticData/MissionMapSet.h"
#include "map/MapController.h"
#include "gameobject/Role.h"
#include "cardController/CardControllerExplore.h"

/*!
 * \class	SceneGameMainState
 *
 * \brief	�� SceneGameMain ���׵�״̬��
 *
 */
class SceneGameMainState : public BaseSceneState<SceneGameMain>
{
private:

	/*!
	 * \fn	SceneGameMainState::SceneGameMainState()
	 *
	 * \brief	���صĹ��캯��
	 *
	 */
	SceneGameMainState(){}

	/*!
	 * \fn	SceneGameMainState::SceneGameMainState(const SceneGameMainState &sceneGameMainState)
	 *
	 * \brief	���صĿ������캯��
	 *
	 * \param	sceneGameMainState	SceneGameMainState ʵ��
	 */
	SceneGameMainState(const SceneGameMainState &sceneGameMainState){}

	/*!
	 * \fn	SceneGameMainState& SceneGameMainState::operator=(const SceneGameMainState &sceneGameMainState)
	 *
	 * \brief	���صĿ�����ֵ�����
	 *
	 * \param	sceneGameMainState	SceneGameMainState ʵ��
	 *
	 * \return	���� SceneGameMainState ʵ��
	 */
	SceneGameMainState& operator=(const SceneGameMainState &sceneGameMainState){}

	// �������� //////////////////////////////////////////////////////////////////////////
	/*! \brief	���� EngineMessagePQ::Instance() �ĳ���ָ�� */
	EngineMessagePQ *const EngineMessagePQInstance = EngineMessagePQ::Instance();
	/*! \brief	���� LogicMessagePQ::Instance() �ĳ���ָ�� */
	LogicMessagePQ *const LogicMessagePQInstance = LogicMessagePQ::Instance();
	/*! \brief	���� MsgInterpreter::Instance() �ĳ���ָ�� */
	MsgInterpreter *const MsgInterpreterInstance = MsgInterpreter::Instance();
	/*! \brief	���� MapView::Instance() �ĳ���ָ�� */
	MapView *const MapViewInstance = MapView::Instance();
	/*! \brief	���� MapController::Instance() �ĳ���ָ�� */
	MapController *const MapControllerInstance = MapController::Instance();
	/*! \brief	���� MissionMapSet::Instance() �ĳ���ָ�� */
	MissionMapSet *const MissionMapSetInstance = MissionMapSet::Instance();
	/*! \brief	���� Role::Instance() �ĳ���ָ�� */
	Role *const RoleInstance = Role::Instance();
	/*! \brief	���� CardControllerExplore::Instance() �ĳ���ָ�� */
	CardControllerExplore *const cardControllerExploreInstance = CardControllerExplore::Instance();
	//////////////////////////////////////////////////////////////////////////

public:

	/*!
	 * \fn	SceneGameMainState::~SceneGameMainState();
	 *
	 * \brief	��������
	 *
	 */
	~SceneGameMainState();

	/*!
	 * \fn	static SceneGameMainState* SceneGameMainState::Instance();
	 *
	 * \brief	��ȡ����
	 *
	 * \return	���ص���
	 */
	static SceneGameMainState* Instance();

	/*!
	 * \fn	bool SceneGameMainState::enter(SceneGameMain *scene);
	 *
	 * \brief	״̬������������״̬��ʱ�Ĳ���
	 *
	 * \param [in,out]	scene	SceneGameMain ʵ��
	 *
	 * \return	�����Ƿ�ɹ�ִ��
	 */
	bool  enter(SceneGameMain *scene);

	/*!
	 * \fn	bool SceneGameMainState::update(SceneGameMain *scene, double intervalTime);
	 *
	 * \brief	״̬�����������ظ�ִ�е�״̬���������
	 *
	 * \param [in,out]	scene	SceneGameMain ʵ��
	 * \param	intervalTime 	���ϴβ���������������ʱ��
	 *
	 * \return	�����Ƿ�ɹ�ִ��
	 */
	bool update(SceneGameMain *scene, double intervalTime);

	/*!
	 * \fn	bool SceneGameMainState::exit(SceneGameMain *Scene);
	 *
	 * \brief	״̬���������뿪״̬��ʱ�Ĳ���
	 *
	 * \param [in,out]	Scene	SceneGameMain ʵ��
	 *
	 * \return	�����Ƿ��ִ��
	 */
	bool exit(SceneGameMain *Scene);
};

#endif