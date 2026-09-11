#include "theme.h"

const Theme green_theme{.background = {0.10f, 0.10f, 0.12f, 1.0f},
                       .surface = {0.14f, 0.14f, 0.17f, 1.0f},

                       .text = {0.90f, 0.90f, 0.92f, 1.0f},
                       .text_disabled = {0.50f, 0.50f, 0.55f, 1.0f},

                       .accent = {0.20f, 0.45f, 0.85f, 1.0f},
                       .accent_light = {0.30f, 0.55f, 0.95f, 1.0f},

                       .success = {0.20f, 0.75f, 0.40f, 1.0f},
                       .warning = {0.95f, 0.65f, 0.20f, 1.0f},
                       .error = {0.90f, 0.25f, 0.25f, 1.0f}};

void ApplyTheme(ImGuiStyle& style, const Theme* t) {

    style.Colors[ImGuiCol_WindowBg] = t->background.imgui();
    style.Colors[ImGuiCol_ChildBg] = t->surface.imgui();
    style.Colors[ImGuiCol_PopupBg] = t->surface.imgui();

    style.Colors[ImGuiCol_Text] = t->text.imgui();
    style.Colors[ImGuiCol_TextDisabled] = t->text_disabled.imgui();

    style.Colors[ImGuiCol_FrameBg] = t->surface.imgui();
    style.Colors[ImGuiCol_FrameBgHovered] = t->accent.imgui();
    style.Colors[ImGuiCol_FrameBgActive] = t->accent_light.imgui();

    style.Colors[ImGuiCol_Button] = t->accent.imgui();
    style.Colors[ImGuiCol_ButtonHovered] = t->accent_light.imgui();
    style.Colors[ImGuiCol_ButtonActive] = t->accent.imgui();

    style.Colors[ImGuiCol_Header] = t->accent.imgui();
    style.Colors[ImGuiCol_HeaderHovered] = t->accent_light.imgui();
    style.Colors[ImGuiCol_HeaderActive] = t->accent.imgui();

    style.Colors[ImGuiCol_CheckMark] = t->accent_light.imgui();
    style.Colors[ImGuiCol_SliderGrab] = t->accent.imgui();
    style.Colors[ImGuiCol_SliderGrabActive] = t->accent_light.imgui();

    style.Colors[ImGuiCol_Border] = t->accent.imgui();

    style.Colors[ImGuiCol_TextLink] = t->accent_light.imgui();
    style.Colors[ImGuiCol_DragDropTarget] = t->warning.imgui();

    style.Colors[ImGuiCol_TextSelectedBg] = t->accent.imgui();
}
