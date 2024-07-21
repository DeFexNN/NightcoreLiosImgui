uintptr_t g_il2cpp;
std::map<std::string, uintptr_t> Fields;
std::map<std::string, uintptr_t> Methods;
bool bInitDone = false;

#define LIB OBFUSCATE("libil2cpp.so")
#define LIBU OBFUSCATE("libunity.so")
#define LIBA OBFUSCATE("libanogs.so")
void DoHOOK(void *offseet, void* ptr, void **orig) {
    DobbyHook(offseet, ptr, orig);
}
#define DHOOK(offseet, ptr, orig) DoHOOK((void *)getAbsoluteAddress(LIB, offseet), (void *)ptr, (void **)&orig)
using namespace std;
#define targetLibName OBFUSCATE("libil2cpp.so")
JavaVM* publicVM;
JNIEnv* publicEnv;
uintptr_t address = 0;
int  glWidth, glHeight;

typedef enum { TOUCH_ACTION_DOWN = 0, TOUCH_ACTION_UP, TOUCH_ACTION_MOVE } TOUCH_ACTION;

typedef struct {
    TOUCH_ACTION action;
    float x;
    float y;
    int pointers;
    float y_velocity;
    float x_velocity;
}TOUCH_EVENT;
TOUCH_EVENT g_LastTouchEvent;

#define RET  OBFUSCATE("1E FF 2F E1")
#define BOOL OBFUSCATE("01 00 A0 E3 1E FF 2F E1")
#define INT2 ("02 00 A0 E3 1E FF 2F E1")
#define INT7 OBFUSCATE("07 00 A0 E3 1E FF 2F E1")
#define INT10 OBFUSCATE("0A 00 A0 E3 1E FF 2F E1")
#define INT15 OBFUSCATE("0F 00 A0 E3 1E FF 2F E1")
#define INT16 OBFUSCATE("10 00 A0 E3 1E FF 2F E1")
#define INT17 OBFUSCATE("11 00 A0 E3 1E FF 2F E1")
#define FLOAT2000 OBFUSCATE("FA 04 44 E3 1E FF 2F E1")
#define FLOAT99 OBFUSCATE("c6 02 44 e3 1e ff 2f e1")
#define FLOAT40 OBFUSCATE("20 02 44 E3 1E FF 2F E1")
#define FLOAT100 OBFUSCATE("C8 02 44 E3 1E FF 2F E1")
#define FLOAT1o5 OBFUSCATE("20 02 44 E3 1E FF 2F E1")
#define INT50 OBFUSCATE("37 00 A0 E3 1E FF 2F E1")
#define INT255 OBFUSCATE("FF 00 A0 E3 1E FF 2F E1")
#define INT999 OBFUSCATE("E7 03 00 E3 1E FF 2F E1")
#define INT65550 OBFUSCATE("DC 0F 0F E3 1E FF 2F E1")
#define FLOAT999999999 OBFUSCATE("FF 09 0C E3 00 10 A0 E3 9A 0B 43 E3 1E FF 2F E1")
#define FALSE OBFUSCATE("00 00 A0 E3 1E FF 2F E1")
