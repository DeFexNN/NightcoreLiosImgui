void offsets_load() {
    while (!g_il2cpp) {
        g_il2cpp = Tools::GetBaseAddress(LIB);
        sleep(1);
    }
    //LOGI("libil2cpp.so: %p", g_il2cpp);
    Il2CppAttach();
    std::this_thread::sleep_for(std::chrono::seconds(5));
    //class BehaviorType
    DHOOK(0x226743C, BehaviorType_marshal, _BehaviorType_marshal);
    DHOOK(0x2267444, BehaviorType_unmarshal, _BehaviorType_unmarshal);
    DHOOK(0x226744C, BehaviorType_marshal2, _BehaviorType_marshal2);
    DHOOK(0x2267454, BehaviorType_unmarshal2, _BehaviorType_unmarshal2);
    //CApplicationInspect
    DHOOK(0x2267468, CApplicationInspect_handle, _CApplicationInspect_handle);
    DHOOK(0x22674DC, CApplicationInspect_getType, _CApplicationInspect_getType);
    DHOOK(0x22674E8, CApplicationInspect_marshal, _CApplicationInspect_marshal);
    DHOOK(0x22674F0, CApplicationInspect_unmarshal, _CApplicationInspect_unmarshal);
    DHOOK(0x22674F8, CApplicationInspect_marshal2, _CApplicationInspect_marshal2);
    DHOOK(0x2267500, CApplicationInspect_unmarshal2, _CApplicationInspect_unmarshal2);
    //CFindRoleNameById
    DHOOK(0x22676B4, CFindRoleNameById_handle, _CFindRoleNameById_handle);
    DHOOK(0x2267728, CFindRoleNameById_getType, _CFindRoleNameById_getType);
    DHOOK(0x2267734, CFindRoleNameById_marshal, _CFindRoleNameById_marshal);
    DHOOK(0x2267780, CFindRoleNameById_unmarshal, _CFindRoleNameById_unmarshal);
    DHOOK(0x22677B4, CFindRoleNameById_marshal2, _CApplicationInspect_marshal2);
    DHOOK(0x22677FC, CFindRoleNameById_unmarshal2, _CApplicationInspect_unmarshal2);
    //CGetInspectPlayerInfo
    DHOOK(0x22679EC, CGetInspectPlayerInfo_handle, _CGetInspectPlayerInfo_handle);
    DHOOK(0x2267A60, CGetInspectPlayerInfo_getType, _CGetInspectPlayerInfo_getType);
    DHOOK(0x2267A6C, CGetInspectPlayerInfo_marshal, _CGetInspectPlayerInfo_marshal);
    DHOOK(0x2267A74, CGetInspectPlayerInfo_unmarshal, _CGetInspectPlayerInfo_unmarshal);
    DHOOK(0x2267A7C, CGetInspectPlayerInfo_marshal2, _CGetInspectPlayerInfo_marshal2);
    DHOOK(0x2267A84, CGetInspectPlayerInfo_unmarshal2, _CGetInspectPlayerInfo_unmarshal2);
    //CGetInspectPlayerReportList
    DHOOK(0x2267C38, CGetInspectPlayerReportList_handle, _CGetInspectPlayerReportList_handle);
    DHOOK(0x2267CAC, CGetInspectPlayerReportList_getType, _CGetInspectPlayerReportList_getType);
    DHOOK(0x2267CB8, CGetInspectPlayerReportList_marshal, _CGetInspectPlayerReportList_marshal);
    DHOOK(0x2267CC0, CGetInspectPlayerReportList_unmarshal, _CGetInspectPlayerReportList_unmarshal);
    DHOOK(0x2267CC8, CGetInspectPlayerReportList_marshal2, _CGetInspectPlayerReportList_marshal2);
    DHOOK(0x2267CD0, CGetInspectPlayerReportList_unmarshal2, _CGetInspectPlayerReportList_unmarshal2);
    //CGetInspectStatu
    DHOOK(0x2267E84, CGetInspectStatu_handle, _CGetInspectStatu_handle);
    DHOOK(0x2267EF8, CGetInspectStatu_getType, _CGetInspectStatu_getType);
    DHOOK(0x2267F04, CGetInspectStatu_marshal, _CGetInspectStatu_marshal);
    DHOOK(0x2267F0C, CGetInspectStatu_unmarshal, _CGetInspectStatu_unmarshal);
    DHOOK(0x2267F14, CGetInspectStatu_marshal2, _CGetInspectStatu_marshal2);
    DHOOK(0x2267F1C, CGetInspectStatu_unmarshal2, _CGetInspectStatu_unmarshal2);
    //CGetServerReportStatus
    DHOOK(0x22680D0, CGetServerReportStatus_handle, _CGetServerReportStatus_handle);
    DHOOK(0x2268144, CGetServerReportStatus_getType, _CGetServerReportStatus_getType);
    DHOOK(0x2268150, CGetServerReportStatus_marshal, _CGetServerReportStatus_marshal);
    DHOOK(0x226819C, CGetServerReportStatus_unmarshal, _CGetServerReportStatus_unmarshal);
    DHOOK(0x22681D0, CGetServerReportStatus_marshal2, _CGetServerReportStatus_marshal2);
    DHOOK(0x2268218, CGetServerReportStatus_unmarshal2, _CGetServerReportStatus_unmarshal2);
    //CHeartBeat
    DHOOK(0x2268474, CHeartBeat_handle, _CHeartBeat_handle);
    DHOOK(0x22684E8, CHeartBeat_getType, _CHeartBeat_getType);
    DHOOK(0x22684F4, CHeartBeat_marshal, _CHeartBeat_marshal);
    DHOOK(0x22685AC, CHeartBeat_unmarshal, _CHeartBeat_unmarshal);
    DHOOK(0x226863C, CHeartBeat_marshal2, _CHeartBeat_marshal2);
    DHOOK(0x22686EC, CHeartBeat_unmarshal2, _CHeartBeat_unmarshal2);
    //CReportCustomServer
    DHOOK(0x22689A0, CReportCustomServer_handle, _CReportCustomServer_handle);
    DHOOK(0x2268A14, CReportCustomServer_getType, _CReportCustomServer_getType);
    DHOOK(0x2268A20, CReportCustomServer_marshal, _CReportCustomServer_marshal);
    DHOOK(0x2268A6C, CReportCustomServer_unmarshal, _CReportCustomServer_unmarshal);
    DHOOK(0x2268AA0, CReportCustomServer_marshal2, _CReportCustomServer_marshal2);
    DHOOK(0x2268AE8, CReportCustomServer_unmarshal2, _CReportCustomServer_unmarshal2);
    //CReportRoleCheating
    DHOOK(0x2268D50, CReportRoleCheating_handle, _CReportRoleCheating_handle);
    DHOOK(0x2268DC4, CReportRoleCheating_getType, _CReportRoleCheating_getType);
    DHOOK(0x2268DD0, CReportRoleCheating_marshal, _CReportRoleCheating_marshal);
    DHOOK(0x2268EA0, CReportRoleCheating_unmarshal, _CReportRoleCheating_unmarshal);
    DHOOK(0x2268F5C, CReportRoleCheating_marshal2, _CReportRoleCheating_marshal2);
    DHOOK(0x2269030, CReportRoleCheating_unmarshal2, _CReportRoleCheating_unmarshal2);
    //CReportRoleCheatingById
    DHOOK(0x2269380, CReportRoleCheatingById_handle, _CReportRoleCheatingById_handle);
    DHOOK(0x22693F4, CReportRoleCheatingById_getType, _CReportRoleCheatingById_getType);
    DHOOK(0x2269400, CReportRoleCheatingById_marshal, _CReportRoleCheatingById_marshal);
    DHOOK(0x22694E8, CReportRoleCheatingById_unmarshal, _CReportRoleCheatingById_unmarshal);
    DHOOK(0x22695A4, CReportRoleCheatingById_marshal2, _CReportRoleCheatingById_unmarshal2);
    DHOOK(0x2269684, CReportRoleCheatingById_unmarshal2, _CReportRoleCheatingById_unmarshal2);
    //CReportShenSu
    DHOOK(0x22699F4, CReportShenSu_marshal, _CReportShenSu_marshal);
    DHOOK(0x2269AD0, CReportShenSu_unmarshal, _CReportShenSu_unmarshal);
    DHOOK(0x2269B94, CReportShenSu_marshal2, _CReportShenSu_marshal2);
    DHOOK(0x2269C98, CReportShenSu_unmarshal2, _CReportShenSu_unmarshal2);  
    //InspectReportInfo
    DHOOK(0x2269E8C, InspectReportInfo_marshal, _InspectReportInfo_marshal);
    DHOOK(0x2269FB4, InspectReportInfo_unmarshal, _InspectReportInfo_unmarshal);
    DHOOK(0x226A0A4, InspectReportInfo_marshal2, _InspectReportInfo_marshal2);
    DHOOK(0x226A1EC, InspectReportInfo_unmarshal2, _InspectReportInfo_unmarshal2);
    //SAlertCustomReportStatus
    DHOOK(0x226A3A4, SAlertCustomReportStatus_handle, _SAlertCustomReportStatus_handle);
    DHOOK(0x226A418, SAlertCustomReportStatus_getType, _SAlertCustomReportStatus_getType);
    DHOOK(0x226A424, SAlertCustomReportStatus_marshal, _SAlertCustomReportStatus_marshal);
    DHOOK(0x226A4C0, SAlertCustomReportStatus_unmarshal, _SAlertCustomReportStatus_unmarshal);
    DHOOK(0x226A524, SAlertCustomReportStatus_marshal2, _SAlertCustomReportStatus_marshal2);
    DHOOK(0x226A5B8, SAlertCustomReportStatus_unmarshal2, _SAlertCustomReportStatus_unmarshal2);
    //SFindRoleNameById
    DHOOK(0x226A848, SFindRoleNameById_handle, _SFindRoleNameById_handle);
    DHOOK(0x226A8BC, SFindRoleNameById_getType, _SFindRoleNameById_getType);
    DHOOK(0x226A8C8, SFindRoleNameById_marshal, _SFindRoleNameById_marshal);
    DHOOK(0x226A8FC, SFindRoleNameById_unmarshal, _SFindRoleNameById_unmarshal);
    DHOOK(0x226A930, SFindRoleNameById_marshal2, _SFindRoleNameById_marshal2);
    DHOOK(0x226A968, SFindRoleNameById_unmarshal2, _SFindRoleNameById_unmarshal2);
    //SGetInspectPlayerInfo
    DHOOK(0x226ABB0, SGetInspectPlayerInfo_handle, _SGetInspectPlayerInfo_handle);
    DHOOK(0x226AC24, SGetInspectPlayerInfo_getType, _SGetInspectPlayerInfo_getType);
    DHOOK(0x226AC30, SGetInspectPlayerInfo_marshal, _SGetInspectPlayerInfo_marshal);
    DHOOK(0x226AD30, SGetInspectPlayerInfo_unmarshal, _SGetInspectPlayerInfo_unmarshal);
    DHOOK(0x226AE18, SGetInspectPlayerInfo_marshal2, _SGetInspectPlayerInfo_marshal2);
    DHOOK(0x226AF1C, SGetInspectPlayerInfo_unmarshal2, _SGetInspectPlayerInfo_unmarshal2);
    //SGetInspectPlayerReportList
    DHOOK(0x226B258, SGetInspectPlayerReportList_handle, _SGetInspectPlayerReportList_handle);
    DHOOK(0x226B2CC, SGetInspectPlayerReportList_getType, _SGetInspectPlayerReportList_getType);
    DHOOK(0x226B2D8, SGetInspectPlayerReportList_marshal, _SGetInspectPlayerReportList_marshal);
    DHOOK(0x226B4C8, SGetInspectPlayerReportList_unmarshal, _SGetInspectPlayerReportList_unmarshal);
    DHOOK(0x226B690, SGetInspectPlayerReportList_marshal2, _SGetInspectPlayerReportList_marshal2);
    DHOOK(0x226B884, SGetInspectPlayerReportList_unmarshal2, _SGetInspectPlayerReportList_unmarshal2);
    //SGetInspectStatu
    DHOOK(0x226BC7C, SGetInspectStatu_handle, _SGetInspectStatu_handle);
    DHOOK(0x226BCF0, SGetInspectStatu_getType, _SGetInspectStatu_getType);
    DHOOK(0x226BCFC, SGetInspectStatu_marshal, _SGetInspectStatu_marshal);
    DHOOK(0x226BDC0, SGetInspectStatu_unmarshal, _SGetInspectStatu_unmarshal);
    DHOOK(0x226BE58, SGetInspectStatu_marshal2, _SGetInspectStatu_marshal2);
    DHOOK(0x226BF0C, SGetInspectStatu_unmarshal2, _SGetInspectStatu_unmarshal2);
    //ShenSuType
    DHOOK(0x226C168, ShenSuType_marshal, _ShenSuType_marshal);
    DHOOK(0x226C170, ShenSuType_unmarshal, _ShenSuType_unmarshal);
    DHOOK(0x226C178, ShenSuType_marshal2, _ShenSuType_marshal2);
    DHOOK(0x226C180, ShenSuType_unmarshal2, _ShenSuType_unmarshal2);
    //SInspectPlayerMgs
    DHOOK(0x226C194, SInspectPlayerMgs_handle, _SInspectPlayerMgs_handle);
    DHOOK(0x226C208, SInspectPlayerMgs_getType, _SInspectPlayerMgs_getType);
    DHOOK(0x226C214, SInspectPlayerMgs_marshal, _SInspectPlayerMgs_marshal);
    DHOOK(0x226C250, SInspectPlayerMgs_unmarshal, _SInspectPlayerMgs_unmarshal);
    DHOOK(0x226C284, SInspectPlayerMgs_marshal2, _SInspectPlayerMgs_marshal2);
    DHOOK(0x226C2C4, SInspectPlayerMgs_unmarshal2, _SInspectPlayerMgs_unmarshal2);
    //SReportShenSu
    DHOOK(0x226C4B0, SReportShenSu_marshal, _SReportShenSu_marshal);
    DHOOK(0x226C4E0, SReportShenSu_unmarshal, _SReportShenSu_unmarshal);
    DHOOK(0x226C510, SReportShenSu_marshal2, _SReportShenSu_marshal2);
    DHOOK(0x226C548, SReportShenSu_unmarshal2, _SReportShenSu_unmarshal2);
    
    //CFindRoldeIdByCompetitionName
    /*DHOOK(0x0000000, CFindRoleIdByCompetitionName_handle, _CFindRoleIdByCompetitionName_handle);
    DHOOK(0x0000000, CFindRoleIdByCompetitionName_getType, _CFindRoleIdByCompetitionName_getType);
    DHOOK(0x0000000, CFindRoleIdByCompetitionName_marshal, _CFindRoleIdByCompetitionName_marshal);
    DHOOK(0x0000000, CFindRoleIdByCompetitionName_unmarshal, _CFindRoleIdByCompetitionName_unmarshal);
    DHOOK(0x0000000, CFindRoldeIdByCompetitionName_marshal2, _CFindRoldeIdByCompetitionName_marshal2);
    DHOOK(0x0000000, CFindRoldeIdByCompetitionName_unmarshal2, _CFindRoldeIdByCompetitionName_unmarshal2);*/
    
    hexPatches.VIRT = MemoryPatch::createWithHex(LIBA, 0x19BEED, OBFUSCATE("00 00 00 00"));
    hexPatches.ROOT = MemoryPatch::createWithHex(LIBA, 0x19C9ED, OBFUSCATE("00 00 00 00"));
    hexPatches.GG = MemoryPatch::createWithHex(LIBA, 0x19BAC6, OBFUSCATE("00 00 00 00"));
    hexPatches.EMULATOR = MemoryPatch::createWithHex(LIBA, 0x19B551, OBFUSCATE("00 00 00 00"));
    
    //class CheatMgr
    hexPatches.BP1 = MemoryPatch::createWithHex(LIB, 0x1B8094C, BOOL);

    //class PlayerController 
    hexPatches.BP2 = MemoryPatch::createWithHex(LIB, 0x1B2E928, RET);//CheckGround
    hexPatches.BP3 = MemoryPatch::createWithHex(LIB, 0x1B35A98, RET);//CheckGroundDistance
    hexPatches.BP4 = MemoryPatch::createWithHex(LIB, 0x1B36DD8, FLOAT999999999);//GetFootGroundDis
    hexPatches.BP5 = MemoryPatch::createWithHex(LIB, 0x1B2F95C, RET);//CheckUnderGround
    hexPatches.BP6 = MemoryPatch::createWithHex(LIB, 0x1B371EC, BOOL);//IgnoreGroundBuilding
    hexPatches.BP7 = MemoryPatch::createWithHex(LIB, 0x1B2F128, BOOL);//CheckCanMoveUp
    hexPatches.BP8 = MemoryPatch::createWithHex(LIB, 0x1B38068, RET);//CheckSyncPos
    hexPatches.BP9 = MemoryPatch::createWithHex(LIB, 0x1B381A8, BOOL);//IsCommunityServer
    hexPatches.BP10 = MemoryPatch::createWithHex(LIB, 0x1B382A8, RET);//CheckContinueKillNum
    hexPatches.BP11 = MemoryPatch::createWithHex(LIB, 0x1B383B0, RET);//CheckFar300KillNum
    //hexPatches.BP12 = MemoryPatch::createWithHex(LIB, 0x1B373FC, RET);//SyncMoveStatus
    hexPatches.BP13 = MemoryPatch::createWithHex(LIB, 0x1B3BC84, RET);//CheckBulletThroughWall
    hexPatches.BP14 = MemoryPatch::createWithHex(LIB, 0x1B3CC14, BOOL);//CheckCanUseItem
    hexPatches.BP15 = MemoryPatch::createWithHex(LIB, 0x1B3E068, BOOL);//CheckCanFly
    hexPatches.BP16 = MemoryPatch::createWithHex(LIB, 0x1B3F760, RET);//CheckCamera
    hexPatches.BP17 = MemoryPatch::createWithHex(LIB, 0x1B3FA78, RET);//CheckFly
    hexPatches.BP18 = MemoryPatch::createWithHex(LIB, 0x1B2F284, FALSE);//CheckthroughWall
    hexPatches.BP19 = MemoryPatch::createWithHex(LIB, 0x1B40210, RET);//CheckAnimOverSpeed
    hexPatches.BP20 = MemoryPatch::createWithHex(LIB, 0x1B40418, RET);//CheckTianXian
    
    //class MailMgr
    hexPatches.BP21 = MemoryPatch::createWithHex(LIB, 0x19EAC48, RET);//OnCheatIntError
    //hexPatches.BP64 = MemoryPatch::createWithHex(LIB, 0x171FF88, RET);//SendCheatNumDic
    hexPatches.BP22 = MemoryPatch::createWithHex(LIB, 0x19EB070, RET);//OnCheatFloatError
    hexPatches.BP23 = MemoryPatch::createWithHex(LIB, 0x19EB228, RET);//CheckUnderGround
    hexPatches.BP24 = MemoryPatch::createWithHex(LIB, 0x19EBE70, RET);//CheckCamera
    hexPatches.BP25 = MemoryPatch::createWithHex(LIB, 0x19EC064, RET);//CheckFly
    hexPatches.BP26 = MemoryPatch::createWithHex(LIB, 0x19EC838, RET);//CheckZuobi
    hexPatches.BP27 = MemoryPatch::createWithHex(LIB, 0x19ECDF8, RET);//CheckAnimOverSpeed
    hexPatches.BP28 = MemoryPatch::createWithHex(LIB, 0x19ECF90, RET);//CheckThrougthWall
    hexPatches.BP29 = MemoryPatch::createWithHex(LIB, 0x19EC2C8, RET);//Dosome
    hexPatches.BP30 = MemoryPatch::createWithHex(LIB, 0x19ED5C0, RET);//CheckMsgToSend
    hexPatches.BP41 = MemoryPatch::createWithHex(LIB, 0x19EDF40, RET);//CheckMainFunsNotMsg
    hexPatches.BP42 = MemoryPatch::createWithHex(LIB, 0x19EE1C4, RET);//CheckHeartLive
    
    //class Battle
    hexPatches.Soul = MemoryPatch::createWithHex(LIB, 0x1CCB1DC, RET);//OnSServerPullBack
	Tools::Hook(Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("Battle"), OBFUSCATE("Update"), 0), (void *) &Battle_Update, (void **) &_Battle_Update);
   
    //class MonsterController
    hexPatches.Stop = MemoryPatch::createWithHex(LIB, 0x1A71720, RET);//StartController
    
    //class BombMgr
    hexPatches.Splash = MemoryPatch::createWithHex(LIB, 0x1FD60C0, BOOL);//CheckNoBlock
    
    //class SwimState
    hexPatches.Swim = MemoryPatch::createWithHex(LIB, 0x1AD5C8C, RET); //CheckSwim
    //class PartBehaviour
    hexPatches.PR1 = MemoryPatch::createWithHex(LIB, 0xAD8DFC, BOOL); //public bool get_AllowOp() { }
    //bool skip
    //bool skip
    hexPatches.PR2 = MemoryPatch::createWithHex(LIB, 0xAD9204, BOOL); //public bool get_HavePermit() { }
    hexPatches.PR3 = MemoryPatch::createWithHex(LIB, 0xAD9324, BOOL); //public bool CanUpdate() { }
    hexPatches.PR4 = MemoryPatch::createWithHex(LIB, 0xAD97A0, BOOL); //public bool CanBuild() { }
    
    //Fake Owner >> fast find MyEffectInfos >> public class FriendPermitMgr - baz
    hexPatches.FO1 = MemoryPatch::createWithHex(LIB, 0x19A36A4, BOOL); //HavePermit
    hexPatches.FO2 = MemoryPatch::createWithHex(LIB, 0x19A3854, BOOL); //OtherBoxPermit
    hexPatches.FO3 = MemoryPatch::createWithHex(LIB, 0x19A3924, BOOL); //IsVisitor
    hexPatches.FO4 = MemoryPatch::createWithHex(LIB, 0x19A39A8, BOOL); //HavePermitByInstanceId
    
    //class UnionMgr
    hexPatches.UM = MemoryPatch::createWithHex(LIB, 0x1D42A44, BOOL); //IsSameUnion
    //class LandMineMgr
    hexPatches.FB = MemoryPatch::createWithHex(LIB, 0x1FDD110, RET); //GetDelayTime
    
    //class Component
    Methods["Component::get_transform"] = (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("UnityEngine.dll"), OBFUSCATE("UnityEngine"), OBFUSCATE("Component"), OBFUSCATE("get_transform"));
    Methods["Component::get_gameObject"] = (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("UnityEngine.dll"), OBFUSCATE("UnityEngine"), OBFUSCATE("Component"), OBFUSCATE("get_gameObject"));
    //class Transform
    Methods["Transform::get_position"] = (uintptr_t) Il2CppGetMethodOffset(OBFUSCATE("UnityEngine.dll"), OBFUSCATE("UnityEngine"), OBFUSCATE("Transform"), OBFUSCATE("get_position"));
    set_position = (void *(*)(void *, Vector3)) getAbsoluteAddress(LIB, 0x37A4230);
    
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
	DHOOK(0x1B27BB0, PlayerController_OnLandMineEvent, _PlayerController_OnLandMineEvent);
    DHOOK(0x1B43B14, PlayerController_DrinkWater, _PlayerController_DrinkWater);
    //---
   // hit = (void *(*)(...)) getAbsoluteAddress(LIB, 0x1B42E8C);
    
    //---
    GetCurNearweapon = (void *(*)(void *)) getAbsoluteAddress(LIB, 0x1B25E8C);
    SetAutoRunWithDirection = (void *(*)(void *, Vector3)) getAbsoluteAddress(LIB, 0x1B3F14C);
	CloseAutoRun = (void *(*)(void *)) getAbsoluteAddress(LIB, 0x1B3F2D8);
	
    //class vThirdPersonCamera
    SetLockAtPoint = (void *(*)(void *, Vector3)) getAbsoluteAddress(LIB, 0x1367870);
    //class Rigidbody
    set_velocity = (void (*)(void *, Vector3)) getAbsoluteAddress(LIB, 0x380898C);
    set_detectCollisions = (void (*)(void *, bool)) getAbsoluteAddress(LIB, 0x38091F8);
    get_posRigidbody = (Vector3 (*)(void *)) getAbsoluteAddress(LIB, 0x380924C);
    MovePosition = (void (*)(void *, Vector3)) getAbsoluteAddress(LIB, 0x380947C);
	AddForce = (void (*)(void *, Vector3)) getAbsoluteAddress(LIB, 0x3809684);
    AddForceAtPosition = (void (*)(void *, Vector3, Vector3, int)) getAbsoluteAddress(LIB, 0x38098C4);
    
    //class VehicleMonitor 
    Tools::Hook(Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("VehicleMonitor"), OBFUSCATE("FixedUpdate"), 0), (void *) &VehicleMonitor_FixedUpdate, (void **) &_VehicleMonitor_FixedUpdate);
    Tools::Hook(Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("VehicleMonitor"), OBFUSCATE("OnDestroy"), 0), (void *) &VehicleMonitor_OnDestroy, (void **) &_VehicleMonitor_OnDestroy);
    GetVehicleType = (int (*)(void *)) getAbsoluteAddress(LIB, 0xCC54D0);
    //class BulletControl
    Tools::Hook(Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("BulletControl"), OBFUSCATE("FixedUpdate"), 0), (void *) &BulletControl_FixedUpdate, (void **) &_BulletControl_FixedUpdate);
	
    //class HeatMgr
    DHOOK(0x2164438, HeatMgr_CheckNoBlock, _HeatMgr_CheckNoBlock);
    //class BuilderBehaviour
    Tools::Hook(Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("EasyBuildSystem.Runtimes.Internal.Builder"), OBFUSCATE("BuilderBehaviour"), OBFUSCATE("Update"), 0), (void *) &BuilderBehaviour_Update, (void **) &_BuilderBehaviour_Update);
    RotatePreview = (void *(*)(void *, Vector3)) getAbsoluteAddress(LIB, 0xAF88E0);
    //class Gun
    DHOOK(0xEA1298, Gun_DoOneShoot, _Gun_DoOneShoot);
    DHOOK(0xEAC764, Gun_CaulateMoveAimRadius, _Gun_CaulateMoveAimRadius);
    DHOOK(0xEAC8D8, Gun_CaulateShootAimRadius, _Gun_CaulateShootAimRadius);
    DHOOK(0xEACF60, Gun_DoOneShootRecoil, _Gun_DoOneShootRecoil);
    
    //class DayNightSystem
    Tools::Hook(Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("DayNightSystem"), OBFUSCATE("Update"), 0), (void *) &DayNightSystem_Update, (void **) &_DayNightSystem_Update);
    //class TreeObject
    DHOOK(0x1C823D4, TreeObject_AddToScene, _TreeObject_AddToScene);
    //class GrassObject
    DHOOK(0x1C5FCA4, GrassObject_AddToScene, _GrassObject_AddToScene);
    //class ThingsObject
    DHOOK(0x1C804C4, ThingsObject_AddToScene, _ThingsObject_AddToScene);
    //class MechaController
    Tools::Hook(Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE("SC.AssembledSystem"), OBFUSCATE("MechaController"), OBFUSCATE("Update"), 0), (void *) &MechaController_Update, (void **) &_MechaController_Update);
  
    //class MonsterController
    DHOOK(0x1A76B54, MonsterController_Update, _MonsterController_Update);
    Tools::Hook(Il2CppGetMethodOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("MonsterController"), OBFUSCATE("OnDestroy"), 0), (void *) &MonsterController_OnDestroy, (void **) &_MonsterController_OnDestroy);
   
    //DHOOK(0x97E4D8, PartBehaviour_Awake, _PartBehaviour_Awake);
    DHOOK(0x229C6E0, Mine_Init, _Mine_Init);
	
	//class HandAttack
	OnTriggerEnter1 = (void *(*)(void *)) getAbsoluteAddress(LIB, 0x215797C);
	
	//class Behaviour
    get_isActiveAndEnabled = (bool (*)(void *)) getAbsoluteAddress(LIB, 0x378A48C);

	//class BasePlayerController
	FastChangeAnimatorStates = (bool (*)(void *, int, int, bool, float)) getAbsoluteAddress(LIB, 0x1A98338);
    
    get_layer = (int (*)(...)) getAbsoluteAddress(LIB, 0x378B524);
    ShowDecal = (void *(*)(...)) getAbsoluteAddress(LIB, 0x215D65C);
    PlayHitAudio = (void *(*)(...)) getAbsoluteAddress(LIB, 0x215DC00);
    FindObjectFromInstanceId = (void *(*)(...)) getAbsoluteAddress(LIB, 0x378DBD0);
    Raycast = (bool (*)(...)) getAbsoluteAddress(LIB, 0x3804798);
    ScreenPointToRay =  (Ray (*)(...)) getAbsoluteAddress(LIB, 0x1369EE8);
    DHOOK(0x215797C, OnTriggerEnter2, _OnTriggerEnter2);
   
    bInitDone = true;
    pthread_exit(0);
 
}
