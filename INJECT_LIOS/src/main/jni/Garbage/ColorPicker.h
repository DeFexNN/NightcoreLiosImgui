void ColorPicker(const char* name, ImVec4 &color, bool prd = false, bool* rainbow = nullptr, bool* pulse = nullptr, bool* dark = nullptr) {
    ImGuiColorEditFlags misc_flags = ImGuiColorEditFlags_AlphaPreview;
    static ImVec4 backup_color;
    auto s = ImGui::GetWindowDrawList();
    
    bool open_popup = ImGui::ColorButton((std::string(name) + std::string(("##3b"))).c_str(), color, misc_flags);
    
    if (open_popup) {
        ImGui::OpenPopup(name);
        backup_color = color;
    }
    
    if (ImGui::BeginPopup(name)) {
        ImGui::Separator();
        ImGui::ColorPicker4(("##picker"), (float *) &color,misc_flags |ImGuiColorEditFlags_NoTooltip | ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_NoSmallPreview | ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_AlphaBar |ImGuiColorEditFlags_NoOptions );
        ImGui::EndPopup();
    }
}
