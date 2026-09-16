#pragma once
#include <ImGuiFileDialog.h>

#include <string>

struct settings_filedialog {
  IGFD::FileDialogConfig config;
  ImVec2 window_minSize = ImVec2(800.f, 400.0f);
  ImVec2 window_maxSize = ImVec2(0.0f, 0.0f);
  std::string filters = ".cpp,.h,.hpp";
  std::string button_label = "Testing file dialog";
  std::string vKey = "FileDialog";
  std::string vTitle = "Choose file";
};

std::string filedialog_instance(settings_filedialog& settings);
void filedialog_button(settings_filedialog& settings);
