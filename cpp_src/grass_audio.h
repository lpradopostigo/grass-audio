#pragma once
#include "bass.h"
#include "bassmix.h"
#include <functional>

class grass_audio {
public:
  explicit grass_audio(std::vector<std::vector<unsigned char>> files, DWORD frequency = 44100);
  ~grass_audio() = default;

  [[maybe_unused]] void play() const;
  [[maybe_unused]] void pause() const;
  [[maybe_unused]] void stop(); // TODO
  [[maybe_unused]] void set_position(double position) const;
  [[maybe_unused]] void set_volume(float value) const; // TODO
  [[maybe_unused]] [[nodiscard]]  double get_position() const; // TEST

  [[maybe_unused]] void remove_listener(DWORD listener) const; //TODO
  [[maybe_unused]] DWORD on_position_reached(const std::function<void()> &callback,//TODO
                                             double position,
                                             bool remove_listener = false) const;
  [[maybe_unused]] DWORD on_end(const std::function<void()> &callback, bool remove_listener = false) const;//TODO
  [[maybe_unused]] DWORD on_position_set(const std::function<void()> &callback,
                                         bool remove_listener = false) const;//TODO

private:
  std::vector<std::vector<unsigned char>> files{};

  DWORD current_stream = 0;
  int current_position = 0;
  HSTREAM mixer_stream = 0;

  void load_next_file();
};

