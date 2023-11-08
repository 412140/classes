#include <iostream>
#include "media.h"

using namespace std;

class music : public media
{
 public:
  char sTitle[30];
  char artist[30];
  char publisher[30];
  int year;
  int dur;
};
