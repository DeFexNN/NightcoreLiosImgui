bool test, test2, test3;
void (*_MonsterController_Update)(void *monster);
void MonsterController_Update(void *monster){
	if (monster != NULL) {
        for (int i = 0; i < monsters.size(); i++){
            Monster = monsters[i];
        }
		
		if(MonsterData.StopMonster){
			*(bool*)((uintptr_t)monster + Il2CppGetFieldOffset(OBFUSCATE("Assembly-CSharp.dll"), OBFUSCATE(""), OBFUSCATE("MonsterController"), OBFUSCATE("CanMove"))) = false;
        }
        if (!monsterFind(monster)) monsters.push_back(monster);
        if (monsters.size() > 99) {
            monsters.clear();
        }
    }
    _MonsterController_Update(monster);
}

int MonsterID(void *monster){
    void *point = *(void**)((uint64_t)monster + 0x48);
    if(point != 0){
        return *(int*)((uint64_t)point + 0x8);
    }
    
}
float MonsterHP(void *monster){    
        return *(float*)((uint64_t)monster + 0x20);   
}
void (*_MonsterController_OnDestroy)(void *monster);
void MonsterController_OnDestroy(void *monster) {
    if (monster != NULL) {
        monsters.clear();
    }
    _MonsterController_OnDestroy(monster);
}


void (*_OtherPlayerController_Update)(void *player);
void OtherPlayerController_Update(void* player){
    if (player != NULL) {
        for (int i = 0; i < players.size(); i++){
            Enemy = players[i];
        }
        if (!playerFind(player)) players.push_back(player);
        if (players.size() > ESPVar.MAX_ENEMY) {
            players.clear();
        }
		
    }
    _OtherPlayerController_Update(player);
}

void (*_OtherPlayerController_OnDestroy)(void *player);
void OtherPlayerController_OnDestroy(void *player) {
    if (player != NULL) {
        players.clear();
    }
    _OtherPlayerController_OnDestroy(player);
}

MonoString *GetPlayerNick(void *player){
    void *PlayerNames = *(void**) ((uint64_t) player + 0x254);
    if(PlayerNames){
        return *(MonoString**) ((uint64_t) PlayerNames + 0x20);
    }
}

bool Offline(void *player) {
    void *PlayerInfos = *(void**) ((uint64_t) player + 0x254);
    if (PlayerInfos) {
        return *(bool*) ((uint64_t) PlayerInfos + 0x7e);
    }
}

int GetCurrentWeaponID(void* player) {
    return *(int*)((uintptr_t)player + 0x1F0);
}

float AimFov = 200.0f;
bool isFov(Vector2 vec1, Vector2 vec2, float radius) {
    int x = vec1.X;
    int y = vec1.Y;
    int x0 = vec2.X;
    int y0 = vec2.Y;
    if ((pow(x - x0, 2) + pow(y - y0, 2)) <= pow(radius, 2)) {
        return true;
    } else {
        return false;
    }
}



bool (*get_isActiveAndEnabled)(void *point);
void (*_Mine_Init)(void *mine, int itemId);
void Mine_Init(void *mine, int itemId){
    if (mine != NULL) {
        for (int i = 0; i < mines.size(); i++){
            Mine = mines[i];
        }
        if (!mineFind(mine)) mines.push_back(mine);
        if (mines.size() > 99) {
            mines.clear();
        }
        if(!get_isActiveAndEnabled(mine)){
            mines.clear();
        }
    }
    _Mine_Init(mine, itemId);
}

int MineID(void *mine){
    void *point = *(void**)((uint64_t)mine + 0x30);
    if(point != 0){
        return *(int*)((uint64_t)point + 0x8);
    }
}

int CustomBone = 0;
void* GetPlayerHead(void* player) {
    
    if(CustomBone == 0){
        return *(void**)((uintptr_t)player + 0x4c);
    } else if(CustomBone == 1){
        return *(void**)((uintptr_t)player + 0x58);
    } 
}


