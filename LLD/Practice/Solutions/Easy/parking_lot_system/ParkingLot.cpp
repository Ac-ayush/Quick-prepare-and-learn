#include <bits/stdc++.h>
#include "ParkingSpot.cpp"
#include "Vehicle.cpp"
using namespace std;

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
    Vehicle* vehicle = spot->removeFromSpot();

    if (vehicle) {
      occupiedSpotsdata.erase(it);
      availableSpots++;
    }

    return vehicle;
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