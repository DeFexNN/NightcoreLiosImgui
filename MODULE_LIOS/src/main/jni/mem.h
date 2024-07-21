void offsets_load() {
    while (!g_il2cpp) {
        g_il2cpp = Tools::GetBaseAddress(LIB);
        sleep(1);
    }
    LOGI("libil2cpp.so: %p", g_il2cpp);
    Il2CppAttach();
    std::this_thread::sleep_for(std::chrono::seconds(5));
    //_CReportRoleCheatingById
    DHOOK(0x216B828, CReportRoleCheatingById_handle, _CReportRoleCheatingById_handle);
    DHOOK(0x216B89C, CReportRoleCheatingById_getType, _CReportRoleCheatingById_getType);
    DHOOK(0x216B8A8, CReportRoleCheatingById_marshal, _CReportRoleCheatingById_marshal);
    DHOOK(0x216B990, CReportRoleCheatingById_unmarshal, _CReportRoleCheatingById_unmarshal);
    //_cReportRoleCheating
    DHOOK(0x216B1F8, CReportRoleCheating_handle, _CReportRoleCheating_handle);
    DHOOK(0x216B26C, CReportRoleCheating_getType, _CReportRoleCheating_getType);
    DHOOK(0x216B278, CReportRoleCheating_marshal, _CReportRoleCheating_marshal);
    DHOOK(0x216B348, CReportRoleCheating_unmarshal, _CReportRoleCheating_unmarshal);
    //_cFindRoldeIdByCompetitionName
    DHOOK(0x215217C, CFindRoleIdByCompetitionName_handle, _CFindRoleIdByCompetitionName_handle);
    DHOOK(0x21521F0, CFindRoleIdByCompetitionName_getType, _CFindRoleIdByCompetitionName_getType);
    DHOOK(0x21521FC, CFindRoleIdByCompetitionName_marshal, _CFindRoleIdByCompetitionName_marshal);
    DHOOK(0x2152230, CFindRoleIdByCompetitionName_unmarshal, _CFindRoleIdByCompetitionName_unmarshal);
    //_cFindRoleNameById
    DHOOK(0x2169B5C, CFindRoleNameById_handle, _CFindRoleNameById_handle);
    DHOOK(0x2169BD0, CFindRoleNameById_getType, _CFindRoleNameById_getType);
    DHOOK(0x2169BDC, CFindRoleNameById_marshal, _CFindRoleNameById_marshal);
    DHOOK(0x2169C28, CFindRoleNameById_unmarshal, _CFindRoleNameById_unmarshal);
 
    hexPatches.VIRT = MemoryPatch::createWithHex(LIBA, 0x19BEED, OBFUSCATE("00 00 00 00"));
    hexPatches.ROOT = MemoryPatch::createWithHex(LIBA, 0x19C9ED, OBFUSCATE("00 00 00 00"));
    hexPatches.GG = MemoryPatch::createWithHex(LIBA, 0x19BAC6, OBFUSCATE("00 00 00 00"));
    hexPatches.EMULATOR = MemoryPatch::createWithHex(LIBA, 0x19B551, OBFUSCATE("00 00 00 00"));
    
    //class CheatMgr
    hexPatches.BP1 = MemoryPatch::createWithHex(LIB, 0x1AA0754, BOOL);

     //class PlayerController 
    hexPatches.BP2 = MemoryPatch::createWithHex(LIB, 0x1A2A340, RET);//CheckGround
    hexPatches.BP3 = MemoryPatch::createWithHex(LIB, 0x1A314B0, RET);//CheckGroundDistance
    hexPatches.BP4 = MemoryPatch::createWithHex(LIB, 0x1A3266C, FLOAT999999999);//GetFootGroundDis
    hexPatches.BP5 = MemoryPatch::createWithHex(LIB, 0x1A2B438, RET);//CheckUnderGround
    hexPatches.BP6 = MemoryPatch::createWithHex(LIB, 0x1A32A80, BOOL);//IgnoreGroundBuilding
    hexPatches.BP7 = MemoryPatch::createWithHex(LIB, 0x1A2AB40, BOOL);//CheckCanMoveUp
    hexPatches.BP8 = MemoryPatch::createWithHex(LIB, 0x1A338FC, RET);//CheckSyncPos
    hexPatches.BP9 = MemoryPatch::createWithHex(LIB, 0x1A33A3C, BOOL);//IsCommunityServer
    hexPatches.BP10 = MemoryPatch::createWithHex(LIB, 0x1A33B3C, RET);//CheckContinueKillNum
    hexPatches.BP11 = MemoryPatch::createWithHex(LIB, 0x1A33C44, RET);//CheckFar300KillNum
    //hexPatches.BP12 = MemoryPatch::createWithHex(LIB, 0x1A34A3C, RET);//SyncMoveStatus
    hexPatches.BP13 = MemoryPatch::createWithHex(LIB, 0x1A36E14, RET);//CheckBulletThroughWall
    hexPatches.BP14 = MemoryPatch::createWithHex(LIB, 0x1A37F4C, BOOL);//CheckCanUseItem
    hexPatches.BP15 = MemoryPatch::createWithHex(LIB, 0x1A391F8, BOOL);//CheckCanFly
    //hexPatches.BP16 = MemoryPatch::createWithHex(LIB, 0x1A3A8F0, RET);//CheckCamera
    hexPatches.BP17 = MemoryPatch::createWithHex(LIB, 0x1A3AC08, RET);//CheckFly
    hexPatches.BP18 = MemoryPatch::createWithHex(LIB, 0x1A2AC9C, FALSE);//CheckthroughWall
    hexPatches.BP19 = MemoryPatch::createWithHex(LIB, 0x1A3B3A0, RET);//CheckAnimOverSpeed
    hexPatches.BP20 = MemoryPatch::createWithHex(LIB, 0x1A3B564, RET);//CheckTianXian
    
    //class MailMgr
    hexPatches.BP21 = MemoryPatch::createWithHex(LIB, 0x190D474, RET);//OnCheatIntError
    //hexPatches.BP64 = MemoryPatch::createWithHex(LIB, 0x171FF88, RET);//SendCheatNumDic
    hexPatches.BP22 = MemoryPatch::createWithHex(LIB, 0x190D89C, RET);//OnCheatFloatError
    hexPatches.BP23 = MemoryPatch::createWithHex(LIB, 0x190DA54, RET);//CheckUnderGround
    //hexPatches.BP24 = MemoryPatch::createWithHex(LIB, 0x190E890, RET);//CheckCamera
    hexPatches.BP25 = MemoryPatch::createWithHex(LIB, 0x190E890, RET);//CheckFly
    hexPatches.BP26 = MemoryPatch::createWithHex(LIB, 0x190EE54, RET);//CheckZuobi
    hexPatches.BP27 = MemoryPatch::createWithHex(LIB, 0x190F414, RET);//CheckAnimOverSpeed
    hexPatches.BP28 = MemoryPatch::createWithHex(LIB, 0x190F5AC, RET);//CheckThrougthWall
    hexPatches.BP29 = MemoryPatch::createWithHex(LIB, 0x190EAE8, RET);//Dosome
    hexPatches.BP30 = MemoryPatch::createWithHex(LIB, 0x190FB74, RET);//CheckMsgToSend
    hexPatches.BP41 = MemoryPatch::createWithHex(LIB, 0x19104F4, RET);//CheckMainFunsNotMsg
    hexPatches.BP42 = MemoryPatch::createWithHex(LIB, 0x1910778, RET);//CheckHeartLive
    
    //class Battle
    hexPatches.Soul = MemoryPatch::createWithHex(LIB, 0x1C0C358, RET);//OnSServerPullBack
    //class MonsterController
    hexPatches.Stop = MemoryPatch::createWithHex(LIB, 0x1991C50, RET);//StartController
    
    //class BombMgr
    hexPatches.Splash = MemoryPatch::createWithHex(LIB, 0x1F0BEB4, BOOL);//CheckNoBlock
    
    //class SwimState
    hexPatches.Swim = MemoryPatch::createWithHex(LIB, 0x19F608C, RET); //CheckSwim
    //class PartBehaviour
    hexPatches.PR1 = MemoryPatch::createWithHex(LIB, 0xA42A4C, BOOL); //public bool get_AllowOp() { }
    //bool skip
    //bool skip
    hexPatches.PR2 = MemoryPatch::createWithHex(LIB, 0xA4D2B4, BOOL); //public bool get_HavePermit() { }
    hexPatches.PR3 = MemoryPatch::createWithHex(LIB, 0xA4D3D4, BOOL); //public bool CanUpdate() { }
    hexPatches.PR4 = MemoryPatch::createWithHex(LIB, 0xA4D850, BOOL); //public bool CanBuild() { }
    
    //Fake Owner >> fast find MyEffectInfos >> public class FriendPermitMgr - baz
    hexPatches.FO1 = MemoryPatch::createWithHex(LIB, 0x171179C, BOOL); //HavePermit
    hexPatches.FO2 = MemoryPatch::createWithHex(LIB, 0x171194C, BOOL); //OtherBoxPermit
    hexPatches.FO3 = MemoryPatch::createWithHex(LIB, 0x1711A1C, BOOL); //IsVisitor
    hexPatches.FO4 = MemoryPatch::createWithHex(LIB, 0x1711AA0, BOOL); //HavePermitByInstanceId
    
    //class UnionMgr
    hexPatches.UM = MemoryPatch::createWithHex(LIB, 0x1C5A2D0, BOOL); //HavePermitByInstanceId
    //class LandMineMgr
    hexPatches.FB = MemoryPatch::createWithHex(LIB, 0x1F12E2C, RET); //GetDelayTime
    
    //class Component
    Methods["Component::get_transform"] = (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("UnityEngine.dll"), OBFUSCATE("UnityEngine"), OBFUSCATE("Component"), OBFUSCATE("get_transform"));
    Methods["Component::get_gameObject"] = (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("UnityEngine.dll"), OBFUSCATE("UnityEngine"), OBFUSCATE("Component"), OBFUSCATE("get_gameObject"));
    //class Transform
    Methods["Transform::get_position"] = (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("UnityEngine.dll"), OBFUSCATE("UnityEngine"), OBFUSCATE("Transform"), OBFUSCATE("get_position"));
    set_position = (void *(*)(void *, Vector3)) getAbsoluteAddress(LIB, 0x372E638);
    
    //class Camera
    Methods["Camera::get_main"] = (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("UnityEngine.dll"), OBFUSCATE("UnityEngine"), OBFUSCATE("Camera"), OBFUSCATE("get_main"), 0);
    Methods["Camera::WorldToScreenPoint"] = (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("UnityEngine.dll"), OBFUSCATE("UnityEngine"), OBFUSCATE("Camera"), OBFUSCATE("WorldToScreenPoint"), 1);
    Methods["Camera::ViewportToWorldPoint"] = (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("UnityEngine.dll"), OBFUSCATE("UnityEngine"), OBFUSCATE("Camera"), OBFUSCATE("ViewportToWorldPoint"), 1);
    //class OtherPlayerController
    Tools::Hook(Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("OtherPlayerController"), OBFUSCATE("Update"), 0), (void *) &OtherPlayerController_Update, (void **) &_OtherPlayerController_Update);
    Tools::Hook(Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("OtherPlayerController"), OBFUSCATE("OnDestroy"), 0), (void *) &OtherPlayerController_OnDestroy, (void **) &_OtherPlayerController_OnDestroy);
    //class PlayerController
    Tools::Hook(Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("PlayerController"), OBFUSCATE("Update"), 0), (void *) &PlayerController_Update, (void **) &_PlayerController_Update);
    Tools::Hook(Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("PlayerController"), OBFUSCATE("OnDestroy"), 0), (void *) &PlayerController_OnDestroy, (void **) &_PlayerController_OnDestroy);
	DHOOK(0x1A2363C, PlayerController_OnLandMineEvent, _PlayerController_OnLandMineEvent);
    DHOOK(0x1A3EC50, PlayerController_DrinkWater, _PlayerController_DrinkWater);
    GetCurNearweapon = (void *(*)(void *)) getAbsoluteAddress(LIB, 0x1A21704);
    SetAutoRunWithDirection = (void *(*)(void *, Vector3)) getAbsoluteAddress(LIB, 0x1A3A2DC);
	CloseAutoRun = (void *(*)(void *)) getAbsoluteAddress(LIB, 0x1A3A468);
	
    //class vThirdPersonCamera
    SetLockAtPoint = (void *(*)(void *, Vector3)) getAbsoluteAddress(LIB, 0x111C0C0);
    //class Rigidbody
    set_velocity = (void (*)(void *, Vector3)) getAbsoluteAddress(LIB, 0x37A1314);
    set_detectCollisions = (void (*)(void *, bool)) getAbsoluteAddress(LIB, 0x37A1B80);
    get_posRigidbody = (Vector3 (*)(void *)) getAbsoluteAddress(LIB, 0x37A1BD4);
    MovePosition = (void (*)(void *, Vector3)) getAbsoluteAddress(LIB, 0x37A1E04);
    AddForceAtPosition = (void (*)(void *, Vector3, Vector3, int)) getAbsoluteAddress(LIB, 0x37A224C);
    
    //class VehicleMonitor 
    Tools::Hook(Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("VehicleMonitor"), OBFUSCATE("FixedUpdate"), 0), (void *) &VehicleMonitor_FixedUpdate, (void **) &_VehicleMonitor_FixedUpdate);
    Tools::Hook(Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("VehicleMonitor"), OBFUSCATE("OnDestroy"), 0), (void *) &VehicleMonitor_OnDestroy, (void **) &_VehicleMonitor_OnDestroy);
    GetVehicleType = (int (*)(void *)) getAbsoluteAddress(LIB, 0xC310D4);
    //class BulletControl
    Tools::Hook(Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("BulletControl"), OBFUSCATE("FixedUpdate"), 0), (void *) &BulletControl_FixedUpdate, (void **) &_BulletControl_FixedUpdate);
	
    //class HeatMgr
    DHOOK(0x2087F94, HeatMgr_CheckNoBlock, _HeatMgr_CheckNoBlock);
    //class BuilderBehaviour
    Tools::Hook(Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("EasyBuildSystem.Runtimes.Internal.Builder"), OBFUSCATE("BuilderBehaviour"), OBFUSCATE("Update"), 0), (void *) &BuilderBehaviour_Update, (void **) &_BuilderBehaviour_Update);
    RotatePreview = (void *(*)(void *, Vector3)) getAbsoluteAddress(LIB, 0xA6BE14);
    //class Gun
    DHOOK(0xE08D88, Gun_DoOneShoot, _Gun_DoOneShoot);
    DHOOK(0xE14044, Gun_CaulateMoveAimRadius, _Gun_CaulateMoveAimRadius);
    DHOOK(0xE141B8, Gun_CaulateShootAimRadius, _Gun_CaulateShootAimRadius);
    DHOOK(0xE14840, Gun_DoOneShootRecoil, _Gun_DoOneShootRecoil);
    
    //class DayNightSystem
    Tools::Hook(Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("DayNightSystem"), OBFUSCATE("Update"), 0), (void *) &DayNightSystem_Update, (void **) &_DayNightSystem_Update);
    //class TreeObject
    DHOOK(0x1B9D6F8, TreeObject_AddToScene, _TreeObject_AddToScene);
    //class GrassObject
    DHOOK(0x1B7A358, GrassObject_AddToScene, _GrassObject_AddToScene);
    //class ThingsObject
    DHOOK(0x1B9B718, ThingsObject_AddToScene, _ThingsObject_AddToScene);
    //class MechaController
    Tools::Hook(Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("SC.AssembledSystem"), OBFUSCATE("MechaController"), OBFUSCATE("Update"), 0), (void *) &MechaController_Update, (void **) &_MechaController_Update);
    
    //class MonsterController
    DHOOK(0x1997084, MonsterController_Update, _MonsterController_Update);
    Tools::Hook(Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("MonsterController"), OBFUSCATE("OnDestroy"), 0), (void *) &MonsterController_OnDestroy, (void **) &_MonsterController_OnDestroy);
   
    //DHOOK(0x97E4D8, PartBehaviour_Awake, _PartBehaviour_Awake);
    DHOOK(0x21C36D0, Mine_Init, _Mine_Init);
	
	//class HandAttack
	OnTriggerEnter1 = (void *(*)(void *)) getAbsoluteAddress(LIB, 0x207B62C);
	
	//class Behaviour
    get_isActiveAndEnabled = (bool (*)(void *)) getAbsoluteAddress(LIB, 0x37144B4);
	
	//class BasePlayerController
	FastChangeAnimatorStates = (bool (*)(void *, int, int, bool, float)) getAbsoluteAddress(LIB, 0x19B8548);
	
	get_tag =  (MonoString *(*)(void *)) getAbsoluteAddress(LIB, 0x000000);
	FindObjectsOfType =  (MonoArray <void **> *(*)(void *)) getAbsoluteAddress(LIB, 0x000000);
	get_name =  (MonoString *(*)(void *)) getAbsoluteAddress(LIB, 0x000000);
	GetType =  (void *(*)(MonoString *)) getAbsoluteAddress(LIB, 0x000000);
	
    bInitDone = true;
    pthread_exit(0);
 
}