float getDistanceToPlayer(Vector3 myPos, Vector3 playerPos) {
    return DrawAddLine::get_3D_Distance(myPos.x, myPos.y, myPos.z, playerPos.x, playerPos.y, playerPos.z);
}

int bulletType;
Vector3 getLockPosition(void* enemy, void* player) {
    Game::BasePlayerController BPC;
    if (enemy == nullptr || player == nullptr) {
        return Vector3(0.f, 0.f, 0.f);
    }
    
    Vector3 playerPos = GetPosition(Enemy);
    Vector3 myPos = GetPosition(Player);
    
    float distanceFov = getDistanceToPlayer(myPos, playerPos);
    
    Vector3 headPos = get_position(BPC.HeadTop(Enemy));
    Vector3 bodyPos = get_position(BPC.RootBone(Enemy));
    Vector3 footPos = get_position(BPC.RightFoot(Enemy));
    
    Vector3 Head = Vector3(headPos.x, headPos.y, headPos.z);
    Vector3 Body = Vector3(bodyPos.x, bodyPos.y, bodyPos.z);
    Vector3 Foot = Vector3(footPos.x, footPos.y, footPos.z);
    
    if (distanceFov < 500.f) {
        if (bulletType == 0) {
            srand(static_cast<unsigned int>(std::chrono::steady_clock::now().time_since_epoch().count()));
            int randomIndex = rand() % 3;
            if (randomIndex == 0) {
                return Head;
            } else if (randomIndex == 1) {
                return Body;
            } else if (randomIndex == 2) {
                return Foot;
            }
            
        } else if (bulletType == 1) {
            return Head;
        } else if (bulletType == 2) {
            return Body;
        } else if (bulletType == 3) {
            return Foot;
        }
    }
    
    return Vector3(0.f, 0.f, 0.f);
}

int getNearPlayer(void* enemy, void* player) {
    Game::BasePlayerController BPC;
    int closestEnemyIndex = -1;
    float shortDistance = std::numeric_limits<float>::max();

    for (int i = 0; i < players.size(); i++) {
        enemy = players[i];
        if (enemy != nullptr && get_main() != nullptr && BPC.HP(Enemy) != 0) {
            Vector3 playerPos = GetPosition(enemy);
            Vector3 myPos = GetPosition(player);

            Vector3 lockPos = WorldToScreen(playerPos);
            if (lockPos.z < 1.f) continue;

            float distTo = getDistanceToPlayer(myPos, playerPos);
            
            bool isFov1 = isFov(Vector2(lockPos.x, lockPos.y), Vector2(glWidth / 2, glHeight / 2), AimFov);
            
            if (distTo < 500.0f) {
                if (isFov1 && distTo < shortDistance) {
                    shortDistance = distTo;
                    closestEnemyIndex = i;
                }
            }
        }
    }

    return closestEnemyIndex;
}


float getDistanceToCenter(Vector2 point, Vector2 center) {
    return sqrt(pow(point.X - center.X, 2) + pow(point.Y - center.Y, 2));
}
Vector3 getClosestPlayerPositionToCenter(std::vector<void*>& players, void* player) {
    Game::BasePlayerController BPC;
    Vector3 myPos = GetPosition(player);
    float minDistance = std::numeric_limits<float>::max();
    Vector3 closestPlayerPos;
    
    for (void* currentEnemy : players) {
        if (currentEnemy != nullptr && get_main() != nullptr && BPC.HP(currentEnemy) != 0) {
            Vector3 playerPos = get_position(GetPlayerHead(currentEnemy));
            Vector3 lockPos = WorldToScreen(playerPos);

            if (lockPos.z >= 1.f) {  // Гравець в фові
                float distToCenter = getDistanceToCenter(Vector2(lockPos.x, lockPos.y), Vector2(glWidth / 2, glHeight / 2));
                if (distToCenter < minDistance) {
                    minDistance = distToCenter;
                    closestPlayerPos = playerPos;
                }
            }
        }
    }

    return closestPlayerPos;
}

