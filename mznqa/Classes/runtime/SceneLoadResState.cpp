#pragma execution_character_set("utf-8")

#include "runtime/SceneLoadResState.h"

#include <cstdio>

#include "json/filereadstream.h"
#include "json/document.h"

// 测试用 //////////////////////////////////////////////////////////////////////////
#include "engine/FileController.h"
#include "dataHandle/CharBufferArea.h"
#include "card/CardRoad.h"
#include "card/CardSkill.h"
#include <string>
//////////////////////////////////////////////////////////////////////////

SceneLoadResState::~SceneLoadResState()
{
}

SceneLoadResState* SceneLoadResState::Instance()
{
	static SceneLoadResState instance;
	return &instance;
}

// 进入状态前的操作
bool SceneLoadResState::enter(SceneLoadRes *scene)
{
	cocos2d::log("[information] 准备进入场景 SceneLoadRes 对应的状态机中...");
	// 测试用 //////////////////////////////////////////////////////////////////////////
	CardSkill cs0(3001, std::string("name"), std::string("describe"), CardBase::BelongTo_RoleMonsterBoth, 10);
	cocos2d::log("%d", cs0.getID());
	cocos2d::log("%d", cs0.getType());
	cocos2d::log("%s", cs0.getName().c_str());
	cocos2d::log("%s", cs0.getDescride().c_str());
	cocos2d::log("%d", cs0.getBelongTo());
	cocos2d::log("%d", cs0.getEffectCount());
	//CharBufferArea::Instance()->test();
	//////////////////////////////////////////////////////////////////////////
	cocos2d::log("[information] 准备进入场景 SceneLoadRes 对应的状态机成功");
	return true;
}

// 状态执行时的操作
bool SceneLoadResState::update(SceneLoadRes *scene, double intervalTime)
{
	cocos2d::log("[information] 开始执行场景 SceneLoadRes 对应的状态机...");
	cocos2d::log("[information] 执行场景 SceneLoadRes 对应的状态机成功");
	return true;
}

// 离开状态前的操作
bool SceneLoadResState::exit(SceneLoadRes *Scene)
{
	cocos2d::log("[information] 准备离开场景 SceneLoadRes 对应的状态机...");
	cocos2d::log("[information] 离开场景 SceneLoadRes 对应的状态机成功");
	return true;
}