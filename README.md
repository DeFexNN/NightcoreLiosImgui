# 🌙 NightcoreLios — ImGui Overlay Game Enhancement Suite

A production-grade Android Unity game enhancement with **Dear ImGui** rendering
overlay, IL2CPP runtime introspection, Dobby inline hooking, Zygisk/Magisk
module injection, and comprehensive anti-cheat bypass architecture.

Three injection variants, one codebase. Built with C++17 (NDK), Java (Android SDK),
and OpenGL ES 3.0.

> *"If you can render it, you can control it."*

---

## Philosophy

NightcoreLios demonstrates the full lifecycle of a sophisticated Android game
modification: from process injection to ImGui overlay rendering, from IL2CPP
symbol resolution to 100+ anti-cheat patches, from Zygisk systemless modules
to server-side authentication.

The codebase is organized as a **single shared core** with three injection
variants, proving that clean architecture allows the same rendering engine,
menu system, and game logic to be delivered through different deployment
mechanisms without code duplication.

---

## Three Injection Variants

```
┌─────────────────────────────────────────────────────────────────┐
│                     Shared Core                                 │
│                                                                  │
│  ImGui Renderer · Menu UI · ESP Engine · Game Hacks             │
│  IL2CPP Resolver · Memory Patches · Anti-Cheat Bypass           │
│  Font Rendering · Theme Engine · Auth System                    │
└──────────────┬──────────────────────────────────────────────────┘
               │
     ┌─────────┼──────────┐
     │         │          │
┌────┴────┐ ┌──┴───┐ ┌───┴──────────┐
│INJECT   │ │INJECT│ │MODULE_LIOS    │
│LIOS     │ │LITE  │ │               │
│         │ │      │ │               │
│JNI_OnLoad│ │APK   │ │Zygisk Module │
│APK-based│ │based │ │Magisk-based  │
│Overlay  │ │AES   │ │Systemless    │
│Activity │ │auth  │ │dlopen hook   │
└─────────┘ └──────┘ └──────────────┘
```

---

## Architecture

```
┌──────────────────────────────────────────────────────────────┐
│                   Injection Phase                             │
│                                                              │
│  JNI_OnLoad / Zygisk → Auth → Poll libil2cpp.so             │
│       │                                                      │
│       ▼                                                      │
│  Hook eglSwapBuffers (Dobby inline hook)                     │
│  Hook InputConsumer::initializeMotionEvent (touch capture)    │
│  Hook RegisterNatives::nativeInjectEvent (Java input)        │
│  offsets_load() → 100+ MemoryPatch + Il2Cpp method hooks     │
└──────────────────────────────────────────────────────────────┘
                            │
┌──────────────────────────────────────────────────────────────┐
│                   Render Loop (every frame)                   │
│                                                              │
│  eglSwapBuffers hook →                                       │
│    ├── glInit() (one-time: ImGui context, fonts, theme)      │
│    ├── LoadMenu() → build ImGui draw data                    │
│    │     ├── ESP Tab (box, skeleton, health, distance)       │
│    │     ├── Weapon Tab (no recoil, fast shoot, bullet mag)  │
│    │     ├── Player Tab (fly, speed, aimbot, auto-farm)      │
│    │     └── Settings Tab (theme, save/load config)          │
│    └── ImGui_ImplOpenGL3_RenderDrawData() → composite        │
└──────────────────────────────────────────────────────────────┘
                            │
┌──────────────────────────────────────────────────────────────┐
│                   Game Manipulation                           │
│                                                              │
│  Battle_Update hook    → player tracking, damage logging     │
│  PlayerController hook → fly, speed, sticky, stealth         │
│  Gun hooks             → no recoil, fast shoot, aim assist   │
│  Vehicle hooks          → fly car, speed boost               │
│  Monster hooks          → collision bypass, damage           │
│  Builder hooks          → force build, rotation control      │
│  ~100 bypass hooks      → CheatMgr, MailMgr, HeartBeat       │
└──────────────────────────────────────────────────────────────┘
```

---

## Code Examples

### eglSwapBuffers Hook — Injecting ImGui Every Frame (C++)

