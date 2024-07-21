void *Enemy, *Player, *EnemyPlayer, *Monster, *Vehicle, *Mine;
struct ESPConfig{
    bool ESP;
    bool ESPLine;
    bool ESPBox;
    bool ESPName;
    bool ESPHealth;
    bool ESPCount;
    bool ESPSkeleton;
    bool ESPDistance;
    bool ESPGunName;
    bool FOV;
    bool BulletLine;
    int MAX_ENEMY = 99;
    int textPositionMode;
    
    bool info;
    float ESPLineRotation;
    ImVec4 ESPLineColor = ImVec4(1.0f, 0.6f, 0.0f, 1.0f);
    ImVec4 ESPLineColorOnline = ImVec4(1.0f, 0.0f, 0.0f, 1.0f);
    ImVec4 ESPBoxColor = ImVec4(1.0f, 0.6f, 0.0f, 0.5f);
    ImVec4 ESPBoxColorOnline = ImVec4(1.0f, 0.0f, 0.0f, 0.5f);
    ImVec4 ESPNameColor = ImVec4(0.8f, 0.8f, 0.8f, 1.0f);
    ImVec4 ESPHealthColor = ImVec4(0.f, 0.f, 0.f, 1.0f);
    ImVec4 ESPCountColor = ImVec4(0.631f, 0.58f, 0.188f, 1.f);
    ImVec4 ESPSkeletonColor = ImVec4(1.0f, 0.0f, 0.0f, 0.7f);
    ImVec4 ESPDistanceColor = ImVec4(1.0f, 0.6f, 0.0f, 1.0f);
    ImVec4 ESPGunNameColor = ImVec4(1.0f, 0.6f, 0.0f, 1.0f);

    bool ESPDistanceMonster;
    bool ESPNameMonster;
    bool ESPHealthMonster;
    ImVec4 ESPMonsterNameColor = ImVec4(0.8f, 0.8f, 0.8f, 1.0f);
    ImVec4 ESPMonsterHealthColor = ImVec4(0.f, 0.f, 0.f, 1.0f);
    ImVec4 ESPMonsterDistanceColor = ImVec4(1.0f, 0.6f, 0.0f, 1.0f);
    
    bool ESPVehicleDistance;
    bool ESPVehicleLine;
    bool ESPVehicleName;
    ImVec4 ESPVehicleDistanceColor = ImVec4(1.0f, 0.6f, 0.0f, 1.0f);
    ImVec4 ESPVehicleLineColor = ImVec4(1.0f, 0.0f, 0.0f, 1.0f);
    ImVec4 ESPVehicleNameColor = ImVec4(0.8f, 0.8f, 0.8f, 1.0f);
    
    bool Stone;
    bool Sulfur;
    bool Titan;
    bool Iron;
    bool ESPMineLine;
    bool ESPMineName;
    bool ESPMineDistance;
    ImVec4 ESPMineLineColor = ImVec4(1.0f, 0.0f, 0.0f, 1.0f);
    ImVec4 ESPMineNameColor = ImVec4(0.8f, 0.8f, 0.8f, 1.0f);
    ImVec4 ESPMineDistanceColor = ImVec4(1.0f, 0.6f, 0.0f, 1.0f);
    
} ESPVar;

struct PlayerController{
    bool Sticky;
    float Force;
    float Speed;
    int UP;
    bool FLY;
    int DOWN;
    bool Collision;
    float FlySpeed = 0.5f;
    float Height = 0.5f;
    bool Drink;
    bool FastHit;
    bool AutoFarm;
	bool AimBot;
	bool NoShake;
	bool Animator;
	int Mode;
	int StateID;
} MyPlayerData;

struct BulletControl{
    bool bullet; 
} BulletData;

struct ObjectData{
    bool tree, grass, things;
} Texture;

struct Battle{
    bool Soul;
} BattleData;

struct BuilderBehaviour{
    bool ForceBuild;
    float x, y, z;
} BuilderData;

struct HeatMgr {
    bool Splash;
} HeatData;

struct Gun{
    bool FastShoot;
    int ShootNumber;
    bool NoRecoil;
} GunData;

struct MonsterController {
    bool StopMonster;
} MonsterData;

struct MechaController {
    bool Collision;
} MechaData;

struct VehicleMonitor {
	bool Fly;
	float Speed;
	float Height = 1.f;
	float Force;
} VehicleData;
