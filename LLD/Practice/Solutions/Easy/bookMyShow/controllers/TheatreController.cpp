#include <bits/stdc++.h>
#include<movie.cpp>
#include<city.cpp>
#include<show.cpp>
#include<theatre.cpp>
using namespace std;

// Assume City is an enum defined elsewhere
enum class City {
    Bangalore,
    Delhi
};

// Forward declarations
class Movie;
class Show;
class Theatre;

class TheatreController {
public:
    // Map<City, List<Theatre>>
    unordered_map<City, vector<Theatre*>> cityVsTheatre;
    // Nagpur → [PVR, INOX]
    // Mumbai → [Cinepolis, Carnival]

    // List<Theatre>
    vector<Theatre*> allTheatre;
    // allTheatre = [PVR, INOX, Cinepolis, Carnival]

    // Constructor
    TheatreController() {
        cityVsTheatre = unordered_map<City, vector<Theatre*>>();
        allTheatre = vector<Theatre*>();
    }

    // ADD theatre to a particular city
    void addTheatre(Theatre* theatre, City city) {
        allTheatre.push_back(theatre);

        vector<Theatre*> theatres;
        if (cityVsTheatre.find(city) != cityVsTheatre.end()) {
            theatres = cityVsTheatre[city];
        }
        theatres.push_back(theatre);
        cityVsTheatre[city] = theatres;
    }

    // Get all shows of a particular movie in a particular city
    map<Theatre*, vector<Show>> getAllShow(Movie* movie, City city) {
        // get all the theatres of this city
        map<Theatre*, vector<Show>> theatreVsShows;

        vector<Theatre*> theatres;
        if (cityVsTheatre.find(city) != cityVsTheatre.end()) {
            theatres = cityVsTheatre[city];
        }
        // theatre = [PVR, INOX]

        // filter the theatres which run this movie
        for (Theatre* theatre : theatres) {
            vector<Show> givenMovieShows;
            vector<Show> shows = theatre->getShows();
            // shows = [morning, evening]

            for (Show& show : shows) {
                if (show.getMovie()->getMovieId() == movie->getMovieId()) {
                    givenMovieShows.push_back(show);
                }
            }
            // givenMovieShows = [morning, evening]
            if (!givenMovieShows.empty()) {
                theatreVsShows[theatre] = givenMovieShows;
            }
        }

        return theatreVsShows;
    }
};
