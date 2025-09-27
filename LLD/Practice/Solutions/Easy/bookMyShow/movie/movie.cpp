#ifndef MOVIE_H
#define MOVIE_H

#include <bits/stdc++.h>
using namespace std;

class Movie
{
    int movieId;
    string movieName;
    int durationInMinutes;

public:
    Movie(int id, string name, int duration)
    {
        this->movieId = id;
        this->movieName = name;
        this->durationInMinutes = duration;
        // other details like Genere, Language etc.
    }

    int getMovieId()
    {
        return movieId;
    }

    void setMovieId(int movieId)
    {
        this->movieId = movieId;
    }

    string getMovieName()
    {
        return movieName;
    }

    void setMovieName(string movieName)
    {
        this->movieName = movieName;
    }

    int getMovieDuration()
    {
        return durationInMinutes;
    }

    void setMovieDuration(int movieDuration)
    {
        this->durationInMinutes = movieDuration;
    }
};

#endif // MOVIE_H