#ifndef VIDEOGAMES_H
#define VIDEOGAMES_H

#include <iostream>
#include "media.h"
using namespace std;

class videoGames : public media
{
 public:
  videoGames(const char* title, int year, const char* publisher, int rating);
  const char* getPublisher() const;
  int getRating() const;
  const char* getType() const;
  void printInfo() const;
private:
  char publisher[50];
  int rating;
};






#endif
