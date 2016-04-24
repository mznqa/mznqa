/*!
 * \file	Classes\engine\SpriteRole.h
 *
 * \brief	������ SpriteRole
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_ENGINE_SPRITEROLE_H_
#define MZNQA_CLASSES_ENGINE_SPRITEROLE_H_

#include <string>

#include "cocos2d.h"

/*!
 * \class	SpriteRole
 *
 * \brief	��ɫ������
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
	 * \brief	����Flag
	 */
	enum ActionFlags
	{
		ActionFlags_MoveTo = 1	///< �ƶ�����Ŀ���
	};

	/*!
	 * \fn	SpriteRole::SpriteRole()
	 *
	 * \brief	���캯��
	 *
	 */
	SpriteRole()
	{
	}

	/*!
	 * \fn	SpriteRole::~SpriteRole()
	 *
	 * \brief	��������
	 *
	 */
	~SpriteRole()
	{
	}

	/*!
	 * \fn	static SpriteRole* SpriteRole::create(const std::string &filename);
	 *
	 * \brief	���ݸ�����ͼƬ��Դ·��������ɫ����
	 *
	 * \param	filename	ָ�����ڴ�����ɫ�����ͼƬ��Դ·��
	 *
	 * \return	���� SpriteRole ʵ��
	 */
	static SpriteRole* create(const std::string &filename);

	/*!
	 * \fn	void SpriteRole::initialize();
	 *
	 * \brief	��ʼ����ɫ����
	 *
	 */
	void initialize();

	/*!
	 * \fn	void SpriteRole::refreshPosition();
	 *
	 * \brief	ˢ�½�ɫ��������Ļ�ϵ�λ��
	 *
	 */
	void refreshPosition();
};

#endif
