void Skeleton(ImVec4 color, float line, void *player) {
    Game::BasePlayerController Bone;
    Vector3 J1 = get_position(Bone.HeadTop(player));
    Vector3 J2 = get_position(Bone.NeckBone(player));
    Vector3 J3 = get_position(Bone.RightHandGuaDian(player));
    Vector3 J4 = get_position(Bone.LeftHandGuaDian(player));
    Vector3 J5 = get_position(Bone.RightHand(player));
    Vector3 J6 = get_position(Bone.LeftHand(player));
    Vector3 J7 = get_position(Bone.RootBone(player));
    Vector3 J8 = get_position(Bone.RightFoot(player));
    Vector3 J9 = get_position(Bone.LeftFoot(player));

    Vector3 JJ1 = WorldToScreen(J1);
    Vector3 JJ2 = WorldToScreen(J2);
    Vector3 JJ3 = WorldToScreen(J3);
    Vector3 JJ4 = WorldToScreen(J4);
    Vector3 JJ5 = WorldToScreen(J5);
    Vector3 JJ6 = WorldToScreen(J6);
    Vector3 JJ7 = WorldToScreen(J7);
    Vector3 JJ8 = WorldToScreen(J8);
    Vector3 JJ9 = WorldToScreen(J9);
    if (JJ1.z > 0 && JJ2.z > 0 && JJ3.z > 0 && JJ4.z > 0 && JJ5.z > 0 && JJ6.z > 0 && JJ7.z > 0 && JJ8.z > 0 && JJ9.z > 0) {
        DrawAddLine::DrawLine(ImVec2(JJ1.x, glHeight - JJ1.y), ImVec2(JJ2.x, glHeight - JJ2.y), color, line);
        DrawAddLine::DrawLine(ImVec2(JJ2.x, glHeight - JJ2.y), ImVec2(JJ5.x, glHeight - JJ5.y), color, line);
        DrawAddLine::DrawLine(ImVec2(JJ2.x, glHeight - JJ2.y), ImVec2(JJ6.x, glHeight - JJ6.y), color, line);
        DrawAddLine::DrawLine(ImVec2(JJ5.x, glHeight - JJ5.y), ImVec2(JJ3.x, glHeight - JJ3.y), color, line);
        DrawAddLine::DrawLine(ImVec2(JJ6.x, glHeight - JJ6.y), ImVec2(JJ4.x, glHeight - JJ4.y), color, line);
        DrawAddLine::DrawLine(ImVec2(JJ2.x, glHeight - JJ2.y), ImVec2(JJ7.x, glHeight - JJ7.y), color, line);
        DrawAddLine::DrawLine(ImVec2(JJ7.x, glHeight - JJ7.y), ImVec2(JJ8.x, glHeight - JJ8.y), color, line);
        DrawAddLine::DrawLine(ImVec2(JJ7.x, glHeight - JJ7.y), ImVec2(JJ9.x, glHeight - JJ9.y), color, line);
    }
}

int onlineCount = 0;
int offlineCount = 0;

