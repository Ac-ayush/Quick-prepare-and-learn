#ifndef MOVIECONTROLLER_H
#define MOVIECONTROLLER_H

#include <bits/stdc++.h>
#include "../movie/movie.cpp"
#include "../enums/city.cpp"
using namespace std;

class MovieController
{
private:
    unordered_map<City, vector<Movie *>> cityVsMovies;
    vector<Movie *> allMovies;

public:
    MovieController() = default;

    void addMovie(Movie *movie, City city)
    {
        allMovies.push_back(movie);
        cityVsMovies[city].push_back(movie);
    }

    Movie *getMovieByName(const string &movieName)
    {
        for (Movie *movie : allMovies)
        {
            if (movie->getMovieName() == movieName)
            {
                return movie;
            }
        }
        return nullptr;
    }

    vector<Movie *> getMoviesByCity(City city)
    {
        if (cityVsMovies.find(city) != cityVsMovies.end())
        {
            return cityVsMovies[city];
        }
        return {}; // return empty vector if city not found
    }
};

#endif // MOVIECONTROLLER_H
