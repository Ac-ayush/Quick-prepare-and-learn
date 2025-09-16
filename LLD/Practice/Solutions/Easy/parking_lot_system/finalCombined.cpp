
/*
* This is final combined file 
* You will find all the code here including all classes and main funciton.
*/

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
        if (this->isAvailable)
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
        return true;
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

class ParkingLot {
  vector<ParkingSpot*> spots;
  unordered_map<string, ParkingSpot*> occupiedSpotsdata;  // licence -> spot
  int capacity;
  int availableSpots;

 public:
  ParkingLot(int compactCount, int regularCount, int largeCount) {
    this->capacity = compactCount + regularCount + largeCount;
    this->availableSpots = capacity;

    int index = 0;
    for (int i = 0; i < compactCount; i++) {
        spots.push_back(new ParkingSpot(index++, SpotSize::COMPACT));
    }
    for (int i = 0; i < regularCount; i++) {
        spots.push_back(new ParkingSpot(index++, SpotSize::REGULAR));
    }
    for (int i = 0; i < largeCount; i++) {
        spots.push_back(new ParkingSpot(index++, SpotSize::LARGE));
    }
  }

  int getcapacity() { return capacity; }

  int getAvailableSpots() { return availableSpots; }

  ParkingSpot* findAvailableSpot(Vehicle* vehicle) {
    for (auto& spot : spots) {
      if (spot->checkIsAvailable() && spot->canFitVehicle(vehicle)) {
        return spot;
      }
    }
    return nullptr;
  }

  bool parkVehicle(Vehicle* vehicle) {
    if (!vehicle) return false;

    // check if already parked
    if (occupiedSpotsdata.find(vehicle->getLicenceNumber()) !=
        occupiedSpotsdata.end()) {
      return false;
    }

    if (availableSpots < 1) {
      cout << "No spots available" << endl;
      return false;
    }

    // check for avaialble spot
    ParkingSpot* spotToPark = findAvailableSpot(vehicle);

    if (!spotToPark) return false;

    if (spotToPark->parkVehicle(vehicle)) {
      occupiedSpotsdata[vehicle->getLicenceNumber()] = spotToPark;
      availableSpots--;
      return true;
    }
  }

  Vehicle* removeVehicle(string licenceNumber) {
    auto it = occupiedSpotsdata.find(licenceNumber);
    if (it == occupiedSpotsdata.end()) return nullptr;
    

    ParkingSpot* spot = it->second;
    Vehicle* vehicleToremoved = spot->removeFromSpot();

    if (vehicleToremoved) {
      occupiedSpotsdata.erase(it);
      availableSpots++;
    }

    return vehicleToremoved;
  }

  void printDetails() {
    cout << " -- parking lot details-- " << endl;

    cout << " Capacity : " << capacity << endl;
    cout << " Occupied Spots : " << (capacity - availableSpots) << endl;
    cout << " Available Spots Count : " << availableSpots << endl;
  }

  void printOccupancy() {
    cout << " -- parking lot occupancy list details-- " << endl;
    for (auto& spot : spots) {
      spot->printDetails();
    }
  }
};

int main() 
{
    //create parking lot 
    ParkingLot parkinglot(2, 3, 2); // 2 compact, 3 regular, 2 large spots
  
    parkinglot.printDetails();
    
    //create vehicle 
    Vehicle* car1 = new Vehicle("CAR001", vehicleType::CAR, "blue");
    Vehicle* car2 = new Vehicle("CAR002", vehicleType::CAR, "blue");
    Vehicle*  bike1 = new Vehicle("BIKE001", vehicleType::BIKE, "blue");
    Vehicle* truck1 = new Vehicle("TRUCK001", vehicleType::TRUCK, "blue");
    
    //check vehicle details 
    // car1->printDetails();
    
    
    //Lets park vehicle 
    cout<<endl<<"Parking Vehicles...."<<endl;
    if(parkinglot.parkVehicle(car1)){
      cout<<"parked successfully"<<endl;
      car1->printDetails();
    }
    
    if(parkinglot.parkVehicle(bike1)){
      cout<<"parked successfully"<<endl;
      bike1->printDetails();
    }
    
    if(parkinglot.parkVehicle(truck1)){
      cout<<"parked successfully"<<endl;
      truck1->printDetails();
    }
    
    
    //Current status of parking lot
    cout<<endl;
    parkinglot.printDetails();
    // parkinglot.printOccupancy();
    
    std::cout << "\nRemoving vehicle CAR001..." << std::endl;
    Vehicle* removed = parkinglot.removeVehicle("CAR001");
    if (removed) {
        std::cout << "Removed successfully: ";
        removed->printDetails();
        delete removed;
    }
    
    // Try to park another car
    if(parkinglot.parkVehicle(car2)){
      cout<<"parked successfully"<<endl;
      car2->printDetails();
    }
    
    
    // Final status
    std::cout << "\nFinal parking lot status:" << std::endl;
    parkinglot.printDetails();
    parkinglot.printOccupancy();
    
  
    delete car2;
    delete bike1;
    delete truck1;
    
    return 0;
    
}