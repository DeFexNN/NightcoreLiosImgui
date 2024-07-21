//#include "hook.h"
#include <cstring>
#include <cstdio>
#include <jni.h>
#include <unistd.h>
#include <sys/system_properties.h>
#include <dlfcn.h>
#include "Includes/Dobby/dobby.h"

JNIEnv *g_env = nullptr;
#include "ImGui/backends/imgui_impl_opengl3.h"
#include "ImGui/backends/imgui_impl_android.h"
//#include "main.h"
#include "Include.h"
#include <curl/curl.h>
#include <EGL/egl.h>
const char* gamePKG = OBFUSCATE("com.herogame.gplay.lastdayrulessurvival");
#define HOOK(ret, func, ...) \
    ret (*orig##func)(__VA_ARGS__); \
    ret my##func(__VA_ARGS__)


    


struct My_Patches {
    MemoryPatch Sh, BP1, BP2, BP3, BP4, BP5, BP6, BP7, BP8, BP9, BP10, BP11, BP12, BP13, BP14, BP15,
    BP16, BP17, BP18, BP19, BP20, BP21, BP22, BP23, BP24, BP25, BP26, BP27, BP28, BP29, BP30, BP31,
    BP32, BP33, BP34, BP35, BP36, BP37, BP38, BP39, BP40, BP41, BP42, BP43, BP44, BP45, BP46, BP47,
    BP48, BP49, BP50, BP51, BP52, BP53, BP54, BP55, BP56, BP57, BP58, BP59, BP60, BP61, BP62, BP63,
    BP64, BP65, BP66, BP67, BP68, BP69, BP70, BP71, BP72, BP73, BP74, BP75, BP76, BP77, BP78, BP79,
    BP80, BP81, BP82, BP83, BP84, BP85, BP86, BP87, BP88, BP89, BP90, BP91, BP92, BP93, BP94, BP95,
    BP96, BP97, BP98, BP99, BP100, BP101, BP102, BP103, BP104, BP105, BP106, BP107, BP108, BP109,
    BP110, BP111, BP112, BP113, BP114, BP115, BP116, BP117, BP118, BP119, BP120, BP121, BP122, BP123,
    BP124, BP125, BP126, BP127, BP128, BP129, BP130, BP131, BP132, BP133,
    Soul, Stop, Splash, Swim, PR1, PR2, PR3, PR4, FO1, FO2, FO3, FO4, UM, FB, VIRT, ROOT, GG, EMULATOR, BOOT, GPU, PP, PP2, PP3;
} hexPatches;



ImVec2 WinPos, WinSize;

#include "var.h"
#include "Function/Include.h"
#include "menu.h"
#include "style.h"

static bool init;
bool HandleInputEvent(JNIEnv *env, int motionEvent, int x, int y, int p);
float initialTouchX, initialTouchY;
static bool openeds = true;
bool  HandleInputEvent(JNIEnv *env, int motionEvent, int x, int y, int p) {
    float velocity_y = (float)((float)y - g_LastTouchEvent.y) / 100.f;
    g_LastTouchEvent = {.action = (TOUCH_ACTION) motionEvent, .x = static_cast<float>(x), .y = static_cast<float>(y), .pointers = p, .y_velocity = velocity_y};
    ImGuiIO &io = ImGui::GetIO();
    io.MousePos.x = g_LastTouchEvent.x;
    io.MousePos.y = g_LastTouchEvent.y;
    if(motionEvent == 2){
        if (g_LastTouchEvent.pointers > 1) {
            io.MouseWheel = g_LastTouchEvent.y_velocity;
            io.MouseDown[0] = false;
        }
        else {
            io.MouseWheel = 0;
        }
    }
    if(motionEvent == 0){
        io.MouseDown[0] = true;
    }
    if(motionEvent == 1){
        io.MouseDown[0] = false;
    }
    if (g_LastTouchEvent.action == 0) {
            initialTouchX = g_LastTouchEvent.x;
            initialTouchY = g_LastTouchEvent.y;
    }
     if (g_LastTouchEvent.action == 1
        && g_LastTouchEvent.x >= WinPos.x
        && g_LastTouchEvent.y >= (WinPos.y)
        && g_LastTouchEvent.x <= (WinPos.x + WinSize.x)
        && g_LastTouchEvent.y <= (WinPos.y + WinSize.y)
            && (g_LastTouchEvent.x - initialTouchX) < 10
            && (g_LastTouchEvent.y - initialTouchY) < 10
    ) {
               openeds = !openeds;
    }
    return true;
}
 
bool (*old_nativeInjectEvent )(JNIEnv*, jobject ,jobject event);
bool hook_nativeInjectEvent(JNIEnv* env, jobject instance,jobject event){
        jclass MotionEvent = env->FindClass((OBFUSCATE("android/view/MotionEvent")));
        if(!MotionEvent){
        }
        
        if(!env->IsInstanceOf(event, MotionEvent)){
            return old_nativeInjectEvent(env, instance, event);
        }
        jmethodID id_getAct = env->GetMethodID(MotionEvent, (OBFUSCATE("getActionMasked")), (OBFUSCATE("()I")));
        jmethodID id_getX = env->GetMethodID(MotionEvent, (OBFUSCATE("getX")), (OBFUSCATE("()F")));
        jmethodID id_getY = env->GetMethodID(MotionEvent, (OBFUSCATE("getY")), (OBFUSCATE("()F")));
        jmethodID id_getPs = env->GetMethodID(MotionEvent, (OBFUSCATE("getPointerCount")), (OBFUSCATE("()I")));
        HandleInputEvent(env, env->CallIntMethod(event, id_getAct),env->CallFloatMethod(event, id_getX), env->CallFloatMethod(event, id_getY), env->CallIntMethod(event, id_getPs));
        if (true){
            return old_nativeInjectEvent(env, instance, event);
        }
        return false;
}

jint (*old_RegisterNatives )(JNIEnv*, jclass, JNINativeMethod*,jint);
jint hook_RegisterNatives(JNIEnv* env, jclass destinationClass, JNINativeMethod* methods,
                          jint totalMethodCount){

    int currentNativeMethodNumeration;
    for (currentNativeMethodNumeration = 0; currentNativeMethodNumeration < totalMethodCount; ++currentNativeMethodNumeration )
    {
        if (!strcmp(methods[currentNativeMethodNumeration].name, (OBFUSCATE("nativeInjectEvent"))) ){
            DobbyHook(methods[currentNativeMethodNumeration].fnPtr, (void*)hook_nativeInjectEvent, (void **)&old_nativeInjectEvent);
        }
    }
    return old_RegisterNatives(env, destinationClass, methods, totalMethodCount);
}

void glInit() {
    if (!init) {
        auto context = ImGui::CreateContext();
        if (!context) {
            return;
        }
        ImGuiIO &io = ImGui::GetIO();
        io.Fonts->AddFontFromMemoryTTF(&Font, sizeof Font, 24.0f, NULL, io.Fonts->GetGlyphRangesCyrillic());
        
        VerdanaFont = io.Fonts->AddFontFromMemoryTTF(&verdana, sizeof verdana, 18.0f);
        HorstFont = io.Fonts->AddFontFromMemoryTTF(&monster, sizeof monster, 34.0f);
        IconsFont = io.Fonts->AddFontFromMemoryTTF(Icons, sizeof Icons, 35);
        DefualtFont = io.Fonts->AddFontFromMemoryTTF(&Font, sizeof Font, 24.0f, NULL, io.Fonts->GetGlyphRangesCyrillic());
        SmallFont = io.Fonts->AddFontFromMemoryTTF(&Font, sizeof Font, 19.0f, NULL, io.Fonts->GetGlyphRangesCyrillic());
        TahomaFont = io.Fonts->AddFontFromMemoryTTF(Tahoma, sizeof Tahoma, 24);
        static const ImWchar fontt_ranges[] = { 0x0020, 0x00FF, 0x2000, 0x206F, 0x3000, 0x30FF, 0x31F0, 0x31FF, 0xFF00, 0xFFEF, 0xFFFD, 0xFFFD, 0x4E00, 0x9FAF, 0x0400, 0x052F, 0x2DE0, 0x2DFF, 0xA640, 0xA69F, 0 };
        ChinaFont = io.Fonts->AddFontFromMemoryTTF((void*)OPPOSans_H, OPPOSans_H_size, 24.0f, NULL, fontt_ranges);
        
        io.IniFilename = NULL;
        io.KeyMap[ImGuiKey_UpArrow] = 19;
        io.KeyMap[ImGuiKey_DownArrow] = 20;
        io.KeyMap[ImGuiKey_LeftArrow] = 21;
        io.KeyMap[ImGuiKey_RightArrow] = 22;
        io.KeyMap[ImGuiKey_Enter] = 66;
        io.KeyMap[ImGuiKey_Backspace] = 67;
        io.KeyMap[ImGuiKey_PageUp] = 92;
        io.KeyMap[ImGuiKey_PageDown] = 93;
        io.KeyMap[ImGuiKey_Escape] = 111;
        io.KeyMap[ImGuiKey_Delete] = 112;
        io.KeyMap[ImGuiKey_Home] = 122;
        io.KeyMap[ImGuiKey_End] = 123;
        io.KeyMap[ImGuiKey_Insert] = 124;
        io.KeyMap[ImGuiKey_UpArrow] = 19;
        io.KeyMap[ImGuiKey_DownArrow] = 20;
        io.KeyMap[ImGuiKey_LeftArrow] = 21;
        io.KeyMap[ImGuiKey_RightArrow] = 22;
        io.KeyMap[ImGuiKey_Enter] = 66;
        io.KeyMap[ImGuiKey_Backspace] = 67;
        io.KeyMap[ImGuiKey_PageUp] = 92;
        io.KeyMap[ImGuiKey_PageDown] = 93;
        io.KeyMap[ImGuiKey_Escape] = 111;
        io.KeyMap[ImGuiKey_Delete] = 112;
        io.KeyMap[ImGuiKey_Home] = 122;
        io.KeyMap[ImGuiKey_End] = 123;
        io.KeyMap[ImGuiKey_Insert] = 124;

        
        
      

        ImGui_ImplAndroid_Init(nullptr);
        ImGui_ImplOpenGL3_Init();
        switch (g_LastTouchEvent.action) {
            case TOUCH_ACTION_MOVE:
                if (g_LastTouchEvent.pointers > 1) {
                    io.MouseWheel = g_LastTouchEvent.y_velocity;
                    io.MouseDown[0] = false;
                } else {
                    io.MouseWheel = 0;
                }
                break;
            case TOUCH_ACTION_DOWN:
                io.MouseDown[0] = true;
                break;
            case TOUCH_ACTION_UP:
                io.MouseDown[0] = false;
                break;
            default:
                break;
        }
        init = true;
    }
    if (init){
        ImGuiIO &io = ImGui::GetIO();
        
        static bool WantTextInputLast = false;
        SetDarkBlueTheme();
        LoadMenu();
        
        
        io.KeysDown[io.KeyMap[ImGuiKey_UpArrow]],io.KeysDown[io.KeyMap[ImGuiKey_DownArrow]],io.KeysDown[io.KeyMap[ImGuiKey_LeftArrow]] ,io.KeysDown[io.KeyMap[ImGuiKey_RightArrow]] ,io.KeysDown[io.KeyMap[ImGuiKey_Tab]] ,io.KeysDown[io.KeyMap[ImGuiKey_Enter]],io.KeysDown[io.KeyMap[ImGuiKey_Backspace]] ,io.KeysDown[io.KeyMap[ImGuiKey_PageUp]],io.KeysDown[io.KeyMap[ImGuiKey_PageDown]],io.KeysDown[io.KeyMap[ImGuiKey_Escape]],io.KeysDown[io.KeyMap[ImGuiKey_Delete]],io.KeysDown[io.KeyMap[ImGuiKey_Home]],io.KeysDown[io.KeyMap[ImGuiKey_End]],io.KeysDown[io.KeyMap[ImGuiKey_Insert]] = false;

        ImGui::EndFrame();
    }
}

EGLBoolean (*old_eglSwapBuffers)(EGLDisplay dpy, EGLSurface surface);
EGLBoolean hook_eglSwapBuffers(EGLDisplay dpy, EGLSurface surface) {
    eglQuerySurface(dpy, surface, EGL_WIDTH, &glWidth);
    eglQuerySurface(dpy, surface, EGL_HEIGHT, &glHeight);
    glInit();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    return old_eglSwapBuffers(dpy, surface);
}

HOOK(void, Input, void *thiz, void *ex_ab, void *ex_ac){
    origInput(thiz, ex_ab, ex_ac);
    DobbyHook((void*)g_env->functions->RegisterNatives, (void*)hook_RegisterNatives, (void **)&old_RegisterNatives);
    if (init) ImGui_ImplAndroid_HandleInputEvent((AInputEvent *)thiz); 
    return;
}


int isGame(JNIEnv *env, jstring appDataDir) {
    if (!appDataDir)
        return 0;
    g_env = env;
    const char *app_data_dir = env->GetStringUTFChars(appDataDir, nullptr);
    int user = 0;
    static char package_name[256];
    if (sscanf(app_data_dir, ("/data/%*[^/]/%d/%s"), &user, package_name) != 2) {
        if (sscanf(app_data_dir, OBFUSCATE("/data/%*[^/]/%s"), package_name) != 1) {
            package_name[0] = '\0';
            return 0;
        }
    }
    if (strcmp(package_name, gamePKG) == 0) {
        game_data_dir = new char[strlen(app_data_dir) + 1];
        strcpy(game_data_dir, app_data_dir);
        env->ReleaseStringUTFChars(appDataDir, app_data_dir);
        return 1;
    } else {
        env->ReleaseStringUTFChars(appDataDir, app_data_dir);
        return 0;
    }
}

static int GetAndroidApiLevel() {
    char prop_value[PROP_VALUE_MAX];
    __system_property_get(OBFUSCATE("ro.build.version.sdk"), prop_value);
    return atoi(prop_value);
}

void dlopen_process(const char *name, void *handle) {
    if (!il2cpp_handle) {
        if (strstr(name, OBFUSCATE("libil2cpp.so"))) {
            il2cpp_handle = handle;
        }
    }
    if (!unity_handle) {
        if (strstr(name, OBFUSCATE("libunity.so"))) {
            unity_handle = handle;
        }
    }
    if (!egl_handle) {
        if (strstr(name, OBFUSCATE("libEGL.so"))) {
            egl_handle = handle;
        }
    }
    if (!gl2_handle) {
        if (strstr(name, OBFUSCATE("libGLESv2.so"))) {
            gl2_handle = handle;
        }
    }
}





HOOK_DEF(void*, __loader_dlopen, const char *filename, int flags, const void *caller_addr) {
    void *handle = orig___loader_dlopen(filename, flags, caller_addr);
    dlopen_process(filename, handle);
    return handle;
}

HOOK_DEF(void*, do_dlopen_V24, const char *name, int flags, const void *extinfo,
         void *caller_addr) {
    void *handle = orig_do_dlopen_V24(name, flags, extinfo, caller_addr);
    dlopen_process(name, handle);
    return handle;
}

HOOK_DEF(void*, do_dlopen_V19, const char *name, int flags, const void *extinfo) {
    void *handle = orig_do_dlopen_V19(name, flags, extinfo);
    dlopen_process(name, handle);
    return handle;
}


#include "mem.h"

size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* userp) {
    size_t total_size = size * nmemb;
    userp->append((char*)contents, total_size);
    return total_size;
}

