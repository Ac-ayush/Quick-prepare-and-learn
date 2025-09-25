#include <bits/stdc++.h>
#include <seat.cpp>
using namespace std;


class Screen {
private:
    int screenId;
    vector<Seat> seats;

public:
    // Constructors
    Screen() : screenId(0) {}
    Screen(int id, const vector<Seat>& s) : screenId(id), seats(s) {}

    // Getters & Setters
    int getScreenId() const {
        return screenId;
    }

    void setScreenId(int id) {
        screenId = id;
    }

    vector<Seat>& getSeats() {
        return seats;
    }

    void setSeats(const vector<Seat>& s) {
        seats = s;
    }
};