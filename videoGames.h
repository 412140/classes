#include <iostream>
#include "media.h"
using namespace std;

class videoGames : public media
{
 public:
  char title[30];
  char pub[30];
  int rating;
  int year;
};
