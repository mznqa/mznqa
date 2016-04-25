/*!
 * \file	Classes\runtime\SceneGuideState.h
 *
 * \brief	定义类 SceneGuideState
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
 * \brief	单例。与 SceneGuide 配套的状态机
 *
 */
class SceneGuideState : public BaseSceneState<SceneGuide>
{
private:

	/*!
	 * \fn	SceneGuideState::SceneGuideState()
	 *
	 * \brief	隐藏的构造函数
	 *
	 */
	SceneGuideState(){}

	/*!
	 * \fn	SceneGuideState::SceneGuideState(const SceneGuideState &sceneGuideState)
	 *
	 * \brief	隐藏的拷贝构造函数
	 *
	 * \param	sceneGuideState	SceneGuideState 实例
	 */
	SceneGuideState(const SceneGuideState &sceneGuideState){}

	/*!
	 * \fn	SceneGuideState& SceneGuideState::operator=(const SceneGuideState &sceneGuideState)
	 *
	 * \brief	隐藏的拷贝赋值运算符
	 *
	 * \param	sceneGuideState	SceneGuideState 实例
	 *
	 * \return	返回 SceneGuideState 实例
	 */
	SceneGuideState& operator=(const SceneGuideState &sceneGuideState){}
public:

	/*!
	 * \fn	SceneGuideState::~SceneGuideState();
	 *
	 * \brief	析构函数
	 *
	 */
	~SceneGuideState();

	/*!
	 * \fn	static SceneGuideState* SceneGuideState::Instance();
	 *
	 * \brief	获取单例
	 *
	 * \return	返回单例
	 */
	static SceneGuideState* Instance();

	/*!
	 * \fn	bool SceneGuideState::enter(SceneGuide *scene);
	 *
	 * \brief	状态机操作：进入状态机时的操作
	 *
	 * \param [in,out]	scene	SceneGuide 实例
	 *
	 * \return	返回是否成功执行
	 */
	bool enter(SceneGuide *scene);

	/*!
	 * \fn	bool SceneGuideState::update(SceneGuide *scene, double intervalTime);
	 *
	 * \brief	状态机操作：可重复执行的状态机主体操作
	 *
	 * \param [in,out]	scene	SceneGuide 实例
	 * \param	intervalTime 	自上次操作以来所经历的时间
	 *
	 * \return	返回是否成功执行
	 */
	bool update(SceneGuide *scene, double intervalTime);

	/*!
	 * \fn	bool SceneGuideState::exit(SceneGuide *Scene);
	 *
	 * \brief	状态机操作：离开状态机时的操作
	 *
	 * \param [in,out]	Scene	SceneGuide 实例
	 *
	 * \return	返回是否成功执行
	 */
	bool exit(SceneGuide *Scene);
};

#endif