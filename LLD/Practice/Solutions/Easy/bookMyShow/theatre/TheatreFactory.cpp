#include <bits/stdc++.h>
#include <screen.cpp>
#include <city.cpp>
#include <show.cpp>
#include<theatre.cpp>
using namespace std;

class TheatreFactory {
public:
    //Only Admin
    static Theatre createTheatre(int theatreId, const string& name, City city, const vector<Show>& shows) {
        Theatre theatre;
        theatre.setTheatreId(theatreId);
        theatre.setTheatreName(name);
        theatre.setScreens(createScreens());
        theatre.setCity(city);
        theatre.setShows(shows);
        return theatre;
    }

private:
    static vector<Screen> createScreens() {
        Screen screen;
        screen.setScreenId(1);
        screen.setSeats(createSeats());
        return {screen};  // initializer list = single-element vector
    }

    static vector<Seat> createSeats() {
        vector<Seat> seats;
        seats.reserve(100);   // optimize capacity upfront
        for (int i = 1; i <= 100; i++) {
            seats.emplace_back(Seat());  // add 100 Seat objects
        }
        return seats;
    }
};