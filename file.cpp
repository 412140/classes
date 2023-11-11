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

void addMedia(media *m);
void searchMedia(const char *searchTerm, int searchYear = -1);
void delMed(const char *searchTerm, int searchYear = -1);
// has to be global
vector<media *> mediaDb;
int main()
{

    // vector<media *> mediaDb;

    char cmd[20];
    while (true)
    {
        cout << "commands: add/search/delete/quit" << endl;
        cin >> cmd;

        if (strcmp(cmd, "add") == 0)
        {
            char type[20];
            cout << "enter a type: game, music, or movie" << endl;
            cin >> type;

            if (strcmp(type, "game") == 0)
            {
                int year, rating;
                char title[50];
                char publisher[50];

                cout << "enter title" << endl;
                cin >> title;
                cout << "enter year" << endl;
                cin >> year;
                cout << "enter publisher" << endl;
                cin >> publisher;
                cout << "enter rating" << endl;
                cin >> rating;

                videoGames *game = new videoGames(title, year, publisher, rating);
                addMedia(game);
            }
            else if (strcmp(type, "music") == 0)
            {
                char title[50];
                char artist[50];
                int year, duration;
                char publisher[50];

                cout << "Enter title: ";
                cin.ignore(); // Ignore newline character in buffer
                cin.getline(title, sizeof(title));
                cout << "Enter artist ";
                cin.ignore(); // Ignore newline character in buffer
                cin.getline(artist, sizeof(artist));
                cout << "enter year: ";
                cin >> year;
                cout << "enter duration (in minutes): ";
                cin >> duration;
                cout << "enter publisher: ";
                cin.ignore(); // Ignore newline character in buffer
                cin.getline(publisher, sizeof(publisher));

                music *song = new music(title, artist, year, duration, publisher);
                addMedia(song);
            }
            else if (strcmp(type, "movie") == 0)
            {
                char title[50];
                char director[50];
                int year, duration, rating;

                cout << "Enter title: ";
                cin.ignore(); // Ignore newline character in buffer
                cin.getline(title, sizeof(title));
                cout << "Enter director: ";
                cin.ignore(); // Ignore newline character in buffer
                cin.getline(director, sizeof(director));
                cout << "Enter year: ";
                cin >> year;
                cout << "Enter duration (in minutes): ";
                cin >> duration;
                cout << "Enter rating: ";
                cin >> rating;

                movie *mv = new movie(title, director, year, duration, rating);
                addMedia(mv);
            }
        }
        else if (strcmp(cmd, "search") == 0)
        {
            char searchTerm[50];
            int year = -1;
            cout << "enter title or year" << endl;
            cin.ignore(); // Ignore newline character in buffer
            cin.getline(searchTerm, sizeof(searchTerm));
            cout << "year: (enter if skip)";
            cin >> year;
            searchMedia(searchTerm, year);
        }
        else if (strcmp(cmd, "delete") == 0)
        {
            char searchTerm[50];
            int searchYear = -1;
            cout << "title OR year to delete" << endl;
            cin.ignore(); // Ignore newline characer in buffer
            cin.getline(searchTerm, sizeof(searchTerm));
            cout << "year? (enter to skip)" << endl;
            cin >> searchYear;
            delMed(searchTerm, searchYear);
        }
        else if (strcmp(cmd, "quit") == 0)
        {
            break;
        }
    }

    for (media *m : mediaDb)
    {
        delete m;
    }
    mediaDb.clear();
    return 0;
}

// Function definitions outside of main
void addMedia(media *m)
{
    mediaDb.push_back(m);
}

void searchMedia(const char *searchTerm, int searchYear)
{
    for (media *m : mediaDb)
    {
        if (strstr(m->getTitle(), searchTerm) || (searchYear == -1 || m->getYear() == searchYear))
        {
            m->printInfo();
            cout << "." << endl;
        }
    }
}

void delMed(const char *searchTerm, int searchYear)
{
    for (auto it = mediaDb.begin(); it != mediaDb.end();)
    {
        if (strstr((*it)->getTitle(), searchTerm) || (searchYear == -1 || (*it)->getYear() == searchYear))
        {
            (*it)->printInfo();
            cout << "y/n to delete." << endl;
            char choice;
            cin >> choice;
            if (choice == 'y' || choice == 'Y')
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