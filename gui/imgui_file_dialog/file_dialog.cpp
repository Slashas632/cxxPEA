#include "file_dialog.h"

#include <iostream>
#include <string>

#include "ImGuiFileDialog.h"

void filedialog_instance(settings_filedialog& settings) {
  if (ImGuiFileDialog::Instance()->Display(settings.vKey)) {
    if (ImGuiFileDialog::Instance()->IsOk()) {
      std::string filePath = ImGuiFileDialog::Instance()->GetFilePathName();

      std::cout << "selected file: " << filePath << "\n";
    }
    ImGuiFileDialog::Instance()->Close();
  }
}

void filedialog_button(settings_filedialog& settings) {
  if (ImGui::Button(settings.button_label.c_str())) {
    settings.config.path = ".";

    ImGuiFileDialog::Instance()->OpenDialog(settings.vKey, settings.vTitle,
                                            settings.filters.c_str(),
                                            settings.config);
  }
}
