LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

$(call import-add-path,$(LOCAL_PATH)/../../cocos2d)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/external)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/cocos)

LOCAL_MODULE := cocos2dcpp_shared

LOCAL_MODULE_FILENAME := libcocos2dcpp

FILE_LIST := $(wildcard $(LOCAL_PATH)/../../Classes/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/common/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/data/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/lib/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/lib/cJSON/*.c)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/UIIntro/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/UIAvatar/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/UIStudy/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/UIPractice/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/UIMessages/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/UIMyPage/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/UISettings/*.cpp)
LOCAL_SRC_FILES := $(FILE_LIST:$(LOCAL_PATH)/%=%)
LOCAL_SRC_FILES += hellocpp/main.cpp


LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes 
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/common/
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/data/
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/lib/
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/lib/cJSON/
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/UIIntro/
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/UIAvatar/
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/UIStudy/
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/UIPractice/
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/UIMessages/
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/UIMyPage/
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/UISettings/
# sooho added for using ui classes 2015.2.2
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../cocos2d/cocos/ui 

LOCAL_WHOLE_STATIC_LIBRARIES := cocos2dx_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocosdenshion_static

# LOCAL_WHOLE_STATIC_LIBRARIES += box2d_static
# LOCAL_WHOLE_STATIC_LIBRARIES += cocosbuilder_static
# LOCAL_WHOLE_STATIC_LIBRARIES += spine_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocostudio_static
# LOCAL_WHOLE_STATIC_LIBRARIES += cocos_network_static
# LOCAL_WHOLE_STATIC_LIBRARIES += cocos_extension_static


include $(BUILD_SHARED_LIBRARY)

$(call import-module,.)
$(call import-module,audio/android)

# $(call import-module,Box2D)
# $(call import-module,editor-support/cocosbuilder)
# $(call import-module,editor-support/spine)
$(call import-module,editor-support/cocostudio)
# $(call import-module,network)
# $(call import-module,extensions)
