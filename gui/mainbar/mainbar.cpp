#include "mainbar.h"

#include "imgui.h"


void file_bar(Options::file_bar& filebar) {
  if (ImGui::BeginMainMenuBar()) {
    if (ImGui::BeginMenu("File")) {
      if (ImGui::MenuItem("Exit")) {
        filebar.program_loop = false;
      }
      ImGui::EndMenu();
    }
    ImGui::EndMainMenuBar();
  }
}

void MainBar(Options& options) { file_bar(options.filebar); }
