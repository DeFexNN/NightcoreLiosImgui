void DrawText2(float fontSize, ImVec2 position, ImVec4 color, const char *text, bool center = true) {
    auto background = ImGui::GetBackgroundDrawList();
    if(background) {
        if (center) {
            ImVec2 textSize = ImGui::CalcTextSize(text);
            ImVec2 centeredPosition = ImVec2(position.x - (textSize.x * 0.5f), position.y - (textSize.y * 0.5f));
            background->AddText(NULL, fontSize, centeredPosition, ImColor(color.x, color.y, color.z, color.w), text);
        } else {
            background->AddText(NULL, fontSize, position, ImColor(color.x, color.y, color.z, color.w), text);
        }
    }
}

Vector3 GetPosition(void *point){
    return get_position(get_transform(point));
}



