#ifndef MUSIC_H
#define MUSIC_H

#include <iostream>
#include "media.h"

using namespace std;

class music : public media
{
public:
  music(const char *title, const char *artist, int year, int duration, const char *publisher);
  const char *getArtist() const;
  int getDuration() const;
  const char *getPublisher() const;
  const char *getType() const;
  void printInfo() const;

private:
  char artist[40];
  int duration;
  char publisher[40];
};
#endif
