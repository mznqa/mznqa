/*!
 * \file	Classes\runtime\BaseSceneState.h
 *
 * \brief	������ BaseSceneState
 */

#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_RUNTIME_BASESCENESTATE_H_
#define MZNQA_CLASSES_RUNTIME_BASESCENESTATE_H_

/*!
 * \class	BaseSceneState
 *
 * \brief	����״̬������
 *
 * \tparam	SceneType	��������
 */
template <typename SceneType>
class BaseSceneState
{
public:

	/*!
	 * \fn	BaseSceneState::BaseSceneState()
	 *
	 * \brief	Ĭ�Ϲ��캯��
	 *
	 */
	BaseSceneState(){}

	/*!
	 * \fn	virtual BaseSceneState::~BaseSceneState()
	 *
	 * \brief	��������
	 *
	 */
	virtual ~BaseSceneState(){}

	/*!
	 * \fn	virtual bool BaseSceneState::enter(SceneType *scene) = 0;
	 *
	 * \brief	����״̬��ǰ���еĲ���
	 *
	 *
	 * \param [in,out]	scene	ָ��״̬����Ӧ�ĳ���
	 *
	 * \return	�÷���Ϊ���麯�����ڴ˲��޶�����ֵ�ľ�������������ھ���ʵ��
	 */
	virtual bool enter(SceneType *scene) = 0;

	/*!
	 * \fn	virtual bool BaseSceneState::update(SceneType *scene, double intervalTime) = 0;
	 *
	 * \brief	�������ø÷�������ת״̬��
	 *
	 * \param [in,out]	scene	ָ��״̬����Ӧ�ĳ���
	 * \param	intervalTime 	�����ϴε��ø÷�����ʱ���������룩
	 *
	 * \return	�÷���Ϊ���麯�����ڴ˲��޶�����ֵ�ľ�������������ھ���ʵ��
	 */

	virtual bool update(SceneType *scene, double intervalTime) = 0;

	/*!
	 * \fn	virtual bool BaseSceneState::exit(SceneType *Scene) = 0;
	 *
	 * \brief	�뿪״̬��ǰ���еĲ���
	 *
	 * \param [in,out]	Scene	ָ��״̬����Ӧ�ĳ���
	 *
	 * \return	�÷���Ϊ���麯�����ڴ˲��޶�����ֵ�ľ�������������ھ���ʵ��
	 */

	virtual bool exit(SceneType *Scene) = 0;
};

#endif