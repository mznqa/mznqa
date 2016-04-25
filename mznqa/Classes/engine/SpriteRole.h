/*!
 * \file	Classes\engine\SpriteRole.h
 *
 * \brief	定义类 SpriteRole
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_ENGINE_SPRITEROLE_H_
#define MZNQA_CLASSES_ENGINE_SPRITEROLE_H_

#include <string>

#include "cocos2d.h"

#include "gameobject/Role.h"

/*!
 * \class	SpriteRole
 *
 * \brief	角色精灵类，继承于 cocos2d::Sprite ，并提供一些角色精灵的常用方法
 *
 */
class SpriteRole : public cocos2d::Sprite
{
private:
	/*! \brief	角色精灵随全局地图移动的动作所需的时间 */
	static const float TimeSpriteMoveByMap;

	// 单例别名 //////////////////////////////////////////////////////////////////////////
	/*! \brief	保存 Role::Instance() 的常量指针 */
	Role *const RoleInstance = Role::Instance();
	//////////////////////////////////////////////////////////////////////////
public:

	/*!
	 * \enum	ActionFlags
	 *
	 * \brief	动作Flag，用于标识动作
	 */
	enum ActionFlags
	{
		ActionFlags_MoveTo = 1	///< 移动自身到目标点的动作
	};

	/*!
	 * \fn	SpriteRole::SpriteRole()
	 *
	 * \brief	构造函数
	 *
	 */
	SpriteRole()
	{
	}

	/*!
	 * \fn	SpriteRole::~SpriteRole()
	 *
	 * \brief	析构函数
	 *
	 */
	~SpriteRole()
	{
	}

	/*!
	 * \fn	static SpriteRole* SpriteRole::create(const std::string &filename);
	 *
	 * \brief	根据给定的图片资源路径创建角色精灵，继承于cocos2d的做法，不使用构造函数构造实例，而是使用 create 静态方法来构造实例，以便自动回收资源
	 *
	 * \param	filename	指定用于创建角色精灵的图片资源路径
	 *
	 * \return	返回 SpriteRole 实例
	 */
	static SpriteRole* create(const std::string &filename);

	/*!
	 * \fn	void SpriteRole::initialize();
	 *
	 * \brief	初始化角色精灵，根据角色当前在地图的位置等信息初始化角色
	 *
	 */
	void initialize();

	/*!
	 * \fn	void SpriteRole::refreshPosition();
	 *
	 * \brief	刷新角色精灵在屏幕上的位置
	 *
	 */
	void refreshPosition();
};

#endif
