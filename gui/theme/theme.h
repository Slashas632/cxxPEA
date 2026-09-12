#pragma once

#include <GL/gl.h>

#include "imgui.h"

struct Color {
  float r;
  float g;
  float b;
  float a;

  ImVec4 imgui() const { return ImVec4(r, g, b, a); }

  void apply() const { glClearColor(r, g, b, a); }
};

struct Theme {
  Color background;
  Color surface;
  Color text;
  Color text_disabled;

  Color accent;
  Color accent_light;

  Color success;
  Color warning;
  Color error;
};

enum class ThemeType {

  Dark,
  Gray,
  White
};

void ApplyTheme(ImGuiStyle& style, const Theme* t);

Color HexToColor(uint32_t hex);

extern const Theme green_theme;
extern const Theme cherryred_theme;


extern const Theme* current_theme;
