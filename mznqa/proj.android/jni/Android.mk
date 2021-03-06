LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)





LOCAL_MODULE := cocos2dcpp_shared

LOCAL_MODULE_FILENAME := libcocos2dcpp

LOCAL_SRC_FILES := hellocpp/main.cpp \
              ../../Classes/AppDelegate.cpp \
              ../../Classes/helper/bridge/Bridge.cpp \
              ../../Classes/logic/gameObject/card/CardBase.cpp \
              ../../Classes/logic/gameObject/card/CardRoad.cpp \
              ../../Classes/logic/data/static/card/CardSet.cpp \
              ../../Classes/logic/core/CoreController.cpp \
              ../../Classes/logic/core/state/CoreStateGameMain.cpp \
              ../../Classes/logic/core/state/CoreStateGuide.cpp \
              ../../Classes/logic/core/state/CoreStateResLoading.cpp \
              ../../Classes/helper/fileManager/FileManager.cpp \
              ../../Classes/logic/gameObject/map/GameMap.cpp \
              ../../Classes/interactive/message/InteractiveMessagePQ.cpp \
              ../../Classes/interactive/assets/layer/LayerMap.cpp \
              ../../Classes/logic/message/LogicMessagePQ.cpp \
              ../../Classes/logic/controller/MapController.cpp \
              ../../Classes/logic/gameObject/map/MapNode.cpp \
              ../../Classes/logic/gameObject/map/MapView.cpp \
              ../../Classes/helper/messageInterpreter/MessageInterpreter.cpp \
              ../../Classes/logic/data/static/missionMap/MissionMapSet.cpp \
              ../../Classes/helper/dataLoader/ParseCardRoadSet.cpp \
              ../../Classes/helper/dataLoader/ParseMissionMapMain.cpp \
              ../../Classes/helper/dataLoader/ParseStringSet.cpp \
              ../../Classes/interactive/assets/scene/SceneGameMain.cpp \
              ../../Classes/interactive/assets/scene/SceneGuide.cpp \
              ../../Classes/interactive/assets/scene/SceneResLoading.cpp \
              ../../Classes/logic/dataLoader/StaticDataLoader.cpp \
              ../../Classes/logic/data/static/stringSet/StringSet.cpp \
              ../../Classes/common/arkca/stringTable/StringTable.cpp \
              ../../Classes/interactive/manager/TargetInfo.cpp

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
