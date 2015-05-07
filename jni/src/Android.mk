LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := main

SDL_PATH := ../SDL2

LOCAL_C_INCLUDES := $(LOCAL_PATH)/$(SDL_PATH)/include \
    $(LOCAL_PATH)/SDL2_ttf \
    $(LOCAL_PATH)/SDL2_image \
    $(LOCAL_PATH)/SDL2_mixer

# Add your application source files here...
LOCAL_SRC_FILES := $(SDL_PATH)/src/main/android/SDL_android_main.c \
    $(subst $(LOCAL_PATH)/,, \
    $(wildcard $(LOCAL_PATH)/*.cpp) \
	$(wildcard $(LOCAL_PATH)/JAM/*.cpp))

LOCAL_SHARED_LIBRARIES := SDL2 SDL2_ttf SDL2_image SDL2_mixer

LOCAL_LDLIBS := -lGLESv1_CM -lGLESv2 -llog

#Allow  the use of C++ 11
LOCAL_CFLAGS := -std=c++11

include $(BUILD_SHARED_LIBRARY)

