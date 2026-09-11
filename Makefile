CXX = g++
CXXVERSION= -std=c++17

SRC = main.cpp \
	gui/gui_engine.cpp \
	gui/mainbar/mainbar.cpp \
	gui/theme/theme.cpp \
	gui/imgui/imgui.cpp \
	gui/imgui/imgui_demo.cpp \
	gui/imgui/imgui_draw.cpp \
	gui/imgui/imgui_tables.cpp \
	gui/imgui/imgui_widgets.cpp \
	gui/imgui/backends/imgui_impl_sdl2.cpp \
	gui/imgui/backends/imgui_impl_opengl2.cpp
HEADERS = -I./gui \
	-I./gui/mainbar \
	-I./gui/imgui \
	-I./gui/theme \
	-I./gui/imgui/backends \
	$(shell pkg-config --cflags sdl2)
LDFFLAGS = $(shell pkg-config --libs sdl2) -lGL
TARGET = cxxPEA

run:
	$(CXX) $(CXXVERSION) $(HEADERS) $(SRC) -o $(TARGET) $(LDFFLAGS)
