#include "media.h"
#include <iostream>
using namespace std;

class movies : public media
{
 public:
  char title[50];
  char dirLast[20];
  int year;
  int rating;
  int dur;
};
