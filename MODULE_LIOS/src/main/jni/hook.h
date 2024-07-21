#include <jni.h>


static int enable_hack;
static void *il2cpp_handle = NULL;
static void *unity_handle = NULL;
static char *game_data_dir = NULL;
static void *egl_handle = NULL;
static void *gl2_handle = NULL;
int isGame(JNIEnv *env, jstring appDataDir);

void *hack_thread(void *arg);

#define HOOK_DEF(ret, func, ...) \
  ret (*orig_##func)(__VA_ARGS__); \
  ret new_##func(__VA_ARGS__)



