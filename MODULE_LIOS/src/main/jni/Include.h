#include <pthread.h>
#include <jni.h>
#include <string>
#include <string.h>
#include <cstring>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>
#include <list>
#include <thread>
#include <unistd.h>
#include <iomanip>
#include <algorithm>
#include <map>
#include <openssl/md5.h>
#include <Includes/MD5/md5.h>
#include <sys/system_properties.h>
#include <dlfcn.h>
#include <cstdlib>
#include <stdlib.h>
#include <cinttypes>
#include <cstdio>
#include <EGL/egl.h>
#include <GLES2/gl2.h>
#include "Includes/Obfuscate.h"
#include "Includes/Utils.h"
#include "Includes/Logger.h"
#include "Includes/Macros.h"
#include "Includes/MONOSTRING/MonoHelper.h"
#include "Includes/MONOSTRING/MonoString.h"
#include "Includes/Dobby/dobby.h"
#include "KittyMemory/MemoryPatch.h"
#include "autoaddr.h"   
#include "nlohmann/json.hpp"
#include "hook.h"
#include "ImGui/imgui.h"
#include "ImGui/imgui_internal.h"

#include "ESP/include.h"
#include "ESP/Chams.h"
#include <Substrate/SubstrateHook.h>
#include <Substrate/CydiaSubstrate.h>
#include "ByNameModding/Tools.h"
#include "ByNameModding/fake_dlfcn.h"
#include "ByNameModding/Il2Cpp.h"
#include "random"
#include "Includes/support.h"
#include "zygisk.hpp"
#include "MenuFonts/ImFonts.h"
#include "MenuFonts/icons.h"
#include "MenuFonts/monster.h"
#include "MenuFonts/small.h"
#include "MenuFonts/pixel.h"
#include "MenuFonts/Tahoma.h"
#include "MenuFonts/verdana.h"
#include "MenuFonts/teroryhack.h"
#include "MenuFonts/font.h"
#include "MenuFonts/autofont.h"
#include "MenuFonts/OPPOSans-H.h"
#include <functional>
#include "Garbage/Misc.h"
#include "Garbage/ColorPicker.h"
#include "ImGui/Backends/imgui_impl_opengl3.h"
#include "ImGui/imgui_internal.h"

void CheckBox(const char* str_id, bool* v) {
    ImVec2 p = ImGui::GetCursorScreenPos();
    ImDrawList* draw_list = ImGui::GetWindowDrawList();
    
    float height = ImGui::GetFrameHeight();
    float width = height * 1.95f;
    float radius = height * 0.50f;
    
    ImGui::InvisibleButton(str_id, ImVec2(width, height))
    ;
    if (ImGui::IsItemClicked()) *v = !*v;
    
    float t = *v ? 1.0f : 0.0f;
    ImGuiContext& g = *GImGui;
    float ANIM_SPEED = 0.08f;
    
    if (g.LastActiveId == g.CurrentWindow->GetID(str_id)) {
        float t_anim = ImSaturate(g.LastActiveIdTimer / ANIM_SPEED);
        t = *v ? (t_anim) : (1.0f - t_anim);
    }

    ImU32 col_bg;
    ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, 1);
    if (ImGui::IsItemHovered()) col_bg = ImGui::GetColorU32(ImLerp(ImVec4(0.10f, 0.10f, 0.10f, 1.0f), ImColor(5, 5, 5), t));
    else
    col_bg = ImGui::GetColorU32(ImLerp(ImVec4(0.0f, 0.0f, 0.0f, 1.0f), ImColor(5, 5, 5), t));
    draw_list->AddRectFilled(p, ImVec2(p.x + width, p.y + height), col_bg, height * 0.5f);
    draw_list->AddCircleFilled(ImVec2(p.x + radius + t * (width - radius * 2.0f), p.y + radius), radius - 1.5f, IM_COL32(35, 35, 35, 255));

    ImGui::SameLine();
    ImGui::Text(str_id);
}

MonoString *(*il2cpp_string_new)(const char *hshs);
bool timeToInput;
void* keyboard;
int (*_getTouchCount)(void *instance);
int getTouchCount(void* instance) {
    ImGuiIO &io = ImGui::GetIO();
    if (ImGui::GetIO().WantTextInput) {
        if (timeToInput) {
            timeToInput = false;
            //class TouchScreenKeyboard
            //TouchScreenKeyboard Open(string text, TouchScreenKeyboardType keyboardType, bool autocorrection, bool multiline, bool secure, bool alert, string textPlaceholder, int characterLimit)
            keyboard = (((void *(*)(MonoString *, int, bool, bool, bool, bool, MonoString *,int)) getAbsoluteAddress(LIB, 0x369C38C))
            (il2cpp_string_new(ImGui::GetGlobalBuffer()), 0, true, false, false, false, il2cpp_string_new(""), 0));
        }
        if (keyboard) {
            //class TouchScreenKeyboard
            //string get_text()
            const char *text = (((MonoString *(*)(void*)) getAbsoluteAddress(LIB, 0x369C518)) (keyboard))->toChars();
            if (strlen(text) < 100) strncpy(ImGui::GetGlobalBuffer(), text, 100);
        } else GImGui->ActiveId = 0;
    } else timeToInput = true;
    if (io.WantCaptureMouse) {
        return 0;
    }
    return _getTouchCount(instance);
}


