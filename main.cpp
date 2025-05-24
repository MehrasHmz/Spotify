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
