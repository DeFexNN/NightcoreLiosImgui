#ifndef HOOK_MACROS
#define HOOK_MACROS

#include "Includes/Dobby/dobby.h"

#if defined(__aarch64__)
    #include <And64InlineHook/And64InlineHook.hpp>
#else 
    #include <Substrate/SubstrateHook.h>
    #include <Substrate/CydiaSubstrate.h>
#endif

void hook(void *offset, void* ptr, void **orig) {
#if defined(__aarch64__)
    A64HookFunction(offset, ptr, orig);
#else
    MSHookFunction(offset, ptr, orig);
#endif
}


#define HOOK(offset, ptr, orig) DobbyHook((void *)getAbsoluteAddress(libName, string2Offset(OBFUSCATE(offset))), (void *)ptr, (void **)&orig)
#define HOOK_LIB(lib, offset, ptr, orig) DobbyHook((void *)getAbsoluteAddress(OBFUSCATE(lib), string2Offset(OBFUSCATE(offset))), (void *)ptr, (void **)&orig)

//Obfuscate offset
#define OBFUSCATEOFFSET(str) string2Offset(OBFUSCATE(str)) //Encrypt offset

#endif //Macros For Hook
