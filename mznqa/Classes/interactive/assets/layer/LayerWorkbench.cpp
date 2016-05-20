#pragma execution_character_set("utf-8")

#include "interactive/assets/layer/LayerWorkbench.h"

#include "interactive/manager/TargetInfo.h"

USING_NS_CC;

bool LayerWorkbench::init()
{
	if (!Layer::init())
	{
		return false;
	}

	build();

	return true;
}

void LayerWorkbench::build()
{
	// TODO 待规整文件路径
	background = Sprite::createWithSpriteFrameName("workbench/background.png");
	background->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);
	// TODO 待规整坐标
	background->setPosition(Vec2(
		TargetInfo::Instance()->getScreenSize().width * 0.5,
		TargetInfo::Instance()->getScreenSize().height * 0.005
		));
	addChild(background);

	buttonDraw = ui::Button::create();
	buttonDraw->loadTextureNormal("workbench/button_draw_normal.png", ui::Widget::TextureResType::PLIST);
	buttonDraw->loadTexturePressed("workbench/button_draw_pressed.png", ui::Widget::TextureResType::PLIST);
	buttonDraw->loadTextureDisabled("workbench/button_draw_disabled.png", ui::Widget::TextureResType::PLIST);
	buttonDraw->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	// TODO 待规整坐标
	buttonDraw->setPosition(Vec2(
		background->getContentSize().width * 0.0925,
		background->getContentSize().height * 0.457
		));
	background->addChild(buttonDraw);
}