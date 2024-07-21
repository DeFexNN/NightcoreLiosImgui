#include "Draww.h"
#include "Struc.h"
#include "player.h"

#include "Vector3.h"
#include "Vector2.h"
#include "Quaternion.h"

template <typename T>
struct monoArray {
    void* klass;
    void* monitor;
    void* bounds;
    int   max_length;
    void* vector [1];
    int getLength() {
        return max_length;
    }
    T getPointer() {
        return (T)vector;
    }
};

template <typename T>
struct monoList {
    void *unk0;
    void *unk1;
    monoArray<T> *items;
    int size;
    int version;
    T getItems() {
        return items->getPointer();
    }
    int getSize() {
        return size;
    }
    int getVersion() {
        return version;
    }
};

template <typename K, typename V>
struct monoDictionary {
    void *unk0;
    void *unk1;
    monoArray<int **> *table;
    monoArray<void **> *linkSlots;
    monoArray<K> *keys;
    monoArray<V> *values;
    int touchedSlots;
    int emptySlot;
    int size;
    K getKeys() {
        return keys->getPointer();
    }
    V getValues() {
        return values->getPointer();
    }
    int getNumKeys() {
        return keys->getLength();
    }
    int getNumValues() {
        return values->getLength();
    }
    int getSize() {
        return size;
    }
};


enum FSM_StateFlags
{
    None = 0,
    Moveable = 1,
    DisableFollowCameraRotation = 2,
    DisableWeapon = 4,
    DisableShoot = 8,
    ShootGroundDistanceCheck = 16,
    DisableMove = 32,
    DisableUseItem = 64,
    CanSaveOther = 128,
    FreezeRigidBody = 256,
    NullStateDisableHeadIK = 512,
    DisableHeadInfo = 1024,
    DisableCameraCullingRaycast = 2048,
    DisableFallStateCheck = 4096,
    DisableCheckAim = 8192
};


template <typename T>
struct BaseFsmState;

template <typename T>
struct BaseFsmSystem {
    monoDictionary<T, BaseFsmState<T>> m_StatesDic;
    void *m_CurrentStateActCoroutine;
    void *Ticker;
    bool CanRun;
    void *MapObj;
    bool onCantBreakCalling;
    BaseFsmState<T> CurrentState;

    
};

template <typename T>
struct BaseFsmState {
    MonoString* m_TargetAnimatorName;
    BaseFsmSystem<T>* fsm;
    bool OpenLog;
    bool CanBreak;
    float CheckFinishTime;
    float EnterTime;
    T stateID;
    T PrevStateId;
    const FSM_StateFlags StateFlags;
    uintptr_t PlayerController;
    uintptr_t MonsterController;
    uintptr_t MapObject;

    T get_stateID() {
        return stateID;
    }

    void *set_stateID(void *point, T value) {
        return stateID;
    }

    T get_ID() {
        return stateID;
    }

    virtual FSM_StateFlags get_StateFlags() {
        return FSM_StateFlags::None;
    }
};

struct Vec3{
  float x;
  float y;
  float z;

  Vec3();
  Vec3(float x, float y, float z);
  ~Vec3();
};

Vec3::Vec3() {}
Vec3::Vec3(float x, float y, float z) : x(x), y(y), z(z) {}
Vec3::~Vec3() {}

