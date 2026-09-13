#pragma once

struct Options {
  struct file_bar {
    bool program_loop;
  };
  struct settings_bar {};
  file_bar filebar;
  settings_bar settingsbar;
};

void MainBar(Options& options);

void file_bar(Options::file_bar& filebar);
void settings_bar();
