#include <string>
using namespace std;

enum class vehicleType
{
    BIKE,
    CAR,
    TRUCK,
    BUS
};

class Vehicle
{
    string licenceNumber;
    vehicleType type;
    string color;

public:
    Vehicle(string licenceNumber, vehicleType type, string color)
    {
        this->licenceNumber = licenceNumber;
        this->type = type;
        this->color = color;
    }

    vehicleType getVehicleType()
    {
        return this->type;
    }
};

int main()
{
    Vehicle v1("C4303", vehicleType::CAR, "black");
}