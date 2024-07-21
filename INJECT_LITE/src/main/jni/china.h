void ChinaMenu() {
        
        
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
        ImGui::PushFont(ChinaFont);
        ImGui::Text(OBFUSCATE("视觉:"));
        if (Tabs::ChinaRender(OBFUSCATE("超感知觉"), OBFUSCATE("K"), Page == 1, {175, 45})) Page = 1;
        ImGui::Text(OBFUSCATE("功能:"));
        if (Tabs::ChinaRender(OBFUSCATE("武器"), OBFUSCATE("A"), Page == 2, {175, 45})) Page = 2;
        if (Tabs::ChinaRender(OBFUSCATE("玩家"), OBFUSCATE("I"), Page == 3, {175, 45})) Page = 3;
        if (Tabs::ChinaRender(OBFUSCATE("车辆"), OBFUSCATE("J"), Page == 4, {175, 45})) Page = 4;
        if (Tabs::ChinaRender(OBFUSCATE("建筑"), OBFUSCATE("B"), Page == 5, {175, 45})) Page = 5;
        if (Tabs::ChinaRender(OBFUSCATE("突袭"), OBFUSCATE("P"), Page == 6, {175, 45})) Page = 6;
        ImGui::Text(OBFUSCATE("其他:"));
        if (Tabs::ChinaRender(OBFUSCATE("主要"), OBFUSCATE("D"), Page == 7, {175, 45})) Page = 7;
        /*if (Tabs::RenderTabs(OBFUSCATE("NOWORK"), OBFUSCATE("P"), Page == 6, {175, 45})) Page = 6;
        if (Tabs::RenderTabs(OBFUSCATE("NOWORK2"), OBFUSCATE("Q"), Page == 7, {175, 45})) Page = 7;*/
        
        
        ImVec2 CurPos = ImVec2(195, 8);
        ImVec2 CurPos2 = ImVec2(497, 8);
        
        if (Page == 1) {
            ImGui::SetCursorPos(CurPos);
            ImGui::BeginChild(OBFUSCATE("## PAGE - ESP"), ImVec2(294, -0), true);
            ImGui::TextColored(ImColor(170, 170, 170), OBFUSCATE("敌人:"));
            ImGui::Separator();
            CheckBox(OBFUSCATE("绘制初始化"), &ESPVar.ESP);
            CheckBoxWithColorPicker(OBFUSCATE("射线"), &ESPVar.ESPLine, &ESPVar.ESPLineColorOnline);
            ImGui::RadioButton(OBFUSCATE("顶部"), &ESPVar.textPositionMode, 0);
            ImGui::SameLine();
            ImGui::RadioButton(OBFUSCATE("中心"), &ESPVar.textPositionMode, 1);
            ImGui::SameLine();
            ImGui::RadioButton(OBFUSCATE("底部"), &ESPVar.textPositionMode, 2);
            CheckBoxWithColorPicker(OBFUSCATE("方框"), &ESPVar.ESPBox, &ESPVar.ESPBoxColorOnline);
            CheckBoxWithColorPicker(OBFUSCATE("名字"), &ESPVar.ESPName, &ESPVar.ESPNameColor);
            CheckBoxWithColorPicker(OBFUSCATE("血量"), &ESPVar.ESPHealth, &ESPVar.ESPHealthColor);
            CheckBoxWithColorPicker(OBFUSCATE("数数"), &ESPVar.ESPCount, &ESPVar.ESPCountColor);
            CheckBoxWithColorPicker(OBFUSCATE("骨骼"), &ESPVar.ESPSkeleton, &ESPVar.ESPSkeletonColor);
            CheckBoxWithColorPicker(OBFUSCATE("距离"), &ESPVar.ESPDistance, &ESPVar.ESPDistanceColor);
            CheckBoxWithColorPicker(OBFUSCATE("武器"), &ESPVar.ESPGunName, &ESPVar.ESPGunNameColor);
            ImGui::Separator();
            ImGui::TextColored(ImColor(170, 170, 170), OBFUSCATE("莫恩斯特拉:"));
            ImGui::Separator();
            CheckBoxWithColorPicker(OBFUSCATE("怪物距离"), &ESPVar.ESPDistanceMonster, &ESPVar.ESPMonsterDistanceColor);
            CheckBoxWithColorPicker(OBFUSCATE("怪物名称"), &ESPVar.ESPNameMonster, &ESPVar.ESPMonsterNameColor);
            CheckBoxWithColorPicker(OBFUSCATE("怪物健康"), &ESPVar.ESPHealthMonster, &ESPVar.ESPMonsterHealthColor);
            ImGui::EndChild();
    
            ImGui::SetCursorPos(CurPos2);
            ImGui::BeginChild(OBFUSCATE("## PAGE - OTHER"), ImVec2(345, -0), true);
            ImGui::TextColored(ImColor(170, 170, 170), OBFUSCATE("车辆箭头:"));
            ImGui::Separator();
            CheckBoxWithColorPicker(OBFUSCATE("车距"), &ESPVar.ESPVehicleDistance, &ESPVar.ESPVehicleDistanceColor);
            CheckBoxWithColorPicker(OBFUSCATE("车辆系列"), &ESPVar.ESPVehicleLine, &ESPVar.ESPVehicleLineColor);
            CheckBoxWithColorPicker(OBFUSCATE("车辆名称"), &ESPVar.ESPVehicleName, &ESPVar.ESPVehicleNameColor);
            ImGui::Separator();
            ImGui::TextColored(ImColor(170, 170, 170), OBFUSCATE("矿箭头:"));
            ImGui::Separator();
            CheckBoxWithColorPicker(OBFUSCATE("矿线"), &ESPVar.ESPMineLine, &ESPVar.ESPMineLineColor);
            CheckBoxWithColorPicker(OBFUSCATE("矿井名称"), &ESPVar.ESPMineName, &ESPVar.ESPMineNameColor);
            CheckBoxWithColorPicker(OBFUSCATE("地雷距离"), &ESPVar.ESPMineDistance, &ESPVar.ESPMineDistanceColor);
            if (ImGui::TreeNode("我的设置")) {
                ImGui::Checkbox(OBFUSCATE("石头"), &ESPVar.Stone);
                ImGui::Checkbox(OBFUSCATE("硫"), &ESPVar.Sulfur);
                ImGui::Checkbox(OBFUSCATE("泰坦"), &ESPVar.Titan);
                ImGui::Checkbox(OBFUSCATE("铁"), &ESPVar.Iron);
                
                ImGui::TreePop(); 
            }
            ImGui::Separator();
            
      
            ImGui::EndChild();
        }
        
        if (Page == 2) {
            ImGui::SetCursorPos(CurPos);
            ImGui::BeginChild(OBFUSCATE("## PAGE - WEAPON"), ImVec2(294, -0), true);
            ImGui::TextColored(ImColor(170, 170, 170), OBFUSCATE("武器菜单:"));
            ImGui::Separator();
            ImGui::Checkbox(OBFUSCATE("子弹追踪"), &BulletData.bullet);
            ImGui::Checkbox(OBFUSCATE("射速"), &GunData.FastShoot);
            ImGui::Checkbox(OBFUSCATE("无后坐力"), &GunData.NoRecoil);
            
            ImGui::EndChild();
    
            ImGui::SetCursorPos(CurPos2);
            ImGui::BeginChild(OBFUSCATE("## PAGE - SETTINGS"), ImVec2(345, -0), true);
            ImGui::TextColored(ImColor(170, 170, 170), OBFUSCATE("设置武器:"));
            ImGui::Separator();
            if(ImGui::Combo("骨", &boneint, OBFUSCATE("头部\0身体\0"))){
                switch(boneint){
                    case 0:
                        CustomBone = 0;
                    break;
                    case 1:
                        CustomBone = 1;
                    break;
                }
            }
            ImGui::SliderInt(OBFUSCATE("数数"), &GunData.ShootNumber, 0, 10);
            
            ImGui::Checkbox(OBFUSCATE("视场角"), &ESPVar.FOV);
            ImGui::Checkbox(OBFUSCATE("子弹线"), &ESPVar.BulletLine);         
            ImGui::SliderFloat(OBFUSCATE("半径"), &AimFov, 0.f, 900.f);
            if(ImGui::Button(OBFUSCATE("全屏"), ImVec2(300, 70))){
              AimFov = 1150;
            }
            ImGui::EndChild();
        }
        
        if (Page == 3) {
            ImGui::SetCursorPos(CurPos);
            ImGui::BeginChild(OBFUSCATE("## PAGE - PLAYER"), ImVec2(294, -0), true);
            ImGui::TextColored(ImColor(170, 170, 170), OBFUSCATE("播放器菜单:"));
            ImGui::Separator();
            ImGui::Checkbox(OBFUSCATE("飞人"), &flymenu);
            if(ImGui::Checkbox(OBFUSCATE("水下"), &swim)){
                if(swim){
                    hexPatches.Swim.Modify();
                } else {
                    hexPatches.Swim.Restore();
                }
            }
            ImGui::Checkbox(OBFUSCATE("黏"), &MyPlayerData.Sticky);
            ImGui::Checkbox(OBFUSCATE("隐藏树"), &Texture.tree);                      
            ImGui::Checkbox(OBFUSCATE("隐藏草"), &Texture.grass);                      
            ImGui::Checkbox(OBFUSCATE("隐藏东西"), &Texture.things);
            if(ImGui::Checkbox(OBFUSCATE("阻止怪物"), &MonsterData.StopMonster)){
                if(MonsterData.StopMonster){
                    hexPatches.Stop.Modify();
                } else {
                    hexPatches.Stop.Restore();
                }
            }
            ImGui::Checkbox(OBFUSCATE("穿透机甲"), &MechaData.Collision);
            ImGui::Checkbox(OBFUSCATE("快速打击"), &MyPlayerData.Drink);
            ImGui::Checkbox(OBFUSCATE("喝水"), &MyPlayerData.Drink);
            ImGui::Checkbox(OBFUSCATE("绿色名称"), &GreenName);
			if(GreenName){
                hexPatches.UM.Modify();
            } else {
                hexPatches.UM.Restore();
            }
			ImGui::Checkbox(OBFUSCATE("汽车农场"), &MyPlayerData.AutoFarm);
            ImGui::Checkbox(OBFUSCATE("无震动"), &MyPlayerData.NoShake);
			ImGui::Checkbox(OBFUSCATE("隐身"), &MyPlayerData.Animator);
			
            ImGui::EndChild();
    
            ImGui::SetCursorPos(CurPos2);
            ImGui::BeginChild(OBFUSCATE("## PAGE - SETTINGS"), ImVec2(345, -0), true);
            ImGui::TextColored(ImColor(170, 170, 170), OBFUSCATE("设置播放器:"));
            ImGui::Separator();
            ImGui::SliderFloat(OBFUSCATE("速度"), &MyPlayerData.FlySpeed, 0.f, 1.f);
            ImGui::SliderFloat(OBFUSCATE("高度"), &MyPlayerData.Height, 0.f, 1.f);
            ImGui::SliderFloat2(OBFUSCATE("菜单销售点"), (float*)&WindowPos, 0.0f, 2040.0f, "%.2f");
            ImGui::SliderFloat(OBFUSCATE("速度人"), &MyPlayerData.Speed, -50.f, 50.f);
            ImGui::SliderFloat(OBFUSCATE("力人"), &MyPlayerData.Force, -50.f, 50.f);
			if (ImGui::TreeNode("我的设置")) {
                ImGui::Checkbox(OBFUSCATE("石头"), &ESPVar.Stone);
                ImGui::Checkbox(OBFUSCATE("硫"), &ESPVar.Sulfur);
                ImGui::Checkbox(OBFUSCATE("泰坦"), &ESPVar.Titan);
                ImGui::Checkbox(OBFUSCATE("铁"), &ESPVar.Iron);
                ImGui::TreePop(); 
            }
			ImGui::RadioButton(OBFUSCATE("司机"), &MyPlayerData.Mode, 0);
            ImGui::SameLine();
            ImGui::RadioButton(OBFUSCATE("蹲伏"), &MyPlayerData.Mode, 1);
			ImGui::SameLine();
            ImGui::RadioButton(OBFUSCATE("爬行"), &MyPlayerData.Mode, 2);
			ImGui::RadioButton(OBFUSCATE("睡觉"), &MyPlayerData.Mode, 3);
			ImGui::SameLine();
			ImGui::RadioButton(OBFUSCATE("敲"), &MyPlayerData.Mode, 4);
			
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
            ImGui::TextColored(ImColor(170, 170, 170), OBFUSCATE("车辆菜单:"));
            ImGui::Separator();
            ImGui::Checkbox(OBFUSCATE("飞行器"), &vehiclemenu);
            if(vehiclemenu){
                flymenu = true;
            }
            ImGui::EndChild();
    
            ImGui::SetCursorPos(CurPos2);
            ImGui::BeginChild(OBFUSCATE("## PAGE - SETTINGS"), ImVec2(345, -0), true);
            ImGui::TextColored(ImColor(170, 170, 170), OBFUSCATE("设置车辆:"));
            ImGui::Separator();
            ImGui::SliderFloat(OBFUSCATE("速度"), &VehicleData.Speed, 0.f, 32.f);
            ImGui::SliderFloat(OBFUSCATE("力量"), &VehicleData.Force, 0.f, 100.f);
            ImGui::SliderFloat(OBFUSCATE("高度"), &VehicleData.Height, 1.f, 5.f);
            ImGui::SliderFloat2(OBFUSCATE("菜单销售点"), (float*)&WindowPos, 0.0f, 2040.0f, "%.2f");
            ImGui::EndChild();
        }
        
        if (Page == 5) {
            ImGui::SetCursorPos(CurPos);
            ImGui::BeginChild(OBFUSCATE("## PAGE - BUILDING"), ImVec2(294, -0), true);
            ImGui::TextColored(ImColor(170, 170, 170), OBFUSCATE("建筑菜单:"));
            ImGui::Separator();
            ImGui::Checkbox(OBFUSCATE("强制构建"), &BuilderData.ForceBuild);           
            if(ImGui::Checkbox(OBFUSCATE("假主人"), &fakeowner)){
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
            if(ImGui::Checkbox(OBFUSCATE("允许操作"), &own1)){
               if(own1){
                   hexPatches.PR1.Modify();
               } else {
                   hexPatches.PR1.Restore();
               }
           }
           if(ImGui::Checkbox(OBFUSCATE("有许可证"), &own2)){
               if(own2){
                   hexPatches.PR2.Modify();
               } else {
                   hexPatches.PR2.Restore();
               }
           }
           if(ImGui::Checkbox(OBFUSCATE("可以更新"), &own3)){
               if(own3){
                   hexPatches.PR3.Modify();
               } else {
                   hexPatches.PR3.Restore();
               }
           }
           if(ImGui::Checkbox(OBFUSCATE("可以建造"), &own4)){
                if(own4){
                    hexPatches.PR4.Modify();
                } else {
                    hexPatches.PR4.Restore();
                }
            }
            ImGui::EndChild();
    
            ImGui::SetCursorPos(CurPos2);
            ImGui::BeginChild(OBFUSCATE("## PAGE - SETTINGS"), ImVec2(345, -0), true);
            ImGui::TextColored(ImColor(170, 170, 170), OBFUSCATE("设置大厦:"));
            ImGui::Separator();
            ImGui::SliderFloat(OBFUSCATE("X"), &BuilderData.x, -360.f, 360.f);
            ImGui::SliderFloat(OBFUSCATE("Y"), &BuilderData.y, -360.f, 360.f);
            ImGui::SliderFloat(OBFUSCATE("Z"), &BuilderData.z, -360.f, 360.f);
            ImGui::EndChild();
        }
        
        if (Page == 6) {
            ImGui::SetCursorPos(CurPos);
            ImGui::BeginChild(OBFUSCATE("## PAGE - RAID"), ImVec2(294, -0), true);
            ImGui::TextColored(ImColor(170, 170, 170), OBFUSCATE("RAID菜单:"));
            ImGui::Separator();           
            if(ImGui::Checkbox(OBFUSCATE("炸弹飞溅"), &HeatData.Splash)){
                if(HeatData.Splash){
                    hexPatches.Splash.Modify();
                } else {
                    hexPatches.Splash.Restore();
                }
            }
            ImGui::Checkbox(OBFUSCATE("快速爆炸"), &FastBoom);
            if(FastBoom){
                hexPatches.FB.Modify();
            } else {
                hexPatches.FB.Restore();
            }
            ImGui::EndChild();
    
            ImGui::SetCursorPos(CurPos2);
            ImGui::BeginChild(OBFUSCATE("## PAGE - SETTINGS"), ImVec2(345, -0), true);
            ImGui::TextColored(ImColor(170, 170, 170), OBFUSCATE("设置RAID:"));
            ImGui::Separator();
            ImGui::EndChild();
        }
        
        if (Page == 7) {
            ImGui::SetCursorPos(CurPos);
            ImGui::BeginChild(OBFUSCATE("## PAGE - MAIN"), ImVec2(-0, -0), true);
            
            ImGui::TextColored(ImColor(170, 170, 170), OBFUSCATE("主要的"));
            ImGui::Separator();
            ImGui::Spacing();
            time_t now = time(0);
            tm* ltm = localtime(&now);
            char t_time[80]; char t_data[80];
            strftime(t_time, 80, OBFUSCATE("%d.%m.%Y"), ltm);
            strftime(t_data, 80, OBFUSCATE("%H:%M:%S"), ltm);
            
            ImGui::Checkbox(OBFUSCATE("显示水印"), &Watermark_Bool);
            
            ImGui::Checkbox(OBFUSCATE("按钮POS"), &changepos);
            if(changepos){
                butpos = 0.10f;
            } else {
                butpos = 0.98f;
            }
            ImGui::Checkbox(OBFUSCATE("快速打开超感知觉"), &fastopenesp);
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
            if(ImGui::Checkbox(OBFUSCATE("旁路"), &BP)){
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
                    hexPatches.BP43.Modify();
                    hexPatches.BP44.Modify();
                    hexPatches.BP45.Modify();
                    hexPatches.BP46.Modify();
                    hexPatches.BP47.Modify();
                    hexPatches.BP48.Modify();
                    
                    hexPatches.BP49.Modify();
                    hexPatches.BP50.Modify();
                    hexPatches.BP51.Modify();
                    hexPatches.BP52.Modify();
                    hexPatches.BP53.Modify();
                    hexPatches.BP54.Modify();
                    hexPatches.BP55.Modify();
                    hexPatches.BP55.Modify();
                    hexPatches.BP56.Modify();
                    hexPatches.BP57.Modify();
                    hexPatches.BP58.Modify();
                    hexPatches.BP59.Modify();
                    hexPatches.BP60.Modify();
                    hexPatches.BP61.Modify();
                    hexPatches.BP62.Modify();
                    hexPatches.BP63.Modify();
                    hexPatches.BP64.Modify();
                    hexPatches.BP65.Modify();
                    hexPatches.BP66.Modify();
                    hexPatches.BP67.Modify();
                    hexPatches.BP68.Modify();
                    hexPatches.BP69.Modify();
                    hexPatches.BP70.Modify();
                    hexPatches.BP71.Modify();
                    hexPatches.BP72.Modify();
                    hexPatches.BP73.Modify();
                    hexPatches.BP74.Modify();
                    hexPatches.BP75.Modify();
                    hexPatches.BP76.Modify();
                    hexPatches.BP77.Modify();
                    hexPatches.BP78.Modify();
                    hexPatches.BP79.Modify();
                    hexPatches.BP80.Modify();
                    hexPatches.BP81.Modify();
                    hexPatches.BP82.Modify();
                    hexPatches.BP83.Modify();
                    hexPatches.BP84.Modify();
                    hexPatches.BP85.Modify();
                    hexPatches.BP86.Modify();
                    hexPatches.BP87.Modify();
                    hexPatches.BP88.Modify();
                    hexPatches.BP89.Modify();
                    hexPatches.BP90.Modify();
                    
                    hexPatches.BP91.Modify();
                    hexPatches.BP92.Modify();
                    hexPatches.BP93.Modify();
                    hexPatches.BP94.Modify();
                    hexPatches.BP95.Modify();
                    hexPatches.BP96.Modify();
                    hexPatches.BP97.Modify();
                    hexPatches.BP98.Modify();
                    hexPatches.BP99.Modify();
                    hexPatches.BP100.Modify();
                    hexPatches.BP101.Modify();
                    hexPatches.BP102.Modify();
                    hexPatches.BP103.Modify();
                    hexPatches.BP104.Modify();
                    hexPatches.BP105.Modify();
                    hexPatches.BP106.Modify();
                    hexPatches.BP107.Modify();
                    hexPatches.BP108.Modify();
                    
                    hexPatches.BP109.Modify();
                    hexPatches.BP110.Modify();
                    hexPatches.BP111.Modify();
                    hexPatches.BP112.Modify();
                    hexPatches.BP113.Modify();
                    hexPatches.BP114.Modify();
                    hexPatches.BP115.Modify();
                    hexPatches.BP116.Modify();
                    hexPatches.BP117.Modify();
                    hexPatches.BP118.Modify();
                    hexPatches.BP119.Modify();
                    hexPatches.BP120.Modify();
                    hexPatches.BP121.Modify();
                    hexPatches.BP122.Modify();
                    hexPatches.BP123.Modify();
                    hexPatches.BP124.Modify();
                    hexPatches.BP125.Modify();
                    hexPatches.BP126.Modify();
                    hexPatches.BP127.Modify();
                    hexPatches.BP128.Modify();
                    hexPatches.BP129.Modify();
                    hexPatches.BP130.Modify();
                    hexPatches.BP131.Modify();
                    hexPatches.BP132.Modify();
                    hexPatches.BP133.Modify();
                }
            }
            ImGui::EndChild();
            ImGui::PopFont();
        }
        ImGui::End();
        
    }
