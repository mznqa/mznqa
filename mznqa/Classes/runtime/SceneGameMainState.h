/*!
 * \file	Classes\runtime\SceneGameMainState.h
 *
 * \brief	定义类 SceneGameMainState
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
 * \brief	与 SceneGameMain 配套的状态机
 *
 */
class SceneGameMainState : public BaseSceneState<SceneGameMain>
{
private:

	/*!
	 * \fn	SceneGameMainState::SceneGameMainState()
	 *
	 * \brief	隐藏的构造函数
	 *
	 */
	SceneGameMainState(){}

	/*!
	 * \fn	SceneGameMainState::SceneGameMainState(const SceneGameMainState &sceneGameMainState)
	 *
	 * \brief	隐藏的拷贝构造函数
	 *
	 * \param	sceneGameMainState	SceneGameMainState 实例
	 */
	SceneGameMainState(const SceneGameMainState &sceneGameMainState){}

	/*!
	 * \fn	SceneGameMainState& SceneGameMainState::operator=(const SceneGameMainState &sceneGameMainState)
	 *
	 * \brief	隐藏的拷贝赋值运算符
	 *
	 * \param	sceneGameMainState	SceneGameMainState 实例
	 *
	 * \return	返回 SceneGameMainState 实例
	 */
	SceneGameMainState& operator=(const SceneGameMainState &sceneGameMainState){}

	// 单例别名 //////////////////////////////////////////////////////////////////////////
	/*! \brief	保存 EngineMessagePQ::Instance() 的常量指针 */
	EngineMessagePQ *const EngineMessagePQInstance = EngineMessagePQ::Instance();
	/*! \brief	保存 LogicMessagePQ::Instance() 的常量指针 */
	LogicMessagePQ *const LogicMessagePQInstance = LogicMessagePQ::Instance();
	/*! \brief	保存 MsgInterpreter::Instance() 的常量指针 */
	MsgInterpreter *const MsgInterpreterInstance = MsgInterpreter::Instance();
	/*! \brief	保存 MapView::Instance() 的常量指针 */
	MapView *const MapViewInstance = MapView::Instance();
	/*! \brief	保存 MapController::Instance() 的常量指针 */
	MapController *const MapControllerInstance = MapController::Instance();
	/*! \brief	保存 MissionMapSet::Instance() 的常量指针 */
	MissionMapSet *const MissionMapSetInstance = MissionMapSet::Instance();
	/*! \brief	保存 Role::Instance() 的常量指针 */
	Role *const RoleInstance = Role::Instance();
	/*! \brief	保存 CardControllerExplore::Instance() 的常量指针 */
	CardControllerExplore *const cardControllerExploreInstance = CardControllerExplore::Instance();
	//////////////////////////////////////////////////////////////////////////

public:

	/*!
	 * \fn	SceneGameMainState::~SceneGameMainState();
	 *
	 * \brief	析构函数
	 *
	 */
	~SceneGameMainState();

	/*!
	 * \fn	static SceneGameMainState* SceneGameMainState::Instance();
	 *
	 * \brief	获取单例
	 *
	 * \return	返回单例
	 */
	static SceneGameMainState* Instance();

	/*!
	 * \fn	bool SceneGameMainState::enter(SceneGameMain *scene);
	 *
	 * \brief	状态机操作：进入状态机时的操作
	 *
	 * \param [in,out]	scene	SceneGameMain 实例
	 *
	 * \return	返回是否成功执行
	 */
	bool  enter(SceneGameMain *scene);

	/*!
	 * \fn	bool SceneGameMainState::update(SceneGameMain *scene, double intervalTime);
	 *
	 * \brief	状态机操作：可重复执行的状态机主体操作
	 *
	 * \param [in,out]	scene	SceneGameMain 实例
	 * \param	intervalTime 	自上次操作以来所经历的时间
	 *
	 * \return	返回是否成功执行
	 */
	bool update(SceneGameMain *scene, double intervalTime);

	/*!
	 * \fn	bool SceneGameMainState::exit(SceneGameMain *Scene);
	 *
	 * \brief	状态机操作：离开状态机时的操作
	 *
	 * \param [in,out]	Scene	SceneGameMain 实例
	 *
	 * \return	返回是否成执行
	 */
	bool exit(SceneGameMain *Scene);
};

#endif