bool flymenu;
float windowPosX = 0.f;
float windowPosY = 0.f;
ImVec2 WindowPos = ImVec2(windowPosX, windowPosY);
const char* text = OBFUSCATE("ON\nSOUL");
const char* text2 = OBFUSCATE("UP");
const char* text3 = OBFUSCATE("ON");
const char* text4 = OBFUSCATE("DOWN");
const char* text5 = OBFUSCATE("ON\nNO\nCLIP");
bool isUpButtonHeld = false;
bool isDownButtonHeld = false;
int FORCEEEEE;
float currentFlyHeight = 0.0f;
int UpFly = 1;
int UpCar = 0;
bool vehiclemenu;
int desiredHeight = 200;
float windowPosX2 = 0.f;
float windowPosY2 = 0.f;
const char* testb3 = OBFUSCATE("OPEN");
void MenuFly() {
    if(flymenu){
        ImGuiIO& io = ImGui::GetIO();
        ImVec2 windowSize = io.DisplaySize;
        ImVec2 buttonSize = ImVec2(80, 80);
        ImVec2 buttonPos(windowSize.x - buttonSize.x - 10, windowSize.y / 2 - buttonSize.y - 10);
        ImGui::PushStyleVar(ImGuiStyleVar_Alpha, 0.4f); // Adjust transparency (0.0 - fully transparent, 1.0 - fully opaque)


        ImVec4 normalColor = ImGui::GetStyleColorVec4(ImGuiCol_Button);
        ImVec4 pressedColor = ImVec4(0.5f, 0.5f, 0.5f, 1.0f); // Adjust pressed color
        ImGui::PushStyleColor(ImGuiCol_Button, normalColor);
        ImGui::PushStyleColor(ImGuiCol_ButtonActive, pressedColor);

        ImGui::SetNextWindowPos(WindowPos);
        ImGui::SetNextWindowSize(ImVec2(400, 460));
        ImGui::Begin(OBFUSCATE("#FLYMENU"), nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoBackground);
        if (ImGui::Button(text, buttonSize)) {
            BattleData.Soul = !BattleData.Soul;
        }
        text = BattleData.Soul ? OBFUSCATE("OFF\nSOUL") : OBFUSCATE("ON\nSOUL");
        if(BattleData.Soul){
            hexPatches.Soul.Modify();
        } else {
            hexPatches.Soul.Restore();
        }
        if (ImGui::Button(text2, buttonSize)) {
            UpFly = 0;
        } else if (ImGui::IsItemActive()) {
            UpFly = 1;
        }
        
        if(vehiclemenu){
            ImGui::SameLine();
            if (ImGui::Button(OBFUSCATE("UP2"), buttonSize)) {
                UpCar = 0;
            } else if (ImGui::IsItemActive()) {
                desiredHeight += VehicleData.Height;
            }
        }
        if (ImGui::Button(text3, buttonSize)) {
            MyPlayerData.FLY = !MyPlayerData.FLY;
        }
        text3 = MyPlayerData.FLY ? OBFUSCATE("OFF") : OBFUSCATE("ON");
        
        if(vehiclemenu){
            ImGui::SameLine();
            if (ImGui::Button(testb3, buttonSize)) {
                VehicleData.Fly = !VehicleData.Fly;
            }
            testb3 = VehicleData.Fly ? OBFUSCATE("CLOSE") : OBFUSCATE("OPEN");
        }
        if (ImGui::Button(text4, buttonSize)) {
            UpFly = 0;
        } else if (ImGui::IsItemActive()) {
            UpFly = 2;
        }
        
        if(vehiclemenu){
            ImGui::SameLine();
            if (ImGui::Button(OBFUSCATE("DOWN2"), buttonSize)) {
                UpCar = 0;
            } else if (ImGui::IsItemActive()) {
                desiredHeight -= VehicleData.Height;
            }
        }
        if (ImGui::Button(text5, buttonSize)) {
            MyPlayerData.Collision = !MyPlayerData.Collision;
        }
        text5 = MyPlayerData.Collision ? OBFUSCATE("OFF\nNO\nCLIP") : OBFUSCATE("ON\nNO\nCLIP");
        ImGui::PopStyleColor(2);
        ImGui::PopStyleVar();
    }
    ImGui::End();
    
}


