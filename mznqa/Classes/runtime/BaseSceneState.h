/*!
 * \file	Classes\runtime\BaseSceneState.h
 *
 * \brief	定义类 BaseSceneState
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_RUNTIME_BASESCENESTATE_H_
#define MZNQA_CLASSES_RUNTIME_BASESCENESTATE_H_

/*!
 * \class	BaseSceneState
 *
 * \brief	场景状态机基类
 *
 * \tparam	SceneType	场景类型
 */
template <typename SceneType>
class BaseSceneState
{
public:

	/*!
	 * \fn	BaseSceneState::BaseSceneState()
	 *
	 * \brief	默认构造函数
	 *
	 */
	BaseSceneState(){}

	/*!
	 * \fn	virtual BaseSceneState::~BaseSceneState()
	 *
	 * \brief	析构函数
	 *
	 */
	virtual ~BaseSceneState(){}

	/*!
	 * \fn	virtual bool BaseSceneState::enter(SceneType *scene) = 0;
	 *
	 * \brief	进入状态机前进行的操作
	 *
	 *
	 * \param [in,out]	scene	指向状态机对应的场景
	 *
	 * \return	该方法为纯虚函数，在此不限定返回值的具体意义而依赖于具体实现
	 */
	virtual bool enter(SceneType *scene) = 0;

	/*!
	 * \fn	virtual bool BaseSceneState::update(SceneType *scene, double intervalTime) = 0;
	 *
	 * \brief	持续调用该方法以运转状态机
	 *
	 * \param [in,out]	scene	指向状态机对应的场景
	 * \param	intervalTime 	距离上次调用该方法的时间间隔（毫秒）
	 *
	 * \return	该方法为纯虚函数，在此不限定返回值的具体意义而依赖于具体实现
	 */

	virtual bool update(SceneType *scene, double intervalTime) = 0;

	/*!
	 * \fn	virtual bool BaseSceneState::exit(SceneType *Scene) = 0;
	 *
	 * \brief	离开状态机前进行的操作
	 *
	 * \param [in,out]	Scene	指向状态机对应的场景
	 *
	 * \return	该方法为纯虚函数，在此不限定返回值的具体意义而依赖于具体实现
	 */

	virtual bool exit(SceneType *Scene) = 0;
};

#endif