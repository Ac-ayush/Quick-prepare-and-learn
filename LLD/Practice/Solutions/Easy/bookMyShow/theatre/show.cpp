#ifndef SHOW_H
#define SHOW_H

#include <bits/stdc++.h>
#include "../movie/movie.cpp"
#include "screen.cpp"
using namespace std;

class Show
{
private:
    int showId;
    Movie *movie;   // Could use shared_ptr<Movie>
    Screen *screen; // Could use shared_ptr<Screen>
    int showStartTime;
    vector<int> bookedSeatIds;

public:
    // Constructors
    Show() : showId(0), movie(nullptr), screen(nullptr), showStartTime(0) {}
    Show(int id, Movie *m, Screen *s, int startTime)
        : showId(id), movie(m), screen(s), showStartTime(startTime) {}

    // Getters & Setters
    int getShowId() const
    {
        return showId;
    }

    void setShowId(int id)
    {
        showId = id;
    }

    Movie *getMovie() const
    {
        return movie;
    }

    void setMovie(Movie *m)
    {
        movie = m;
    }

    Screen *getScreen() const
    {
        return screen;
    }

    void setScreen(Screen *s)
    {
        screen = s;
    }

    int getShowStartTime() const
    {
        return showStartTime;
    }

    void setShowStartTime(int startTime)
    {
        showStartTime = startTime;
    }

    vector<int> &getBookedSeatIds()
    {
        return bookedSeatIds;
    }

    void setBookedSeatIds(const vector<int> &seats)
    {
        bookedSeatIds = seats;
    }
};

#endif // SHOW_H
