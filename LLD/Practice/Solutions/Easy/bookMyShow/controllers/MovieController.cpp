#include <bits/stdc++.h>
#include<movie.cpp>
#include<city.cpp>
using namespace std;


class MovieController {
private:
    unordered_map<City, vector<Movie*>> cityVsMovies;
    vector<Movie*> allMovies;

public:
    MovieController() = default;

    void addMovie(Movie* movie, City city) {
        allMovies.push_back(movie);
        cityVsMovies[city].push_back(movie);
    }

    Movie* getMovieByName(const string& movieName) {
        for (Movie* movie : allMovies) {
            if (movie->getMovieName() == movieName) {
                return movie;
            }
        }
        return nullptr;
    }

    vector<Movie*> getMoviesByCity(City city) {
        if (cityVsMovies.find(city) != cityVsMovies.end()) {
            return cityVsMovies[city];
        }
        return {}; // return empty vector if city not found
    }
};
