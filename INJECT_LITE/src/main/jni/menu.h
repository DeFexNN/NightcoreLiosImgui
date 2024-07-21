ImVec4 menu_accent = ImVec4(128 / 255.f, 134 / 255.f, 150 / 255.f, 255 / 255.f);
ImColor watermark_accent = ImColor(131, 141, 255);
bool menu, BP2, swim, fakeowner, own1, own2, own3, own4, GreenName, FastBoom = false;
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
    
    void EnglishMenu() {
        
        
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
        if (ImGui::Button(OBFUSCATE("TELEGRAM: @DeFexHacks VIP VERSION [LITE]"), ImVec2(500, 30))) menu = !menu;
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
        ImGui::PushFont(SmallFont);
        ImGui::Text(OBFUSCATE("VISUALS:"));
        if (Tabs::RenderTabs(OBFUSCATE("ESP"), OBFUSCATE("K"), Page == 1, {175, 45})) Page = 1;
        ImGui::Text(OBFUSCATE("FUNCTION:"));
        if (Tabs::RenderTabs(OBFUSCATE("WEAPON"), OBFUSCATE("A"), Page == 2, {175, 45})) Page = 2;
        if (Tabs::RenderTabs(OBFUSCATE("PLAYER"), OBFUSCATE("I"), Page == 3, {175, 45})) Page = 3;
        if (Tabs::RenderTabs(OBFUSCATE("VEHICLE"), OBFUSCATE("J"), Page == 4, {175, 45})) Page = 4;
        if (Tabs::RenderTabs(OBFUSCATE("BUILDING"), OBFUSCATE("B"), Page == 5, {175, 45})) Page = 5;
        if (Tabs::RenderTabs(OBFUSCATE("RAID"), OBFUSCATE("P"), Page == 6, {175, 45})) Page = 6;
        ImGui::Text(OBFUSCATE("MISC:"));
        if (Tabs::RenderTabs(OBFUSCATE("MAIN"), OBFUSCATE("D"), Page == 7, {175, 45})) Page = 7;
        /*if (Tabs::RenderTabs(OBFUSCATE("NOWORK"), OBFUSCATE("P"), Page == 6, {175, 45})) Page = 6;
        if (Tabs::RenderTabs(OBFUSCATE("NOWORK2"), OBFUSCATE("Q"), Page == 7, {175, 45})) Page = 7;*/
        ImGui::PopFont();
        
        ImVec2 CurPos = ImVec2(195, 8);
        ImVec2 CurPos2 = ImVec2(497, 8);
        
        if (Page == 1) {
            ImGui::SetCursorPos(CurPos);
            ImGui::BeginChild(OBFUSCATE("## PAGE - ESP"), ImVec2(294, -0), true);
            ImGui::TextColored(ImColor(170, 170, 170), OBFUSCATE("ENEMIES:"));
            ImGui::Separator();
            CheckBox(OBFUSCATE("OPEN"), &ESPVar.ESP);
            CheckBoxWithColorPicker(OBFUSCATE("LINE"), &ESPVar.ESPLine, &ESPVar.ESPLineColorOnline);
            ImGui::Separator();
            ImGui::RadioButton(OBFUSCATE("Top"), &ESPVar.textPositionMode, 0);
            ImGui::SameLine();
            ImGui::RadioButton(OBFUSCATE("Center"), &ESPVar.textPositionMode, 1);
            ImGui::SameLine();
            ImGui::RadioButton(OBFUSCATE("Bottom"), &ESPVar.textPositionMode, 2);
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
            ImGui::Checkbox(OBFUSCATE("BUTTON POS"), &changepos);
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
				/*ImGui::Text("Layer: %d", layer);
				ImGui::Text("Target State Name: %s", targetStateName->toChars());
				ImGui::Text("State Hash: %d", stateHash);
				ImGui::Text("Is Cross: %s", isCross ? "true" : "false");*/

			} else {
				ImGui::Text(OBFUSCATE("ID null"));
			}
			if(Player != 0){
				ImGui::TextColored(ImColor(111, 255, 0), OBFUSCATE("BYPASS ACTIVATED"));
				BP = true;
			} else {
				ImGui::TextColored(ImColor(255, 0, 0), OBFUSCATE("BYPASS IS NOT ACTIVE"));
				BP = false;
			}
            if(ImGui::Checkbox(OBFUSCATE("BYPASS 2.0"), &BP)){
                if(BP2){
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
            }
            
            ImGui::EndChild();
        }
        ImGui::End();
    }
    
    #include "china.h"
    bool langenglish = true;
    bool langchina = true;
    void SelectLanguage(){
        if(langenglish && langchina){
            ImGuiIO& io = ImGui::GetIO();
            ImVec2 windowSize = io.DisplaySize;
            ImVec2 buttonSize = ImVec2(80, 80);
            ImVec2 buttonPos(windowSize.x - buttonSize.x - 10, windowSize.y / 2 - buttonSize.y - 10);
            ImGui::SetNextWindowPos(LangPos);
            ImGui::SetNextWindowSize(ImVec2(400, 460));
            ImGui::Begin(OBFUSCATE("chinalang"), nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoBackground);
            
        
            if (ImGui::Button("EN", buttonSize)) {
                langenglish = false;
            } 

            ImGui::PushFont(ChinaFont);
            if (ImGui::Button("中国", buttonSize)) {
               langchina = false;
            } 
            ImGui::PopFont();
        }
        ImGui::End();
        
    }
    void LoadEnglish(){
        if(!langenglish){
            EnglishMenu();
        }
    }
    
    void LoadChina(){
        if(!langchina){
            ChinaMenu();
        }
    }
    
}



