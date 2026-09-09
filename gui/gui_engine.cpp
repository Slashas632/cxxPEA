#include <iostream>

// ImGui include'ai
#include <SDL.h>
#include <SDL_opengl.h>

#include "imgui.h"
#include "imgui_impl_opengl2.h"
#include "imgui_impl_sdl2.h"

int main_window() {
  const char* main_window_name = "Main Window - cxxPEA";
  int plotis;
  int aukstis;

  plotis = 1280;
  aukstis = 720;

  SDL_Init(SDL_INIT_VIDEO);

  SDL_Window* langas = SDL_CreateWindow(
      main_window_name, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, plotis,
      aukstis, SDL_WINDOW_OPENGL);

  SDL_GLContext context = SDL_GL_CreateContext(langas);

  IMGUI_CHECKVERSION();
  ImGui::CreateContext();

  ImGui_ImplSDL2_InitForOpenGL(langas, context);
  ImGui_ImplOpenGL2_Init();

  // sukurtas loop kad langas neuzsidarytu iskart po pasileidimo
  // visad veikiantis kol programa run'nina
  while (true) {
    SDL_Event event;
    // Tikrina ar vartotojas atliko veiksma
    while (SDL_PollEvent(&event)) {
      ImGui_ImplSDL2_ProcessEvent(&event);
      if (event.type == SDL_QUIT) return 0;
    }

    ImGui_ImplOpenGL2_NewFrame();
    ImGui_ImplSDL2_NewFrame();

    ImGui::NewFrame();
    ImGuiIO& io = ImGui::GetIO();
    ImGui::SetNextWindowPos({0, 0});
    ImGui::SetNextWindowSize(io.DisplaySize);
    ImGui::Begin("Window");

    // cia rasomas pagrindis kodas kas vyksta languose

    ImGui::End();
    ImGui::Render();

    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());
    SDL_GL_SwapWindow(langas);
  }
  return 0;
}
