#include <bits/stdc++.h>
using namespace std;

enum class City
{
    Bangalore,
    Mumbai,
    Chennai,
    Delhi
};

// ✅ Provide a "values()" helper like Java
inline vector<City> values() {
    return { City::Bangalore, City::Mumbai, City::Chennai, City::Delhi };
}

// ✅ Provide a "toString" helper for display
inline string toString(City city) {
    switch (city) {
        case City::Bangalore: return "Bangalore";
        case City::Mumbai:    return "Mumbai";
        case City::Chennai:   return "Chennai";
        case City::Delhi:     return "Delhi";
        default:              return "Unknown";
    }
}