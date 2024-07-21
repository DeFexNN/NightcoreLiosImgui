#include <cstring>
#include <jni.h>
#include <pthread.h>
#include <unistd.h>
#include <cstdio>
#include "hook.h"
#include "zygisk.hpp"
#include <chrono>
#include <thread>
#include "Includes/Obfuscate.h"
using zygisk::Api;
using zygisk::AppSpecializeArgs;
using zygisk::ServerSpecializeArgs;

class MyModule : public zygisk::ModuleBase {
public:
    void onLoad(Api *api, JNIEnv *env) override {
        env_ = env;
    }

    void preAppSpecialize(AppSpecializeArgs *args) override {
        if (!args || !args->nice_name) {
            return;
        }
        enable_hack = isGame(env_, args->app_data_dir);
    }

    void postAppSpecialize(const AppSpecializeArgs *) override {
        if (enable_hack) {
            launchCheatLogic();
        }
    }

private:
    JNIEnv *env_{};
    bool enable_hack{false};

    void launchCheatLogic() {
        pthread_t ntid;
        pthread_create(&ntid, nullptr, hack_thread, nullptr);
    }

    bool fileExists(const char *filename) {
        return access(filename, F_OK) != -1;
    }
};


REGISTER_ZYGISK_MODULE(MyModule)