void (*_PlayerController_DrinkWater)(void *point);
void PlayerController_DrinkWater(void *point){ }

void (*_PlayerController_OnLandMineEvent)(void *point, Vector3 value);
void PlayerController_OnLandMineEvent(void *point, Vector3 value){
	if(!MyPlayerData.NoShake){
		_PlayerController_OnLandMineEvent(point, value);
	}
}

bool saveFlyH = false;
float savedHeight = 0.0f;

void HandleFlight(void *m_Rigidbody) {
    Vector3 MyPos = get_posRigidbody(m_Rigidbody);
    if (MyPlayerData.FLY) {
        set_velocity(m_Rigidbody, Vector3(MyPlayerData.FlySpeed, MyPlayerData.FlySpeed, MyPlayerData.FlySpeed));

        if (UpFly == 1) {
            MovePosition(m_Rigidbody, Vector3(MyPos.x, MyPos.y + MyPlayerData.Height, MyPos.z));
			saveFlyH = false;
        } else if (UpFly == 2) {
            MovePosition(m_Rigidbody, Vector3(MyPos.x, MyPos.y - MyPlayerData.Height, MyPos.z));
			saveFlyH = false;
        } else if (UpFly == 0) {
            if (!saveFlyH) {
                savedHeight = MyPos.y; // Сохраняем высоту только один раз
                saveFlyH = true;
            }
            MovePosition(m_Rigidbody, Vector3(MyPos.x, savedHeight, MyPos.z)); // Используем сохраненную высоту для перемещения
        }
    } else {
        saveFlyH = false; // Сбрасываем флаг, когда персонаж перестает летать
    }
}





int itemid;
vector<Vector3> startPositions;
void *(*SetLockAtPoint)(void *point, Vector3 pos);
void *(*SetAutoRunWithDirection)(void *point, Vector3 direction);
void *(*CloseAutoRun)(void *point);
void *(*GetCurNearweapon)(void *point);
void *(*OnTriggerEnter1)(void *point);
bool (*FastChangeAnimatorStates)(void *, int layer, int stateHash, bool allowReplay, float normalizedTime);


