LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)





LOCAL_MODULE := cocos2dcpp_shared

LOCAL_MODULE_FILENAME := libcocos2dcpp

LOCAL_SRC_FILES := hellocpp/main.cpp \
                   ../../Classes/AppDelegate.cpp \
                   ../../Classes/card/CardBase.cpp \
                   ../../Classes/card/CardMonster.cpp \
                   ../../Classes/card/CardRoad.cpp \
                   ../../Classes/card/CardSkill.cpp \
                   ../../Classes/card/CardTreasure.cpp \
                   ../../Classes/cardController/CardBoxRTM.cpp \
                   ../../Classes/cardController/CardControllerCombat.cpp \
                   ../../Classes/cardController/CardControllerExplore.cpp \
                   ../../Classes/combatSystem/EffectPQ.cpp \
                   ../../Classes/coreStateMachine/CoreStateMachine.cpp \
                   ../../Classes/coreStateMachine/CoreStateNone.cpp \
                   ../../Classes/dataHandle/CharBufferArea.cpp \
                   ../../Classes/dataHandle/ParserCardSkill.cpp \
                   ../../Classes/dataHandle/ParserMapArchives.cpp \
                   ../../Classes/dataHandle/ParserMapMissionMain.cpp \
                   ../../Classes/dataHandle/StaticDataLoader.cpp \
                   ../../Classes/effect/EffectFunSet.cpp \
                   ../../Classes/engine/FileController.cpp \
                   ../../Classes/engine/LayerMap.cpp \
                   ../../Classes/engine/LayerWorkbench.cpp \
                   ../../Classes/engine/SceneDebug.cpp \
                   ../../Classes/engine/SceneGameMain.cpp \
                   ../../Classes/engine/SceneGuide.cpp \
                   ../../Classes/engine/SceneLoadRes.cpp \
                   ../../Classes/engine/SizeController.cpp \
                   ../../Classes/engine/SpriteCard.cpp \
                   ../../Classes/engine/SpriteHandCard.cpp \
                   ../../Classes/engine/SpriteRole.cpp \
                   ../../Classes/gameObject/Monster.cpp \
                   ../../Classes/gameObject/Role.cpp \
                   ../../Classes/map/MapController.cpp \
                   ../../Classes/map/MapView.cpp \
                   ../../Classes/map/MissionMap.cpp \
                   ../../Classes/message/EngineMessagePQ.cpp \
                   ../../Classes/message/LogicMessagePQ.cpp \
                   ../../Classes/message/MsgInterpreter.cpp \
                   ../../Classes/runtime/SceneGameMainState.cpp \
                   ../../Classes/runtime/SceneGuideState.cpp \
                   ../../Classes/runtime/SceneLoadResState.cpp \
                   ../../Classes/staticData/CardSet.cpp \
                   ../../Classes/staticData/MissionMapSet.cpp

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes

# _COCOS_HEADER_ANDROID_BEGIN
# _COCOS_HEADER_ANDROID_END


LOCAL_STATIC_LIBRARIES := cocos2dx_static

# _COCOS_LIB_ANDROID_BEGIN
# _COCOS_LIB_ANDROID_END

include $(BUILD_SHARED_LIBRARY)

$(call import-module,./prebuilt-mk)

# _COCOS_LIB_IMPORT_ANDROID_BEGIN
# _COCOS_LIB_IMPORT_ANDROID_END
