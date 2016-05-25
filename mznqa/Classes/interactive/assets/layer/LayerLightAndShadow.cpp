/*!
 * \file	Classes\interactive\assets\layer\LayerLightAndShadow.cpp
 *
 * \brief	¶¨ÒåÀà LayerLightAndShadow
 */

#pragma execution_character_set("utf-8")

#include "interactive/assets/layer/LayerLightAndShadow.h"

#include "interactive/manager/TargetInfo.h"
#include "interactive/manager/GlobalManager.h"

USING_NS_CC;

bool LayerLightAndShadow::init()
{
	if (!Layer::init())
	{
		return false;
	}

	return true;
}

void LayerLightAndShadow::createStencil()
{
	stencil = DrawNode::create();
}

void LayerLightAndShadow::createLight()
{
	clipperLight = ClippingNode::create();
	clipperLight->setStencil(stencil);
	clipperLight->setInverted(false);
	clipperLight->setAlphaThreshold(0);
	clipperLight->setPosition(Vec2(0, 0));
	clipperLight->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	addChild(clipperLight, 2);

	contentLight = Sprite::create("lightxx.png");
	BlendFunc bl = { GL_ZERO, GL_ONE_MINUS_SRC_ALPHA };
	contentLight->setBlendFunc(bl);
	clipperLight->addChild(contentLight);
}

void LayerLightAndShadow::createShadow()
{
	clipperShadow = ClippingNode::create();
	clipperShadow->setStencil(stencil);
	clipperShadow->setInverted(true);
	clipperShadow->setAlphaThreshold(0);
	clipperShadow->setPosition(Vec2(0, 0));
	clipperShadow->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	addChild(clipperShadow, 2);

	contentShadow = LayerColor::create(Color4B(0, 0, 0, 200));;
	contentShadow->setContentSize(Size(
		TargetInfo::Instance()->getScreenSize().width * 2.5,
		TargetInfo::Instance()->getScreenSize().height * 2.5
		));
	contentShadow->ignoreAnchorPointForPosition(false);
	contentShadow->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	clipperShadow->addChild(contentShadow);
}

void LayerLightAndShadow::updateLightAndShadow(
	const ArKCa::Vector2<int> &lightPosition,
	const std::list<ArKCa::LineSegment<float>> &edge
	)
{
	stencil->clear();
	Vec2 position = GlobalManager::Instance()->mapPosition2LayerMapPosition(lightPosition);
	clipperLight->setPosition(position);
	clipperShadow->setPosition(position);
	stencil->setPosition(-position);
	auto it = edge.cbegin();
	auto itEnd = edge.cend();
	while (it != itEnd)
	{
		stencil->drawTriangle(
			position,
			GlobalManager::Vector22Vec2(it->firstEndingPoint),
			GlobalManager::Vector22Vec2(it->secondEndingPoint),
			Color4F::BLACK
			);
		++it;
	}
}