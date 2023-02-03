// Emily Vo & Dhwani Patel
// Project 1
// This program reads in data about songs, artists, and albums from a file, and stores the information in a series of maps
// CS 302
// 2/2/23
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <map>
#include <string.h>
#include <iomanip>
#include <algorithm>
using namespace std;

/* define the structs for Song, Album, and Artist */
struct Song
{
    string title;
    string time;
    int track;
};

struct Album
{
    map<int, Song> songs;
    string name;
    int time = 0;
    int nsongs;
};

struct Artist
{
    map<string, Album> albums;
    string name;
    int time = 0;
    int nsongs;
};

int main(int argc, char *argv[])
{
    string line, nTitle, nTime, nArtist, nAlbum, nGenre;
    int nTrack;
    map<string, Artist> artists;
    // iterators for the artists, albums, and songs maps
    map<string, Artist>::iterator artist_it;
    map<int, Song>::iterator song_it;
    map<string, Album>::iterator album_it;

    // variables for the current song, artist, and album
    Song cSong;
    Artist cArtist;
    Album cAlbum;

    // open the file from the command line argument
    ifstream fin;
    fin.open(argv[1]);

    while (getline(fin, line))
    {
        // read in the input as strings
        stringstream ss(line);
        ss >> nTitle >> nTime >> nArtist >> nAlbum >> nGenre >> nTrack;

        replace(nTitle.begin(), nTitle.end(), '_', ' ');
        replace(nArtist.begin(), nArtist.end(), '_', ' ');
        replace(nAlbum.begin(), nAlbum.end(), '_', ' ');
        replace(nGenre.begin(), nGenre.end(), '_', ' ');

        // assign the values to the current song; store the info in teh cSong struct
        cSong.title = nTitle;
        cSong.time = nTime;
        cSong.track = nTrack;

        // check if the artist exists in the map 'artists'
        artist_it = artists.find(nArtist);

        // if the artist does not exist, add them to the map; create a new artist
        if (artist_it == artists.end())
        {
            cArtist.name = nArtist;
            cArtist.time = 0;
            cArtist.nsongs = 0;

            artists.insert(make_pair(nArtist, cArtist));
            artist_it = artists.find(nArtist);
        }

        // increase the # of songs for the artist
        artist_it->second.nsongs += 1;
        // check if the album exists in the artist's albums map
        album_it = artist_it->second.albums.find(nAlbum);

        // if not, create a new album
        if (album_it == artist_it->second.albums.end())
        {
            cAlbum.name = nAlbum;
            cAlbum.time = 0;
            cAlbum.nsongs = 0;
            artist_it->second.albums.insert(make_pair(nAlbum, cAlbum));
            album_it = artist_it->second.albums.find(nAlbum);
        }

        // increase the number of songs for the album
        album_it->second.nsongs += 1;
        // keep inserting songs
        album_it->second.songs.insert(make_pair(nTrack, cSong));

        /* calculate the total time for the artist and album */
        int nMinutes = 0;
        int nSeconds = 0;
        int colonIndex = nTime.find(":");

        // string to int conversion
        nMinutes = stoi(nTime.substr(0, colonIndex));
        nSeconds = stoi(nTime.substr(colonIndex + 1));

        int totalSeconds = nMinutes * 60 + nSeconds;

        // add total time to artist and album times
        artist_it->second.time += totalSeconds;
        album_it->second.time += totalSeconds;
    }

    /* sort the map of songs within each album under each artist; print out the results */
    for (artist_it = artists.begin(); artist_it != artists.end(); artist_it++)
    {
        cout << artist_it->second.name << ": " << artist_it->second.nsongs << ", " << artist_it->second.time / 60 << ":" << setfill('0') << setw(2) << artist_it->second.time % 60 << endl;

        for (album_it = artist_it->second.albums.begin(); album_it != artist_it->second.albums.end(); album_it++)
        {

            cout << "        " << album_it->second.name << ": " << album_it->second.nsongs << ", " << album_it->second.time / 60 << ":" << setfill('0') << setw(2) << album_it->second.time % 60 << endl;

            for (song_it = album_it->second.songs.begin(); song_it != album_it->second.songs.end(); song_it++)
            {

                cout << "                " << song_it->second.track << ". " << song_it->second.title << ": " << song_it->second.time << endl;
            }
        }
    }
    fin.close();
    return 0;
}