void DrawESP() {
    Game::BasePlayerController BPC;
    if (ESPVar.ESP) {
        //if (!bInitDone) return;

        for (int i = 0; i < players.size(); i++) {
            EnemyPlayer = players[i];

            if (EnemyPlayer != 0 && get_main() != 0) {
                Vector3 EnemyPos = GetPosition(EnemyPlayer);
                Vector3 MyPos = GetPosition(Player);
                float DistanceTo = DrawAddLine::get_3D_Distance(MyPos.x, MyPos.y, MyPos.z, EnemyPos.x, EnemyPos.y, EnemyPos.z);
                Vector3 Head = Vector3(EnemyPos.x, EnemyPos.y + 2, EnemyPos.z);
                Vector3 Bottom = Vector3(EnemyPos.x, EnemyPos.y, EnemyPos.z);

                auto HeadPosition = WorldToScreen(Head);
                auto BottomPosition = WorldToScreen(Bottom);

                if (HeadPosition.z < 1.f) continue;
                if (BottomPosition.z < 1.f) continue;
                bool PlayerGetInfo = Offline(EnemyPlayer);
                if (ESPVar.ESPCount) {
                    if (PlayerGetInfo == false) {
                       // onlineCount = players;
                    } else {
                       // offlineCount = players;
                    }
                    std::string playerInfo = to_string(onlineCount) + " : " + to_string(offlineCount);

                    DrawAddLine::DrawText2(50.0f,
                        ImVec2(glWidth * 0.5f - 0.0f, glHeight * 0.1f),
                        ESPVar.ESPCountColor,
                        playerInfo.c_str());
                }
                if (DistanceTo < 500 && BPC.HP(EnemyPlayer) != 0) {
                    if (ESPVar.ESPLine) {
                        bool radioTop = (ESPVar.textPositionMode == 0);
                        bool radioCenter = (ESPVar.textPositionMode == 1);
                        bool radioBottom = (ESPVar.textPositionMode == 2);

                        if (PlayerGetInfo == false) {
                            if (radioTop) {
                                DrawAddLine::DrawLine(ImVec2(glWidth * 0.5f, glHeight * ESPVar.ESPLineRotation),
                                    ImVec2(HeadPosition.x, glHeight - HeadPosition.y),
                                    ESPVar.ESPLineColorOnline, 1.0f);
                            } else if (radioCenter) {
                                DrawAddLine::DrawLine(ImVec2(glWidth / 2, glHeight / 2 + ESPVar.ESPLineRotation),
                                    ImVec2(HeadPosition.x, glHeight - HeadPosition.y),
                                    ESPVar.ESPLineColorOnline, 1.0f);
                            } else if (radioBottom) {
                                DrawAddLine::DrawLine(ImVec2(glWidth * 0.5f, glHeight * (1.0f - ESPVar.ESPLineRotation)),
                                    ImVec2(HeadPosition.x, glHeight - HeadPosition.y),
                                    ESPVar.ESPLineColorOnline, 1.0f);
                            }
                        } else if (PlayerGetInfo == true) {
                            if (radioTop) {
                                DrawAddLine::DrawLine(ImVec2(glWidth * 0.5f, glHeight * ESPVar.ESPLineRotation),
                                    ImVec2(HeadPosition.x, glHeight - HeadPosition.y),
                                    ESPVar.ESPLineColor, 1.0f);
                            } else if (radioCenter) {
                                DrawAddLine::DrawLine(ImVec2(glWidth / 2, glHeight / 2 + ESPVar.ESPLineRotation),
                                    ImVec2(HeadPosition.x, glHeight - HeadPosition.y),
                                    ESPVar.ESPLineColor, 1.0f);
                            } else if (radioBottom) {
                                DrawAddLine::DrawLine(ImVec2(glWidth * 0.5f, glHeight * (1.0f - ESPVar.ESPLineRotation)),
                                    ImVec2(HeadPosition.x, glHeight - HeadPosition.y),
                                    ESPVar.ESPLineColor, 1.0f);
                            }
                        }

                        float boxHeight = abs(HeadPosition.y - BottomPosition.y) / 0.8f;
                        float boxWidth = boxHeight * 0.60f;
                        Rect playerRect(HeadPosition.x - (boxWidth / 2), (glHeight - HeadPosition.y - 0.f), boxWidth, boxHeight);

                        if (ESPVar.ESPBox) {
                            if (PlayerGetInfo == false) {
                                DrawAddLine::DrawBox2(playerRect, ESPVar.ESPBoxColorOnline, ImVec4(0.0f, 0.0f, 0.0f, 0.3f), 1.0f);
                            } else if (PlayerGetInfo == true) {
                                DrawAddLine::DrawBox2(playerRect, ESPVar.ESPBoxColor, ImVec4(0.0f, 0.0f, 0.0f, 0.3f), 1.0f);
                            }
                        }

                        if (ESPVar.ESPName) {
                            float fontSize = 25.0f;
                            ImVec2 textPosition(playerRect.x + playerRect.width / 2, playerRect.y - fontSize - -8.5f);
                            DrawAddLine::DrawText2(fontSize, textPosition, ESPVar.ESPNameColor, GetPlayerNick(EnemyPlayer)->toChars());
                        }

                        if (ESPVar.BulletLine) {
                            float minDistanceToCenter = std::numeric_limits<float>::max();
                            int closestEnemyIndex = -1;
                            Vector2 screenCenter(glWidth / 2, glHeight / 2);

                            for (int i = 0; i < players.size(); i++) {
                                void* currentEnemy = players[i];

                                if (currentEnemy != nullptr && get_main() != nullptr && BPC.HP(currentEnemy) != 0) {
                                    Vector3 playerHeadTop = get_position(BPC.HeadTop(currentEnemy));
                                    Vector3 myPos = GetPosition(Player);

                                    Vector3 lockPos = WorldToScreen(playerHeadTop);

                                    if (lockPos.z < 1.f) {
                                        continue;
                                    }

                                    bool isFov1 = isFov(Vector2(lockPos.x, lockPos.y), screenCenter, AimFov);

                                    if (isFov1) {
                                        float distanceToCenter = Vector2::Distance(screenCenter, Vector2(lockPos.x, glHeight - lockPos.y));

                                        if (distanceToCenter < minDistanceToCenter) {
                                            minDistanceToCenter = distanceToCenter;
                                            closestEnemyIndex = i;
                                        }
                                    }
                                }
                            }

                            if (closestEnemyIndex != -1) {
                                void* closestEnemy = players[closestEnemyIndex];
                                Vector3 playerHeadTop = get_position(BPC.HeadTop(closestEnemy));
                                Vector3 lockPos = WorldToScreen(playerHeadTop);
                                bool isFov2 = isFov(Vector2(lockPos.x, lockPos.y), screenCenter, AimFov);

                                if (isFov2) {
                                    DrawAddLine::DrawLine(ImVec2(glWidth / 2, glHeight / 2),
                                        ImVec2(lockPos.x, glHeight - lockPos.y), ImVec4(1, 0, 0, 1), 1);
                                }
                            }
                        }

                        if (ESPVar.ESPHealth) {
                            ImVec2 healthBarPosition(HeadPosition.x - 50.129f, glHeight - HeadPosition.y - 52.699f);

                            DrawAddLine::DrawHorizontalHealthBar(Vector2(HeadPosition.x - 50.129f, glHeight - HeadPosition.y - 52.699f),
                                100.f,
                                16.f,
                                BPC.MaxHp(EnemyPlayer),
                                BPC.HP(EnemyPlayer),
                                ImVec4(0.988f, 0.463f, 0.f, 1.f),
                                ImVec4(0.004f, 451.f, 0.004f, 1.f));
                        }

                        

                        

                        if (ESPVar.ESPSkeleton) {
                            Skeleton(ESPVar.ESPSkeletonColor, 1.0f, EnemyPlayer);
                        }

                        float fontSize = 22.0f;

                        if (ESPVar.ESPDistance) {
                            char extra[30];
                            sprintf(extra, OBFUSCATE("%0.0f m"), DistanceTo);
                            ImVec2 textPosition(playerRect.x + playerRect.width / 2, playerRect.y + playerRect.height + fontSize + 8.5f);
                            DrawAddLine::DrawText2(fontSize, textPosition, ESPVar.ESPDistanceColor, extra);
                        }

                        if (ESPVar.ESPGunName) {
                            int WeaponID = GetCurrentWeaponID(EnemyPlayer);
                            std::string currhun = OBFUSCATE("");
                            if (WeaponID == -1) currhun = "[HAND]";
                            else if (WeaponID == 52101) currhun = "[SMG]";
                            else if (WeaponID == 52111) currhun = "[FAMAS]";
                            else if (WeaponID == 52121) currhun = "[UZI]";
                            else if (WeaponID == 52211) currhun = "[AKM]";
                            else if (WeaponID == 52231) currhun = "[M4]";
                            else if (WeaponID == 52311) currhun = "[M24]";
                            else if (WeaponID == 52221) currhun = "[QBZ]";
                            else if (WeaponID == 52232) currhun = "[RPG]";
                            else if (WeaponID == 52011) currhun = "[PISTOL]";
                            else if (WeaponID == 55001) currhun = "[STONE AXE]";
                            else currhun = "[" + to_string(WeaponID) + "]";

                            ImVec2 textPosition(playerRect.x + playerRect.width / 2, playerRect.y + playerRect.height + fontSize + 28.5f);
                            DrawAddLine::DrawText2(fontSize, textPosition, ESPVar.ESPGunNameColor, currhun.c_str());
                        }
                    }
                }
            }
        }

        if(ESPVar.info){
        
            /*RaycastHit INFO;
            Vector3 point = info2.m_Point;
            Vector3 point2 = info2.m_Normal;
            int id = info2.m_FaceID;
            float dist = info2.m_Distance;
            Vector2 UV = info2.m_UV;
            int num = info2.m_Collider;
            DrawAddLine::DrawText2(25.f,
            ImVec2(glWidth * 0.2f, glHeight * 0.2f), ImVec4(1, 1, 1, 1),
                 ("X: " + to_string(point.x) + " Y: " + to_string(point.y) + " Z: " + to_string(point.z) +
                 "\nX: " + to_string(point2.x) + " Y: " + to_string(point2.y) + " Z: " + to_string(point2.z) + 
                 "\nFACE ID: " + to_string(id) + 
                 "\nDISTANCE: " + to_string(dist) +
                 "\nX: " + to_string(UV.X) + " Y: " + to_string(UV.Y) +
                 "\nCOLLIDER: " + to_string(num) +
                 "\nBe Hited Ins Id: " + to_string(na) + 
                 "\nPart Id" + to_string(sa) + 
                 "\nGun Target Score" + to_string(ma)).c_str());*/
        }
        if (ESPVar.FOV) {
            DrawAddLine::DrawCircle(ImVec4(0.4, 0.2, 0.8, 1), glWidth * 0.5f, glHeight * 0.5f, AimFov, false);
        }
       
    }
}

