// Emily Vo and Dhwani Patel
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
    string time; // could also be a string
};

struct Album
{
    map<string, Song> songs;
    string name;
    int time = 0;
    int nsongs; // optional variable but makes it easier
};

struct Artist
{
    map<string, Album> albums;
    string name;
    int time = 0;
    int nsongs;
};


void time(string &line)
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
}

int main(int argc, char *argv[])
{
    string line, nTitle, nArtist, nAlbum, nGenre, nTrack;
    map <string, Artist> artists;
	map <string, Artist>::iterator artist_it;
	map <int, Song>::iterator song_it;
	map <string, Album>::iterator album_it;



    while(getline(cin, line))
    {
//        replace(line.begin(), line.end(), '_', ' ');

		//reading in the input as strings
        stringstream ss(line);
		replace(line.begin(), line.end(), '_', ' ');

        ss >> nTitle >> nTime >> nArtist >> nAlbum >> nGenre >> nTrack;
		
		Song cSong;

		cSong.title = nTitle;
		cSong.time = nTime;

		//check if the artist exists in the map 'artists'
		
		artist_it = artist.find(nArtist);
		if(artist_it == artist.end()){
			
			Artist cArtist;

			cArtist.name = nArtist;
			cArtist.time = 0;

			artist.insert(pair<cArtist.name, cArtist>);
			
		}
		else{
			album_it = album.find(nAlbum);
	        if(album_it == album.end()){

		        Album cAlbum;

			    cAlbum.name = nAlbum;
				cAlbum.time = 0;
				album.insert(pair<cAlbum.name, cAlbum>);

			}

		}
		
		song.insert(pair<cSong.time, cSong>);


    }

    return 0;
}
