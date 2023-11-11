#include "movie.h"
#include <cstring>
#include <iostream>

using namespace std;

movie::movie(const char *title, const char *director, int year, int durating, int rating)
    : media(title, year), duration(duration), rating(rating)
{
  strncpy(this->director, director, 39);
  this->director[39] = '\0';
}

const char *movie::getDirector() const
{
  return director;
}
int movie::getDuration() const
{
  return duration;
}

int movie::getRating() const
{
  return rating;
}

const char *movie::getType() const
{
  return "movie";
}

void movie::printInfo() const
{
  media::printInfo();
  cout << "director" << director << ",duration" << duration << "m ,rating" << rating << endl;
}
