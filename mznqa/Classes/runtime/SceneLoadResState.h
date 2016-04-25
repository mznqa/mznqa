/*!
 * \file	Classes\runtime\SceneLoadResState.h
 *
 * \brief	定义类 SceneLoadResState
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
 * \brief	单例。与 SceneLoadRes 配套的状态机
 *
 */
class SceneLoadResState : public BaseSceneState<SceneLoadRes>
{
private:

	/*!
	 * \fn	SceneLoadResState::SceneLoadResState()
	 *
	 * \brief	隐藏的构造函数
	 *
	 */
	SceneLoadResState(){}

	/*!
	 * \fn	SceneLoadResState::SceneLoadResState(const SceneLoadResState &sceneLoadResState)
	 *
	 * \brief	隐藏的拷贝构造函数
	 *
	 * \param	sceneLoadResState	SceneLoadResState 实例
	 */
	SceneLoadResState(const SceneLoadResState &sceneLoadResState){}

	/*!
	 * \fn	SceneLoadResState& SceneLoadResState::operator=(const SceneLoadResState &sceneLoadResState)
	 *
	 * \brief	隐藏的拷贝复制运算符
	 *
	 * \param	sceneLoadResState	SceneLoadResState 实例
	 *
	 * \return	返回 SceneLoadResState 实例
	 */
	SceneLoadResState& operator=(const SceneLoadResState &sceneLoadResState){}

	// 单例别名 //////////////////////////////////////////////////////////////////////////
	/*! \brief	保存 EngineMessagePQ::Instance() 的常量指针 */
	EngineMessagePQ *const EngineMessagePQInstance = EngineMessagePQ::Instance();
	/*! \brief	保存 LogicMessagePQ::Instance() 的常量指针 */
	LogicMessagePQ *const LogicMessagePQInstance = LogicMessagePQ::Instance();
	/*! \brief	保存 MsgInterpreter::Instance() 的常量指针 */
	MsgInterpreter *const MsgInterpreterInstance = MsgInterpreter::Instance();
	//////////////////////////////////////////////////////////////////////////

public:

	/*!
	 * \fn	SceneLoadResState::~SceneLoadResState();
	 *
	 * \brief	析构函数
	 *
	 */
	~SceneLoadResState();

	/*!
	 * \fn	static SceneLoadResState* SceneLoadResState::Instance();
	 *
	 * \brief	获取单例
	 *
	 * \return	返回单例
	 */
	static SceneLoadResState* Instance();

	/*!
	 * \fn	bool SceneLoadResState::enter(SceneLoadRes *scene);
	 *
	 * \brief	状态机操作：进入状态机时的操作
	 *
	 * \param [in,out]	scene	SceneLoadRes 实例
	 *
	 * \return	返回是否成功执行
	 */
	bool  enter(SceneLoadRes *scene);

	/*!
	 * \fn	bool SceneLoadResState::update(SceneLoadRes *scene, double intervalTime);
	 *
	 * \brief	状态机操作：可重复执行的状态机主体操作
	 *
	 * \param [in,out]	scene	SceneLoadRes 实例
	 * \param	intervalTime 	自上次操作以来所经历的时间
	 *
	 * \return	返回是否成功执行
	 */
	bool update(SceneLoadRes *scene, double intervalTime);

	/*!
	 * \fn	bool SceneLoadResState::exit(SceneLoadRes *Scene);
	 *
	 * \brief	状态机操作：离开状态机时的操作
	 *
	 * \param [in,out]	Scene	SceneLoadRes 实例
	 *
	 * \return	返回是否成功执行
	 */
	bool exit(SceneLoadRes *Scene);
};

#endif