void MonsterESP(){
    Game::MapObject MO;
    if (ESPVar.ESP) {
        if (!bInitDone) {
            return;
        }

        for (int i = 0; i < monsters.size(); i++) {
            Monster = monsters[i];
            if (Monster != 0 && get_main() != 0) {
                Vector3 MonsterPos = GetPosition(Monster);
                Vector3 Head = Vector3(MonsterPos.x, MonsterPos.y + 1.0f, MonsterPos.z);
                Vector3 Bottom = Vector3(MonsterPos.x, MonsterPos.y, MonsterPos.z);
                auto HeadPosition = WorldToScreen(Head);
                auto BottomPosition = WorldToScreen(Bottom);

                if (HeadPosition.z < 1.f) continue;

                float fontSize = 25.0f;
                float boxHeight = abs(HeadPosition.y - BottomPosition.y) / 0.8f;
                float boxWidth = boxHeight * 0.60f;
                Rect playerRect(HeadPosition.x - (boxWidth / 2), (glHeight - HeadPosition.y - 0.f), boxWidth, boxHeight);

                if (ESPVar.ESPNameMonster) {
                    ImVec2 textPosition(playerRect.x + playerRect.width / 2, playerRect.y + playerRect.height + fontSize - 40.5f);
                    DrawAddLine::DrawText2(fontSize, textPosition, ESPVar.ESPMonsterNameColor, ("HP: " + std::to_string(static_cast<int>(MO.Hp(Monster)))).c_str());
                }

                if (ESPVar.ESPDistanceMonster) {
                    Vector3 MyPos = GetPosition(Player);
                    float DistanceTo = DrawAddLine::get_3D_Distance(MyPos.x, MyPos.y, MyPos.z, MonsterPos.x, MonsterPos.y, MonsterPos.z);
                    char extra[30];
                    sprintf(extra, OBFUSCATE("%0.0f m"), DistanceTo);
                    ImVec2 textPosition(playerRect.x + playerRect.width / 2, playerRect.y + playerRect.height + fontSize + 8.5f);
                    DrawAddLine::DrawText2(fontSize, textPosition, ESPVar.ESPMonsterDistanceColor, extra);
                }

                if (ESPVar.ESPHealthMonster) {
                    int NpcID = MonsterID(Monster);
                    std::string currmonster = OBFUSCATE("");

                    if (NpcID == 1) currmonster = "[RABBIT]";
                    else if (NpcID == 2) currmonster = "[WOLF]";
                    else if (NpcID == 3) currmonster = "[BEAR]";
                    else if (NpcID == 4) currmonster = "[DEER]";
                    else if (NpcID == 5) currmonster = "[LYNX]";
                    else if (NpcID == 6) currmonster = "[BOAR]";
                    else if (NpcID == 7) currmonster = "[PHEASANT]";
                    else if (NpcID == 8) currmonster = "[HORSE]";
                    else if (NpcID == 146) currmonster = "[BATTLE BOT]";
                    else if (NpcID == 143) currmonster = "[BATTLE BOT]";
                    else if (NpcID == 144) currmonster = "[BATTLE BOT]";
                    else if (NpcID == 1003) currmonster = "[FAT ZOMBIE]";
                    else if (NpcID == 1005) currmonster = "[INFECTED ORDERLY]";
                    else if (NpcID == 1006) currmonster = "[INFECT EXPLORER]";
                    else if (NpcID == 1007) currmonster = "[INFECT DOG]";
                    else if (NpcID == 1004) currmonster = "[INFECTED ZOMBIE]";
                    else if (NpcID == 1008) currmonster = "[EG BOSS]";
                    else if (NpcID >= 10000 && NpcID <= 12000) currmonster = "[FARM BOT]";
                    else currmonster = "[" + std::to_string(NpcID) + "]";
                    ImVec2 textPosition(playerRect.x + playerRect.width / 2, playerRect.y + playerRect.height + fontSize - 16.0f);
                    DrawAddLine::DrawText2(fontSize, textPosition, ESPVar.ESPMonsterHealthColor, currmonster.c_str());
                }
            }
        }
    }
}