std::string readFileText(const char* myFile, int lineNum) {
    std::ifstream file(myFile);
    if (!file.is_open())
        return "";

    std::string line;
    for (int i = 1; i <= lineNum; ++i) {
        if (!std::getline(file, line))
            break;
    }

    file.close();
    return line;
}

bool Auth() {
    // Отримуємо значення з системних властивостей
    char prop_build_id[PROP_VALUE_MAX];
    char prop_uuid[PROP_VALUE_MAX];
    char prop_name[PROP_VALUE_MAX];
    char prop_manufacture[PROP_VALUE_MAX];
	
    __system_property_get(OBFUSCATE("ro.build.id"), prop_build_id);
    __system_property_get(OBFUSCATE("ro.build.fingerprint"), prop_uuid);
    __system_property_get(OBFUSCATE("ro.product.name"), prop_name);
    __system_property_get(OBFUSCATE("ro.product.manufacturer"), prop_manufacture);

    // Формуємо URL для запиту
    std::string url = OBFUSCATE("https://defexggxhuligan.000webhostapp.com/fuckraphael.php");

    // Ініціалізуємо curl
    CURL *curl = curl_easy_init();

    // Перевіряємо успішність ініціалізації
    if (curl) {
        // Створюємо структуру для зберігання відповіді
        std::string response;

        // Устанавлюємо URL
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

        // Включаємо verbose mode для логгування
        curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);

        // Встановлюємо буфер для отримання повідомлення про помилку
        char errorBuffer[CURL_ERROR_SIZE];
        curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, errorBuffer);

        // Встановлюємо метод запиту POST
        curl_easy_setopt(curl, CURLOPT_POST, 1L);

        // Формуємо рядок з даними для POST-запиту
		std::string username = OBFUSCATE("username=");
		std::string password = OBFUSCATE("&password=");
		std::string uuid = OBFUSCATE("&uuid=");
		std::string manufacturer = OBFUSCATE("&manufacturer=");
		std::string model = OBFUSCATE("&model=");
        const char* filePath = OBFUSCATE("/storage/emulated/0/Android/data/com.herogame.gplay.survival.lite/files/key.cfg");
        std::string fileContent = readFileText(filePath, 1);
        std::string postData = username + fileContent + password + std::string(prop_build_id) + uuid + std::string(prop_uuid) + manufacturer + std::string(prop_manufacture) + model + std::string(prop_name);

        // Встановлюємо CURLOPT_POSTFIELDS для передачі POST-даних через curl
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postData.c_str());

        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);

        // Встановлюємо callback-функцію для запису даних
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);

        // Передаємо дані запиту
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        // Виконуємо запит
        CURLcode res = curl_easy_perform(curl);

        // Отримуємо HTTP-код відповіді
        long http_code = 0;
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
        LOGD("HTTP Response Code: %ld", http_code);

        // Перевіряємо успішність виконання запиту
        if (res != CURLE_OK) {
            // Логуємо помилку
            LOGE("curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            // Виводимо повідомлення про помилку з буфера
            LOGE("Error Buffer: %s\n", errorBuffer);
        }

        // Звільняємо ресурси curl
        curl_easy_cleanup(curl);
		//LOGD("Response: %s", response.c_str());
        std::string obfuscatedString = OBFUSCATE("Login success");
		return (response.find(obfuscatedString.c_str()) != std::string::npos);

    }

    return false;
}

