# Designing a Parking Lot System

## Requirements
1. The parking lot should have multiple levels, each level with a certain number of parking spots.
2. The parking lot should support different types of vehicles, such as cars, motorcycles, and trucks.
3. Each parking spot should be able to accommodate a specific type of vehicle.
4. The system should assign a parking spot to a vehicle upon entry and release it when the vehicle exits.
5. The system should track the availability of parking spots and provide real-time information to customers.
6. The system should handle multiple entry and exit points and support concurrent access.

## Design

### Classes
1. Vehicle & Enums 
    - type : Bike, Car, Bus, Truck
    - number
    - license
    - sizeType (Enums) : Compact, Medium, Large
2. Parking Spot 
    - sizeType (Compact, Medium, Large)
    - isAvailable
3. Parking Lot 
    - totalSpots
    - avaialbleSpots
    - vehicleList : that are present in this lot/floor
4. Parking Lot Manager
    - total parking lots 
    - list of parking lots