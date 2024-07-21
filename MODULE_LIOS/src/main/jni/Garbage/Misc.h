void TextShadow(const char* v) {
    auto cur = ImGui::GetCursorPos();
    ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0,0,0,1));
    ImGui::Text(v);
    ImGui::PopStyleColor();
    ImGui::Text(v);
}

void TextGradient(const char* text, ImVec4 color1, ImVec4 color2) {
    ImVec2 pos = ImGui::GetCursorScreenPos();
    ImDrawList* drawList = ImGui::GetWindowDrawList();
    for (int i = 0; i < strlen(text); i++) {
        float t = (float)i / (float)strlen(text);
        ImVec4 color = ImVec4(ImLerp(color1.x, color2.x, t), ImLerp(color1.y, color2.y, t), ImLerp(color1.z, color2.z, t), ImLerp(color1.w, color2.w, t));
        drawList->AddText(pos, ImGui::GetColorU32(color), &text[i], &text[i + 1]);
        pos.x += ImGui::CalcTextSize(&text[i], &text[i + 1]).x;
    }
}

void DrawLineGlowW(ImVec2 start,ImVec2 end,ImColor col,float size, int gsize) {
    ImGui::GetBackgroundDrawList()->AddLine(start,end,col,size);
    for(int i = 0; i < gsize; i++) {
        ImGui::GetBackgroundDrawList()->AddLine(start,end,ImColor(col.Value.x,col.Value.y,col.Value.z,col.Value.w * (1.0f / (float)gsize) * (((float)(gsize - i))/(float)gsize)),size + i);
        }
    }

void DrawLineGlow(ImVec2 start,ImVec2 end,ImVec4 col,float size, int gsize) {
    ImGui::GetBackgroundDrawList()->AddLine(start,end,ImGui::GetColorU32(col),size);
    for(int i = 0; i < gsize; i++) {
        ImGui::GetBackgroundDrawList()->AddLine(start,end,ImGui::GetColorU32(ImVec4(col.x,col.y,col.z,col.w * (1.0f / (float)gsize) * (((float)(gsize - i))/(float)gsize))),size + i);
        }
    }
    
 void WatermarkLineGlow(ImVec2 start,ImVec2 end,ImColor col,float size, int gsize) {
        ImGui::GetBackgroundDrawList()->AddLine(start,end,col,size);
        for(int i = 0; i < gsize; i++) {
            ImGui::GetBackgroundDrawList()->AddLine(start,end,ImColor(col.Value.x,col.Value.y,col.Value.z,col.Value.w * (1.0f / (float)gsize) * (((float)(gsize - i))/(float)gsize)),size + i);
        }
    }


float toasttimer = 0;
float toastmaxtime = 0;
const char* toasttext = 0;

void Toast(const char *text, int length = 1) {
    toasttext = text;
    toasttimer = length;
    toastmaxtime = length;
}

void RenderToast() {
    ImGuiIO &io = ImGui::GetIO();
    if (toasttimer <= 0)
        return;
        
        toasttimer -= io.DeltaTime;
        float alpha;
        
        if (toasttimer >= 0.1f && toasttimer <= toastmaxtime - 0.1f) alpha = 1;
        if (toasttimer < 0.1f) alpha = toasttimer * 10;
        if (toasttimer > toastmaxtime - 0.1f) alpha = (toastmaxtime - toasttimer) * 10;

        ImGui::GetForegroundDrawList()->AddRectFilled(ImVec2(io.DisplaySize.x / 2 - ImGui::CalcTextSize(toasttext).x/2 - 20, io.DisplaySize.y * 0.8 - ImGui::CalcTextSize(toasttext).y/2 - 20 - alpha * 5),
        ImVec2(io.DisplaySize.x / 2 + ImGui::CalcTextSize(toasttext).x/2 + 20, io.DisplaySize.y * 0.8 + ImGui::CalcTextSize(toasttext).y/2 + 20 - alpha * 5),
        ImColor(0,0,0,85), 0);

        ImGui::GetForegroundDrawList()->AddText(ImVec2(io.DisplaySize.x / 2 - ImGui::CalcTextSize(toasttext).x/2, io.DisplaySize.y * 0.8 - ImGui::CalcTextSize(toasttext).y/2 - alpha * 5),
        ImColor(1.0f, 1.0f, 1.0f, alpha), toasttext);
    }

void TextCentered(std::string text) {
    auto windowWidth = ImGui::GetWindowSize().x;
    auto textWidth = ImGui::CalcTextSize(text.c_str()).x;
    ImGui::SetCursorPosX((windowWidth - textWidth) * 0.5f);
    ImGui::Text(text.c_str());
}
