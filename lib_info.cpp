#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <string.h>
#include <iomanip>
using namespace std;

struct Song
{
    string title;
    int time; // could also be a string
};

struct Album
{
    map<int, Song> songs;
    string name;
    int time;
    int nsongs; // optional variable but makes it easier
};

struct Artist
{
    map<string, Album> albums;
    string name;
    int time;
    int nsongs;
};


/*void time(string &line)
{
    int min = 0, sec = 0;
    for (int i = 0; i < line.size(); i++)
    {
        min += stoi(line[1].substr(0, line[1].find(":")));
        sec += stoi(line[1].substr(line[1].find(":") + 1));

        if (sec >= 60)
        {
            min += 1;
            sec -= 60;
        }
        cout << setfill('0') << setw(2) << min << " " << sec << endl << endl;
    }
}*/

int main(int argc, char *argv[])
{
    string line, title, time, artist, album, genre, track;
    map <string, Artist> artists;
    map <string, Artist> artists::iterator artist_it;
    map<string, Album> album;
    map<string, Album> album::iterator album_it;

    while(getline(cin, line))
    {
        replace(line.begin(), line.end(), '_', ' ');

        stringstream ss(line);
        ss >> title >> time >> artist >> album >> genre >> track;
        cout << title << " " << time << " " << artist << " " << album << " " << genre << " " << track << endl;

        /*ss if (artists.insert(pair).second)
        {
        }
        else
        {
        }

        chunks(line);
        time(line);*/
    }

    return 0;
}
