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

/*!
 * \class	SpriteRole
 *
 * \brief	角色精灵类
 *
 */
class SpriteRole : public cocos2d::Sprite
{
private:
	static float timeSpriteMoveByMap;
public:

	/*!
	 * \enum	ActionFlags
	 *
	 * \brief	动作Flag
	 */
	enum ActionFlags
	{
		ActionFlags_MoveTo = 1	///< 移动自身到目标点
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
	 * \brief	根据给定的图片资源路径创建角色精灵
	 *
	 * \param	filename	指定用于创建角色精灵的图片资源路径
	 *
	 * \return	返回 SpriteRole 实例
	 */
	static SpriteRole* create(const std::string &filename);

	/*!
	 * \fn	void SpriteRole::initialize();
	 *
	 * \brief	初始化角色精灵
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