```cpp
EGLBoolean (*old_eglSwapBuffers)(EGLDisplay dpy, EGLSurface surface);

EGLBoolean hook_eglSwapBuffers(EGLDisplay dpy, EGLSurface surface) {
    eglQuerySurface(dpy, surface, EGL_WIDTH,  &glWidth);
    eglQuerySurface(dpy, surface, EGL_HEIGHT, &glHeight);

    if (!imguiInitialized) {
        glInit();  // one-time: ImGui::CreateContext, fonts, theme
        imguiInitialized = true;
    }

    // Start new ImGui frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplAndroid_NewFrame(glWidth, glHeight);
    ImGui::NewFrame();

    LoadMenu();  // build all ImGui UI elements

    ImGui::EndFrame();
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    return old_eglSwapBuffers(dpy, surface);
}
```

### IL2CPP Runtime Introspection

```cpp
// Resolve Unity IL2CPP functions dynamically — works across game updates
void* resolve_il2cpp_function(const char* klass, const char* method, int args) {
    auto domain = r_il2cpp_domain_get();
    auto assembly = r_il2cpp_domain_assembly_open(domain, "Assembly-CSharp");
    auto image = r_il2cpp_assembly_get_image(assembly);

    Il2CppClass* clazz = r_il2cpp_class_from_name(image, "", klass);
    const MethodInfo* mi = r_il2cpp_class_get_method_from_name(clazz, method, args);

    return (void*)mi->methodPointer;
}

// Usage:
auto update_fn = (UpdateFunc)resolve_il2cpp_function(
    "BattleWorld", "Update", 0);
```

### Dobby Inline Hook Pattern

```cpp
#include <dobby.h>

// Hook any function with signature-compatible replacement
void* (*old_PlayerController_Update)(void* instance);

void hook_PlayerController_Update(void* instance) {
    // Get player position, apply fly/speed/stealth modifications
    auto transform = Component_GetTransform(instance);
    auto position = Transform_GetPosition(transform);

    if (settings.fly) {
        position.y += flySpeed * deltaTime;
        Transform_SetPosition(transform, position);
    }
    if (settings.speed) {
        // Modify movement speed multiplier
        *speedPtr = speedMultiplier;
    }

    return old_PlayerController_Update(instance);
}

// Install hook
DobbyHook(resolve_il2cpp_function("PlayerController", "Update", 1),
          (void*)hook_PlayerController_Update,
          (void**)&old_PlayerController_Update);
```

### Anti-Cheat Bypass (Systematic)

```cpp
// Hook every anti-cheat traffic serialization method to empty stubs.
// The game still thinks it's reporting — it just sends nothing.

// Pattern: Hook C*_Serializer::Marshal → return without serializing
#define ANTI_CHEAT_HOOK(name) \
    DobbyHook(resolve_il2cpp_function("C" #name "Inspect", "OnInspIn", 1), \
              (void*)dummy_bypass, (void**)&old_##name);

ANTI_CHEAT_HOOK(Application)   // CApplicationInspect::OnInspIn
ANTI_CHEAT_HOOK(HeartBeat)     // CHeartBeat::OnInspIn
ANTI_CHEAT_HOOK(ReportRole)    // CReportRoleCheating::OnInspIn
ANTI_CHEAT_HOOK(CheckMemory)   // memory integrity verification
ANTI_CHEAT_HOOK(CheckRoot)     // root detection bypass
ANTI_CHEAT_HOOK(CheckEmulator) // emulator detection bypass
// ... 100+ more

void dummy_bypass(void* instance) {
    return;  // literally nothing
}
```

### ImGui Menu with Custom Widgets

```cpp
#include "Garbage/Tabs.h"
#include "Garbage/ColorPicker.h"

static int currentTab = 0;

void LoadMenu() {
    ImGui::SetNextWindowPos({50, 50}, ImGuiCond_FirstUseEver);
    ImGui::SetNextWindowSize({600, 400}, ImGuiCond_FirstUseEver);

    ImGui::Begin("NightcoreLios", nullptr,
        ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);

    // Custom animated tab bar
    CustomTabs("ESP\0Weapon\0Player\0Vehicle\0Settings\0", &currentTab);

    switch (currentTab) {
        case 0: // ESP
            ImGui::Checkbox("Box ESP",   &settings.box);
            ImGui::Checkbox("Skeleton",   &settings.skeleton);
            ImGui::Checkbox("Health Bar", &settings.healthBar);
            ImGui::ColorEdit3("Box Color", settings.boxColor);
            break;
        case 1: // Weapon
            ImGui::Checkbox("No Recoil",  &settings.noRecoil);
            ImGui::Checkbox("Fast Shoot", &settings.fastShoot);
            ImGui::SliderFloat("Aim FOV", &settings.aimFov, 1, 360);
            break;
        // ... more tabs
    }

    ImGui::End();
}
```

