#include "media.h"
#include "videoGames.h"
#include "music.h"
#include "movie.h"
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;
/*
ghazi abbas
fall sem c++ galbraith

build a media database using classes in other files, using vectors

Sources:
https://stackoverflow.com/questions/10865861/when-to-use-vectors-and-when-to-use-arrays-in-c
https://cplusplus.com/forum/articles/10627/
https://www.youtube.com/watch?v=dQG41m6vf3A
https://www.youtube.com/watch?v=rJlJ8qqVm3k
https://learn.microsoft.com/en-us/cpp/cpp/const-cpp?view=msvc-170
https://stackoverflow.com/questions/5200572/what-does-const-mean-in-context-at-the-end-of-a-function-definition
https://www.youtube.com/watch?v=Bf8a6IC1dE8


+

All tutorial videos on canvas pages
 */


int main()
{
  vector<media*> mediaDb; // https://www.geeksforgeeks.org/vector-in-cpp-stl/
  void addMedia(media* m)
  {
    mediaDb.push_back(m);
    
  }
  


void searchMedia(const char* searchTerm, int searchYear = -1)
{
  for(media* m : mediaDb)
    {//https://cplusplus.com/reference/cstring/strstr/
      if(strstr(m->getTitle(), searchTerm) || (searchyear == -1 || media->getYear() == searchYear))
	{
	  media->printInfo();
	  cout << "." << endl;
	}
    }
}

void delMed(const char* searchTerm, int searchYear = -1)
{
  for(auto it = mediaDb.begin(); it== mediaDb.end();)
    {
      if(strstr((*it)->getTitle(), searchTerm)|| (searchYear == -1 || (*it)->getYear() == searchYear))
	{
	  (*it)->printInfo();
	  cout << "y/n to delete." << endl;
	  char choice;
	  cin >> choice;
	  if(choice == "y" || choice == "Y")
	    {
	      delete *it;
	      it = mediaDb.erase(it);
	      
	    }
	  else
	    {
	      ++it;
	    }
	}
	else
	  {
	    ++it;
	  }
    }
  }
}

 char cmd[20];
 while(true)
   {
     cout << "commands: add/search/delete/quit" << endl;
     cin >> cmd;

     if(strcmp(cmd, "add")==0)
       {
	 char type[20];
	 cout<< "enter a type: game, music, or movie"<< type << endl;

	 if(strcmp(type, "game")==0)
	   {
	     int year, rating;
	     int publisher[50];

	     cout << "enter title" << endl;
	     cin >> tile;
	     cout << "enter year" << endl;
	     cin >> year;
	     cout<< "enter publisher" << endl;
	     cin >> publisher;
	     cout << "enter rating" << endl;
	     cin >> rating;

	     videoGames* game = new videoGames(title, year, publisher, rating);
	     addMedia(game);
	   }
	 else if(strcmp(type, "music"))
	   {
	     char title[44];
	     char artist[40];
	     int year, duration;
	     char publisher[40];

	     cout << "Enter title: ";
             cin >> title;
             cout << "Enter artist ";
             cin >> artist;
             cout << "enter year";
             cin >> year;
             cout << "enter duration (in minutes): ";
             cin >> duration;
             cout << "enter publisher:";
             cin >> publisher;

	     music* music = new music(title, artist, year, duration, publisher);
	     addMedia(music);
	   }
	 else if(strcmp(type, "movie")==0)
	   {
	     char title[44];
	     char director[40];
	     int year, duration, rating;
    

	        cout << "Enter title: ";
                cin >> title;
                cout << "Enter artist: ";
                cin >> artist;
                cout << "Enter year: ";
                cin >> year;
                cout << "Enter duration (in minutes): ";
                cin >> duration;
                cout << "Enter publisher: ";
                cin >> publisher;

		movie* movie = new movie(title, director, year, duration, rating);
		addMedia(movie);
	   }
	 else if(strcmp(cmd, "search")==0)
	   {
	 char searchTerm[50];
	 int year = -1;
	 cout << "enter title or year" << endl;
	 cin >> searchTerm;
	 cout << "year: (enter if skip)";
	 cin.ignore();
	 cin.clear();
	 if(!(cin >> searchYear))//
	   {
	     searchYear = -1;
	   }
	   searchMedia(searchTerm, searchYear);
	   }
	 else if(strcmp(cmd, "delete")==0)
	   {
	     char searchTerm[50];
	     int searchYear = -1;
	     cout << "title OR year to delete" << endl;
	     cin >> searchTerm;
	     cout << "year? (enter to skip)" << endl;
	     cin.ignore();
	     cin.clear();
	     if(!(cin>>searchYear))
	       {
		 searchYear = -1;
	       }
	     delMed(searchTerm, searchYear);
	   }
	 else if(strcmp(cmd, "quit") == 0)
	   {
	     break;
	   }
		 

 
}

     for(media* m : mediaDb)
       {
	 delete media;
       }
     mediaDb.clear();
     return 0;
   }