void (*_PlayerController_Update)(void *myplayer);
void PlayerController_Update(void* myplayer){
    if (myplayer != NULL){
        for (int i = 0; i < myplayers.size(); i++){
            Player = myplayers[i];
        }
        if (!myplayerFind(myplayer)) myplayers.push_back(myplayer);
        if (myplayers.size() > ESPVar.MAX_ENEMY) {
            myplayers.clear();
        }
        void *m_Rigidbody = *(void **)((uint64_t)myplayer + 0x2A0);
        if(MyPlayerData.Collision){
            set_detectCollisions(m_Rigidbody, false);
        } else {
            set_detectCollisions(m_Rigidbody, true);
        }
        
        if(MyPlayerData.Drink){
            _PlayerController_DrinkWater(myplayer);
            MyPlayerData.Drink = false;
        }
		HandleFlight(m_Rigidbody);
       
        void *NearWeapon = GetCurNearweapon(myplayer);
		if(NearWeapon != 0){
			itemid = *(int*) ((uint64_t)NearWeapon + 0x68);
		}
		if(MyPlayerData.Animator){
			FastChangeAnimatorStates(myplayer, 0, MyPlayerData.StateID, true, 0.f);
		}
        if (MyPlayerData.FastHit) {
			if(NearWeapon != 0){
				void *HandAttack = *(void **)((uint64_t)NearWeapon + 0x64);
				OnTriggerEnter1(HandAttack);
			}
		}
		if(test){
            
		} 
		void *vThirdPersonCamera = *(void**)((long)myplayer + 0x220);
		if(MyPlayerData.AutoFarm){
    		if(itemid == 55001);
    		else if(itemid == 55002);
    		else if(itemid == 55003);
    		float closestDistance = std::numeric_limits<float>::max(); // Инициализируем переменную для хранения расстояния до ближайшего объекта
    		void* closestMine = nullptr; // Инициализируем переменную для хранения указателя на ближайший объект
			
			
    		for (int i = 0; i < mines.size(); i++) {
        		Mine = mines[i];
        		Game::MapObject MO;
        		Vector3 MyPos = GetPosition(Player);
        		Vector3 MinePos = GetPosition(Mine);
        		float DistanceTo = DrawAddLine::get_3D_Distance(MinePos.x, MinePos.y, MinePos.z, MyPos.x, MyPos.y, MyPos.z);
        		startPositions.push_back(MyPos);
        		int ID = MineID(Mine);
        		if ((ID == 10001 && ESPVar.Stone) || (ID == 10003 && ESPVar.Sulfur) ||
            		(ID == 10011 && ESPVar.Titan) || (ID == 10005 && ESPVar.Iron)) {
            		if(Mine != 0 && NearWeapon != 0 && get_isActiveAndEnabled(Mine) != 0){
                		if(DistanceTo > 2.f && DistanceTo < closestDistance){ // Добавляем проверку на расстояние до объекта
                    	closestDistance = DistanceTo; // Обновляем ближайшее расстояние
                    	closestMine = Mine; // Обновляем указатель на ближайший объект
                	}
            	}
        	}
    	}
		void *HandAttack = *(void **)((uint64_t)NearWeapon + 0x64);
    	if(closestMine != nullptr){ // Проверяем, что найден ближайший объект
        	Vector3 MyPos = GetPosition(Player);
        	Vector3 MinePos = GetPosition(closestMine);
        	float DistanceTo = DrawAddLine::get_3D_Distance(MinePos.x, MinePos.y, MinePos.z, MyPos.x, MyPos.y, MyPos.z);
        	if(DistanceTo > 2.f){
            	Vector3 newDir = MinePos - MyPos;
            	SetAutoRunWithDirection(myplayer, newDir);
            	SetLockAtPoint(vThirdPersonCamera, MinePos);
            	MonsterData.StopMonster = true;
				if(DistanceTo < 2.1f){
					OnTriggerEnter1(HandAttack);
					CloseAutoRun(myplayer);
				}
        	} else if(!mines.empty()){
            	//MonsterData.StopMonster = false;
				Vector3 startPos = MyPos - startPositions[0];

				SetAutoRunWithDirection(myplayer, startPos);
				mines.clear();
        	}
	    }
	}

		Game::BasePlayerController BPC;
        if(MyPlayerData.AimBot && myplayer != 0){
        	int nearestEnemyIndex = getNearPlayer(Enemy, Player);
        	if (nearestEnemyIndex != -1) {
            	void *nearestEnemy = players[nearestEnemyIndex];
            	if(nearestEnemy != 0 && get_main != 0 && BPC.HP(Enemy) != 0){
                	Vector3 closestPlayerPos = getClosestPlayerPositionToCenter(players, Player);
                	SetLockAtPoint(vThirdPersonCamera, closestPlayerPos);
            	}
        	} 
    	}	
        if(MyPlayerData.Sticky){
            for (const auto& player : players) {
                bool foundPlayerInFov = false;
                Vector3 PlayerPos = get_posRigidbody(m_Rigidbody);
                Vector3 EnemyPos = GetPosition(player);
                Vector3 toEnemyDirection = EnemyPos - PlayerPos;
            
                toEnemyDirection = Vector3::Normalized(toEnemyDirection);
                auto justPos = WorldToScreen(EnemyPos);
                bool isPlayerInFov = isFov(Vector2(justPos.x, justPos.y), Vector2(glWidth / 2, glHeight / 2), AimFov);

                if (isPlayerInFov) {
                    foundPlayerInFov = true;
                    AddForceAtPosition(m_Rigidbody, toEnemyDirection * MyPlayerData.Force, Vector3(0, 0, 0), FORCEEEEE);
                    float movementSpeed = MyPlayerData.Speed;
                    set_velocity(m_Rigidbody, toEnemyDirection * movementSpeed);
                    set_detectCollisions(m_Rigidbody, false);
                    break;
                }
                if(!foundPlayerInFov){
                    set_detectCollisions(m_Rigidbody, true);
                }
            }
        }
    }
    return _PlayerController_Update(myplayer);
}

