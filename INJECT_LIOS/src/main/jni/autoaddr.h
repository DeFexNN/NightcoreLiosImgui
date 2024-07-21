#include <dlfcn.h>
#include <cstdlib>
#include <cstring>
#include <cinttypes>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#define DO_API(r, n, p) r (*n) p
#undef DO_API
typedef unsigned long ulong;
ulong il2cpp_base = 0;
void init_il2cpp_api() {
#define DO_API(r, n, p) n = (r (*) p)dlsym(il2cpp_handle, #n)
#undef DO_API
}

ulong get_module_base(const char *module_name) {
    ulong addr = 0;
    char line[1024];
    uint64_t start = 0;
    uint64_t end = 0;
    char flags[5];
    char path[PATH_MAX];

    FILE *fp = fopen("/proc/self/maps", "r");
    if (fp != nullptr) {
        while (fgets(line, sizeof(line), fp)) {
            strcpy(path, "");
            sscanf(line, "%" PRIx64"-%" PRIx64" %s %*" PRIx64" %*x:%*x %*u %s\n", &start, &end,
                    flags, path);
#if defined(__aarch64__)
            if (strstr(flags, "x") == 0) //TODO
                continue;
#endif
            if (strstr(path, module_name)) {
                addr = start;
                break;
            }
        }
        fclose(fp);
    }
    return addr;
}
const char * libName = "lib/arm/libil2cpp.so";
ulong getAdresss(ulong address) {
    if (il2cpp_base == 0) {
        il2cpp_base = get_module_base(libName);
    }
    return (il2cpp_base + address);
}
void* getAdress(ulong address) {
    if (il2cpp_base == 0) {
        il2cpp_base = get_module_base(libName);
    }
    return (void*)(il2cpp_base + address);
}
void origin_thread(void* ){
    init_il2cpp_api(); //For open lib be correctly
    il2cpp_base = get_module_base(libName);
    //LOGI(S("coke_base addr star && end +-: %ld "), il2cpp_base);
}
//IMGUI PRIBLUDES :D
