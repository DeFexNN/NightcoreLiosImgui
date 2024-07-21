ImVec4 menu_accent = ImVec4(128 / 255.f, 134 / 255.f, 150 / 255.f, 255 / 255.f);
ImColor watermark_accent = ImColor(131, 141, 255);
bool menu, BP, swim, fakeowner, own1, own2, own3, own4, GreenName, FastBoom = false;
static int Page = 7;
static int ForceMode = 0;
static int boneint = 0;
bool Watermark_Bool = true;
float butpos = 0.98f;
bool changepos;
bool fastopenesp;
ImVec2 LangPos = ImVec2(500.f, 50.f);
#include "ImGui/box_shadow.cpp"
namespace MainMenu {
    bool Language;
    #include "Garbage/Tabs.h"
    #include "Garbage/Watermark.h"
    
   void ColorPickerButton(const char* label, ImVec4* color) {
        ImGui::ColorEdit4(label, &color->x, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel);
    }
    void CheckBoxWithColorPicker(const char* label, bool* value, ImVec4* color) {
        CheckBox(label, value);
        ImGui::SameLine();
        ColorPickerButton((std::string("##ColorPicker") + label).c_str(), color);
    }
    void FlyMenu(){
        MenuFly();
        
    }
    
    void Menu() {
        
        
        if (Watermark_Bool) {
            Watermark();
            Watermark1();
        }
        
        float alphamenu = 0.0f;
        if (menu && alphamenu < 1.f) {
            alphamenu += 0.025f;
        } else if (!menu && menu > 0.025f) {
            alphamenu -= 0.025f;
        }
        
        ImGui::SetNextWindowPos(ImVec2(glWidth * 0.5, glHeight * butpos), ImGuiCond_Always, ImVec2(0.5, 0.90));
        ImGui::Begin(OBFUSCATE("##Open menu"), NULL, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavInputs | ImGuiWindowFlags_NoNavFocus | ImGuiWindowFlags_NoNav | ImGuiWindowFlags_NoDecoration);
        if (ImGui::Button(OBFUSCATE("TELEGRAM: @DeFexHacks VIP VERSION [LIOS]"), ImVec2(500, 30))) menu = !menu;
        if (!menu) return;
        
        ImGui::SetNextWindowPos(ImVec2(200, 50), ImGuiCond_FirstUseEver);
        ImGui::SetNextWindowSize(ImVec2(850, 620), ImGuiCond_FirstUseEver);
        ImGui::Begin(OBFUSCATE("##Menu"), NULL, 3);
        RectangleShadowSettings shadowSettings2;
        shadowSettings2.rectSize = ImVec2(ImGui::GetWindowSize().x, ImGui::GetWindowSize().y);
        static ImVec2 mainpos = ImGui::GetWindowPos();
        shadowSettings2.sigma = 30;
        shadowSettings2.padding = ImVec2(0, 0);
        shadowSettings2.rectPos = shadowSettings2.padding;
        shadowSettings2.rings = 15;
        shadowSettings2.spacingBetweenRings = 5;
        shadowSettings2.samplesPerCornerSide = 20;
        shadowSettings2.spacingBetweenSamples = 15;
        shadowSettings2.shadowColor = ImVec4(0.62f, 0.f, 0.f, 0.8f);
        shadowSettings2.shadowSize = ImVec2(15,15);
        drawRectangleShadowVerticesAdaptive(shadowSettings2);
        
        ImGui::SetCursorPos(ImVec2(20, 30));
        
        ImGui::PushFont(HorstFont);
        TextGradient(OBFUSCATE("NIGHTCORE"), ImVec4(1.0f, 1.0f, 1.0f, 1.0f), ImVec4(130 / 255.0f, 141 / 255.0f, 255 / 255.0f, 255 / 255.0f));
        ImGui::PopFont(); 
        
        ImGui::SetCursorPos(ImVec2(35, 55));
        ImGui::TextColored(ImColor(100, 100, 100), OBFUSCATE("_____________"));
        
        ImGui::SetCursorPosY(95);
        if(Language){
			ImGui::PushFont(ChinaFont);
		} else {
			ImGui::PushFont(SmallFont);
		}
        ImGui::Text(Language ? OBFUSCATE("视觉:") : OBFUSCATE("VISUALS:"));
        if (Tabs::RenderTabs(Language ? OBFUSCATE("超感知觉") : OBFUSCATE("ESP"), OBFUSCATE("K"), Page == 1, {175, 45})) Page = 1;
        ImGui::Text(Language ? OBFUSCATE("功能:") : OBFUSCATE("FUNCTION:"));
        if (Tabs::RenderTabs(Language ? OBFUSCATE("武器") : OBFUSCATE("WEAPON"), OBFUSCATE("A"), Page == 2, {175, 45})) Page = 2;
        if (Tabs::RenderTabs(Language ? OBFUSCATE("玩家") : OBFUSCATE("PLAYER"), OBFUSCATE("I"), Page == 3, {175, 45})) Page = 3;
        if (Tabs::RenderTabs(Language ? OBFUSCATE("车辆") : OBFUSCATE("VEHICLE"), OBFUSCATE("J"), Page == 4, {175, 45})) Page = 4;
        if (Tabs::RenderTabs(Language ? OBFUSCATE("建筑") : OBFUSCATE("BUILDING"), OBFUSCATE("B"), Page == 5, {175, 45})) Page = 5;
        if (Tabs::RenderTabs(Language ? OBFUSCATE("突袭") : OBFUSCATE("RAID"), OBFUSCATE("P"), Page == 6, {175, 45})) Page = 6;
        ImGui::Text(Language ? OBFUSCATE("其他:") : OBFUSCATE("MISC:"));
        if (Tabs::RenderTabs(Language ? OBFUSCATE("主要") : OBFUSCATE("MAIN"), OBFUSCATE("D"), Page == 7, {175, 45})) Page = 7;
        /*if (Tabs::RenderTabs(OBFUSCATE("NOWORK"), OBFUSCATE("P"), Page == 6, {175, 45})) Page = 6;
        if (Tabs::RenderTabs(OBFUSCATE("NOWORK2"), OBFUSCATE("Q"), Page == 7, {175, 45})) Page = 7;*/
        
        
        ImVec2 CurPos = ImVec2(195, 8);
        ImVec2 CurPos2 = ImVec2(497, 8);
        
        if (Page == 1) {
            ImGui::SetCursorPos(CurPos);
            ImGui::BeginChild(OBFUSCATE("## PAGE - ESP"), ImVec2(294, -0), true);
            ImGui::TextColored(ImColor(170, 170, 170), Language ? OBFUSCATE("敌人:") : OBFUSCATE("ENEMIES:"));
            ImGui::Separator();
            CheckBox(Language ? OBFUSCATE("绘制初始化") : OBFUSCATE("OPEN"), &ESPVar.ESP);
            CheckBoxWithColorPicker(Language ? OBFUSCATE("射线") : OBFUSCATE("LINE"), &ESPVar.ESPLine, &ESPVar.ESPLineColorOnline);
            ImGui::Separator();
            ImGui::RadioButton(Language ? OBFUSCATE("顶部") : OBFUSCATE("Top"), &ESPVar.textPositionMode, 0);
            ImGui::SameLine();
            ImGui::RadioButton(Language ? OBFUSCATE("中心") : OBFUSCATE("Center"), &ESPVar.textPositionMode, 1);
            ImGui::SameLine();
            ImGui::RadioButton(Language ? OBFUSCATE("底部") : OBFUSCATE("Bottom"), &ESPVar.textPositionMode, 2);
            ImGui::Separator();
            if(ESPVar.textPositionMode == 0){
                ESPVar.ESPLineRotation = 0.f;
            } else if(ESPVar.textPositionMode == 1){
                ESPVar.ESPLineRotation = 0.5f;
            } else if(ESPVar.textPositionMode == 2){
                ESPVar.ESPLineRotation = 1.f;
            }
            CheckBoxWithColorPicker(OBFUSCATE("BOX"), &ESPVar.ESPBox, &ESPVar.ESPBoxColor);
            CheckBoxWithColorPicker(OBFUSCATE("NAME"), &ESPVar.ESPName, &ESPVar.ESPNameColor);
            CheckBoxWithColorPicker(OBFUSCATE("HEALTH"), &ESPVar.ESPHealth, &ESPVar.ESPHealthColor);
            CheckBoxWithColorPicker(OBFUSCATE("COUNT"), &ESPVar.ESPCount, &ESPVar.ESPCountColor);
            CheckBoxWithColorPicker(OBFUSCATE("SKELETON"), &ESPVar.ESPSkeleton, &ESPVar.ESPSkeletonColor);
            CheckBoxWithColorPicker(OBFUSCATE("DISTANCE"), &ESPVar.ESPDistance, &ESPVar.ESPDistanceColor);
            CheckBoxWithColorPicker(OBFUSCATE("WEAPON NAME"), &ESPVar.ESPGunName, &ESPVar.ESPGunNameColor);
            ImGui::Separator();
            ImGui::TextColored(ImColor(170, 170, 170), OBFUSCATE("MONSTERS:"));
            ImGui::Separator();
            CheckBoxWithColorPicker(OBFUSCATE("MONSTER DISTANCE"), &ESPVar.ESPDistanceMonster, &ESPVar.ESPMonsterNameColor);
            CheckBoxWithColorPicker(OBFUSCATE("MONSTER NAME"), &ESPVar.ESPNameMonster, &ESPVar.ESPMonsterDistanceColor);
            CheckBoxWithColorPicker(OBFUSCATE("MONSTER HEALTH"), &ESPVar.ESPHealthMonster, &ESPVar.ESPMonsterHealthColor);
            ImGui::EndChild();
    
            ImGui::SetCursorPos(CurPos2);
            ImGui::BeginChild(OBFUSCATE("## PAGE - OTHER"), ImVec2(345, -0), true);
            ImGui::TextColored(ImColor(170, 170, 170), OBFUSCATE("VEHICLE ESP:"));
            ImGui::Separator();
            CheckBoxWithColorPicker(OBFUSCATE("VEHICLE DISTANCE"), &ESPVar.ESPVehicleDistance, &ESPVar.ESPVehicleDistanceColor);
            CheckBoxWithColorPicker(OBFUSCATE("VEHICLE LINE"), &ESPVar.ESPVehicleLine, &ESPVar.ESPVehicleLineColor);
            CheckBoxWithColorPicker(OBFUSCATE("VEHICLE NAME"), &ESPVar.ESPVehicleName, &ESPVar.ESPVehicleNameColor);
            ImGui::Separator();
            ImGui::TextColored(ImColor(170, 170, 170), OBFUSCATE("MINE ESP:"));
            ImGui::Separator();
            CheckBoxWithColorPicker(OBFUSCATE("MINE LINE"), &ESPVar.ESPMineLine, &ESPVar.ESPMineLineColor);
            CheckBoxWithColorPicker(OBFUSCATE("MINE NAME"), &ESPVar.ESPMineName, &ESPVar.ESPMineNameColor);
            CheckBoxWithColorPicker(OBFUSCATE("MINE DISTANCE"), &ESPVar.ESPMineDistance, &ESPVar.ESPMineDistanceColor);
            if (ImGui::TreeNode("SETTINGS MINE")) {
                ImGui::Checkbox(OBFUSCATE("STONE"), &ESPVar.Stone);
                ImGui::Checkbox(OBFUSCATE("SULFUR"), &ESPVar.Sulfur);
                ImGui::Checkbox(OBFUSCATE("TITAN"), &ESPVar.Titan);
                ImGui::Checkbox(OBFUSCATE("IRON"), &ESPVar.Iron);
                
                ImGui::TreePop(); 
            }
            
            
            ImGui::EndChild();
        }
        
        if (Page == 2) {
            ImGui::SetCursorPos(CurPos);
            ImGui::BeginChild(OBFUSCATE("## PAGE - WEAPON"), ImVec2(294, -0), true);
            ImGui::TextColored(ImColor(170, 170, 170), OBFUSCATE("WEAPON MENU:"));
            ImGui::Separator();
            ImGui::Checkbox(OBFUSCATE("BULLET TRACK"), &BulletData.bullet);
            ImGui::Checkbox(OBFUSCATE("FAST SHOOT"), &GunData.FastShoot);
            ImGui::Checkbox(OBFUSCATE("NO RECOIL"), &GunData.NoRecoil);
            ImGui::Checkbox(OBFUSCATE("AIM BOT"), &MyPlayerData.AimBot);
			
            ImGui::EndChild();
            
    
            ImGui::SetCursorPos(CurPos2);
            ImGui::BeginChild(OBFUSCATE("## PAGE - SETTINGS"), ImVec2(345, -0), true);
            ImGui::TextColored(ImColor(170, 170, 170), OBFUSCATE("SETTINGS WEAPON:"));
            ImGui::Separator();
            if(ImGui::Combo("BONE", &boneint, OBFUSCATE("Head\0Body\0"))){
                switch(boneint){
                    case 0:
                        CustomBone = 0;
                    break;
                    case 1:
                        CustomBone = 1;
                    break;
                }
            }
            ImGui::SliderInt(OBFUSCATE("COUNT"), &GunData.ShootNumber, 0, 10);
            ImGui::Checkbox(OBFUSCATE("FOV"), &ESPVar.FOV);
            ImGui::Checkbox(OBFUSCATE("BULLET LINE"), &ESPVar.BulletLine);         
            ImGui::SliderFloat(OBFUSCATE("RADIUS"), &AimFov, 0.f, 900.f);
            if(ImGui::Button(OBFUSCATE("FULL SCREEN"), ImVec2(300, 70))){
              AimFov = 1150;
            }
            ImGui::EndChild();
        }
        
        if (Page == 3) {
            ImGui::SetCursorPos(CurPos);
            ImGui::BeginChild(OBFUSCATE("## PAGE - PLAYER"), ImVec2(294, -0), true);
            ImGui::TextColored(ImColor(170, 170, 170), OBFUSCATE("PLAYER MENU:"));
            ImGui::Separator();
            ImGui::Checkbox(OBFUSCATE("FLY MAN"), &flymenu);
            if(ImGui::Checkbox(OBFUSCATE("UNDERWATER"), &swim)){
                if(swim){
                    hexPatches.Swim.Modify();
                } else {
                    hexPatches.Swim.Restore();
                }
            }
            ImGui::Checkbox(OBFUSCATE("STICKY"), &MyPlayerData.Sticky);
            ImGui::Checkbox(OBFUSCATE("HIDE TREE"), &Texture.tree);                      
            ImGui::Checkbox(OBFUSCATE("HIDE GRASS"), &Texture.grass);                      
            ImGui::Checkbox(OBFUSCATE("HIDE THINGS"), &Texture.things);
            if(ImGui::Checkbox(OBFUSCATE("STOP MONSTER"), &MonsterData.StopMonster)){
                if(MonsterData.StopMonster){
                    hexPatches.Stop.Modify();
                } else {
                    hexPatches.Stop.Restore();
                }
            }
            ImGui::Checkbox(OBFUSCATE("PENETRATE MECHA"), &MechaData.Collision);
            ImGui::Checkbox(OBFUSCATE("FAST HIT"), &MyPlayerData.FastHit);
            ImGui::Checkbox(OBFUSCATE("DRINK WATER"), &MyPlayerData.Drink);
            ImGui::Checkbox(OBFUSCATE("GREEN NAME"), &GreenName);
			if(GreenName){
                hexPatches.UM.Modify();
            } else {
                hexPatches.UM.Restore();
            }
			ImGui::Checkbox(OBFUSCATE("AUTO FARM"), &MyPlayerData.AutoFarm);
            ImGui::Checkbox(OBFUSCATE("NO SHAKE"), &MyPlayerData.NoShake);
			ImGui::Checkbox(OBFUSCATE("STEALTH"), &MyPlayerData.Animator);
			
			
            ImGui::EndChild();
    
            ImGui::SetCursorPos(CurPos2);
            ImGui::BeginChild(OBFUSCATE("## PAGE - SETTINGS"), ImVec2(345, -0), true);
            ImGui::TextColored(ImColor(170, 170, 170), OBFUSCATE("SETTINGS PLAYER:"));
            ImGui::Separator();
            ImGui::SliderFloat(OBFUSCATE("VELOCITY"), &MyPlayerData.FlySpeed, 0.f, 1.f);
            ImGui::SliderFloat(OBFUSCATE("HEIGHT"), &MyPlayerData.Height, 0.f, 1.f);
            ImGui::SliderFloat2(OBFUSCATE("MENU POS"), (float*)&WindowPos, 0.0f, 2040.0f, "%.2f");
            ImGui::SliderFloat(OBFUSCATE("SPEED MAN"), &MyPlayerData.Speed, -50.f, 50.f);
            ImGui::SliderFloat(OBFUSCATE("FORCE MAN"), &MyPlayerData.Force, -50.f, 50.f);
			if (ImGui::TreeNode("SETTINGS MINE")) {
                ImGui::Checkbox(OBFUSCATE("STONE"), &ESPVar.Stone);
                ImGui::Checkbox(OBFUSCATE("SULFUR"), &ESPVar.Sulfur);
                ImGui::Checkbox(OBFUSCATE("TITAN"), &ESPVar.Titan);
                ImGui::Checkbox(OBFUSCATE("IRON"), &ESPVar.Iron);
                ImGui::TreePop(); 
            }
			ImGui::RadioButton(OBFUSCATE("Driver"), &MyPlayerData.Mode, 0);
            ImGui::SameLine();
            ImGui::RadioButton(OBFUSCATE("Crouch"), &MyPlayerData.Mode, 1);
			ImGui::SameLine();
            ImGui::RadioButton(OBFUSCATE("Crawl"), &MyPlayerData.Mode, 2);
			ImGui::RadioButton(OBFUSCATE("Sleep"), &MyPlayerData.Mode, 3);
			ImGui::SameLine();
			ImGui::RadioButton(OBFUSCATE("Knock"), &MyPlayerData.Mode, 4);
			
			if(MyPlayerData.Mode == 0){
				MyPlayerData.StateID = -230889187;
			} else if(MyPlayerData.Mode == 1){
				MyPlayerData.StateID = 531867845;
			} else if(MyPlayerData.Mode == 2){
				MyPlayerData.StateID = 1245347906;
			} else if(MyPlayerData.Mode == 3){
				MyPlayerData.StateID = 0;
			} else if(MyPlayerData.Mode == 4){
				MyPlayerData.StateID = 563599642;
			} 
            ImGui::EndChild();
        }
        
        if (Page == 4) {
            ImGui::SetCursorPos(CurPos);
            ImGui::BeginChild(OBFUSCATE("## PAGE - VEHICLE"), ImVec2(294, -0), true);
            ImGui::TextColored(ImColor(170, 170, 170), OBFUSCATE("VEHICLE MENU:"));
            ImGui::Separator();
            ImGui::Checkbox(OBFUSCATE("FLY VEHICLE"), &vehiclemenu);
            if(vehiclemenu){
                flymenu = true;
            }
            ImGui::EndChild();
    
            ImGui::SetCursorPos(CurPos2);
            ImGui::BeginChild(OBFUSCATE("## PAGE - SETTINGS"), ImVec2(345, -0), true);
            ImGui::TextColored(ImColor(170, 170, 170), OBFUSCATE("SETTINGS VEHICLE:"));
            ImGui::Separator();
            ImGui::SliderFloat(OBFUSCATE("SPEED"), &VehicleData.Speed, 0.f, 32.f);
            ImGui::SliderFloat(OBFUSCATE("FORCE"), &VehicleData.Force, 0.f, 100.f);
            ImGui::SliderFloat(OBFUSCATE("HEIGHT"), &VehicleData.Height, 1.f, 5.f);
            ImGui::SliderFloat2(OBFUSCATE("MENU POS"), (float*)&WindowPos, 0.0f, 2040.0f, "%.2f");
			
            ImGui::EndChild();
        }
        
        if (Page == 5) {
            ImGui::SetCursorPos(CurPos);
            ImGui::BeginChild(OBFUSCATE("## PAGE - BUILDING"), ImVec2(294, -0), true);
            ImGui::TextColored(ImColor(170, 170, 170), OBFUSCATE("BUILDING MENU:"));
            ImGui::Separator();
            ImGui::Checkbox(OBFUSCATE("FORCE BUILD"), &BuilderData.ForceBuild);           
            if(ImGui::Checkbox(OBFUSCATE("FAKE OWNER"), &fakeowner)){
                if(fakeowner){
                    hexPatches.FO1.Modify();
                    hexPatches.FO2.Modify();
                    hexPatches.FO4.Modify();
                } else {
                    hexPatches.FO1.Restore();
                    hexPatches.FO2.Restore();
                    hexPatches.FO4.Restore();
                }
            }
            if(ImGui::Checkbox(OBFUSCATE("ALLOW OP"), &own1)){
               if(own1){
                   hexPatches.PR1.Modify();
               } else {
                   hexPatches.PR1.Restore();
               }
           }
           if(ImGui::Checkbox(OBFUSCATE("HAVE PERMIT"), &own2)){
               if(own2){
                   hexPatches.PR2.Modify();
               } else {
                   hexPatches.PR2.Restore();
               }
           }
           if(ImGui::Checkbox(OBFUSCATE("CAN UPDATE"), &own3)){
               if(own3){
                   hexPatches.PR3.Modify();
               } else {
                   hexPatches.PR3.Restore();
               }
           }
           if(ImGui::Checkbox(OBFUSCATE("CAN BUILD"), &own4)){
                if(own4){
                    hexPatches.PR4.Modify();
                } else {
                    hexPatches.PR4.Restore();
                }
            }
            ImGui::EndChild();
    
            ImGui::SetCursorPos(CurPos2);
            ImGui::BeginChild(OBFUSCATE("## PAGE - SETTINGS"), ImVec2(345, -0), true);
            ImGui::TextColored(ImColor(170, 170, 170), OBFUSCATE("SETTINGS BUILDING:"));
            ImGui::Separator();
            ImGui::SliderFloat(OBFUSCATE("X"), &BuilderData.x, -360.f, 360.f);
            ImGui::SliderFloat(OBFUSCATE("Y"), &RotateY, -360.f, 360.f);
            ImGui::SliderFloat(OBFUSCATE("Z"), &BuilderData.z, -360.f, 360.f);
            ImGui::EndChild();
        }
        
        if (Page == 6) {
            ImGui::SetCursorPos(CurPos);
            ImGui::BeginChild(OBFUSCATE("## PAGE - RAID"), ImVec2(294, -0), true);
            ImGui::TextColored(ImColor(170, 170, 170), OBFUSCATE("RAID MENU:"));
            ImGui::Separator();           
            if(ImGui::Checkbox(OBFUSCATE("BOMB SPLASH"), &HeatData.Splash)){
                if(HeatData.Splash){
                    hexPatches.Splash.Modify();
                } else {
                    hexPatches.Splash.Restore();
                }
            }       
            ImGui::Checkbox(OBFUSCATE("FAST BOOM"), &FastBoom);
            if(FastBoom){
                hexPatches.FB.Modify();
            } else {
                hexPatches.FB.Restore();
            }
            ImGui::EndChild();
    
            ImGui::SetCursorPos(CurPos2);
            ImGui::BeginChild(OBFUSCATE("## PAGE - SETTINGS"), ImVec2(345, -0), true);
            ImGui::TextColored(ImColor(170, 170, 170), OBFUSCATE("SETTINGS RAID:"));
            ImGui::Separator();
            ImGui::EndChild();
        }
        
        if (Page == 7) {
            ImGui::SetCursorPos(CurPos);
            ImGui::BeginChild(OBFUSCATE("## PAGE - MAIN"), ImVec2(-0, -0), true);
            
            ImGui::TextColored(ImColor(170, 170, 170), OBFUSCATE("MAIN"));
            ImGui::Separator();
            ImGui::Spacing();
            time_t now = time(0);
            tm* ltm = localtime(&now);
            char t_time[80]; char t_data[80];
            strftime(t_time, 80, OBFUSCATE("%d.%m.%Y"), ltm);
            strftime(t_data, 80, OBFUSCATE("%H:%M:%S"), ltm);
            
            ImGui::Checkbox(OBFUSCATE("SHOW WATERMARK"), &Watermark_Bool);
            ImGui::Checkbox(Language ? OBFUSCATE("BUTTON POS") : OBFUSCATE("BUTTON POS"), &changepos);
            if(changepos){
                butpos = 0.10f;
            } else {
                butpos = 0.98f;
            }
            
			
            ImGui::Checkbox(OBFUSCATE("FAST OPEN ESP"), &fastopenesp);
            if(fastopenesp){
                ESPVar.ESP = true;
                ESPVar.ESPLine = true;
                ESPVar.ESPBox = true;
                ESPVar.ESPName = true;
                ESPVar.ESPHealth = true;
                ESPVar.ESPCount = true;
                ESPVar.ESPSkeleton = true;
                ESPVar.ESPDistance = true;
                ESPVar.ESPGunName = true;
            } else {
                ESPVar.ESP = false;
                ESPVar.ESPLine = false;
                ESPVar.ESPBox = false;
                ESPVar.ESPName = false;
                ESPVar.ESPHealth = false;
                ESPVar.ESPCount = false;
                ESPVar.ESPSkeleton = false;
                ESPVar.ESPDistance = false;
                ESPVar.ESPGunName = false;
            }
			
			if(Player != 0){
				ImGui::Text("HAND ID: %i, VA: %p", itemid, &itemid);
                ImGui::Text("1. Head Position: X: %f, Y: %f, Z: %f", HeadPos.x, HeadPos.y, HeadPos.z);
                ImGui::Text("2. Collider ID: %i", collid);
                ImGui::Text("3. Distance: %f", dis);
                ImGui::Text("4. Layer: %i", layer);
                ImGui::Text("5. Point: X: %f, Y: %f, Z: %f", Point.x, Point.y, Point.z);
                ImGui::Text("6. Normal: X: %f, Y: %f, Z: %f", Normal.x, Normal.y, Normal.z);
                ImGui::Text("7. Origin: X: %f, Y: %f, Z: %f", Origin.x, Origin.y, Origin.z);
                ImGui::Text("8. Direction: X: %f, Y: %f, Z: %f", Dir.x, Dir.y, Dir.z);    
			} else {
				ImGui::Text("ID null");
			}
             
			if(Battle != 0){
				ImGui::TextColored(ImColor(34, 139, 34),Language ? OBFUSCATE("自動旁路：工作") : OBFUSCATE("AUTO BYPASS: WORK"));
				BP = true;
			} else {
				ImGui::TextColored(ImColor(255, 0, 0), Language ? OBFUSCATE("自動旁路：等待...") : OBFUSCATE("AUTO BYPASS: WAITING..."));
				BP = false;
			}
			if(BP){
                    hexPatches.BP1.Modify();
                    hexPatches.BP2.Modify();
                    hexPatches.BP3.Modify();
                    hexPatches.BP4.Modify();
                    hexPatches.BP5.Modify();
                    hexPatches.BP6.Modify();
                    hexPatches.BP7.Modify();
                    hexPatches.BP8.Modify();
                    hexPatches.BP9.Modify();
                    hexPatches.BP10.Modify();
                    hexPatches.BP11.Modify();
                    hexPatches.BP12.Modify();
                    hexPatches.BP13.Modify();
                    hexPatches.BP14.Modify();
                    hexPatches.BP15.Modify();
                    hexPatches.BP16.Modify();
                    hexPatches.BP17.Modify();
                    hexPatches.BP18.Modify();
                    hexPatches.BP19.Modify();
                    hexPatches.BP20.Modify();
                    hexPatches.BP21.Modify();
                    hexPatches.BP22.Modify();
                    hexPatches.BP23.Modify();
                    hexPatches.BP24.Modify();
                    hexPatches.BP25.Modify();
                    hexPatches.BP26.Modify();
                    hexPatches.BP27.Modify();
                    hexPatches.BP28.Modify();
                    hexPatches.BP29.Modify();
                    hexPatches.BP30.Modify();
                    hexPatches.BP31.Modify();
                    hexPatches.BP32.Modify();
                    hexPatches.BP33.Modify();
                    hexPatches.BP34.Modify();
                    hexPatches.BP35.Modify();
                    hexPatches.BP36.Modify();
                    hexPatches.BP37.Modify();
                    hexPatches.BP38.Modify();
                    hexPatches.BP39.Modify();
                    hexPatches.BP40.Modify();
                    hexPatches.BP41.Modify();
                    hexPatches.BP42.Modify();
                    //BP = false;
                }
			
            ImGui::Checkbox(Language ? OBFUSCATE("KNIFE TRACK") : OBFUSCATE("Tesot"), &test);
            
			ImGui::PopFont();
			ImGui::PushFont(ChinaFont);
			bool checked = Language;
   		 	ImGui::Checkbox(Language ? OBFUSCATE("ENGLISH") : OBFUSCATE("中国"), &checked);
    		Language = checked;
            ImGui::PopFont();
            ImGui::EndChild();
        }
        ImGui::End();
    }
}

void LoadMenu(){
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplAndroid_NewFrame(glWidth, glHeight);
    ImGui::NewFrame();
    
	
    hexPatches.VIRT.Modify();
    hexPatches.ROOT.Modify();
    hexPatches.GG.Modify();
    hexPatches.EMULATOR.Modify();
    
    
    ImGui::PushFont(ChinaFont);
    DrawESP();
    //MonsterESP();
    //VehicleESP();
    MineESP();
    ImGui::PopFont();
    RenderToast();
    MainMenu::Menu();
    MainMenu::FlyMenu();
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}


