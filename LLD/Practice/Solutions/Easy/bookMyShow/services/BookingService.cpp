#include <bits/stdc++.h>
#include <string>
#include "city.cpp"
#include "MovieController.cpp"
#include "TheatreController.cpp"
#include "movie.cpp"
#include "show.cpp"
#include "theatre.cpp"
#include "BookingDataFactory.cpp"
#include "PaymentService.cpp"

using namespace std;

class BookingService {
private:
    static BookingService* instance; // ✅ Singleton instance

    MovieController movieController;
    TheatreController theatreController;

    // ✅ Private constructor
    BookingService() {}

    // Helper to generate random UUID-like string
    string generateUUID() {
        stringstream ss;
        for (int i = 0; i < 8; ++i) ss << hex << rand() % 16;
        ss << "-";
        for (int i = 0; i < 4; ++i) ss << hex << rand() % 16;
        ss << "-";
        for (int i = 0; i < 4; ++i) ss << hex << rand() % 16;
        ss << "-";
        for (int i = 0; i < 4; ++i) ss << hex << rand() % 16;
        ss << "-";
        for (int i = 0; i < 12; ++i) ss << hex << rand() % 16;
        return ss.str();
    }

public:
    static BookingService* getInstance() { // ✅ Singleton method
        if (!instance) {
            instance = new BookingService();
        }
        return instance;
    }

    void startBookingSession() {
        printHeader("🎬 Welcome to BookMyShow 🎟️");
        bool continueBooking = true;

        while (continueBooking) {
            City userCity = selectCity();
            Movie* selectedMovie = selectMovie(userCity);
            Show selectedShow = selectShow(userCity, selectedMovie);
            bookSeat(selectedShow);

            cout << "Do you want to book another ticket? (yes/no): ";
            string response;
            cin >> response;
            for (auto &c : response) c = tolower(c); // lowercase
            continueBooking = (response == "yes");
        }

        printSuccess("Thank you for using BookMyShow! 🎬 Have a great day!");
    }

    City selectCity() {
        printSection("🏙️ Select Your City");
        vector<City> cities = values(); // assume you implemented values() in City enum
        for (size_t i = 0; i < cities.size(); i++) {
            cout << "   " << (i + 1) << ". " << toString(cities[i]) << endl;
        }
        return cities[getUserChoice(1, cities.size()) - 1];
    }

    Movie* selectMovie(City city) {
        vector<Movie*> movies = movieController.getMoviesByCity(city);
        printSection("🎥 Available Movies in " + toString(city));
        for (size_t i = 0; i < movies.size(); i++) {
            cout << "   " << (i + 1) << ". " << movies[i]->getMovieName() << endl;
        }
        return movies[getUserChoice(1, movies.size()) - 1];
    }

    Show selectShow(City city, Movie* movie) {
        map<Theatre*, vector<Show>> showsMap = theatreController.getAllShow(movie, city);

        vector<Show> availableShows;
        printSection("🎭 Available Shows for " + movie->getMovieName() + " in " + toString(city));
        int index = 1;
        for (auto& entry : showsMap) {
            Theatre* theatre = entry.first;
            for (auto show : entry.second) {
                cout << "   " << index << ". " << show.getShowStartTime()
                     << " at 🎦 " << theatre->getTheatreName() << endl;
                availableShows.push_back(show);
                index++;
            }
        }
        return availableShows[getUserChoice(1, availableShows.size()) - 1];
    }

    void bookSeat(Show show) {
        printSection("💺 Select Your Seat (1-100)");
        int seatNumber = getUserChoice(1, 100);
        vector<int>& bookedSeats = show.getBookedSeatIds();

        if (find(bookedSeats.begin(), bookedSeats.end(), seatNumber) != bookedSeats.end()) {
            cout << "❌ Seat already booked! Please try another seat." << endl;
            bookSeat(show);
        } else {
            bookedSeats.push_back(seatNumber);
            PaymentService paymentService;
            bool paymentSuccess = paymentService.processPayment(250); // Example amount

            if (paymentSuccess) {
                printSuccess("✅ Booking Successful! Enjoy your movie! 🍿");
                generateTicket(show, seatNumber);
            } else {
                cout << "❌ Payment failed! Please try again." << endl;
                bookedSeats.erase(remove(bookedSeats.begin(), bookedSeats.end(), seatNumber), bookedSeats.end());
            }
        }
    }

    void generateTicket(Show show, int seatNumber) {
        cout << "\n========================================" << endl;
        cout << "🎟️       MOVIE TICKET CONFIRMATION       🎟️" << endl;
        cout << "========================================" << endl;
        cout << "🎬 Movie: " << show.getMovie()->getMovieName() << endl;
        cout << "⏰ Show Time: " << show.getShowStartTime() << ":00" << endl;
        cout << "💺 Seat Number: " << seatNumber << endl;
        cout << "----------------------------------------" << endl;
        time_t t = time(nullptr);
        cout << "📅 Date: " << put_time(localtime(&t), "%Y-%m-%d") << endl;
        cout << "🆔 Booking ID: " << generateUUID() << endl;
        cout << "========================================" << endl;
        cout << "🎉 Enjoy your movie! 🍿 Have a great time!" << endl;
        cout << "========================================\n" << endl;
    }

    int getUserChoice(int min, int max) {
        int choice;
        do {
            cout << "👉 Enter choice (" << min << "-" << max << "): ";
            while (!(cin >> choice)) {
                cout << "❌ Invalid input! Please enter a number." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } while (choice < min || choice > max);
        return choice;
    }

    void printHeader(const string& text) {
        cout << "\n══════════════════════════════════════════" << endl;
        cout << "          " << text << endl;
        cout << "══════════════════════════════════════════\n" << endl;
    }

    void printSection(const string& text) {
        cout << "\n🔹 " << text << endl;
        cout << "──────────────────────────────────────────" << endl;
    }

    void printSuccess(const string& text) {
        cout << "\n🎉 " << text << "\n" << endl;
    }

    void initialize() {
        BookingDataFactory::createMovies(movieController);
        BookingDataFactory::createTheatres(movieController, theatreController);
    }
};

// Define static instance
BookingService* BookingService::instance = nullptr;