void *hack_thread(void *arg) {
    if(Auth()){
        
    
    int api_level = GetAndroidApiLevel();
    if (api_level >= 33) {
            void *libdl_handle = dlopen(OBFUSCATE("libdl.so"), RTLD_LAZY);
            void *addr = dlsym(libdl_handle, OBFUSCATE("__loader_dlopen"));
            LOGI(OBFUSCATE("__loader_dlopen at: %p"), addr);
            DobbyHook(addr, (void *) new___loader_dlopen,
                     (void **) &orig___loader_dlopen);
        if (api_level >= 26) {
            void *libdl_handle = dlopen(OBFUSCATE("libdl.so"), RTLD_LAZY);
            void *addr = dlsym(libdl_handle, OBFUSCATE("__loader_dlopen"));
            LOGI(OBFUSCATE("__loader_dlopen at: %p"), addr);
            DobbyHook(addr, (void *) new___loader_dlopen,
                     (void **) &orig___loader_dlopen);
        } else if (api_level >= 24) {
            void *addr = DobbySymbolResolver(nullptr,
                                         OBFUSCATE("__dl__Z9do_dlopenPKciPK17android_dlextinfoPv"));
            if (addr) {
                LOGI(OBFUSCATE("get cock at: %p"), addr);
                DobbyHook(addr, (void *) new_do_dlopen_V24,
                         (void **) &orig_do_dlopen_V24);
            }
        } else {
            void *addr = DobbySymbolResolver(nullptr,
                                         OBFUSCATE("__dl__Z9do_dlopenPKciPK17android_dlextinfo"));
            if (addr) {
                LOGI(OBFUSCATE("get cock at: %p"), addr);
                DobbyHook(addr, (void *) new_do_dlopen_V19,
                         (void **) &orig_do_dlopen_V19);
            }
        }
        while (!il2cpp_handle) {
            sleep(1);
        }
        origin_thread(il2cpp_handle);
        sleep(5);
        while (!unity_handle or !gl2_handle) {
            sleep(1);
        }
    
        
        auto eglSwapBuffers = dlsym(unity_handle, OBFUSCATE("eglSwapBuffers"));
        const char *dlsym_error = dlerror();
        if (dlsym_error) {
            DobbyHook(eglSwapBuffers, (void *) hook_eglSwapBuffers, (void **) &old_eglSwapBuffers);
        } else {
            DobbyHook(eglSwapBuffers, (void *) hook_eglSwapBuffers, (void **) &old_eglSwapBuffers);
        }
        void *sym_input = DobbySymbolResolver(OBFUSCATE("/system/lib/libinput.so"), OBFUSCATE("_ZN7android13InputConsumer21initializeMotionEventEPNS_11MotionEventEPKNS_12InputMessageE"));
        if (NULL != sym_input) {
            DobbyHook((void *)sym_input, (void *) myInput, (void **)&origInput);
        }
        do {
            sleep(1);
        } while (!isLibraryLoaded(OBFUSCATE("libil2cpp.so")));
        offsets_load();

        return nullptr;
    } else {
        sleep(2);
        auto addr = (uintptr_t)dlsym(RTLD_NEXT, OBFUSCATE("eglSwapBuffers"));
        DobbyHook((void*)addr, (void*)hook_eglSwapBuffers, (void**)&old_eglSwapBuffers);
        void *sym_input = DobbySymbolResolver((OBFUSCATE("/system/lib/libinput.so")), (OBFUSCATE("_ZN7android13InputConsumer21initializeMotionEventEPNS_11MotionEventEPKNS_12InputMessageE")));
        if (NULL != sym_input) {
            DobbyHook(sym_input,(void*)myInput,(void**)&origInput);
        }
        ProcMap il2cppMap;
        
        do {
            il2cppMap = KittyMemory::getLibraryMap(OBFUSCATE("libil2cpp.so"));
            sleep(1);
        } while (!il2cppMap.isValid());
        
        ProcMap anogsMap;
        do {
            anogsMap = KittyMemory::getLibraryMap(OBFUSCATE("libanogs.so"));
            sleep(1);
        } while (!anogsMap.isValid());
       offsets_load();
        
        return nullptr;
    }
    }
}

