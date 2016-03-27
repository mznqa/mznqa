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
#include "effect/Effect.h"
#include "effect/EffectFunSet.h"
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
	Effect ef0("去0血", Effect::Receiver_Other, 0, std::vector<int>());
	Effect ef1("去1血", Effect::Receiver_Other, 1, std::vector<int>());
	Effect ef2("去2血", Effect::Receiver_Other, 2, std::vector<int>());
	std::vector<Effect> effectSet = {
		ef0, ef1, ef2
	};
	CardSkill cs(3000, "技能卡0", "describe", CardBase::BelongTo_RoleMonsterBoth, effectSet);
	EffectFunSet::getFunByIndex(cs.getEffectSet().at(0).getFunIndex())(cs.getEffectSet().at(0).getArgs());

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