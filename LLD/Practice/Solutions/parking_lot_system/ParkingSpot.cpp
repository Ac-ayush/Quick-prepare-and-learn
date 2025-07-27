#include "Vehicle.cpp"

enum class SpotSize
{
    COMPACT,
    REGULAR,
    LARGE
};

class ParkingSpot
{
    int spotNumber;
    SpotSize sizeType;
    bool isAvailable;
    Vehicle *vehicle;

public:
    ParkingSpot(int spotNumber, SpotSize sizeType)
    {
        this->spotNumber = spotNumber;
        this->sizeType = sizeType;
        this->isAvailable = true;
    }

    int getNumber() { return spotNumber; }

    bool checkIsAvailable() { return isAvailable; }

    Vehicle *getVehicleDetails()
    {
        if (!this->isAvailable)
        {
            return nullptr;
        }

        return vehicle;
    }

    bool canFitVehicle(Vehicle *vehicle)
    {
        if (!vehicle)
            return false;

        switch (vehicle->getVehicleType())
        {
        case vehicleType::BIKE:
            return true; // can park anywhere

        case vehicleType::CAR:
            return sizeType != SpotSize::COMPACT;

        case vehicleType::BUS:
        case vehicleType::TRUCK:
            return sizeType == SpotSize::LARGE;

        default:
            return false;
        }
        return false;
    }

    //park here
    bool parkVehicle(Vehicle* vehicle){
        if(!isAvailable || !canFitVehicle(vehicle))return false;

        this->vehicle = vehicle;
        isAvailable = false;
    }

    //remove from spot
    Vehicle* removeFromSpot(){
        if(!vehicle)return nullptr;

        auto vehicleToremoved = getVehicleDetails();

        vehicle = nullptr;
        isAvailable = true;

        return vehicleToremoved;
    }


    void printDetails(){
        cout<<" --ParkingSpot Details-- "<<endl;
        cout<<"Spot number: "<<spotNumber<<endl;
        cout<<"Availability: " <<(isAvailable ? "Available" : "Occupied")<<endl;

        if(!vehicle){
            cout<<" Vehicle : No vehicle parked"<<endl;
        }
        else{
            vehicle->printDetails();
        }
    }
};