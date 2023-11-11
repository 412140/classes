#ifndef MEDIA_H
#define MEDIA_H

#include <iostream>

using namespace std;

class media
{
 public:
  media(const char* title, int year);
  const char* getTitle() const;
  int getYear() const;
  const char* getType() const;
  void printInfo() const;
  ~media();
protected:
  char title[44];
  int year;
  
};
#endif