void VehicleESP(){
    if (ESPVar.ESP){
        for (int i = 0; i < vehicles.size(); i++){
            Vehicle = vehicles[i];
            if (Vehicle != 0 && get_main() != 0){
                Vector3 VehiclePos = GetPosition(Vehicle);
                Vector3 MyPos = GetPosition(Player);
                Vector3 Head = Vector3(VehiclePos.x, VehiclePos.y + 1.0f, VehiclePos.z);
                Vector3 Bottom = Vector3(VehiclePos.x, VehiclePos.y, VehiclePos.z);
                auto HeadPosition = WorldToScreen(Head);
                auto BottomPosition = WorldToScreen(Bottom);
   
                if (HeadPosition.z < 1.f) continue;
                
                float DistanceTo = DrawAddLine::get_3D_Distance(MyPos.x, MyPos.y, MyPos.z, VehiclePos.x, VehiclePos.y, VehiclePos.z);
                float boxHeight = abs(HeadPosition.y - BottomPosition.y) / 0.8f;
                float boxWidth = boxHeight * 0.60f;
                Rect playerRect(HeadPosition.x - (boxWidth / 2), (glHeight - HeadPosition.y - 0.f), boxWidth, boxHeight);
                float fontSize = 25.0f;
                
                if (ESPVar.ESPVehicleDistance) {
                    char extra[30];
                    sprintf(extra, OBFUSCATE("%0.0f m"), DistanceTo);
                    ImVec2 textPosition1(playerRect.x + playerRect.width / 2, playerRect.y + playerRect.height + 25.0f - 16.0f);
                    DrawAddLine::DrawText2(25.0f, textPosition1, ESPVar.ESPVehicleDistanceColor, extra);
                }
                if (ESPVar.ESPVehicleLine) {
                    DrawAddLine::DrawLine(ImVec2(glWidth * 0.5f, glHeight * ESPVar.ESPLineRotation),
                    ImVec2(HeadPosition.x, glHeight - HeadPosition.y),
                    ESPVar.ESPVehicleLineColor, 1.0f);
                }
                if (ESPVar.ESPVehicleName) {
                    int ID = GetVehicleType(Vehicle);
                    std::string currvehicle = OBFUSCATE("");
                    if (ID == 3) currvehicle = "[MOTO]";
                    else if (ID == 6) currvehicle = "[MOUNTAIN BIKE]";
                    else currvehicle = "[" + std::to_string(ID) + "]";
                    ImVec2 textPosition(playerRect.x + playerRect.width / 2, playerRect.y + playerRect.height + fontSize - 36.0f);
                    DrawAddLine::DrawText2(fontSize, textPosition, ESPVar.ESPVehicleNameColor, currvehicle.c_str());
                }    
            }
        }
    }
}


