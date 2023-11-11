#ifndef MOVIE_H
#define MOVIE_H

#include "media.h"

using namespace std;


class movie : public media
{
 public:
  movie(const char* title, const char* director, int year, int duration, int rating);
  const char* getDirector() const;
  int getDuration() const;
  int getRating() const;
  const char* getType() const;
  void printInfo() const;
 private:
  char director[40];
  int duration;
  int rating;
  
};
#endif
