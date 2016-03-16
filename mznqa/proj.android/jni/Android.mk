LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)





LOCAL_MODULE := cocos2dcpp_shared

LOCAL_MODULE_FILENAME := libcocos2dcpp

LOCAL_SRC_FILES := hellocpp/main.cpp \
                   ../../Classes/AppDelegate.cpp \
                   ../../Classes/engine/SceneDebug.cpp \
                   ../../Classes/engine/SceneGuide.cpp \
                   ../../Classes/engine/SceneLoadRes.cpp \
                   ../../Classes/fileio/FileCache.cpp \
                   ../../Classes/fileio/JsonParser.cpp \
                   ../../Classes/message/EngineMessagePQ.cpp \
                   ../../Classes/message/LogicMessagePQ.cpp \
                   ../../Classes/message/MsgInterpreter.cpp \
                   ../../Classes/runtime/SceneGuideState.cpp \
                   ../../Classes/runtime/SceneLoadResState.cpp

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
