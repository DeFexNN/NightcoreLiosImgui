#ifndef ImGuiAndroid_Draww
#define ImGuiAndroid_Draww

#include "ImGui/imgui_internal.h"
#include "Struc.h"
#include "Vector3.h"
#include "Vector2.h"
#include "Quaternion.h"

namespace DrawAddLine {
    void DrawLine(ImVec2 start, ImVec2 end, ImVec4 color, float thickness = 3.0f) {
        auto background = ImGui::GetBackgroundDrawList();
        if (background) {
            background->AddLine(start, end, ImColor(color.x, color.y, color.z, color.w), thickness);
        }
    }

    void DrawCrosshair(ImVec4 color, Vector2 center, float size = 20) {
        float x = center.X - (size / 2.0f);
        float y = center.Y - (size / 2.0f);
        DrawLine(ImVec2(x, center.Y), ImVec2(x + size, center.Y), ImVec4(120, 120, 120, 120));
        DrawLine(ImVec2(center.X, y), ImVec2(center.X, y + size), ImVec4(120, 120, 120, 120));
    }

    void DrawBulletTracer(int x, int y, int x2, int y2, int getH) {
        DrawLine(ImVec2(x, getH - y), ImVec2(x2, getH - y2), ImVec4(255, 255, 255, 255), 5.0f);
        DrawCrosshair(ImVec4(77, 111, 192, 255), Vector2(x2, getH - y2), 100);
    }

    void DrawCircle(ImVec4 color, float X, float Y, float radius, bool filled) {
        auto background = ImGui::GetBackgroundDrawList();
        if (background) {
            if (filled) {
                background->AddCircleFilled(ImVec2(X, Y), radius, ImColor(color.x, color.y, color.z, color.w));
            } else {
                background->AddCircle(ImVec2(X, Y), radius, ImColor(color.x, color.y, color.z, color.w));
            }
        }
    }

    void DrawBox(Rect rect, ImVec4 color, float thickness = 3.0f) {
        ImVec2 v1(rect.x, rect.y);
        ImVec2 v2(rect.x + rect.width, rect.y);
        ImVec2 v3(rect.x + rect.width, rect.y + rect.height);
        ImVec2 v4(rect.x, rect.y + rect.height);

        DrawLine(v1, v2, color, thickness);
        DrawLine(v2, v3, color, thickness);
        DrawLine(v3, v4, color, thickness);
        DrawLine(v4, v1, color, thickness);
    }

    void DrawBox2(Rect rect, ImVec4 borderColor, ImVec4 fillColor, float thickness = 1.0f, float rounding = 16.0f) {
        ImVec2 v1(rect.x, rect.y);
        ImVec2 v2(rect.x + rect.width, rect.y + rect.height);

        // Draw outer contour
        ImGui::GetForegroundDrawList()->AddRectFilled(v1, v2, IM_COL32(fillColor.x * 255, fillColor.y * 255, fillColor.z * 255, fillColor.w * 255), rounding, ImDrawCornerFlags_All);
        ImGui::GetForegroundDrawList()->AddRect(v1, v2, IM_COL32(borderColor.x * 255, borderColor.y * 255, borderColor.z * 255, borderColor.w * 255), rounding, ImDrawCornerFlags_All, thickness);
    }

    void DrawTextAboveBox(const char* text, ImVec2 position, ImVec4 color, float fontSize) {
        auto background = ImGui::GetBackgroundDrawList();
        if (background) {
            ImVec2 textSize = ImGui::CalcTextSize(text);
            position.x -= textSize.x / 2.0f;
            position.y -= textSize.y / 2.0f + fontSize;  // Set the text above the box
            background->AddText(NULL, fontSize, position, ImColor(color.x, color.y, color.z, color.w), text);
        }
    }

    void DrawText2(float fontSize, ImVec2 position, ImVec4 color, const char* text) {
        auto background = ImGui::GetBackgroundDrawList();

        if (background) {
            ImVec2 textSize = ImGui::CalcTextSize(text);

            // Calculate coordinates for centering
            position.x -= textSize.x / 2.0f;
            position.y -= textSize.y / 2.0f;

            background->AddText(NULL, fontSize, position, ImColor(color.x, color.y, color.z, color.w), text);
        }
    }

