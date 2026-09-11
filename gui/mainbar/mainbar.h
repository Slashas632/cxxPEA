#pragma once

struct Options {
  struct file_bar {
    bool program_loop;
  };
  file_bar filebar;
};

void MainBar(Options& options);

void file_bar(Options::file_bar& filebar);
