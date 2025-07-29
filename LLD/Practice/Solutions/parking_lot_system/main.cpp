#include <bits/stdc++.h> 
#include "ParkingLot.cpp"
using namespace std;



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