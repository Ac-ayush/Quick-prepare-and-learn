#include <bits/stdc++.h>
#include <movie.cpp>
using namespace std;

class MovieFactory {
private:
    static unordered_map<string, Movie*> movieCache;

public:
    static Movie* createMovie(int id, const string& name, int duration) {
        auto it = movieCache.find(name);
        if (it != movieCache.end()) {
            return it->second; // return cached
        }
        Movie* movie = new Movie(id, name, duration);
        movieCache[name] = movie;
        return movie;
    }
};