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

void *(*il2cpp_domain_get)();
void *(*il2cpp_object_new)(void *);
void *(*il2cpp_domain_assembly_open)(void *domain, const char *name);
void *(*il2cpp_assembly_get_image)(void *assembly);
void *(*il2cpp_class_from_name)(void *image, const char *namespaze, const char *name);
void *il2cpp_domain = NULL;

void *get_class(const char *assemblyName, const char *namespaze, const char *klassName) {
    auto assembly = il2cpp_domain_assembly_open(il2cpp_domain, assemblyName);
    auto image = il2cpp_assembly_get_image(assembly);
    return il2cpp_class_from_name(image, namespaze, klassName);
}
