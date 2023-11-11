#include "music.h"
#include <cstring>
#include <iostream>

music::music(const char* title, const char* artist, int year, int duration, const char* publisher) :
  media(title, year), duration(duration)
{
  strncpy(this->artist, artist, 39);
  this->artist[39] = '\0';
  strncpy(this->publisher, publisher, 39);
  this->artist[39] = '\0';
}

const char* music::getArtist() const
{
  return artist;
}

int music::getDuration() const
{
  return duration;
}

const char* music::getPublisher() const
{
  return publisher;
}

const char* music::getType() const
{
  return "music";
}

void music::printInfo() const
{
  media::printInfo();
  cout << "artist" << artist << "duration" << duration << "min, publisher" << publisher;
}
