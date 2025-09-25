#include <bits/stdc++.h>
#include <screen.cpp>
#include <city.cpp>
#include <show.cpp>
using namespace std;

class Theatre
{
    int theatreId;
    string address;
    string theatreName;
    City* city;
    vector<Screen> screens;
    vector<Show> shows;

public:
    // Constructors
    Theatre() : theatreId(0), city(nullptr) {}
    Theatre(int id, const string& name, const string& addr, City* c)
        : theatreId(id), theatreName(name), address(addr), city(c) {}

    // Getters & Setters
    int getTheatreId() const {
        return theatreId;
    }

    void setTheatreId(int id) {
        theatreId = id;
    }

    string getAddress() const {
        return address;
    }

    void setAddress(const string& addr) {
        address = addr;
    }

    string getTheatreName() const {
        return theatreName;
    }

    void setTheatreName(const string& name) {
        theatreName = name;
    }

    City* getCity() const {
        return city;
    }

    void setCity(City* c) {
        city = c;
    }

    vector<Screen>& getScreens() {
        return screens;
    }

    void setScreens(const vector<Screen>& scr) {
        screens = scr;
    }

    vector<Show>& getShows() {
        return shows;
    }

    void setShows(const vector<Show>& shw) {
        shows = shw;
    }
};
