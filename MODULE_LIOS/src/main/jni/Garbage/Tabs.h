namespace Tabs {

    bool RenderTabs(const char* label, const char* icon, const bool selected, const ImVec2& size_arg) {
            ImGuiWindow* window = ImGui::GetCurrentWindow();
            if (window->SkipItems)
                return false;

            ImGuiContext& g = *GImGui;
            const ImGuiStyle& style = g.Style;
            const ImGuiID id = window->GetID(label);
            const ImVec2 label_size = ImGui::CalcTextSize(label, NULL, true);

            ImVec2 pos = window->DC.CursorPos;
            ImVec2 size = ImGui::CalcItemSize(size_arg, label_size.x + style.FramePadding.x * 2.0f, label_size.y + style.FramePadding.y * 2.0f);
            const ImRect bb(pos, { pos.x + size.x , pos.y + size.y });

            ImGui::ItemSize(size, style.FramePadding.y);
            if (!ImGui::ItemAdd(bb, id))
                return false;

            bool hovered, held;
            bool pressed = ImGui::ButtonBehavior(bb, id, &hovered, &held, NULL);
        
            float deltatime = 1.5f * ImGui::GetIO().DeltaTime;
            static std::map<ImGuiID, float> hover_animation;
            auto it_hover = hover_animation.find(id);
        
            if (it_hover == hover_animation.end()) {
                hover_animation.insert({ id, 0.f });
                it_hover = hover_animation.find(id);
            }

            it_hover->second = std::clamp(it_hover->second + (2.15f * ImGui::GetIO().DeltaTime *   (hovered ? 1.f : -1.f)), 0.0f, 0.0f);
            it_hover->second *= ImGui::GetStyle().Alpha;

            static std::map<ImGuiID, float> filled_animation;
            auto it_filled = filled_animation.find(id);

            if (it_filled == filled_animation.end()) {
                filled_animation.insert({ id, 0.f });
                it_filled = filled_animation.find(id);
            }

            it_filled->second = std::clamp(it_filled->second + (2.15f * ImGui::GetIO().DeltaTime * (selected ? 1.f : -1.5f)), it_hover->second, 1.f);
            it_filled->second *= ImGui::GetStyle().Alpha;
        
            if (selected) {
            window->DrawList->AddRectFilled(bb.Min, bb.Max,ImColor(43, 42, 50,int(240 * ImGui::GetStyle().Alpha)),4.f);
        }
        else
            window->DrawList->AddRectFilled(bb.Min, bb.Max,ImColor(0,0,0,int(0 * ImGui::GetStyle().Alpha)),4.f);       

        ImGui::PushFont(DefualtFont);
        if (selected)
            window->DrawList->AddText({ bb.Min.x + 55,bb.Min.y + size_arg.y / 2 - ImGui::CalcTextSize(label).y / 2  }, ImColor(255,255,255, int(255 * it_filled->second)), label);
        else
            window->DrawList->AddText({ bb.Min.x + 55,bb.Min.y + size_arg.y / 2 - ImGui::CalcTextSize(label).y / 2  }, ImColor(200,200,200, int(255 * ImGui::GetStyle().Alpha)), label);
        ImGui::PopFont();

        ImGui::PushFont(IconsFont);
        if(selected)
            window->DrawList->AddText({ bb.Min.x + 10,bb.Min.y + size_arg.y / 2 - ImGui::CalcTextSize(icon).y / 2 }, ImColor(130,141,255,int(255 * it_filled->second)), icon);
        else
            window->DrawList->AddText({ bb.Min.x + 10,bb.Min.y + size_arg.y/ 2 - ImGui::CalcTextSize(icon).y / 2 }, ImColor(200,200,200,int(255 * ImGui::GetStyle().Alpha)), icon);
        ImGui::PopFont();
            return pressed;
        }
        
        bool ChinaRender(const char* label, const char* icon, const bool selected, const ImVec2& size_arg) {
            ImGuiWindow* window = ImGui::GetCurrentWindow();
            if (window->SkipItems)
                return false;

            ImGuiContext& g = *GImGui;
            const ImGuiStyle& style = g.Style;
            const ImGuiID id = window->GetID(label);
            const ImVec2 label_size = ImGui::CalcTextSize(label, NULL, true);

            ImVec2 pos = window->DC.CursorPos;
            ImVec2 size = ImGui::CalcItemSize(size_arg, label_size.x + style.FramePadding.x * 2.0f, label_size.y + style.FramePadding.y * 2.0f);
            const ImRect bb(pos, { pos.x + size.x , pos.y + size.y });

            ImGui::ItemSize(size, style.FramePadding.y);
            if (!ImGui::ItemAdd(bb, id))
                return false;

            bool hovered, held;
            bool pressed = ImGui::ButtonBehavior(bb, id, &hovered, &held, NULL);
        
            float deltatime = 1.5f * ImGui::GetIO().DeltaTime;
            static std::map<ImGuiID, float> hover_animation;
            auto it_hover = hover_animation.find(id);
        
            if (it_hover == hover_animation.end()) {
                hover_animation.insert({ id, 0.f });
                it_hover = hover_animation.find(id);
            }

            it_hover->second = std::clamp(it_hover->second + (2.15f * ImGui::GetIO().DeltaTime *   (hovered ? 1.f : -1.f)), 0.0f, 0.0f);
            it_hover->second *= ImGui::GetStyle().Alpha;

            static std::map<ImGuiID, float> filled_animation;
            auto it_filled = filled_animation.find(id);

            if (it_filled == filled_animation.end()) {
                filled_animation.insert({ id, 0.f });
                it_filled = filled_animation.find(id);
            }

            it_filled->second = std::clamp(it_filled->second + (2.15f * ImGui::GetIO().DeltaTime * (selected ? 1.f : -1.5f)), it_hover->second, 1.f);
            it_filled->second *= ImGui::GetStyle().Alpha;
        
            if (selected) {
            window->DrawList->AddRectFilled(bb.Min, bb.Max,ImColor(43, 42, 50,int(240 * ImGui::GetStyle().Alpha)),4.f);
        }
        else
            window->DrawList->AddRectFilled(bb.Min, bb.Max,ImColor(0,0,0,int(0 * ImGui::GetStyle().Alpha)),4.f);       

        ImGui::PushFont(ChinaFont);
        if (selected)
            window->DrawList->AddText({ bb.Min.x + 55,bb.Min.y + size_arg.y / 2 - ImGui::CalcTextSize(label).y / 2  }, ImColor(255,255,255, int(255 * it_filled->second)), label);
        else
            window->DrawList->AddText({ bb.Min.x + 55,bb.Min.y + size_arg.y / 2 - ImGui::CalcTextSize(label).y / 2  }, ImColor(200,200,200, int(255 * ImGui::GetStyle().Alpha)), label);
        ImGui::PopFont();

        ImGui::PushFont(IconsFont);
        if(selected)
            window->DrawList->AddText({ bb.Min.x + 10,bb.Min.y + size_arg.y / 2 - ImGui::CalcTextSize(icon).y / 2 }, ImColor(130,141,255,int(255 * it_filled->second)), icon);
        else
            window->DrawList->AddText({ bb.Min.x + 10,bb.Min.y + size_arg.y/ 2 - ImGui::CalcTextSize(icon).y / 2 }, ImColor(200,200,200,int(255 * ImGui::GetStyle().Alpha)), icon);
        ImGui::PopFont();
            return pressed;
        }
    }