    void DrawCustomBox(Rect rect, ImVec4 outlineColor, ImVec4 fillColor, float rounding = 8.0f, float thickness = 3.0f) {
        // Draw outer contours
        for (float t = 0.0f; t <= 1.0f; t += 0.01f) {
            ImVec2 start = ImVec2(rect.x, rect.y + t * rect.height);
            ImVec2 end = ImVec2(rect.x + rect.width, rect.y + t * rect.height);
            DrawLine(start, end, fillColor, thickness);
        }

        auto background = ImGui::GetBackgroundDrawList();

        if (background) {
            // Outer contours with rounding
            background->AddRect(ImVec2(rect.x, rect.y), ImVec2(rect.x + rect.width, rect.y + rect.height), ImColor(outlineColor.x, outlineColor.y, outlineColor.z, outlineColor.w), rounding, 15, thickness);

            // Fill the inner box with rounding
            if (fillColor.w > 0.0f) {
                background->AddRectFilled(ImVec2(rect.x + 1, rect.y + 1), ImVec2(rect.x + rect.width - 1, rect.y + rect.height - 1), ImColor(fillColor.x, fillColor.y, fillColor.z, fillColor.w), rounding, 15);
            }
        }
    }

    void DrawText3(float fontSize, ImVec2 position, ImVec4 color, const char* text) {
        auto background = ImGui::GetBackgroundDrawList();

        if (background) {
            background->AddText(NULL, fontSize, position, ImColor(color.x, color.y, color.z, color.w), text);
        }
    }

    void DrawHorizontalHealthBar(Vector2 screenPos, float width, float height, float maxHealth, float currentHealth, ImVec4 outlineColor, ImVec4 fillColor) {
        // Outer contours
        DrawCustomBox(Rect(screenPos.X, screenPos.Y, width, height * 1.3f), outlineColor, ImVec4(0, 0, 0, 0), 8.f, 1.f);

        // Inner filled box
        screenPos += Vector2(1.0f, 1.0f);
        float hpWidth = (maxHealth > 0.0f) ? (currentHealth / maxHealth) * (width - 2) : 0.0f;

        // Determine color for the inner box based on health values
        if (currentHealth <= (maxHealth * 0.6)) {
            fillColor = ImVec4(255, 255, 0, 255); // Yellow color if less than 60% health
        }
        if (currentHealth < (maxHealth * 0.3)) {
            fillColor = ImVec4(255, 0, 0, 255); // Red color if less than 30% health
        }
        if (currentHealth <= 0.0f) {
            fillColor = ImVec4(0, 0, 0, 0); // Transparent color if health is zero or less
        }

        auto background = ImGui::GetBackgroundDrawList();
        if (background) {
            background->AddRectFilled(ImVec2(screenPos.X, screenPos.Y), ImVec2(screenPos.X + hpWidth, screenPos.Y + height * 1.3f - 2.0f), ImColor(fillColor.x, fillColor.y, fillColor.z, fillColor.w), 8.f);

            // Display text Health/MaxHealth inside the healthBar
            char buffer[32];
            sprintf(buffer, "%.0f / %.0f", currentHealth, maxHealth);

            ImVec2 textSize = ImGui::CalcTextSize(buffer);
            ImVec2 textPosition(screenPos.X + (width - textSize.x) / 2, screenPos.Y + (height * 1.3f - textSize.y) / 2); // Center text
            DrawText3(height * 1.2f, textPosition, ImVec4(0, 0, 0, 255), buffer); // Reduced text size
        }
    }

    void DrawVerticalHealth(Vector2 end, float h, float health) {
        float x = end.X;
        float y = end.Y;
        h = -h;

        ImVec4 clr = ImVec4(0, 255, 0, 255);

        float hpwidth = h - h * health / 100;

        if (health <= (100 * 0.6)) {
            clr = ImVec4(255, 255, 0, 255);
        }
        if (health < (100 * 0.3)) {
            clr = ImVec4(255, 0, 0, 255);
        }

        Rect hpbar((x + h / 4) - 8, y, 4.0f, -h);
        Rect hp((x + h / 4) - 8, y - hpwidth, 2.0f, -h + hpwidth);

        DrawBox(hpbar, ImVec4(0, 0, 0, 255), 3);

        DrawBox(hp, clr, 3);
    }

    float get_3D_Distance(float Self_x, float Self_y, float Self_z, float Object_x, float Object_y, float Object_z) {
        float x, y, z;
        x = Self_x - Object_x;
        y = Self_y - Object_y;
        z = Self_z - Object_z;
        return (float)(sqrt(x * x + y * y + z * z));
    }
}

#endif

