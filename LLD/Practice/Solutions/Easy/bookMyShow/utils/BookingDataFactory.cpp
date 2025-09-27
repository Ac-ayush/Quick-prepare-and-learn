
#ifndef BOOKINGDATAFACTORY_H
#define BOOKINGDATAFACTORY_H

#include <bits/stdc++.h>
#include "../movie/movie.cpp"
#include "../theatre/screen.cpp"
#include "../theatre/show.cpp"
#include "../theatre/seat.cpp"
#include "../enums/city.cpp"
#include "../controllers/MovieController.cpp"
#include "../controllers/TheatreController.cpp"
#include "../theatre/TheatreFactory.cpp"
#include "../movie/MovieFactory.cpp"
using namespace std;

class BookingDataFactory
{
public:
    static vector<Screen> createScreens();

    static Show createShow(int showId, Movie *movie, int showStartTime);

    static vector<Seat> createSeats();

    static vector<Movie *> createMovies(MovieController &movieController);

    static void createTheatres(MovieController &movieController, TheatreController &theatreController);
};

// ----------- Implementation -----------

vector<Screen> BookingDataFactory::createScreens()
{
    vector<Screen> screens;
    Screen screen1;
    screen1.setScreenId(1);
    screen1.setSeats(createSeats());
    screens.push_back(screen1);
    return screens;
}

Show BookingDataFactory::createShow(int showId, Movie *movie, int showStartTime)
{
    Show show;
    show.setShowId(showId);
    show.setMovie(movie);
    show.setShowStartTime(showStartTime);
    return show;
}

vector<Seat> BookingDataFactory::createSeats()
{
    vector<Seat> seats;
    for (int i = 1; i <= 100; i++)
    {
        Seat seat;
        seat.setSeatId(i);
        seats.push_back(seat);
    }
    return seats;
}

vector<Movie *> BookingDataFactory::createMovies(MovieController &movieController)
{
    Movie *barbie = MovieFactory::createMovie(1, "BARBIE", 128);
    Movie *oppenheimer = MovieFactory::createMovie(2, "OPPENHEIMER", 180);

    movieController.addMovie(barbie, City::Bangalore);
    movieController.addMovie(barbie, City::Delhi);
    movieController.addMovie(oppenheimer, City::Bangalore);
    movieController.addMovie(oppenheimer, City::Delhi);

    return {barbie, oppenheimer};
}

void BookingDataFactory::createTheatres(MovieController &movieController, TheatreController &theatreController)
{
    Movie *barbie = movieController.getMovieByName("BARBIE");
    Movie *oppenheimer = movieController.getMovieByName("OPPENHEIMER");

    // Create theatres dynamically to avoid scope issues
    Theatre *inox = new Theatre();
    *inox = TheatreFactory::createTheatre(
        1, "INOX", City::Bangalore,
        {createShow(1, barbie, 10), createShow(2, oppenheimer, 18)});

    Theatre *pvr = new Theatre();
    *pvr = TheatreFactory::createTheatre(
        2, "PVR", City::Delhi,
        {createShow(3, barbie, 14), createShow(4, oppenheimer, 20)});

    theatreController.addTheatre(inox, City::Bangalore);
    theatreController.addTheatre(pvr, City::Delhi);
}

#endif // BOOKINGDATAFACTORY_H
