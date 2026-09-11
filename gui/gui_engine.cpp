#include <SDL.h>
#include <SDL_opengl.h>

#include "imgui.h"
#include "imgui_impl_opengl2.h"
#include "imgui_impl_sdl2.h"
#include "theme.h"

int main_window() {
  const char* main_window_name = "Main Window - cxxPEA";
  int width;
  int height;

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

  ApplyTheme(style, &dark_theme);

  ImGui_ImplSDL2_InitForOpenGL(langas, context);
  ImGui_ImplOpenGL2_Init();

  // always running loop to refresh user interface
  while (true) {
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
    ImGui::SetNextWindowPos({0, 0});
    ImGui::SetNextWindowSize(io.DisplaySize);
    ImGui::Begin("Window");

    // code for main window

    ImGui::End();
    ImGui::Render();

    glClear(GL_COLOR_BUFFER_BIT);

    ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());
    SDL_GL_SwapWindow(langas);
  }
  return 0;
}