### ESP Rendering (World-to-Screen)

```cpp
void DrawESP() {
    for (auto& player : players) {
        // World to screen transformation
        Vector2 screenPos;
        if (!WorldToScreen(player.position, screenPos)) continue;

        Vector2 headPos;
        WorldToScreen(player.position + Vector3(0, player.height, 0), headPos);

        float boxHeight = abs(screenPos.y - headPos.y);
        float boxWidth  = boxHeight * 0.4f;

        if (settings.box) {
            DrawBox(screenPos.x - boxWidth/2, headPos.y,
                    boxWidth, boxHeight, settings.boxColor);
        }
        if (settings.skeleton) {
            DrawSkeleton(player, settings.skeletonColor);
        }
        if (settings.healthBar) {
            DrawHealthBar(screenPos.x - boxWidth/2 - 4, headPos.y,
                          boxHeight, player.health, player.maxHealth);
        }
        DrawText(screenPos.x, headPos.y - 10,
                 player.name + " [" + std::to_string((int)player.distance) + "m]",
                 settings.textColor);
    }
}
```

### Zygisk Module Entry Point

```cpp
#include "zygisk.hpp"

class MyModule : public zygisk::ModuleBase {
public:
    void onLoad(Api* api, JNIEnv* env) override {
        this->api = api;
        env->GetJavaVM(&vm);
    }

    void preAppSpecialize(AppSpecializeArgs* args) override {
        auto dir = env->GetStringUTFChars(args->app_data_dir, nullptr);
        isTargetGame = strstr(dir, "com.herogame.gplay.lastdayrulessurvival");
        env->ReleaseStringUTFChars(args->app_data_dir, dir);
        // Only inject into target game — no other app affected
    }

    void postAppSpecialize(const AppSpecializeArgs* args) override {
        if (!isTargetGame) return;
        std::thread(hack_thread).detach();  // start cheat logic
    }
};

REGISTER_ZYGISK_MODULE(MyModule)
```

---

## Feature Matrix

| Category | Feature | Mechanism |
|----------|---------|-----------|
| **ESP** | Box, Skeleton, Health Bar, Distance, Weapon | ImGui draw lists, world-to-screen math |
| **Weapon** | No Recoil, Fast Shoot, Bullet Magnet, Aimbot | Gun method hooks via Il2Cpp |
| **Player** | Fly, Speed, Sticky, Stealth, Auto-Farm | PlayerController Update hooks |
| **Vehicle** | Fly Vehicle, Speed Boost | VehicleMonitor Update hooks |
| **Building** | Force Build, Rotation Control | BuilderBehaviour hooks |
| **Monsters** | Collision Bypass, Damage Multiplier | MonsterController hooks |
| **Anti-Cheat** | 100+ bypass patches | CheatMgr, MailMgr, HeartBeat hook stubs |
| **Auth** | Key validation, HWID bind | AES-CBC + PHP backend |
| **UI** | Animated tabs, color picker, watermark | Custom ImGui widgets |

---

## Tech Stack

| Layer | Technology |
|-------|-----------|
| Language | **C++17** (NDK), Java (Android SDK) |
| UI | **Dear ImGui** (OpenGL ES 3.0 backend) |
| Hook Engine | **Dobby** (inline hooking), Cydia Substrate |
| Memory | KittyMemory, `/proc/[pid]/maps`, `process_vm_readv` |
| Injection | JNI_OnLoad, Zygisk/Magisk module |
| Game Engine | Unity + **IL2CPP** scripting backend |
| Auth | libcurl + OpenSSL, AES-CBC |
| String Protect | Compile-time XOR (`OBFUSCATE.h`) |
| Fonts | Embedded TTF (6 fonts, Chinese support) |

---

*"Overlay the world. Under control the game."*
