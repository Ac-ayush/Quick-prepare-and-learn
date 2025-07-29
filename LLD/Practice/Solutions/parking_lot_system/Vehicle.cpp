#include <bits/stdc++.h>
using namespace std;

enum class vehicleType
{
    BIKE,
    CAR,
    TRUCK,
    BUS
};

string vehicleTypeToStr(vehicleType type) {
    switch (type) {
        case vehicleType::BIKE: return "BIKE";
        case vehicleType::CAR: return "CAR";
        case vehicleType::TRUCK: return "TRUCK";
        case vehicleType::BUS: return "BUS";
        default: return "UNKNOWN";
    }
}

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

    string getLicenceNumber()
    {
        return this->licenceNumber;
    }

    string getColor() { return color; }

    void printDetails() {
        cout<<" --Vehicle Details-- "<<endl;
        cout<<"licenceNumber : "<<licenceNumber<<endl;
        cout<<"color : "<<color<<endl;
        
        switch (type)
        {
        case vehicleType::BIKE:
            cout<<"type : BIKE"<<endl;
            break;
        case vehicleType::BUS:
            cout<<"type : BUS"<<endl;
            break;
        case vehicleType::TRUCK:
            cout<<"type : TRUCK"<<endl;
            break;
        case vehicleType::CAR:
            cout<<"type : CAR"<<endl;
            break;

        }
        cout<<endl;
    }
};