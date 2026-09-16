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
	gui/imgui/backends/imgui_impl_opengl2.cpp \
	gui/imgui_file_dialog/ImGuiFileDialog.cpp \
	gui/imgui_file_dialog/file_dialog.cpp
HEADERS = -I./gui \
	-I./gui/mainbar \
	-I./gui/imgui \
	-I./gui/theme \
	-I./gui/imgui/backends \
	-I./gui/imgui_file_dialog \
	$(shell pkg-config --cflags sdl2)
LDFFLAGS = $(shell pkg-config --libs sdl2) -lGL
TARGET = cxxPEA

run:
	$(CXX) $(CXXVERSION) $(HEADERS) $(SRC) -o $(TARGET) $(LDFFLAGS)

clean:
	rm -rf $(TARGET) imgui.ini
debug:
	$(CXX) $(CXXVERSION) -g -O0 -Wall -Wextra $(HEADERS) $(SRC) -o $(TARGET) $(LDFFLAGS)
memory-leak-test:
	$(CXX) $(CXXVERSION) -g -O1 -fsanitize=address,undefined -fno-omit-frame-pointer $(HEADERS) $(SRC) $(LDFFLAGS) -fsanitize=address,undefined -o $(TARGET)
check-leaks: memory-leak-test
	ASAN_OPTIONS=detect_leaks=1:symbolize=1 LSAN_OPTIONS=suppressions=.asan-suppressions ./$(TARGET)