void (*_PlayerController_OnDestroy)(void *player);
void PlayerController_OnDestroy(void *player){
    if(player != 0){
        _PlayerController_OnDestroy(player);
    }
}

void (*_BulletControl_FixedUpdate)(void *pointer);
void BulletControl_FixedUpdate(void *pointer) {
    Game::BasePlayerController BPC;
    if(BulletData.bullet && pointer != 0){
        int nearestEnemyIndex = getNearPlayer(Enemy, Player);
        if (nearestEnemyIndex != -1) {
            void *nearestEnemy = players[nearestEnemyIndex];
            if(nearestEnemy != 0 && get_main != 0 && BPC.HP(Enemy) != 0){
                Vector3 closestPlayerPos = getClosestPlayerPositionToCenter(players, Player);
                set_position(get_transform(pointer),Vector3(closestPlayerPos.x, closestPlayerPos.y, closestPlayerPos.z));
               
            }
        } 
    }
    _BulletControl_FixedUpdate(pointer);
}

static float RotateY;
void *(*RotatePreview)(void *point, Vector3 pos);
void (*_BuilderBehaviour_Update)(void *build);
void BuilderBehaviour_Update(void *build){
    if(BuilderData.ForceBuild && build != 0){
        *(int*)((uint64_t)build + 0x14) = 0;
        RotatePreview(build, Vector3(BuilderData.x, RotateY, BuilderData.z));
    }
    _BuilderBehaviour_Update(build);
}

bool (*_HeatMgr_CheckNoBlock)(void *point, Vector3 pos);
bool HeatMgr_CheckNoBlock(void *point, Vector3 pos){
    if(HeatData.Splash && point != 0){
        return true;
    } else {
        return false;
        _HeatMgr_CheckNoBlock(point, pos);
    }
}

void (*_DayNightSystem_Update)(void *point);
void DayNightSystem_Update(void *point){ }

void (*_MechaController_Update)(void *point);
void MechaController_Update(void *point){
    void *rigid = *(void**)((uint64_t)point + 0x1C);
    if(MechaData.Collision && point != 0){
        set_detectCollisions(rigid, false);
    } else {
        set_detectCollisions(rigid, true);
    }
    _MechaController_Update(point);
}

void (*_VehicleMonitor_FixedUpdate)(void *vehicle);
void VehicleMonitor_FixedUpdate(void *vehicle){
    if (vehicle != NULL) {
        for (int i = 0; i < vehicles.size(); i++){
            Vehicle = vehicles[i];
        }
        if (!vehicleFind(vehicle)) vehicles.push_back(vehicle);
        if (vehicles.size() > ESPVar.MAX_ENEMY) {
            vehicles.clear();
        }
		if(VehicleData.Fly){
			void *SelfRigidbody = *(void**)((uint64_t)vehicle + 0x3C);
			Vector3 VehiclePos = get_posRigidbody(SelfRigidbody);
			Vector3 EnemyPos = GetPosition(Enemy);
			Vector3 toEnemyDirection = EnemyPos - VehiclePos;
            toEnemyDirection = Vector3::Normalized(toEnemyDirection);
			bool foundPlayerInFov = false;
			auto justPos = WorldToScreen(EnemyPos);
			for (const auto& player : players){
				bool isPlayerInFov = isFov(Vector2(justPos.x, justPos.y), Vector2(glWidth / 2, glHeight / 2), AimFov);
            	if (isPlayerInFov) {
                	foundPlayerInFov = true;
                	AddForceAtPosition(SelfRigidbody, toEnemyDirection * VehicleData.Force, Vector3(0, 0, 0), 0);
                	float movementSpeed = VehicleData.Speed;
                	set_velocity(SelfRigidbody, toEnemyDirection * movementSpeed);
                	break;
            	}
			}
			if(!foundPlayerInFov){
				
            	Vector3 CamPos = ViewportToWorldPoint(Vector3(0.5, 0.5, 0.5));
            	Vector3 FLYPOS = Vector3(VehiclePos.x, VehiclePos.y + VehicleData.Height, VehiclePos.z);
            	Vector3 FLYPOS2 = Vector3(VehiclePos.x, VehiclePos.y - VehicleData.Height, VehiclePos.z);
            	Vector3 toEnemyDirection = VehiclePos - CamPos;
            	MovePosition(SelfRigidbody, Vector3(VehiclePos.x, desiredHeight, VehiclePos.z));
            	toEnemyDirection = Vector3::Normalized(toEnemyDirection);
            	AddForceAtPosition(SelfRigidbody, toEnemyDirection * VehicleData.Force, Vector3(0, 0, 0), 0);
            	float movementSpeed = VehicleData.Speed;
            	set_velocity(SelfRigidbody, toEnemyDirection * movementSpeed);
			}
		}
    }
    
    _VehicleMonitor_FixedUpdate(vehicle);
}

