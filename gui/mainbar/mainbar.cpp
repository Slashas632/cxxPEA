#include "mainbar.h"

#include "imgui.h"

void MainBar(bool* p_program_loop) {
  if (ImGui::BeginMainMenuBar()) {
    if (ImGui::BeginMenu("File")) {
      if (ImGui::MenuItem("Exit")) {
        *p_program_loop = false;
      }
      ImGui::EndMenu();
    }
    ImGui::EndMainMenuBar();
  }
}
