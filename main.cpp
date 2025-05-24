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

class Admin {
private:
    string username;
    string password;
public:
    vector<Playlist *> playlists;

    void ArtistMaker(string name, string country, string birthdate) {
        Artist *newArtist = new Artist(name, country, birthdate);
        artists.push_back(newArtist);
    }

    Playlist Makeplaylist() {
        string name;
        int count;

        cout << "Enter playlist name: ";
        cin >> name;

        cout << "Enter expected number of songs: ";
        cin >> count;

        Playlist *newPlaylist = new Playlist(name, count);
        playlists.push_back(newPlaylist);

        cout << "\nPlaylist '" << name << "' created.\n";

        string choice;
        do {
            cout << "\nDo you want to add a music to this playlist? (yes/no): ";
            cin >> choice;

            if (choice == "yes" || choice == "YES" || choice == "Yes") {
                string musicName, releaseYear, genre;

                cout << "Enter music name: ";
                cin.ignore();
                getline(cin, musicName);

                cout << "Enter release year: ";
                getline(cin, releaseYear);

                cout << "Enter genre: ";
                getline(cin, genre);

                Music *newMusic = new Music(musicName, releaseYear, genre);
                newPlaylist->addMusic(newMusic);

                cout << "Music '" << musicName << "' added to the playlist.\n";
            }
        } while (choice == "yes" || choice == "YES" || choice == "Yes");

        do {
            cout << "\nDo you want to remove a music from this playlist? (yes/no): ";
            cin >> choice;

            if (choice == "yes" || choice == "YES" || choice == "Yes") {
                if (newPlaylist->musics.empty()) {
                    cout << "The playlist is empty. Nothing to remove.\n";
                    break;
                }

                cout << "\nCurrent musics in the playlist:\n";
                for (size_t i = 0; i < newPlaylist->musics.size(); ++i) {
                    Music *m = newPlaylist->musics[i];
                    cout << i + 1 << ". " << m->getName()
                         << " | Year: " << m->getReleaseYear()
                         << " | Genre: " << m->getGenre()
                         << " | Artist: " << m->getArtist() << endl;
                }

                int index;
                cout << "Enter the number of the music to remove: ";
                cin >> index;

                if (index >= 1 && index <= newPlaylist->musics.size()) {
                    delete newPlaylist->musics[index - 1];
                    newPlaylist->musics.erase(newPlaylist->musics.begin() + (index - 1));
                    cout << "Music removed.\n";
                } else {
                    cout << "Invalid index.\n";
                }
            }
        } while (choice == "yes" || choice == "YES" || choice == "Yes");
        return *newPlaylist;
    }


    void Addartist() {
        string name, country, birthday;
        cout << "Enter the information of the new Artist:\n";
        cout << "Name: ";
        cin >> name;
        cout << "Country: ";
        cin >> country;
        cout << "Birthday: ";
        cin >> birthday;

        Artist *newArtist = new Artist(name, country, birthday);
        artists.push_back(newArtist);

        string choice;
        do {
            cout << "\nDo you want to add a music or a playlist to this artist? (yes/no): ";
            cin >> choice;

            if (choice == "yes" || choice == "YES" || choice == "Yes") {
                int option;
                cout << "1. Add Playlist\n2. Add Music\nEnter your choice (1 or 2): ";
                cin >> option;

                switch (option) {
                    case 1: {
                        string playlistName;
                        int songCount;
                        cout << "Enter playlist name: ";
                        cin >> playlistName;
                        cout << "Enter expected number of songs: ";
                        cin >> songCount;

                        Playlist *newPlaylist = new Playlist(playlistName, songCount);

                        string addMusicChoice;
                        do {
                            cout << "\nDo you want to add music to this playlist? (yes/no): ";
                            cin >> addMusicChoice;

                            if (addMusicChoice == "yes" || addMusicChoice == "YES" || addMusicChoice == "Yes") {
                                string musicName, year, genre;
                                cout << "Enter music name: ";
                                cin.ignore();
                                getline(cin, musicName);
                                cout << "Enter release year: ";
                                getline(cin, year);
                                cout << "Enter genre: ";
                                getline(cin, genre);

                                Music *m = new Music(musicName, year, genre);
                                newPlaylist->addMusic(m);
                                newArtist->Addmusic(m);
                            }
                        } while (addMusicChoice == "yes" || addMusicChoice == "YES" || addMusicChoice == "Yes");

                        cout << "Playlist '" << playlistName << "' created and linked to artist '"
                             << newArtist->getName() << "'.\n";
                        break;
                    }

                    case 2: {
                        string musicName, year, genre;
                        cout << "Enter music name: ";
                        cin.ignore();
                        getline(cin, musicName);
                        cout << "Enter release year: ";
                        getline(cin, year);
                        cout << "Enter genre: ";
                        getline(cin, genre);

                        Music *m = new Music(musicName, year, genre);
                        newArtist->Addmusic(m);
                        cout << "Music '" << musicName << "' added to artist '" << newArtist->getName() << "'.\n";
                        break;
                    }

                    default:
                        cout << "Invalid option.\n";
                }
            }
        } while (choice == "yes" || choice == "YES" || choice == "Yes");
    }

