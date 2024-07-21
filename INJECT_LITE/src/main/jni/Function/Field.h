typedef void Transform, Animator, CapsuleCollider, GTeamPlayerName, GameObject, SoundControll, PlayerInfo, Coroutine, AnimatorHelper, HoldIK, HeadTrackIK, AimingIK;
struct Game {
public:
    struct MapObject{
        long InsId(void* point){
            return *(long*)((uintptr_t)point + Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("MapObject"), OBFUSCATE("InsId")));
        }
        int CfgId(void* point){
            return *(int*)((uintptr_t)point + Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("MapObject"), OBFUSCATE("CfgId")));
        }
        MonoString *MapObjectName(void *point){
            return *(MonoString**)((uintptr_t)point + Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("MapObject"), OBFUSCATE("MapObjectName")));
        }
        float Hp(void *point){
            return *(float*)((uintptr_t)point + Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("MapObject"), OBFUSCATE("Hp")));
        }
        int MaxHp(void* point){
            return *(int*)((uintptr_t)point + Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("MapObject"), OBFUSCATE("MaxHp")));
        }
		monoList<void *> Renderers(void* point){
            return *(monoList<void *>*)((uintptr_t)point + Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("MapObject"), OBFUSCATE("Renderers")));
        }
    };
    struct BasePlayerController : MapObject{
        Transform *LeftFoot(void* point){
            return *(void**)((uintptr_t)point + Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("BasePlayerController"), OBFUSCATE("LeftFoot")));
        }
        Transform *RightFoot(void* point){
            return *(void**)((uintptr_t)point + Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("BasePlayerController"), OBFUSCATE("RightFoot")));
        }
        Transform *HeadTop(void* point){
            return *(void**)((uintptr_t)point + Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("BasePlayerController"), OBFUSCATE("HeadTop")));
        }

        Transform *HeadBub(void* point){
            return *(void**)((uintptr_t)point + Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("BasePlayerController"), OBFUSCATE("HeadBub")));
        }

        Transform *HeadNameLabel(void* point){
            return *(void**)((uintptr_t)point + Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("BasePlayerController"), OBFUSCATE("HeadNameLabel")));
        }

        Transform *RootBone(void* point){
            return *(void**)((uintptr_t)point + Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("BasePlayerController"), OBFUSCATE("RootBone")));
        }

        Transform *RightHand(void* point){
            return *(void**)((uintptr_t)point + Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("BasePlayerController"), OBFUSCATE("RightHand")));
        }

        Transform *LeftHand(void* point){
            return *(void**)((uintptr_t)point + Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("BasePlayerController"), OBFUSCATE("LeftHand")));
        }

        Transform *NeckBone(void* point){
            return *(void**)((uintptr_t)point + Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("BasePlayerController"), OBFUSCATE("NeckBone")));
        }

        Transform *RightJianbang(void* point){
            return *(void**)((uintptr_t)point + Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("BasePlayerController"), OBFUSCATE("RightJianbang")));
        }

        Transform *RightHandGuaDian(void* point){
            return *(void**)((uintptr_t)point + Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("BasePlayerController"), OBFUSCATE("RightHandGuaDian")));
        }

        Transform *m_GuaDianL1(void* point){
            return *(void**)((uintptr_t)point + Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("BasePlayerController"), OBFUSCATE("m_GuaDianL1")));
        }

        Transform *m_GuaDianL2(void* point){
            return *(void**)((uintptr_t)point + Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("BasePlayerController"), OBFUSCATE("m_GuaDianL2")));
        }

        Transform *m_GuaDianR1(void* point){
            return *(void**)((uintptr_t)point + Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("BasePlayerController"), OBFUSCATE("m_GuaDianR1")));
        }

        Transform *m_GuaDianR2(void* point){
            return *(void**)((uintptr_t)point + Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("BasePlayerController"), OBFUSCATE("m_GuaDianR2")));
        }

        Transform *LeftHandGuaDian(void* point){
            return *(void**)((uintptr_t)point + Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("BasePlayerController"), OBFUSCATE("LeftHandGuaDian")));
        }

        Transform *m_ShouQiangGuaDian(void* point){
            return *(void**)((uintptr_t)point + Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("BasePlayerController"), OBFUSCATE("m_ShouQiangGuaDian")));
        }

        Transform *m_BagGuaDian(void* point){
            return *(void**)((uintptr_t)point + Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("BasePlayerController"), OBFUSCATE("m_BagGuaDian")));
        }

        Transform *m_NearWeaponGuaDian(void* point){
            return *(void**)((uintptr_t)point + Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("BasePlayerController"), OBFUSCATE("m_NearWeaponGuaDian")));
        }
        long RoleId(void *point){
            return *(long*)((uintptr_t)point + Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("BasePlayerController"), OBFUSCATE("RoleId")));
        }
        int HP(void *point){
            return *(int*)((uintptr_t)point + Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("BasePlayerController"), OBFUSCATE("HP")));
        }
        int EP(void *point){
            return *(int*)((uintptr_t)point + Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("BasePlayerController"), OBFUSCATE("EP")));
        }
        int Pulmonary(void *point){
            return *(int*)((uintptr_t)point + Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("BasePlayerController"), OBFUSCATE("Pulmonary")));
        }
        int PulmonaryMax(void *point){
            return *(int*)((uintptr_t)point + Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("BasePlayerController"), OBFUSCATE("PulmonaryMax")));
        }
        bool IsDie(void *point){
            return *(bool*)((uintptr_t)point + Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("BasePlayerController"), OBFUSCATE("IsDie")));
        }
        bool IsDownWaitSave(void *point){
            return *(bool*)((uintptr_t)point + Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("BasePlayerController"), OBFUSCATE("IsDownWaitSave")));
        }
        MonoString *Name(void *point) {
            return *(MonoString**)((uintptr_t)point + Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("BasePlayerController"), OBFUSCATE("Name")));
        }
        bool IsMale(void *point){
            return *(bool*)((uintptr_t)point + Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("BasePlayerController"), OBFUSCATE("IsMale")));
        }
        GTeamPlayerName *NameLabel(void *point){ }
        GameObject *QuickChatLabel(void *point){ }
        SoundControll *SoundControll(void *point){ }
        PlayerInfo *m_PlayerInfo(void *point){ }
        bool NewPlayer(void *point){
            return *(bool*)((uintptr_t)point + Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("BasePlayerController"), OBFUSCATE("NewPlayer")));
        }
        Transform *GliderPoint(void* point){
            return *(void**)((uintptr_t)point + Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("BasePlayerController"), OBFUSCATE("GliderPoint")));
        }
        Transform *ArrowPointStand(void* point){
            return *(void**)((uintptr_t)point + Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("BasePlayerController"), OBFUSCATE("ArrowPointStand")));
        }
        Transform *ArrowPointPa(void* point){
            return *(void**)((uintptr_t)point + Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("BasePlayerController"), OBFUSCATE("ArrowPointPa")));
        }
        GameObject *GliderGo(void *point){ }
        Animator *GliderAnimator(void* point){ }
        Transform *JetPoint(void* point) {
            return *(void**)((uintptr_t)point + Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("BasePlayerController"), OBFUSCATE("JetPoint")));
        }
        GameObject *JetGo(void *point){ }
        bool AutoCut(void *point) {
            return *(bool*)((uintptr_t)point + Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("BasePlayerController"), OBFUSCATE("AutoCut")));
        }
        Vector2 stepUV(void *point){ }
        //int <PlayerInStealth>k__BackingField(void *point){ }
        int stealthGrassID(void *point){
            return *(int*)((uintptr_t)point + Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("BasePlayerController"), OBFUSCATE("stealthGrassID")));
        }
        int VipLevel(void *point){
            return *(int*)((uintptr_t)point + Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("BasePlayerController"), OBFUSCATE("VipLevel")));
        }
        GameObject *TuzhiGo(void *point){ }
        long VehicleId(void *point){
            return *(long*)((uintptr_t)point + Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("BasePlayerController"), OBFUSCATE("VehicleId")));
        }
        GameObject *m_San(void *point){ }
        GameObject *m_SanBag(void *point){ }
        bool m_SanOpened(void *point){ }
        bool m_SanDestroyed(void *point){ }
        bool m_Landed(void *point){ }
        bool Tanshen(void *point) {
            return *(bool*)((uintptr_t)point + Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("BasePlayerController"), OBFUSCATE("Tanshen")));
        }
        bool InBuilding(void *point){
            return *(bool*)((uintptr_t)point + Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("BasePlayerController"), OBFUSCATE("InBuilding")));
        }
        int FootTexture(void *point){ }
        int LastFootTexture(void *point){ }
        int CurFootSoundId(void *point){
            return *(int*)((uintptr_t)point + Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("BasePlayerController"), OBFUSCATE("CurFootSoundId")));
        }
        monoList<int *> FootStoneSound(void *point){
            *(monoList<int *>*)((uintptr_t)point + Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("BasePlayerController"), OBFUSCATE("FootStoneSound")));
        }
        monoList<int *> FootWoodSound(void *point){
            *(monoList<int *>*)((uintptr_t)point + Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("BasePlayerController"), OBFUSCATE("FootWoodSound")));
        }
        monoList<int *> FootMetalSound(void *point){
            *(monoList<int *>*)((uintptr_t)point + Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("BasePlayerController"), OBFUSCATE("FootMetalSound")));
        }
        monoList<int *> FootWaterSound(void *point){
            *(monoList<int *>*)((uintptr_t)point + Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("BasePlayerController"), OBFUSCATE("FootWaterSound")));
        }
        monoList<int *> FootGroundSound(void *point){
            *(monoList<int *>*)((uintptr_t)point + Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("BasePlayerController"), OBFUSCATE("FootGroundSound")));
        }
        monoList<int *> CurFootSoundList(void *point){
            *(monoList<int *>*)((uintptr_t)point + Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("BasePlayerController"), OBFUSCATE("CurFootSoundList")));
        }
        long ParentInsId(void *point){
            return *(long*)((uintptr_t)point + Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("BasePlayerController"), OBFUSCATE("ParentInsId")));
        }
        const int WuDiEffectId = 901;
        AnimatorHelper *m_animatorHelper(void *point){ }
        monoDictionary<MonoString *, void **> m_bodyColliderName2RadiusDic(void *point){ }
        GameObject *DollBones(void *point){ }
        HoldIK *m_HoldIK(void *point){ }
        HoldIK *m_RightHandHoldIK(void *point){ }
        HeadTrackIK *m_HeadIK(void *point){ }
        AimingIK *m_AimingIK(void *point){ }
        Transform *UpperBodyIK(void* point){
            return *(void**)((uintptr_t)point + Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("BasePlayerController"), OBFUSCATE("UpperBodyIK")));
        }
        Quaternion UpperBodyQuaternion(void* point){
            return *(Quaternion*)((uintptr_t)point + Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("BasePlayerController"), OBFUSCATE("UpperBodyQuaternion")));
        }
        bool _NeedHeadIK(void *point){ }
        bool NeedAimIK(void *point){
            return *(bool*)((uintptr_t)point + Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("BasePlayerController"), OBFUSCATE("NeedAimIK")));
        }
        bool NeedHol(void *point){
            return *(bool*)((uintptr_t)point + Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("BasePlayerController"), OBFUSCATE("NeedHol")));
        }
        int DisableHeadIKFrameCount(void *point){
            return *(int*)((uintptr_t)point + Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("BasePlayerController"), OBFUSCATE("DisableHeadIKFrameCount")));
        }
        Vector3 LookAtPosition(void *point){
            return *(Vector3*)((uintptr_t)point + Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("BasePlayerController"), OBFUSCATE("LookAtPosition")));
        }
        Vector2 m_InputVector(void *point){ }
        float m_Yaw(void *point){
            return *(float*)((uintptr_t)point + Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("BasePlayerController"), OBFUSCATE("m_Yaw")));
        }
    };
    struct MonsterController : MapObject {
		bool CanMove(void* point){
            return *(bool*)((uintptr_t)point + Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("MonsterController"), OBFUSCATE("CanMove")));
        }
	};
};

