/*!
 * \file	Classes\engine\LayerMap.h
 *
 * \brief	������ LayerMap
 */
#pragma execution_character_set("utf-8")

#ifndef MZNQA_CLASSES_ENGINE_LAYERMAP_H_
#define MZNQA_CLASSES_ENGINE_LAYERMAP_H_

#include <vector>

#include "cocos2d.h"

#include "map/MapView.h"
#include "define/GlobalDefine.h"
#include "tools/GPointSet.h"
#include "engine/SizeController.h"

/*!
 * \class	LayerMap
 *
 * \brief	��ͼ��
 *
 */
class LayerMap : public cocos2d::Layer
{
private:
	SizeController *const SizeControllerInstance = SizeController::Instance();

	/*! \brief	��ŵ�ͼ�ڵ㾫�� */
	std::vector<std::vector<cocos2d::Sprite*>> mapCellSet;

	/*! \brief	��ͼ��Ұ���ĵ����Ļ���� */
	cocos2d::Vec2 mapViewCenterPoint = cocos2d::Vec2(
		SizeControllerInstance->realityScreenSizeWidth / 2.0,
		SizeControllerInstance->realityScreenSizeHeight / 2.0
		);

public:

	/*!
	 * \enum	ActionFlags
	 *
	 * \brief	���ڵĶ���Flags
	 */
	enum ActionFlags
	{
		ActionFlags_LayerMove = 1	///< �ƶ�������Ķ���
	};

	/*!
	 * \fn	LayerMap::LayerMap()
	 *
	 * \brief	���캯��
	 *
	 */
	LayerMap()
	{
	}

	/*!
	 * \fn	LayerMap::~LayerMap()
	 *
	 * \brief	��������
	 *
	 */
	~LayerMap()
	{
	}

	CREATE_FUNC(LayerMap);

	/*!
	 * \fn	virtual bool LayerMap::init() override;
	 *
	 * \brief	init ������д
	 *
	 */
	virtual bool init() override;

	/*!
	 * \fn	virtual bool LayerMap::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event)override;
	 *
	 * \brief	�����¼���д��������Ļ
	 *
	 */
	virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *unused_event)override;

	/*!
	 * \fn	virtual void LayerMap::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event)override;
	 *
	 * \brief	�����¼���д���ƶ�����
	 *
	 */
	virtual void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *unused_event)override;

	/*!
	 * \fn	virtual void LayerMap::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event)override;
	 *
	 * \brief	�����¼���д���뿪��Ļ
	 *
	 */
	virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event)override;

	/*!
	 * \fn	void LayerMap::addGlobalEventListener();
	 *
	 * \brief	���ȫ���¼�����
	 *
	 */
	void addGlobalEventListener();

	/*!
	 * \fn	void LayerMap::loadMapFromMapController();
	 *
	 * \brief	�ӵ�ͼ������������ȫ�ֵ�ͼ
	 *
	 */
	void loadMapFromMapController();

	/*!
	 * \fn	void LayerMap::refreshPosition();
	 *
	 * \brief	���������λ��
	 *
	 */
	void refreshPosition();

	/*!
	 * \fn	void LayerMap::initialize();
	 *
	 * \brief	��ʼ����ͼ��
	 *
	 */
	void initialize();

	void refreshMapCellWithGPointSet(const GPointSet &gPointSet);
};

#endif
