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

class Database {
public :
    vector<string> Username;
    vector<string> Password;
};

class Lobby {
public:
    vector<Playlist> playlists;
    Database D1;
    Admin A1;
    User U1;
    vector<Music *> allmusics;

    void Run() {
        A1.ArtistMaker("Tiem", "Iran", "1998");
        A1.ArtistMaker("Hayede", "Iran", "1942");
        A1.ArtistMaker("Ebi", "Iran", "1949");
        A1.ArtistMaker("SajadShahi", "Iran", "1999");
        A1.ArtistMaker("Billie Eilish", "US", "2001");

        Music *m1 = new Music("Booye Eydi", "1970", "Pop");
        Music *m2 = new Music("Ashegham Man", "1990", "Pop");
        Music *m3 = new Music("Soghati", "1976", "Pop");
        Music *m4 = new Music("Shabe Eshgh", "1978", "Pop");
        Music *m5 = new Music("Gole Sangam", "1975", "Pop");
        Music *m6 = new Music("Gole Yakh", "1975", "Pop");
        Music *m7 = new Music("+18", "2024", "Rap");
        Music *m8 = new Music("8Khat", "2025", "Rap");
        Music *m9 = new Music("DeleSir", "2024", "R&B");
        Music *m10 = new Music("Ey", "2023", "Rap");
        Music *m11 = new Music("3:00AM", "2024", "Rap");
        Music *m12 = new Music("Ghesse", "2024", "Rap");
        Music *m13 = new Music("Boro", "2024", "Rap");
        Music *m14 = new Music("Bad Guy", "2019", "Pop/Electropop");
        Music *m15 = new Music("Lovely", "2018", "Pop");
        Music *m16 = new Music("When the Party's Over", "2018", "Alternative/Indie");
        Music *m17 = new Music("Happier Than Ever", "2021", "Alternative Rock");

        allmusics.push_back(m1);
        allmusics.push_back(m2);
        allmusics.push_back(m3);
        allmusics.push_back(m4);
        allmusics.push_back(m5);
        allmusics.push_back(m6);
        allmusics.push_back(m7);
        allmusics.push_back(m8);
        allmusics.push_back(m9);
        allmusics.push_back(m10);
        allmusics.push_back(m11);
        allmusics.push_back(m12);
        allmusics.push_back(m13);
        allmusics.push_back(m14);
        allmusics.push_back(m15);
        allmusics.push_back(m16);
        allmusics.push_back(m17);


        A1.artists[0]->musics.push_back(m7);
        A1.artists[0]->musics.push_back(m8);
        A1.artists[0]->musics.push_back(m9);
        A1.artists[0]->musics.push_back(m10);
        A1.artists[0]->Addnumberofmusics(4);


        A1.artists[3]->musics.push_back(m11);
        A1.artists[3]->musics.push_back(m12);
        A1.artists[3]->musics.push_back(m13);
        A1.artists[3]->Addnumberofmusics(3);


        A1.artists[1]->musics.push_back(m2);
        A1.artists[1]->musics.push_back(m4);
        A1.artists[1]->musics.push_back(m5);
        A1.artists[1]->musics.push_back(m3);
        A1.artists[1]->Addnumberofmusics(4);


        A1.artists[2]->musics.push_back(m6);
        A1.artists[2]->musics.push_back(m1);
        A1.artists[2]->Addnumberofmusics(2);


        A1.artists[4]->musics.push_back(m14);
        A1.artists[4]->musics.push_back(m15);
        A1.artists[4]->musics.push_back(m16);
        A1.artists[4]->musics.push_back(m17);
        A1.artists[4]->Addnumberofmusics(4);


        A1.musics.push_back(m1);
        A1.musics.push_back(m2);
        A1.musics.push_back(m3);
        A1.musics.push_back(m4);
        A1.musics.push_back(m5);
        A1.musics.push_back(m6);
        A1.musics.push_back(m7);
        A1.musics.push_back(m8);
        A1.musics.push_back(m9);
        A1.musics.push_back(m10);
        A1.musics.push_back(m11);
        A1.musics.push_back(m12);
        A1.musics.push_back(m13);
        A1.musics.push_back(m14);
        A1.musics.push_back(m15);
        A1.musics.push_back(m16);
        A1.musics.push_back(m17);


        A1.Setusername("AdminUser");
        A1.Setpassword("StrongPassword123");
        int choice1, choice2, choice3;
        string username;
        string password;
        string passcheck;
        do {
            cout << "Which section do you want enter ?\n";
            cout << "1:Users\n2:Admin\n3:Exit";
            cin >> choice1;
            switch (choice1) {
                case 1: { //User
                    cout << "1:Login:\n2:Sign_up\n";
                    cin >> choice2;
                    switch (choice2) {
                        case 1 : {
                            cout << "Please enter your Username and Password :\n";
                            cin >> username;
                            cin >> password;
                            for (int i = 0; i < D1.Username.size(); ++i) {
                                if (username == D1.Username[i] && password == D1.Password[i]) {
                                    cout << "Welcome " << D1.Username[i] << endl;
                                    cout << "As a user, you have access to the following features:\n";
                                    int choice_1;
                                    do {
                                        cout << "1:View the list of saved songs\n";
                                        cout << "2:View the list of liked songs\n";
                                        cout << "3:View the list of liked Playlists\n";
                                        cout << "4:Search\n";
                                        cout << "5:Play musics\n";
                                        cout << "6:Playlists\n";
                                        cout << "7:Exit\n";
                                        cin >> choice_1;
                                        switch (choice_1) {
                                            case 1: {
                                                string ask;
                                                int index;
                                                cout << "Saved songs :" << endl;
                                                U1.ViewSavedmusic();
                                                cout << "Do you want to save a new song?(yes,no)\n";
                                                cin >> ask;
                                                if (ask == "yes") {
                                                    cout << endl << "Which song do you want to save?\n";
                                                    for (int i = 0; i < allmusics.size(); ++i) {
                                                        cout << "_" << i + 1 << " " << "Name : "
                                                             << allmusics[i]->getName() << endl;
                                                    }
                                                    cin >> index;
                                                    U1.Savedmusic(allmusics[index - 1]);
                                                }
                                                break;
                                            }
                                            case 2: {
                                                string ask;
                                                int index;
                                                cout << "Liked songs : " << endl;
                                                U1.ViewLikedmusic();
                                                cout << "Do you want to add a new song to the liked songs ?(yes,no)\n";
                                                cin >> ask;
                                                if (ask == "yes") {
                                                    cout << endl << "Which song do you want to add?\n";
                                                    for (int i = 0; i < allmusics.size(); ++i) {
                                                        cout << "_" << i + 1 << " " << "Name : "
                                                             << allmusics[i]->getName() << endl;
                                                    }
                                                    cin >> index;
                                                    U1.Likedmusic(allmusics[index - 1]);
                                                }
                                                break;
                                            }
                                            case 3: {
                                                cout << "Playlists : " << endl;
                                                if (U1.Allplaylists.empty()) cout << "There is not any playlists";
                                                for (int j = 0; j < U1.Allplaylists.size(); ++j) {
                                                    cout << U1.Allplaylists[j]->getName() << endl;
                                                }
                                                break;
                                            }
                                            case 4: {
                                                int choice0;
                                                cout
                                                        << "In which section would you like to search? Songs or Playlists?\n";
                                                cout << "1:Songs\n2:Playlists:\n";
                                                cin >> choice0;
                                                switch (choice0) {
                                                    case 1: {
                                                        string Musicname;
                                                        cout << "What song are you looking for?\n";
                                                        cin >> Musicname;
                                                        for (int j = 0; j < allmusics.size(); ++j) {
                                                            if (allmusics[j]->getName() == Musicname) {
                                                                cout << "Name : " << allmusics[j]->getName() << endl
                                                                     << "Genre : " << allmusics[j]->getGenre() << endl
                                                                     << "Release Year :  "
                                                                     << allmusics[j]->getReleaseYear() << endl
                                                                     << "Artist : " << allmusics[j]->getArtist()
                                                                     << endl;
                                                            }
                                                        }
                                                        break;
                                                    }
                                                    case 2 : {
                                                        string Playlistname;
                                                        cout << "What playlist are you looking for?\n";
                                                        cin >> Playlistname;
                                                        for (int j = 0; j < U1.Allplaylists.size(); ++j) {
                                                            if (U1.Allplaylists[j]->getName() == Playlistname) {
                                                                cout << "Playlist name : "
                                                                     << U1.Allplaylists[j]->getName() << endl
                                                                     << "Number of musics : "
                                                                     << U1.Allplaylists[j]->numberOfSongs << endl;
                                                            }
                                                        }
                                                        break;
                                                    }
                                                }
                                                break;
                                            }
                                            case 5 : {
                                                string musicplay, v;
                                                bool check = true;
//                                                cout << "How should the song be played?\n";
//                                                cin >> v;
                                                cout << "Enter the name of the song you want to play.\n";
                                                cin >> musicplay;
                                                for (int j = 0; j < allmusics.size(); ++j) {
                                                    if (musicplay == allmusics[j]->getName()) {
                                                        int blinkCount = 4;
                                                        for (int i = 0; i < blinkCount; ++i) {
                                                            std::cout << allmusics[j]->getName() << std::endl;
                                                            std::this_thread::sleep_for(std::chrono::milliseconds(500));
                                                            system("cls");
                                                            std::this_thread::sleep_for(std::chrono::milliseconds(500));
                                                        }
                                                        check = false;
                                                    }
                                                }
                                                cout << endl;
                                                if (check == true) cout << "Not Find!" << endl;
                                                break;
                                            }
                                            case 6 : {
                                                int choice;
                                                cout << "The following features are available in this section:\n";
                                                cout << "1 : Creat playlist\n2 : Show playlists\n3 : Delete playlist\n";
                                                cin >> choice;
                                                switch (choice) {
                                                    case 1 : {
                                                        U1.Creatplaylist();
                                                        break;
                                                    }
                                                    case 2 : {
                                                        int index;
                                                        cout << "Choose one :\n";
                                                        for (int j = 0; j < U1.Allplaylists.size(); ++j) {
                                                            cout << "_" << j + 1 << "_" << U1.Allplaylists[j]->getName()
                                                                 << endl;
                                                        }
                                                        cin >> index;
                                                        cout << U1.Allplaylists[index - 1]->getName() << endl;
                                                        cout << U1.Allplaylists[index - 1]->numberOfSongs << endl;
                                                        for (int j = 0;
                                                             j < U1.Allplaylists[index - 1]->musics.size(); ++j) {
                                                            cout << U1.Allplaylists[index - 1]->musics[j]->getName()
                                                                 << endl;
                                                        }
                                                        break;
                                                    }
                                                    case 3 : {
                                                        if (U1.Allplaylists.empty()) {
                                                            cout << "There is no playlist to delete.\n";
                                                            break;
                                                        }

                                                        cout << "Available playlists:\n";
                                                        for (int i = 0; i < U1.Allplaylists.size(); ++i) {
                                                            cout << i + 1 << ". " << U1.Allplaylists[i]->getName()
                                                                 << endl;
                                                        }

                                                        int deleteIndex;
                                                        cout
                                                                << "Enter the number of the playlist you want to delete:\n";
                                                        cin >> deleteIndex;

                                                        if (deleteIndex < 1 || deleteIndex > U1.Allplaylists.size()) {
                                                            cout << "Invalid index.\n";
                                                        } else {
                                                            delete U1.Allplaylists[deleteIndex - 1];

                                                            U1.Allplaylists.erase(
                                                                    U1.Allplaylists.begin() + deleteIndex - 1);
                                                            cout << "Playlist deleted successfully.\n";
                                                        }
                                                        break;
                                                    }

                                                }
                                                break;
                                            }
                                        }
                                    } while (choice_1 != 7);
                                }
                            }
                            break;
                        }
                        case 2 : {
                            cout << "Please enter your Username and Password :\n";
                            cin >> username;
                            cin >> password;
                            cout << "Please enter your password again :\n";
                            cin >> passcheck;
                            if (password != passcheck) {
                                cout << "Passwords do not match\n" << "try again!\n";
                            } else {
                                cout << "You have successfully registered.\n";
                                cout << "Welcome to new user : " << username << endl;
                                D1.Username.push_back(username);
                                D1.Password.push_back(password);

                            }
                            break;
                        }
                    }
                    break;
                }
                case 2 : {  // Admin
                    cout << "Please enter your Username and Password :\n";
                    cin >> username;
                    cin >> password;
                    if (username != A1.Get_Username() || password != A1.Get_Password()) {
                        cout << "invalid username or password\n";
                    } else {
                        cout << "Welcome to Admin (MehrasHamze)\n";
                        cout << "You are now logged in as admin" << endl;
                        // Admins options
                        cout << "You can now access the following options:\n";
                        // Addartist editartist Showartistinf addmusictoartist Makeplaylist
                        cout
                                << "-1 : Add new Artist\n-2 : Edit Artists\n-3 : Show Artists information\n-4 : Add music to an artist\n-5 : Make Playlist\n";
                        cin >> choice3;
                        switch (choice3) {
                            case 1 : {
                                A1.Addartist();
                                break;
                            }
                            case 2 : {
                                A1.Editartist();
                                break;
                            }
                            case 3 : {
                                A1.Showartistinf();
                                break;
                            }
                            case 4 : {
                                A1.addmusictoartist();
                                break;
                            }
                            case 5 : {
                                A1.Makeplaylist();
                                break;

                            }
                        }
                    }
                }
            }
        } while (choice1 != 3);
    }
};

int main() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    Lobby L1;
    L1.Run();
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    return 0;
}
    