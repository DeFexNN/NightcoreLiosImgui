#include "Includes.h"
#include <includes/Dobby/dobby.h>

namespace Tools {
    void Hook(void *target, void *replace, void **backup);
    void HookDestroy(void *target);
    bool Read(void *addr, void *buffer, size_t length);
    bool Write(void *addr, void *buffer, size_t length);
    bool ReadAddr(void *addr, void *buffer, size_t length);
    bool WriteAddr(void *addr, void *buffer, size_t length);

    bool PVM_ReadAddr(void *addr, void *buffer, size_t length);
    bool PVM_WriteAddr(void *addr, void *buffer, size_t length);

    bool IsPtrValid(void *addr);

    uintptr_t GetBaseAddress(const char *name);
    uintptr_t GetEndAddress(const char *name);
    uintptr_t FindPattern(const char *lib, const char* pattern);

    std::string RandomString(const int len);
    std::string GetPackageName(JNIEnv *env, jobject context);
}
