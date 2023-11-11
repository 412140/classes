#include "media.h"
#include <cstring>
#include <iostream>
//using namespace std;

media::media(const char* title, int year)
{
  strncpy(this->title,title, 43);
  this->title[43] = '\0';
  this->year = year;
}

const char* media::getTitle() const
{
  return title;
}

int media::getYear() const
{
  return year;
}

void media::printInfo() const
{
  cout << " titl" << title << " yeat" << year << endl;
}

const char* media::getType() const
{
  return "media";
}

media::~media()
{}