void MineESP() {
    if (!ESPVar.ESPMineLine || !bInitDone)
        return;
    
    void *PlayerClass = get_class("Assembly-CSharp.dll", "", "Mine");
    void *nowPlayer = il2cpp_object_new(PlayerClass);
    Vector3 pos = GetPosition(nowPlayer);
    Vector3 wPos = WorldToScreen(pos);
    if (wPos.z < 1.f) {
        DrawAddLine::DrawLine(ImVec2(glWidth * 0.5f, glHeight * 0.f), ImVec2(wPos.x, glHeight - wPos.y), ImVec4(1, 0, 1, 1), 3.f);
    }
    /*float fontSize = 25.0f;

    for (int i = 0; i < mines.size(); i++) {
        Mine = mines[i];
        if (Mine == 0 && get_main() == 0 && get_isActiveAndEnabled(Mine) != 0)
            continue;

        Vector3 MinePos = GetPosition(Mine);
        Vector3 Head = Vector3(MinePos.x, MinePos.y + 1.5f, MinePos.z);
        Vector3 Bottom = Vector3(MinePos.x, MinePos.y, MinePos.z);
        auto HeadPosition = WorldToScreen(Head);
        auto BottomPosition = WorldToScreen(Bottom);

        if (HeadPosition.z < 1.f)
            continue;

        float DistanceTo = DrawAddLine::get_3D_Distance(GetPosition(Player).x, GetPosition(Player).y, GetPosition(Player).z, MinePos.x, MinePos.y, MinePos.z);
        if (DistanceTo >= 140)
            continue;

        int ID = MineID(Mine);
        if ((ID == 10001 && ESPVar.Stone) || (ID == 10003 && ESPVar.Sulfur) ||
            (ID == 10011 && ESPVar.Titan) || (ID == 10005 && ESPVar.Iron)) {
                
            std::string currmine = OBFUSCATE("");
            if (ID == 10001) currmine = "[STONE]";
            else if (ID == 10003) currmine = "[SULFUR]";
            else if (ID == 10011) currmine = "[TITAN]";
            else if (ID == 10005) currmine = "[IRON]";
            else currmine = "[" + std::to_string(ID) + "]";
        
            
            
            if(ESPVar.ESPMineLine){
                DrawAddLine::DrawLine(ImVec2(glWidth * 0.5f, glHeight * ESPVar.ESPLineRotation - 300.0f),
                                  ImVec2(HeadPosition.x, glHeight - HeadPosition.y),
                                  ESPVar.ESPMineLineColor, 1.0f);
            }
             
            float boxHeight = abs(HeadPosition.y - BottomPosition.y) / 0.8f;
            float boxWidth = boxHeight * 0.60f;
            Rect playerRect(HeadPosition.x - (boxWidth / 2), (glHeight - HeadPosition.y - 0.f), boxWidth, boxHeight);
            if(ESPVar.ESPMineName){
                ImVec2 textPosition(playerRect.x + playerRect.width / 2, playerRect.y + playerRect.height + fontSize + 8.5f);
				Game::MapObject MO;
                DrawAddLine::DrawText2(fontSize, textPosition, ESPVar.ESPMineNameColor, currmine.c_str());
            }
            
            if(ESPVar.ESPMineDistance){
                char extra[30];
                sprintf(extra, OBFUSCATE("%0.0f m"), DistanceTo);
                ImVec2 textPosition1(playerRect.x + playerRect.width / 2, playerRect.y + playerRect.height + fontSize - 16.0f);
                DrawAddLine::DrawText2(fontSize, textPosition1, ESPVar.ESPMineDistanceColor, extra);
            }
        }
    }*/
}

