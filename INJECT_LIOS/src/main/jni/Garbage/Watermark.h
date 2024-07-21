void Watermark() {
    ImGui::SetNextWindowPos(ImVec2(15,  10), ImGuiCond_Always);
    ImGui::SetNextWindowSize(ImVec2(55,  50), ImGuiCond_Always);

    if (ImGui::Begin("##Watermark", nullptr,
        ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | 
        ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoCollapse | 
        ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoFocusOnAppearing | 
        ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavInputs | ImGuiWindowFlags_NoNavFocus | 
        ImGuiWindowFlags_NoNav | ImGuiWindowFlags_NoDecoration)) {

        ImGui::PushFont(HorstFont);
        TextGradient(OBFUSCATE("NC"), ImVec4(1.0f, 1.0f, 1.0f, 1.0f), ImVec4(130 / 255.0f, 141 / 255.0f, 255 / 255.0f, 255 / 255.0f));
        ImGui::PopFont();
        
        ImGui::End();
    }
}

void Watermark1() {
    ImGui::SetNextWindowPos(ImVec2(75,  15), ImGuiCond_Always);
    ImGui::SetNextWindowSize(ImVec2(250,  40), ImGuiCond_Always);

    if (ImGui::Begin("##Watermark1", nullptr,
        ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | 
        ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoScrollWithMouse | ImGuiWindowFlags_NoCollapse | 
        ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoFocusOnAppearing | 
        ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavInputs | ImGuiWindowFlags_NoNavFocus | 
        ImGuiWindowFlags_NoNav | ImGuiWindowFlags_NoDecoration)) {

        ImGuiIO &io = ImGui::GetIO();
        time_t now = time(0);
        tm* ltm = localtime(&now);
        char buffer[80];
        strftime(buffer, 80, "%H:%M", ltm);
        std::string datatime = ("%s", buffer);

        int fps_counter = io.Framerate;
        std::string fpscounter = std::to_string(fps_counter);

        ImGui::TextColored(ImColor(150, 150, 150), " · ");
        ImGui::SameLine();
        ImGui::TextColored(ImColor(watermark_accent), "TIME: ");
        ImGui::SameLine();
        ImGui::Text(datatime.c_str());
        ImGui::SameLine(0, 2);
        ImGui::TextColored(ImColor(150, 150, 150), " I ");
        ImGui::SameLine();
        ImGui::TextColored(ImColor(watermark_accent), "FPS: ");
        ImGui::SameLine(0, 2);
        ImGui::Text(fpscounter.c_str());
        ImGui::SameLine();
        ImGui::TextColored(ImColor(150, 150, 150), " · ");

        ImGui::End();
    }
}

