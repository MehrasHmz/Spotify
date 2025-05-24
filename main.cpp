#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <windows.h>

using namespace std;

class Music;

class Artist;

class Playlist;

class User;

class Admin;

class Artist {
private:
    string Name;
    string country;
    string birthDate;

    int Numberofalbums = 0;
    int NumberofMusics = 0;

public:
    vector<Music *> musics;

    Artist() = default;

    Artist(string N, string C, string B) {
        Name = N;
        country = C;
        birthDate = B;
    }

    void Addmusic(Music *music0) {
        musics.push_back(music0);
    }

    void setCountry(string c) {
        country = c;
    }

    void Addnumberofalbums(int a) {
        Numberofalbums += a;
    }

    void Addnumberofmusics(int a) {
        NumberofMusics += a;
    }

    string getCountry() const {
        return country;
    }

    void setBirthDate(string b) {
        birthDate = b;
    }

    string getBirthDate() const {
        return birthDate;
    }

    void setName(const string &name) {
        Name = name;
    }

    string getName() const {
        return Name;
    }

    void setNumberofalbums(int albums) {
        Numberofalbums = albums;
    }

    int getNumberofalbums() const {
        return Numberofalbums;
    }

    void setNumberofMusics(int musics) {
    }

    int getNumberofMusics() const {
        return NumberofMusics;
    }
};

class Music {
private:
    string name;
    Artist *artist = nullptr;
    string releaseYear;
    string genre;

public:

    void setArtistPointer(Artist *a) {
        artist = a;
    }

    Music() = default;

    Music(string n, string r, string g) {
        name = n;
        releaseYear = r;
        genre = g;
    }

    void setName(string n) {
        name = n;
    }

    string getName() const {
        return name;
    }

    void setartist(string n) {
        if (artist)
            artist->setName(n);
    }

    string getArtist() const {
        if (artist)
            return artist->getName();
        return "Unknown";
    }

    void SetReleaseYear(string r) {
        releaseYear = r;
    }

    string getReleaseYear() const {
        return releaseYear;
    }

    void setGenre(string g) {
        genre = g;
    }

    string getGenre() const {
        return genre;
    }
};

class User {
private:
    string username;
    string password;
    vector<Artist *> artists;
    Playlist *LikedMusics;
    Playlist *Savedmusics;
    Music music0;
public:
    vector<Playlist *> Allplaylists;

    User() {
        LikedMusics = new Playlist("LikedMusics", 0);
        Savedmusics = new Playlist("Savedmusics", 0);
        Allplaylists.push_back(LikedMusics);
        Allplaylists.push_back(Savedmusics);
    }


    void Savedmusic(Music *music) {
        Savedmusics->addMusic(music);
        Savedmusics->numberOfSongs++;
    }

    void Likedmusic(Music *music) {
        LikedMusics->addMusic(music);
        LikedMusics->numberOfSongs++;
    }

    void Addmusictoplaylist(Playlist *playlist, Music *music) {
        playlist->addMusic(music);
        playlist->numberOfSongs++;
    }

    void ViewLikedmusic() {
        string ask;
        if (LikedMusics->musics.empty()) cout << "Playlist is empty!\n";
        else {
            for (int i = 0; i < LikedMusics->musics.size(); ++i) {
                cout << "name : " << LikedMusics->musics[i]->getName() << " Artist : "
                     << LikedMusics->musics[i]->getArtist()
                     << " releaseYear : " << LikedMusics->musics[i]->getReleaseYear() << " Genre : "
                     << LikedMusics->musics[i]->getGenre();
            }
            cout << endl;
        }
    }

    void ViewSavedmusic() {
        if (Savedmusics->musics.empty()) cout << "Playlist is empty!\n";
        else {
            for (int i = 0; i < Savedmusics->musics.size(); ++i) {
                cout << " name : " << Savedmusics->musics[i]->getName() << " Artist : "
                     << Savedmusics->musics[i]->getArtist()
                     << " releaseYear : " << Savedmusics->musics[i]->getReleaseYear() << " Genre : "
                     << Savedmusics->musics[i]->getGenre();
            }
            cout << endl;
        }
    }


    void Creatplaylist() {
        string name, name2, gnr, rsy;
        string choice;
        int numberOfSongs = 0;
        cout << "Please enter the name of playlist: ";
        cin >> name;
        Playlist *newPlaylist = new Playlist(name, numberOfSongs);
        Allplaylists.push_back(newPlaylist);
        cout << "Playlist \"" << name << "\" has been created and added to your main playlists." << endl;
        cout << "Do you want to add a song to this playlist?(yes/no)\n";
        cin >> choice;
        if (choice == "yes") {
            cout << "Please enter the name of song :\n";
            cin >> name2;
            cout << "Please enter the date of song :\n";
            cin >> rsy;
            cout << "Please enter the genre of song :\n";
            cin >> gnr;
            Music *newmusic = new Music(name2, rsy, gnr);
            newPlaylist->addMusic(newmusic);
        }
    }

    void setUsername(string uname) {
        username = uname;
    }

    string getUsername() const {
        return username;
    }

    void setPassword(string pwd) {
        password = pwd;
    }

    string getPassword() const {
        return password;
    }

    void Showartistinf() {
        int index;
        cout << "Which artist do you want to choose?" << endl;
        for (int i = 0; i < artists.size(); ++i) {
            cout << "Artist : " << artists[i]->getName() << "Artist number : " << i + 1 << endl;
        }
        cin >> index;
        cout << "Name : " << artists[index - 1]->getName() << endl;
        cout << "country : " << artists[index - 1]->getCountry() << endl;
        cout << "birthYear : " << artists[index - 1]->getBirthDate() << endl;
    }
};
