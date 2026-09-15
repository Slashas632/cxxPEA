#pragma once
#include <ImGuiFileDialog.h>

#include <string>

struct settings_filedialog {
  IGFD::FileDialogConfig config;
  std::string filters = ".cpp, .h, .hpp";
  std::string button_label = "Testing file dialog";
  std::string vKey = "FileDialog";
  std::string vTitle = "Choose file";
};

void filedialog_instance(settings_filedialog& settings);
void filedialog_button(settings_filedialog& settings);
