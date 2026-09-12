#include "theme.h"

#define HEX(c) HexToColor(c)

Color HexToColor(uint32_t hex) {
  float r = ((hex >> 16) & 0xFF) / 255.0f;
  float g = ((hex >> 8) & 0xFF) / 255.0f;
  float b = (hex & 0xFF) / 255.0f;

  return {r, g, b, 1.0f};
}

const Theme green_theme{.background = HEX(0x1A1A1F),
                        .surface = HEX(0x24242B),

                        .text = HEX(0xE6E6EB),
                        .text_disabled = HEX(0x80808C),

                        .accent = HEX(0x33D973),
                        .accent_light = HEX(0x4CF28C),

                        .success = HEX(0x33BF66),
                        .warning = HEX(0xF2A633),
                        .error = HEX(0xE64040)};

const Theme cherryred_theme{.background = HEX(0x1A1A1F),
                        .surface = HEX(0x24242B),

                        .text = HEX(0xE6E6EB),
                        .text_disabled = HEX(0xA00323),

                        .accent = HEX(0x730219),
                        .accent_light = HEX(0xA00323),

                        .success = HEX(0x33BF66),
                        .warning = HEX(0xF2A633),
                        .error = HEX(0xE64040)};


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
