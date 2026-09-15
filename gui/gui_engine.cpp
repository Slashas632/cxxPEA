#include <SDL.h>
#include <SDL_opengl.h>
#include <iostream>
#include <string>

#include "imgui.h"
#include "imgui_impl_opengl2.h"
#include "imgui_impl_sdl2.h"
#include "ImGuiFileDialog.h"

#include "mainbar.h"
#include "theme.h"

int main_window() {
  const char* main_window_name = "Main Window - cxxPEA";
  int width;
  int height;

  Options menu_bar_options;

  menu_bar_options.filebar.program_loop = true;

  width = 1280;
  height = 720;

  SDL_Init(SDL_INIT_VIDEO);

  SDL_Window* langas = SDL_CreateWindow(
      main_window_name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width,
      height, SDL_WINDOW_OPENGL);

  SDL_GLContext context = SDL_GL_CreateContext(langas);

  IMGUI_CHECKVERSION();
  ImGui::CreateContext();

  ImGuiStyle& style = ImGui::GetStyle();
  ApplyTheme(style, &cherryred_theme);

  ImGui_ImplSDL2_InitForOpenGL(langas, context);
  ImGui_ImplOpenGL2_Init();

  // always running loop to refresh user interface
  while (menu_bar_options.filebar.program_loop) {
    SDL_Event event;
    // always checks for any user input
    while (SDL_PollEvent(&event)) {
      ImGui_ImplSDL2_ProcessEvent(&event);
      if (event.type == SDL_QUIT) return 0;
    }

    ImGui_ImplOpenGL2_NewFrame();
    ImGui_ImplSDL2_NewFrame();
    ImGui::NewFrame();

    ImGuiIO& io = ImGui::GetIO();

    ImGui::SetNextWindowPos(ImVec2(0, ImGui::GetFrameHeight()));
    ImGui::SetNextWindowSize(
        ImVec2(io.DisplaySize.x, io.DisplaySize.y - ImGui::GetFrameHeight()));

    ImGui::Begin("##MainWindow", nullptr,
                 ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize |
                     ImGuiWindowFlags_NoMove);

    MainBar(menu_bar_options);

    if (ImGui::Button("Testing file dialog")) {
      IGFD::FileDialogConfig config;
      config.path = ".";

      ImGuiFileDialog::Instance()->OpenDialog(
        "FileDialog",
        "Choose file",
        ".cpp, .h, .hpp",
        config
      );
    }
    ImGui::End();

    if (ImGuiFileDialog::Instance()->Display("ChooseFileDlgKey")) {
      if (ImGuiFileDialog::Instance()->IsOk()){
        std::string filePath = ImGuiFileDialog::Instance()->GetFilePathName();

        std::cout << "selected file: " << filePath << "\n";
      }
      ImGuiFileDialog::Instance()->Close();
    }

    ImGui::Render();

    glClear(GL_COLOR_BUFFER_BIT);

    ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());
    SDL_GL_SwapWindow(langas);
  }
  return 0;
}