static bool showLoginMenu = true;
static std::string err;
void LoginMenu() {
    if (showLoginMenu) {
      ImGui::CreateContext();
      ImGui::StyleColorsDark();
      ImGuiStyle &style = ImGui::GetStyle();
      ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 6.0f);
      ImGui::PushStyleVar(ImGuiStyleVar_ChildBorderSize, 0.0f);
      ImGui::PushStyleVar(ImGuiStyleVar_PopupBorderSize, 0.0f);
      ImGui::PushStyleVar(ImGuiStyleVar_FrameRounding, 4.0f);
      ImGui::PushStyleVar(ImGuiStyleVar_ScrollbarRounding, 0.0f);
      ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.255f, 0.294f, 1.f, 0.5f));

      ImGuiIO& io = ImGui::GetIO();
      ImGui::SetNextWindowSize(ImVec2(400.000f, 480.000f), ImGuiCond_Once);
      ImGui::Begin("DEFEX PREMIUM", NULL, 3);

      ImVec2 P1, P2;
      ImDrawList* pDrawList;
      const auto& CurrentWindowPos = ImGui::GetWindowPos();
      const auto& pWindowDrawList = ImGui::GetWindowDrawList();
      const auto& pBackgroundDrawList = ImGui::GetBackgroundDrawList();
      const auto& pForegroundDrawList = ImGui::GetForegroundDrawList();

      P1 = ImVec2(6.000f, 8.000f);
      P1.x += CurrentWindowPos.x;
      P1.y += CurrentWindowPos.y;
      P2 = ImVec2(393.000f, 473.000f);
                P2.x += CurrentWindowPos.x;
                P2.y += CurrentWindowPos.y;
                pDrawList = pWindowDrawList;
                pDrawList->AddRectFilled(P1, P2, ImColor(0.157f, 0.275f, 0.353f, 1.000f), 5.000f);

                P1 = ImVec2(8.000f, 10.000f);
                P1.x += CurrentWindowPos.x;
                P1.y += CurrentWindowPos.y;
                P2 = ImVec2(391.000f, 471.000f);
                P2.x += CurrentWindowPos.x;
                P2.y += CurrentWindowPos.y;
                pDrawList = pWindowDrawList;
                pDrawList->AddRectFilled(P1, P2, ImColor(0.012f, 0.078f, 0.157f, 1.000f), 5.000f);

                P1 = ImVec2(25.000f, 450.000f);
                P1.x += CurrentWindowPos.x;
                P1.y += CurrentWindowPos.y;
                pDrawList = pWindowDrawList;
                pDrawList->AddCircleFilled(P1, 7.000f, ImColor(0.020f, 0.980f, 1.000f, 1.000f), 0);

                P1 = ImVec2(374.000f, 450.000f);
                P1.x += CurrentWindowPos.x;
                P1.y += CurrentWindowPos.y;
                pDrawList = pWindowDrawList;
                pDrawList->AddCircleFilled(P1, 7.000f, ImColor(0.020f, 0.980f, 1.000f, 1.000f), 0);

                P1 = ImVec2(30.000f, 448.000f);
                P1.x += CurrentWindowPos.x;
                P1.y += CurrentWindowPos.y;
                P2 = ImVec2(80.000f, 453.000f);
                P2.x += CurrentWindowPos.x;
                P2.y += CurrentWindowPos.y;
                pDrawList = pWindowDrawList;
                pDrawList->AddRectFilledMultiColor(P1, P2,
                                                   ImColor(0.020f, 0.980f, 1.000f, 1.000f),
                                                   ImColor(0.012f, 0.078f, 0.157f, 1.000f),
                                                   ImColor(0.012f, 0.078f, 0.157f, 1.000f),
                                                   ImColor(0.020f, 0.980f, 1.000f, 1.000f));

                P1 = ImVec2(23.000f, 395.000f);
                P1.x += CurrentWindowPos.x;
                P1.y += CurrentWindowPos.y;
                P2 = ImVec2(28.500f, 445.000f);
                P2.x += CurrentWindowPos.x;
                P2.y += CurrentWindowPos.y;
                pDrawList = pWindowDrawList;
                pDrawList->AddRectFilledMultiColor(P1, P2,
                                                   ImColor(0.012f, 0.078f, 0.157f, 1.000f),
                                                   ImColor(0.012f, 0.078f, 0.157f, 1.000f),
                                                   ImColor(0.020f, 0.980f, 1.000f, 1.000f),
                                                   ImColor(0.020f, 0.980f, 1.000f, 1.000f));

                P1 = ImVec2(321.000f, 453.000f);
                P1.x += CurrentWindowPos.x;
                P1.y += CurrentWindowPos.y;
                P2 = ImVec2(371.000f, 448.000f);
                P2.x += CurrentWindowPos.x;
                P2.y += CurrentWindowPos.y;
                pDrawList = pWindowDrawList;
                pDrawList->AddRectFilledMultiColor(P1, P2,
                                                   ImColor(0.012f, 0.078f, 0.157f, 1.000f),
                                                   ImColor(0.020f, 0.980f, 1.000f, 1.000f),
                                                   ImColor(0.012f, 0.980f, 1.000f, 1.000f),
                                                   ImColor(0.012f, 0.078f, 0.157f, 1.000f));

                P1 = ImVec2(371.500f, 395.000f);
                P1.x += CurrentWindowPos.x;
                P1.y += CurrentWindowPos.y;
                P2 = ImVec2(376.500f, 445.000f);
                P2.x += CurrentWindowPos.x;
                P2.y += CurrentWindowPos.y;
                pDrawList = pWindowDrawList;
                pDrawList->AddRectFilledMultiColor(P1, P2,
                                                   ImColor(0.012f, 0.078f, 0.157f, 1.000f),
                                                   ImColor(0.012f, 0.078f, 0.157f, 1.000f),
                                                   ImColor(0.020f, 0.980f, 1.000f, 1.000f),
                                                   ImColor(0.020f, 0.980f, 1.000f, 1.000f));

                P1 = ImVec2(90.000f, 170.000f);
                P1.x += CurrentWindowPos.x;
                P1.y += CurrentWindowPos.y;
                P2 = ImVec2(342.000f, 198.000f);
                P2.x += CurrentWindowPos.x;
                P2.y += CurrentWindowPos.y;
                pDrawList = pWindowDrawList;
                pDrawList->AddRect(P1, P2, ImColor(0.020f, 0.980f, 1.000f, 1.000f), 3.000f);

                P1 = ImVec2(200.000f, 290.000f);
                P1.x += CurrentWindowPos.x;
                P1.y += CurrentWindowPos.y;
                pDrawList = pWindowDrawList;
                pDrawList->AddCircleFilled(P1, 7.000f, ImColor(0.020f, 0.980f, 1.000f, 1.000f), 4);

                P1 = ImVec2(60.000f, 292.000f);
                P1.x += CurrentWindowPos.x;
                P1.y += CurrentWindowPos.y;
                P2 = ImVec2(200.000f, 289.000f);
                P2.x += CurrentWindowPos.x;
                P2.y += CurrentWindowPos.y;
                pDrawList = pWindowDrawList;
                pDrawList->AddRectFilledMultiColor(P1, P2,
                                                   ImColor(0.012f, 0.078f, 0.157f, 1.000f),
                                                   ImColor(0.020f, 0.980f, 1.000f, 1.000f),
                                                   ImColor(0.020f, 0.980f, 1.000f, 1.000f),
                                                   ImColor(0.012f, 0.008f, 0.157f, 1.000f));

                P1 = ImVec2(205.000f, 292.000f);
                P1.x += CurrentWindowPos.x;
                P1.y += CurrentWindowPos.y;
                P2 = ImVec2(340.000f, 289.000f);
                P2.x += CurrentWindowPos.x;
                P2.y += CurrentWindowPos.y;
                pDrawList = pWindowDrawList;
                pDrawList->AddRectFilledMultiColor(P1, P2,
                                                   ImColor(0.020f, 0.980f, 1.000f, 1.000f),
                                                   ImColor(0.012f, 0.078f, 0.157f, 1.000f),
                                                   ImColor(0.020f, 0.008f, 0.157f, 1.000f),
                                                   ImColor(0.012f, 0.980f, 1.000f, 1.000f));

                P1 = ImVec2(200.000f, 370.000f);
                P1.x += CurrentWindowPos.x;
                P1.y += CurrentWindowPos.y;
                P2 = ImVec2(300.000f, 372.000f);
                P2.x += CurrentWindowPos.x;
                P2.y += CurrentWindowPos.y;
                pDrawList = pWindowDrawList;
                //@Mr_TrojanOp
                pDrawList->AddRectFilledMultiColor(P1, P2,
                                                   ImColor(0.020f, 0.980f, 1.000f, 1.000f),
                                                   ImColor(0.012f, 0.078f, 0.157f, 1.000f),
                                                   ImColor(0.012f, 0.078f, 0.157f, 1.000f),
                                                   ImColor(0.020f, 0.980f, 1.000f, 1.000f));

                P1 = ImVec2(95.000f, 372.000f);
                P1.x += CurrentWindowPos.x;
                P1.y += CurrentWindowPos.y;
                P2 = ImVec2(200.000f, 370.000f);
                P2.x += CurrentWindowPos.x;
                P2.y += CurrentWindowPos.y;
                pDrawList = pWindowDrawList;
                pDrawList->AddRectFilledMultiColor(P1, P2,
                                                   ImColor(0.012f, 0.078f, 0.157f, 1.000f),
                                                   ImColor(0.020f, 0.980f, 1.000f, 1.000f),
                                                   ImColor(0.020f, 0.980f, 1.000f, 1.000f),
                                                   ImColor(0.012f, 0.078f, 0.157f, 1.000f));

                P1 = ImVec2(50.000f, 110.000f);
                P1.x += CurrentWindowPos.x;
                P1.y += CurrentWindowPos.y;
                P2 = ImVec2(205.000f, 112.000f);
                P2.x += CurrentWindowPos.x;
                P2.y += CurrentWindowPos.y;
                pDrawList = pWindowDrawList;
                pDrawList->AddRectFilledMultiColor(P1, P2,
                                                   ImColor(0.012f, 0.078f, 0.157f, 1.000f),
                                                   ImColor(0.020f, 1.000f, 1.000f, 1.000f),
                                                   ImColor(0.020f, 1.000f, 1.000f, 1.000f),
                                                   ImColor(0.012f, 0.078f, 0.157f, 1.000f));

                P1 = ImVec2(205.000f, 110.000f);
                P1.x += CurrentWindowPos.x;
                P1.y += CurrentWindowPos.y;
                P2 = ImVec2(354.000f, 112.000f);
                P2.x += CurrentWindowPos.x;
                P2.y += CurrentWindowPos.y;
                pDrawList = pWindowDrawList;
                pDrawList->AddRectFilledMultiColor(P1, P2,
                                                   ImColor(0.020f, 1.000f, 1.000f, 1.000f),
                                                   ImColor(0.012f, 0.078f, 0.157f, 1.000f),
                                                   ImColor(0.012f, 0.078f, 0.157f, 1.000f),
                                                   ImColor(0.020f, 1.000f, 1.000f, 1.000f));

                P1 = ImVec2(45.000f, 50.000f);
                P1.x += CurrentWindowPos.x;
                P1.y += CurrentWindowPos.y;
                pDrawList = pWindowDrawList;
                pDrawList->AddCircleFilled(P1, 7.000f, ImColor(1.000f, 1.000f, 1.000f, 1.000f), 4);

                P1 = ImVec2(15.000f, 49.000f);
                P1.x += CurrentWindowPos.x;
                P1.y += CurrentWindowPos.y;
                P2 = ImVec2(40.000f, 51.000f);
                P2.x += CurrentWindowPos.x;
                P2.y += CurrentWindowPos.y;
                pDrawList = pWindowDrawList;
                pDrawList->AddRectFilledMultiColor(P1, P2,
                                                   ImColor(0.012f, 0.078f, 0.157f, 1.000f),
                                                   ImColor(1.000f, 1.000f, 1.000f, 1.000f),
                                                   ImColor(1.000f, 1.000f, 1.000f, 1.000f),
                                                   ImColor(0.012f, 0.078f, 0.157f, 1.000f));

                P1 = ImVec2(50.000f, 51.000f);
                P1.x += CurrentWindowPos.x;
                P1.y += CurrentWindowPos.y;
                P2 = ImVec2(75.000f, 49.000f);
                P2.x += CurrentWindowPos.x;
                P2.y += CurrentWindowPos.y;
                pDrawList = pWindowDrawList;
                pDrawList->AddRectFilledMultiColor(P1, P2,
                                                   ImColor(1.000f, 1.000f, 1.000f, 1.000f),
                                                   ImColor(0.012f, 0.078f, 0.157f, 1.000f),
                                                   ImColor(0.012f, 0.078f, 0.157f, 1.000f),
                                                   ImColor(1.000f, 1.000f, 1.000f, 1.000f));

                P1 = ImVec2(44.000f, 20.000f);
                P1.x += CurrentWindowPos.x;
                P1.y += CurrentWindowPos.y;
                P2 = ImVec2(46.000f, 46.000f);
                P2.x += CurrentWindowPos.x;
                P2.y += CurrentWindowPos.y;
                pDrawList = pWindowDrawList;
                pDrawList->AddRectFilledMultiColor(P1, P2,
                                                   ImColor(0.012f, 0.078f, 0.157f, 1.000f),
                                                   ImColor(0.012f, 0.078f, 0.157f, 1.000f),
                                                   ImColor(1.000f, 1.000f, 1.000f, 1.000f),
                                                   ImColor(1.000f, 1.000f, 1.000f, 1.000f));

                P1 = ImVec2(44.000f, 54.000f);
                P1.x += CurrentWindowPos.x;
                P1.y += CurrentWindowPos.y;
                P2 = ImVec2(46.000f, 80.000f);
                P2.x += CurrentWindowPos.x;
                P2.y += CurrentWindowPos.y;
                pDrawList = pWindowDrawList;
                pDrawList->AddRectFilledMultiColor(P1, P2,
                                                   ImColor(1.000f, 1.000f, 1.000f, 1.000f),
                                                   ImColor(1.000f, 1.000f, 1.000f, 1.000f),
                                                   ImColor(0.012f, 0.078f, 0.157f, 1.000f),
                                                   ImColor(0.012f, 0.078f, 0.157f, 1.000f));

                P1 = ImVec2(345.000f, 50.000f);
                P1.x += CurrentWindowPos.x;
                P1.y += CurrentWindowPos.y;
                pDrawList = pWindowDrawList;
                pDrawList->AddCircleFilled(P1, 7.000f, ImColor(1.000f, 1.000f, 1.000f, 1.000f), 4);

                P1 = ImVec2(310.000f, 49.000f);
                P1.x += CurrentWindowPos.x;
                P1.y += CurrentWindowPos.y;
                P2 = ImVec2(340.000f, 51.000f);
                P2.x += CurrentWindowPos.x;
                P2.y += CurrentWindowPos.y;
                pDrawList = pWindowDrawList;
                pDrawList->AddRectFilledMultiColor(P1, P2,
                                                   ImColor(0.012f, 0.078f, 0.157f, 1.000f),
                                                   ImColor(1.000f, 1.000f, 1.000f, 1.000f),
                                                   ImColor(1.000f, 1.000f, 1.000f, 1.000f),
                                                   ImColor(0.012f, 0.078f, 0.157f, 1.000f));

                P1 = ImVec2(350.000f, 49.000f);
                P1.x += CurrentWindowPos.x;
                P1.y += CurrentWindowPos.y;
                P2 = ImVec2(380.000f, 51.000f);
                P2.x += CurrentWindowPos.x;
                P2.y += CurrentWindowPos.y;
                pDrawList = pWindowDrawList;
                pDrawList->AddRectFilledMultiColor(P1, P2,
                                                   ImColor(1.000f, 1.000f, 1.000f, 1.000f),
                                                   ImColor(0.012f, 0.078f, 0.157f, 1.000f),
                                                   ImColor(0.012f, 0.078f, 0.157f, 1.000f),
                                                   ImColor(1.000f, 1.000f, 1.000f, 1.000f));

                P1 = ImVec2(344.000f, 20.000f);
                P1.x += CurrentWindowPos.x;
                P1.y += CurrentWindowPos.y;
                P2 = ImVec2(346.000f, 46.000f);
                P2.x += CurrentWindowPos.x;
                P2.y += CurrentWindowPos.y;
                pDrawList = pWindowDrawList;
                pDrawList->AddRectFilledMultiColor(P1, P2,
                                                   ImColor(0.012f, 0.078f, 0.157f, 1.000f),
                                                   ImColor(0.012f, 0.078f, 0.157f, 1.000f),
                                                   ImColor(1.000f, 1.000f, 1.000f, 1.000f),
                                                   ImColor(1.000f, 1.000f, 1.000f, 1.000f));

                P1 = ImVec2(344.000f, 54.000f);
                P1.x += CurrentWindowPos.x;
                P1.y += CurrentWindowPos.y;
                P2 = ImVec2(346.000f, 80.000f);
                P2.x += CurrentWindowPos.x;
                P2.y += CurrentWindowPos.y;
                pDrawList = pWindowDrawList;
                pDrawList->AddRectFilledMultiColor(P1, P2,
                                                   ImColor(1.000f, 1.000f, 1.000f, 1.000f),
                                                   ImColor(1.000f, 1.000f, 1.000f, 1.000f),
                                                   ImColor(0.012f, 0.078f, 0.157f, 1.000f),
                                                   ImColor(0.012f, 0.078f, 0.157f, 1.000f));

        ImGui::SetCursorPos(ImVec2(130.000f, 90.000f));
        ImGui::Text("NIGHTCORE VIP LOGIN");
        ImGui::SetCursorPos(ImVec2(92.000f, 122.000f));
        ImGui::Text("https://t.me/defexhacks");
        ImGui::SetCursorPos(ImVec2(50.000f, 170.000f));
        ImGui::PushFont(IconsFont);
        ImGui::Button(ICON_FA_KEY"", ImVec2(35.000f, 30.000f));
        ImGui::SetCursorPos(ImVec2(50.000f, 210.000f));
        ImGui::Button(ICON_FA_KEYBOARD"", ImVec2(35.000f, 30.000f));
        ImGui::PopFont();
        ImGui::SetNextItemWidth(250.000f);
        ImGui::SetCursorPos(ImVec2(92.000f, 171.600f));
        static char s[64];
        ImGui::InputText("##key", s, sizeof s);
        ImGui::SetCursorPos(ImVec2(92.000f, 210.000f));
        if(ImGui::Button("PASTE YOUR KEY", ImVec2(250.000f, 30.000f))) {
                   
        }
        static std::string err;
        ImGui::SetCursorPos(ImVec2(125.000f, 320.000f));
        if (ImGui::Button("LOGIN", ImVec2(150.000f, 40.000f))) {
            showLoginMenu = false;
        }
        ImGui::PopStyleVar();
        ImGui::PopStyleColor();
    }
    ImGui::End();
}

void LoadMenu (){
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplAndroid_NewFrame(glWidth, glHeight);
    ImGui::NewFrame();
    LoginMenu();
	
    hexPatches.VIRT.Modify();
    hexPatches.ROOT.Modify();
    hexPatches.GG.Modify();
    hexPatches.EMULATOR.Modify();
    
    
    if (!showLoginMenu) {
        ImGui::PushFont(ChinaFont);
        DrawESP();
        MonsterESP();
        VehicleESP();
        MineESP();
        //DumpObjects();
        ImGui::PopFont();
        RenderToast();
        MainMenu::SelectLanguage();
        MainMenu::LoadEnglish();
        MainMenu::LoadChina();
        MainMenu::FlyMenu();
    }
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void LoginChecker(){
    LoadMenu();
    
}

