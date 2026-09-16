#include "file_dialog.h"

#include <iostream>
#include <string>

#include "ImGuiFileDialog.h"

std::string filedialog_instance(settings_filedialog& settings) {
  std::string selected_path;
  if (ImGuiFileDialog::Instance()->Display(settings.vKey, ImGuiWindowFlags_NoCollapse, settings.window_minSize, settings.window_maxSize)) {
    if (ImGuiFileDialog::Instance()->IsOk()) {
      std::string selected_path = ImGuiFileDialog::Instance()->GetFilePathName();

      std::cout << "selected file: " << selected_path << "\n";
    }
    ImGuiFileDialog::Instance()->Close();
  }
  return selected_path;
}

void filedialog_button(settings_filedialog& settings) {
  if (ImGui::Button(settings.button_label.c_str())) {
    settings.config.path = ".";
    settings.config.countSelectionMax = 1;
    ImGuiFileDialog::Instance()->OpenDialog(settings.vKey, settings.vTitle,
                                            settings.filters.c_str(),
                                            settings.config);
  }
}
