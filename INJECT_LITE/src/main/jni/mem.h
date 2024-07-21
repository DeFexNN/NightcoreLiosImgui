void offsets_load() {
    while (!g_il2cpp) {
        g_il2cpp = Tools::GetBaseAddress(LIB);
        sleep(1);
    }
    LOGI("libil2cpp.so: %p", g_il2cpp);
    Il2CppAttach();
    std::this_thread::sleep_for(std::chrono::seconds(5));
	/*
	//BehaviorType
	DHOOK(0x1EFC65C, BehaviorType_marshal, _BehaviorType_marshal);
    DHOOK(0x1EFC664, BehaviorType_unmarshal, _BehaviorType_unmarshal);
    DHOOK(0x1EFC66C, BehaviorType_marshall, _BehaviorType_marshall);
    DHOOK(0x1EFC674, BehaviorType_unmarshall, _BehaviorType_unmarshall);
	//CApplicationInspect
	DHOOK(0x1EFC688, CApplicationInspect_handle, _CApplicationInspect_handle);
    DHOOK(0x1EFC6FC, CApplicationInspect_getType, _CApplicationInspect_getType);
    DHOOK(0x1EFC708, CApplicationInspect_marshal, _CApplicationInspect_marshal);
    DHOOK(0x1EFC754, CApplicationInspect_unmarshal, _CApplicationInspect_unmarshal);
	DHOOK(0x1EFC788, CApplicationInspect_marshall, _CApplicationInspect_marshall);
    DHOOK(0x1EFC7D0, CApplicationInspect_unmarshall, _CApplicationInspect_marshall);
	*/
	
	//CFindRoleNameById
    DHOOK(0x1EFC9C0, CFindRoleNameById_handle, _CFindRoleNameById_handle);
    DHOOK(0x1EFCA34, CFindRoleNameById_getType, _CFindRoleNameById_getType);
    DHOOK(0x1EFCA40, CFindRoleNameById_marshal, _CFindRoleNameById_marshal);
    DHOOK(0x1EFCA8C, CFindRoleNameById_unmarshal, _CFindRoleNameById_unmarshal);
	DHOOK(0x1EFCAC0, CFindRoleNameById_marshall, _CFindRoleNameById_marshall);
    DHOOK(0x1EFCB08, CFindRoleNameById_unmarshall, _CFindRoleNameById_unmarshall);
	/*
	//CGetInspectPlayerInfo
	DHOOK(0x1EFCD64, CGetInspectPlayerInfo_handle, _CGetInspectPlayerInfo_getType);
    DHOOK(0x1EFCDD8, CGetInspectPlayerInfo_getType, _CGetInspectPlayerInfo_getType);
    DHOOK(0x1EFCDE4, CGetInspectPlayerInfo_marshal, _CGetInspectPlayerInfo_marshal);
    DHOOK(0x1EFCE9C, CGetInspectPlayerInfo_unmarshal, _CGetInspectPlayerInfo_unmarshal);
	DHOOK(0x1EFCF2C, CGetInspectPlayerInfo_marshall, _CGetInspectPlayerInfo_marshall);
    DHOOK(0x1EFCFEC, CGetInspectPlayerInfo_unmarshall, _CGetInspectPlayerInfo_unmarshall);
	//CGetInspectPlayerReportList
	DHOOK(0x1EFD2A0, CGetInspectPlayerReportList_handle, _CGetInspectPlayerReportList_handle);
    DHOOK(0x1EFD314, CGetInspectPlayerReportList_getType, _CGetInspectPlayerReportList_getType);
    DHOOK(0x1EFD320, CGetInspectPlayerReportList_marshal, _CGetInspectPlayerReportList_marshal);
    DHOOK(0x1EFD36C, CGetInspectPlayerReportList_unmarshal, _CGetInspectPlayerReportList_unmarshal);
	DHOOK(0x1EFD3A0, CGetInspectPlayerReportList_marshall, _CGetInspectPlayerReportList_marshall);
    DHOOK(0x1EFD3E8, CGetInspectPlayerReportList_unmarshall, _CGetInspectPlayerReportList_unmarshall);
	//CGetInspectStatu - класса нету
	DHOOK(0x1EFD650, CGetInspectStatu_handle, _CGetInspectStatu_handle);
    DHOOK(0x1EFD6C4, CGetInspectStatu_getType, _CGetInspectStatu_getType);
    DHOOK(0x1EFD6D0, CGetInspectStatu_marshal, _CGetInspectStatu_marshal);
    DHOOK(0x1EFD7A0, CGetInspectStatu_unmarshal, _CGetInspectStatu_unmarshal);
	DHOOK(0x1EFD85C, CGetInspectStatu_marshall, _CGetInspectStatu_marshall);
    DHOOK(0x1EFD930, CGetInspectStatu_unmarshall, _CGetInspectStatu_unmarshall);
	//CGetServerReportStatus
	DHOOK(0x1EFDC80, CGetServerReportStatus_handle, _CGetInspectStatu_handle);
    DHOOK(0x1EFDCF4, CGetServerReportStatus_getType, _CGetInspectStatu_getType);
    DHOOK(0x1EFDD00, CGetServerReportStatus_marshal, _CGetInspectStatu_marshal);
    DHOOK(0x1EFDDE8, CGetServerReportStatus_unmarshal, _CGetInspectStatu_unmarshal);
	DHOOK(0x1EFDEA4, CGetServerReportStatus_marshall, _CGetInspectStatu_marshall);
    DHOOK(0x1EFDF84, CGetServerReportStatus_unmarshall, _CGetInspectStatu_unmarshall);
	*/
	//CHeartBeat
	DHOOK(0x1EFE724, CHeartBeat_handle, _CHeartBeat_handle);
    DHOOK(0x1EFE798, CHeartBeat_getType, _CHeartBeat_unmarshal);
    DHOOK(0x1EFE7A4, CHeartBeat_marshal, _CHeartBeat_unmarshal);
    DHOOK(0x1EFE81C, CHeartBeat_unmarshal, _CHeartBeat_unmarshal);
	DHOOK(0x1EFE880, CHeartBeat_marshall, _CHeartBeat_unmarshall);
    DHOOK(0x1EFE8FC, CHeartBeat_unmarshall, _CHeartBeat_unmarshall);
	//CReportCustomServer
	DHOOK(0x1EFD2A0, CReportCustomServer_handle, _CReportCustomServer_handle);
    DHOOK(0x1EFD314, CReportCustomServer_getType, _CReportCustomServer_unmarshal);
    DHOOK(0x1EFD320, CReportCustomServer_marshal, _CReportCustomServer_unmarshal);
    DHOOK(0x1EFD36C, CReportCustomServer_unmarshal, _CReportCustomServer_unmarshal);
	DHOOK(0x1EFD3A0, CReportCustomServer_marshall, _CReportCustomServer_unmarshall);
    DHOOK(0x1EFD3E8, CReportCustomServer_unmarshall, _CReportCustomServer_unmarshall);
    //CReportRoleCheating 
    DHOOK(0x1EFD650, CReportRoleCheating_handle, _CReportRoleCheating_handle);
    DHOOK(0x1EFD6C4, CReportRoleCheating_getType, _CReportRoleCheating_getType);
    DHOOK(0x1EFD6D0, CReportRoleCheating_marshal, _CReportRoleCheating_marshal);
    DHOOK(0x1EFD7A0, CReportRoleCheating_unmarshal, _CReportRoleCheating_unmarshal);
	DHOOK(0x1EFD85C, CReportRoleCheating_marshall, _CReportRoleCheating_marshall);
    DHOOK(0x1EFD930, CReportRoleCheating_unmarshall, _CReportRoleCheating_unmarshall);
	//CReportRoleCheatingById
    DHOOK(0x1EFDC80, CReportRoleCheatingById_handle, _CReportRoleCheatingById_handle);
    DHOOK(0x1EFDCF4, CReportRoleCheatingById_getType, _CReportRoleCheatingById_getType);
    DHOOK(0x1EFDD00, CReportRoleCheatingById_marshal, _CReportRoleCheatingById_marshal);
    DHOOK(0x1EFDDE8, CReportRoleCheatingById_unmarshal, _CReportRoleCheatingById_unmarshal);
	DHOOK(0x1EFDEA4, CReportRoleCheatingById_marshall, _CReportRoleCheatingById_marshall);
    DHOOK(0x1EFDF84, CReportRoleCheatingById_unmarshall, _CReportRoleCheatingById_unmarshall);
    //CReportShenSu
    DHOOK(0x1EFE2F8, CReportShenSu_marshal, _CReportShenSu_marshal);
    DHOOK(0x1EFE3D4, CReportShenSu_unmarshal, _CReportShenSu_unmarshal);
	DHOOK(0x1EFE498, CReportShenSu_marshall, _CReportShenSu_marshall);
    DHOOK(0x1EFE688, CReportShenSu_unmarshall, _CReportRoleCheatingById_unmarshall);
	//InspectReportInfo
	//SAlertCustomReportStatus
	//SFindRoleNameById
	//SGetInspectPlayerInfo
	//SGetInspectPlayerReportList
	//SGetInspectStatu
	//ShenSuType
	//SInspectPlayerMgs
	//SReportShenSu
    //CFindRoldeIdByCompetitionName - не связано с  gs-cheating_report
    /*DHOOK(0x1EE4C54, CFindRoleIdByCompetitionName_handle, _CFindRoleIdByCompetitionName_handle);
    DHOOK(0x1EE4CC8, CFindRoleIdByCompetitionName_getType, _CFindRoleIdByCompetitionName_getType);
    DHOOK(0x1EE4CD4, CFindRoleIdByCompetitionName_marshal, _CFindRoleIdByCompetitionName_marshal);
    DHOOK(0x1EE4D08, CFindRoleIdByCompetitionName_unmarshal, _CFindRoleIdByCompetitionName_unmarshal);*/
	
    //CGetAntiCheatingReward
    /*hexPatches.VIRT = MemoryPatch::createWithHex(LIBA, 0x2056B0, OBFUSCATE("00 00 00 00"));
    hexPatches.ROOT = MemoryPatch::createWithHex(LIBA, 0x18B7FC, OBFUSCATE("00 00 00 00"));
    hexPatches.GG = MemoryPatch::createWithHex(LIBA, 0x18A8DC, OBFUSCATE("00 00 00 00"));
    hexPatches.EMULATOR = MemoryPatch::createWithHex(LIBA, 0x18A433, OBFUSCATE("00 00 00 00"));
    */
    //class CheatMgr
    hexPatches.BP1 = MemoryPatch::createWithHex(LIB, 0x18AD040, BOOL);

     //class PlayerController 
    hexPatches.BP2 = MemoryPatch::createWithHex(LIB, 0x18366B8, RET);//CheckGround
    hexPatches.BP3 = MemoryPatch::createWithHex(LIB, 0x183DA64, RET);//CheckGroundDistance
    hexPatches.BP4 = MemoryPatch::createWithHex(LIB, 0x183EA04, FLOAT999999999);//GetFootGroundDis
    hexPatches.BP5 = MemoryPatch::createWithHex(LIB, 0x18377B0, RET);//CheckUnderGround
    hexPatches.BP6 = MemoryPatch::createWithHex(LIB, 0x183EE18, BOOL);//IgnoreGroundBuilding
    hexPatches.BP7 = MemoryPatch::createWithHex(LIB, 0x1836EB8, BOOL);//CheckCanMoveUp
    hexPatches.BP8 = MemoryPatch::createWithHex(LIB, 0x183FC94, RET);//CheckSyncPos
    hexPatches.BP9 = MemoryPatch::createWithHex(LIB, 0x183FDD4, BOOL);//IsCommunityServer
    hexPatches.BP10 = MemoryPatch::createWithHex(LIB, 0x183FED4, RET);//CheckContinueKillNum
    hexPatches.BP11 = MemoryPatch::createWithHex(LIB, 0x183FFDC, RET);//CheckFar300KillNum
    //hexPatches.BP12 = MemoryPatch::createWithHex(LIB, 0x183C4B8, RET);//SyncMoveStatus
    hexPatches.BP13 = MemoryPatch::createWithHex(LIB, 0x1843BFC, RET);//CheckBulletThroughWall
    hexPatches.BP14 = MemoryPatch::createWithHex(LIB, 0x1844D34, BOOL);//CheckCanUseItem
    hexPatches.BP15 = MemoryPatch::createWithHex(LIB, 0x1845FE0, BOOL);//CheckCanFly
    //hexPatches.BP16 = MemoryPatch::createWithHex(LIB, 0x1842208, RET);//CheckCamera
    hexPatches.BP17 = MemoryPatch::createWithHex(LIB, 0x1838934, RET);//CheckFly
    hexPatches.BP18 = MemoryPatch::createWithHex(LIB, 0x1837014, FALSE);//CheckthroughWall
    hexPatches.BP19 = MemoryPatch::createWithHex(LIB, 0x1847CF4, RET);//CheckAnimOverSpeed
    hexPatches.BP20 = MemoryPatch::createWithHex(LIB, 0x1847EB8, RET);//CheckTianXian
    
    //class MailMgr
    hexPatches.BP21 = MemoryPatch::createWithHex(LIB, 0x17277B4, RET);//OnCheatIntError
    //hexPatches.BP64 = MemoryPatch::createWithHex(LIB, 0x171FF88, RET);//SendCheatNumDic
    hexPatches.BP22 = MemoryPatch::createWithHex(LIB, 0x1727BDC, RET);//OnCheatFloatError
    hexPatches.BP23 = MemoryPatch::createWithHex(LIB, 0x1727D94, RET);//CheckUnderGround
    //hexPatches.BP24 = MemoryPatch::createWithHex(LIB, 0x172386C, RET);//CheckCamera
    hexPatches.BP25 = MemoryPatch::createWithHex(LIB, 0x1728BD0, RET);//CheckFly
    hexPatches.BP26 = MemoryPatch::createWithHex(LIB, 0x1728E1C, RET);//CheckZuobi
    hexPatches.BP27 = MemoryPatch::createWithHex(LIB, 0x17293DC, RET);//CheckAnimOverSpeed
    hexPatches.BP28 = MemoryPatch::createWithHex(LIB, 0x1729574, RET);//CheckThrougthWall
    hexPatches.BP29 = MemoryPatch::createWithHex(LIB, 0x1729B08, RET);//Dosome
    hexPatches.BP30 = MemoryPatch::createWithHex(LIB, 0x1729DF4, RET);//CheckMsgToSend
    hexPatches.BP41 = MemoryPatch::createWithHex(LIB, 0x172A774, RET);//CheckMainFunsNotMsg
    hexPatches.BP42 = MemoryPatch::createWithHex(LIB, 0x172A9F8, RET);//CheckHeartLive
    
    //class Battle
    hexPatches.Soul = MemoryPatch::createWithHex(LIB, 0x1A169E8, RET);//OnSServerPullBack
    //class MonsterController
    hexPatches.Stop = MemoryPatch::createWithHex(LIB, 0x17A104C, RET);//StartController
    
    //class BombMgr
    hexPatches.Splash = MemoryPatch::createWithHex(LIB, 0x1B90D88, BOOL);//CheckNoBlock
    
    //class SwimState
    hexPatches.Swim = MemoryPatch::createWithHex(LIB, 0x18028F0, RET); //CheckSwim
    //class PartBehaviour
    hexPatches.PR1 = MemoryPatch::createWithHex(LIB, 0x97E954, BOOL); //public bool get_AllowOp() { }
    //bool skip
    //bool skip
    hexPatches.PR2 = MemoryPatch::createWithHex(LIB, 0x97E9B8, BOOL); //public bool get_HavePermit() { }
    hexPatches.PR3 = MemoryPatch::createWithHex(LIB, 0x97E9D0, BOOL); //public bool CanUpdate() { }
    hexPatches.PR4 = MemoryPatch::createWithHex(LIB, 0x97EAF0, BOOL); //public bool CanBuild() { }
    
    //Fake Owner >> fast find MyEffectInfos >> public class FriendPermitMgr - baz
    hexPatches.FO1 = MemoryPatch::createWithHex(LIB, 0x16B6784, BOOL); //HavePermit
    hexPatches.FO2 = MemoryPatch::createWithHex(LIB, 0x16B6934, BOOL); //OtherBoxPermit
    hexPatches.FO3 = MemoryPatch::createWithHex(LIB, 0x16B6A04, BOOL); //IsVisitor
    hexPatches.FO4 = MemoryPatch::createWithHex(LIB, 0x16B6A88, BOOL); //HavePermitByInstanceId
    
    //class UnionMgr
    hexPatches.UM = MemoryPatch::createWithHex(LIB, 0x1A4CF98, BOOL); //HavePermitByInstanceId
    //class LandMineMgr
    hexPatches.FB = MemoryPatch::createWithHex(LIB, 0x1CF5E78, RET); //GetDelayTime
    
    //class Component
    Methods["Component::get_transform"] = (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("UnityEngine.dll"), OBFUSCATE("UnityEngine"), OBFUSCATE("Component"), OBFUSCATE("get_transform"));
    Methods["Component::get_gameObject"] = (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("UnityEngine.dll"), OBFUSCATE("UnityEngine"), OBFUSCATE("Component"), OBFUSCATE("get_gameObject"));
    //class Transform
    Methods["Transform::get_position"] = (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("UnityEngine.dll"), OBFUSCATE("UnityEngine"), OBFUSCATE("Transform"), OBFUSCATE("get_position"));
    set_position = (void *(*)(void *, Vector3)) getAbsoluteAddress(LIB, 0x34D20B0);
    
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
    DHOOK(0x184BDA8, PlayerController_DrinkWater, _PlayerController_DrinkWater);
    GetCurNearweapon = (void *(*)(void *)) getAbsoluteAddress(LIB, 0x182D208);
    SetAutoRunWithDirection = (void *(*)(void *, Vector3)) getAbsoluteAddress(LIB, 0x18470C4);
	CloseAutoRun = (void *(*)(void *)) getAbsoluteAddress(LIB, 0x1847250);
	DHOOK(0x182F02C, PlayerController_OnLandMineEvent, _PlayerController_OnLandMineEvent);
	
    //class vThirdPersonCamera
    SetLockAtPoint = (void *(*)(void *, Vector3)) getAbsoluteAddress(LIB, 0x113CF70);
    //class Rigidbody
    set_velocity = (void (*)(void *, Vector3)) getAbsoluteAddress(LIB, 0x3543950);
    set_detectCollisions = (void (*)(void *, bool)) getAbsoluteAddress(LIB, 0x35441BC);
    get_posRigidbody = (Vector3 (*)(void *)) getAbsoluteAddress(LIB, 0x3544210);
    MovePosition = (void (*)(void *, Vector3)) getAbsoluteAddress(LIB, 0x3544440);
	
    //class VehicleMonitor 
    Tools::Hook(Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("VehicleMonitor"), OBFUSCATE("FixedUpdate"), 0), (void *) &VehicleMonitor_FixedUpdate, (void **) &_VehicleMonitor_FixedUpdate);
    Tools::Hook(Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("VehicleMonitor"), OBFUSCATE("OnDestroy"), 0), (void *) &VehicleMonitor_OnDestroy, (void **) &_VehicleMonitor_OnDestroy);
    GetVehicleType = (int (*)(void *)) getAbsoluteAddress(LIB, 0xC43B80);
    //class BulletControl
    Tools::Hook(Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("BulletControl"), OBFUSCATE("FixedUpdate"), 0), (void *) &BulletControl_FixedUpdate, (void **) &_BulletControl_FixedUpdate);
	
    //class HeatMgr
    DHOOK(0x1E5DE1C, HeatMgr_CheckNoBlock, _HeatMgr_CheckNoBlock);
    //class BuilderBehaviour
    Tools::Hook(Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("EasyBuildSystem.Runtimes.Internal.Builder"), OBFUSCATE("BuilderBehaviour"), OBFUSCATE("Update"), 0), (void *) &BuilderBehaviour_Update, (void **) &_BuilderBehaviour_Update);
    RotatePreview = (void *(*)(void *, Vector3)) getAbsoluteAddress(LIB, 0x99B588);
    //class Gun
    DHOOK(0xDEEC44, Gun_DoOneShoot, _Gun_DoOneShoot);
    DHOOK(0xDF9190, Gun_CaulateMoveAimRadius, _Gun_CaulateMoveAimRadius);
    DHOOK(0xDF9304, Gun_CaulateShootAimRadius, _Gun_CaulateShootAimRadius);
    DHOOK(0xDEE70C, Gun_DoOneShootRecoil, _Gun_DoOneShootRecoil);
    
    //class DayNightSystem
    Tools::Hook(Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("DayNightSystem"), OBFUSCATE("Update"), 0), (void *) &DayNightSystem_Update, (void **) &_DayNightSystem_Update);
    //class TreeObject
    DHOOK(0x19A12A4, TreeObject_AddToScene, _TreeObject_AddToScene);
    //class GrassObject
    DHOOK(0x197DD14, GrassObject_AddToScene, _GrassObject_AddToScene);
    //class ThingsObject
    DHOOK(0x199F2C4, ThingsObject_AddToScene, _ThingsObject_AddToScene);
    //class MechaController
    Tools::Hook(Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("SC.AssembledSystem"), OBFUSCATE("MechaController"), OBFUSCATE("Update"), 0), (void *) &MechaController_Update, (void **) &_MechaController_Update);
    
    //class MonsterController
    DHOOK(0x17A63C0, MonsterController_Update, _MonsterController_Update);
    Tools::Hook(Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("MonsterController"), OBFUSCATE("OnDestroy"), 0), (void *) &MonsterController_OnDestroy, (void **) &_MonsterController_OnDestroy);
   
    //DHOOK(0x97E4D8, PartBehaviour_Awake, _PartBehaviour_Awake);
    DHOOK(0x1F93BE8, Mine_Init, _Mine_Init);
	
	//class HandAttack
	OnTriggerEnter1 = (void *(*)(void *)) getAbsoluteAddress(LIB, 0x1E510EC);
	
	//class Behaviour
    get_isActiveAndEnabled = (bool (*)(void *)) getAbsoluteAddress(LIB, 0x34B8834);
	
	//class BasePlayerController
	FastChangeAnimatorStates = (bool (*)(void *, int, int, bool, float)) getAbsoluteAddress(LIB, 0x17C657C);
	
	//DHOOK(0x17C6830, baobap, _baobap);
	get_tag =  (MonoString *(*)(void *)) getAbsoluteAddress(LIB, 0x000000);
	FindObjectsOfType =  (MonoArray <void **> *(*)(void *)) getAbsoluteAddress(LIB, 0x000000);
	get_name =  (MonoString *(*)(void *)) getAbsoluteAddress(LIB, 0x000000);
	GetType =  (void *(*)(MonoString *)) getAbsoluteAddress(LIB, 0x000000);
	
    bInitDone = true;
    pthread_exit(0);
 
}
