//
// Copyright 2011 Tero Saarni
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#include <stdint.h>
#include <jni.h>
#include <android/native_window.h> // requires ndk r5 or newer
#include <android/native_window_jni.h> // requires ndk r5 or newer

#include "jniapi.h"
#include "logger.h"
#include "renderer.h"

#define LOG_TAG "EglSample"


static ANativeWindow *window = 0;
static Renderer *renderer = 0;

extern "C" JNIEXPORT void JNICALL Java_glnative_example_NativeView_nativeOnCreate(JNIEnv* jenv,
                                                                                       jclass type)
{
    LOG_INFO("nativeOnStart");
    renderer = new Renderer();
    return;
}

extern "C" JNIEXPORT void JNICALL Java_glnative_example_NativeView_nativeOnResume(JNIEnv* jenv,
                                                                                        jclass type)
{
    LOG_INFO("nativeOnResume");
    renderer->start();
    return;
}

extern "C" JNIEXPORT void JNICALL Java_glnative_example_NativeView_nativeOnPause(JNIEnv* jenv,
                                                                                       jclass type)
{
    LOG_INFO("nativeOnPause");
    renderer->stop();
    return;
}

extern "C" JNIEXPORT void JNICALL Java_glnative_example_NativeView_nativeOnStop(JNIEnv* jenv,
                                                                                      jclass type)
{
    LOG_INFO("nativeOnStop");
    delete renderer;
    renderer = 0;
    return;
}

extern "C" JNIEXPORT void JNICALL Java_glnative_example_NativeView_nativeSetSurface(JNIEnv* jenv,
                                                                                          jclass type, jobject surface)
{
    if (surface != 0) {
        window = ANativeWindow_fromSurface(jenv, surface);
        LOG_INFO("Got window %p", window);
        renderer->setWindow(window);
    } else {
        LOG_INFO("Releasing window");
        ANativeWindow_release(window);
    }

    return;
}