int (*GetVehicleType)(void *);

int VehicleID(void *vehicle){
    void *point = *(void**)((uint64_t)vehicle + 0x44);
    if(point){
        return *(int*)((uint64_t)vehicle + 0x8);
    }
}
void (*_VehicleMonitor_OnDestroy)(void *vehicle);
void VehicleMonitor_OnDestroy(void *vehicle) {
    if (vehicle != NULL) {
        vehicles.clear();
    }
    _VehicleMonitor_OnDestroy(vehicle);
}

void *Battle;
void (*_Battle_Update)(void *point);
void Battle_Update(void *point){
	Battle = point;
	_Battle_Update(point);
}

struct RaycastHit {
    Vector3 m_Point;
    Vector3 m_Normal;
    uint32_t m_FaceID;
    float m_Distance;
    Vector2 m_UV;
    int m_Collider;
};

struct Ray{
    Vector3 m_Origin;
    Vector3 m_Direction;
};


void *(*FindObjectFromInstanceId)(...);
bool (*Raycast)(...);
int collid;
float dis;
RaycastHit hit;
Ray ray;
int layer, type;
void *(*PlayHitAudio)(...);
void *(*ShowDecal)(...);
int (*get_layer)(...);
Ray (*ScreenPointToRay)(...);
Vector3 HeadPos, Point, Normal, Origin, Dir;
void (*_OnTriggerEnter2)(void *attack);
void OnTriggerEnter2(void *attack){
    int nearestEnemyIndex = getNearPlayer(Enemy, Player);
    Game::BasePlayerController BPC;  
    void *NearWeapon = GetCurNearweapon(Player);
    if (test && nearestEnemyIndex != -1 && NearWeapon) {
        void *nearestEnemy = players[nearestEnemyIndex];
        if(nearestEnemy != 0 && get_main != 0 && BPC.HP(Enemy) != 0){   
            HeadPos = GetPosition(nearestEnemy);
            layer = get_layer(nearestEnemy);
            ray = ScreenPointToRay(vThirdPersonCamera(), HeadPos);
            if(Raycast(ray, &hit)){
                Point = hit.m_Point;
                Normal = hit.m_Normal;
                dis = hit.m_Distance;
                collid = hit.m_Collider;
                Origin = ray.m_Origin;
                Dir = ray.m_Direction;
                void *Collider = FindObjectFromInstanceId(hit.m_Collider);
                ShowDecal(attack);
                PlayHitAudio(attack, hit, true);
                int shootNumber = std::min(GunData.ShootNumber, 10);
                for (int i = 0; i < shootNumber; ++i) {
                    _OnTriggerEnter2(attack);
                }      
            }
            
        }
    } 
    _OnTriggerEnter2(attack);
}