    void Editartist() {
        string name;
        string country;
        string birthday;
        int choice;
        int index;
        cout << "Which artist do you want to change?" << endl;
        for (int i = 0; i < artists.size(); ++i) {
            cout << "Artist : " << artists[i]->getName() << "Artist number : " << i + 1 << endl;
        }
        cin >> index;
        cout << "What do you want to change ? \n";
        cout << "1.name \n2.country \n3.birthday\n";
        cin >> choice;
        switch (choice) {
            case 1: {
                cin >> name;
                artists[index - 1]->setName(name);
                break;
            }
            case 2: {
                cin >> country;
                artists[index - 1]->setCountry(country);
                break;
            }
            case 3: {
                cin >> birthday;
                artists[index - 1]->setBirthDate(birthday);
                break;
            }
        }
    }

    void Showartistinf() {
        int index;
        cout << "Which artist do you want to choose?" << endl;
        for (int i = 0; i < artists.size(); ++i) {
            cout << "Artist : " << artists[i]->getName() << " \nArtist number : " << i + 1 << endl;
        }
        cout << "Which artist's information do you want to check more closely?\n";
        cin >> index;
        if (index < 1 || index > (int) artists.size()) {
            cout << "Invalid artist number!" << endl;
            return;
        }
        cout << "Name : " << artists[index - 1]->getName() << endl;
        cout << "country : " << artists[index - 1]->getCountry() << endl;
        cout << "birthYear : " << artists[index - 1]->getBirthDate() << endl;
        for (int i = 0; i < artists[index - 1]->musics.size(); ++i) {
            cout << "Musics : \n" << "Name : " << artists[index - 1]->musics[i]->getName() << "\nReleaseYear : "
                 << artists[index - 1]->musics[i]->getReleaseYear() << "\nGenre : "
                 << artists[index - 1]->musics[i]->getGenre() << endl;
        }
        cout << "\nNumber of songs :"
             << artists[index - 1]->getNumberofMusics() << "\nNumber of albums : "
             << artists[index - 1]->getNumberofalbums() << endl;
    }

    void addmusictoartist() {
        if (artists.empty()) {
            cout << "No artists available.\n";
            return;
        }
        cout << "Choose artist:\n";
        for (int i = 0; i < artists.size(); ++i) {
            cout << i + 1 << ". " << artists[i]->getName() << endl;
        }

        int choice;
        cin >> choice;
        if (choice < 1 || choice > artists.size()) {
            cout << "Invalid artist selection.\n";
            return;
        }

        if (musics.empty()) {
            cout << "No musics available to add.\n";
            return;
        }

        cout << "Choose music to add:\n";
        for (int i = 0; i < musics.size(); ++i) {
            cout << i + 1 << ". " << musics[i]->getName() << endl;
        }

        int index;
        cin >> index;
        if (index < 1 || index > musics.size()) {
            cout << "Invalid music selection.\n";
            return;
        }

        artists[choice - 1]->Addmusic(musics[index - 1]);
        musics[index - 1]->setArtistPointer(artists[choice - 1]);
        cout << "Music added to artist successfully.\n";
        artists[choice - 1]->Addnumberofmusics(1);
    }

    void Setusername(string A = "AdminUser") {
        this->username = A;
    }

    string Get_Username() {
        return username;
    }

    string Get_Password() {
        return password;
    }

    void Setpassword(string B = "StrongPassword123") {
        password = B;
    }

    void Checkenter(string user, string pass) {
        bool entercheck = true;
        if (user == username && pass == password) {
            cout << "welcome " << username << endl;
        } else {
            cout << "invalid username or password\n";
            entercheck = false;
        }
    }

    vector<Music *> musics;
    vector<Artist *> artists;
};
