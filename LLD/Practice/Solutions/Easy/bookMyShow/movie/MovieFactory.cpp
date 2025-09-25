#include <bits/stdc++.h>
#include <movie.cpp>
using namespace std;

class MovieFactory
{
private:
    // Cache: key = movie name, value = shared_ptr<Movie>
    static unordered_map<string, shared_ptr<Movie>> movieCache;

public:
    static shared_ptr<Movie> createMovie(int id, const string &name, int duration)
    {
        auto it = movieCache.find(name);
        if (it != movieCache.end())
        {
            return it->second; // return existing movie
        }
        auto movie = make_shared<Movie>(id, name, duration);
        movieCache[name] = movie;
        return movie;
    }
};