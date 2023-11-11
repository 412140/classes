#include "videoGames.h"
#include <cstring>
#include <iostream>
using namespace std;

videoGames::videoGames(const char* title, int year, const char* publisher, int rating)
  : media(title, year), rating(rating)
{
  strncpy(this->publisher, publisher, 49);
  this->publisher[49] = '\0';
 

}

const char* videoGames::getPublisher() const
{
  return publisher;
}

int videoGames::getRating() const
{
  return rating;
}

const char* videoGames::getType() const
{
  return "game";
}

void videoGames::printInfo() const
{
  media::printInfo();
  cout << " publisher"<< publisher <<"rating" << rating << endl;
}

