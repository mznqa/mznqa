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

#include "gameobject/Role.h"

/*!
 * \class	SpriteRole
 *
 * \brief	��ɫ�����࣬�̳��� cocos2d::Sprite �����ṩһЩ��ɫ����ĳ��÷���
 *
 */
class SpriteRole : public cocos2d::Sprite
{
private:
	/*! \brief	��ɫ������ȫ�ֵ�ͼ�ƶ��Ķ��������ʱ�� */
	static const float TimeSpriteMoveByMap;

	// �������� //////////////////////////////////////////////////////////////////////////
	/*! \brief	���� Role::Instance() �ĳ���ָ�� */
	Role *const RoleInstance = Role::Instance();
	//////////////////////////////////////////////////////////////////////////
public:

	/*!
	 * \enum	ActionFlags
	 *
	 * \brief	����Flag�����ڱ�ʶ����
	 */
	enum ActionFlags
	{
		ActionFlags_MoveTo = 1	///< �ƶ�����Ŀ���Ķ���
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
	 * \brief	���ݸ�����ͼƬ��Դ·��������ɫ���飬�̳���cocos2d����������ʹ�ù��캯������ʵ��������ʹ�� create ��̬����������ʵ�����Ա��Զ�������Դ
	 *
	 * \param	filename	ָ�����ڴ�����ɫ�����ͼƬ��Դ·��
	 *
	 * \return	���� SpriteRole ʵ��
	 */
	static SpriteRole* create(const std::string &filename);

	/*!
	 * \fn	void SpriteRole::initialize();
	 *
	 * \brief	��ʼ����ɫ���飬���ݽ�ɫ��ǰ�ڵ�ͼ��λ�õ���Ϣ��ʼ����ɫ
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
