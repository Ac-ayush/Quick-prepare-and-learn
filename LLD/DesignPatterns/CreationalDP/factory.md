# 🔹 Factory Method Design Pattern
- Factory Method is a creational design pattern that provides an interface for creating objects in a superclass, but allows subclasses to alter the type of objects that will be created.

## 1. Problem Statement
You want to create different types of objects (**Car, Bike, Truck, etc.**).

- If you use `new Car()` or `new Bike()` everywhere in your code, it becomes:
  - ❌ Hard to maintain (change in one class requires changes everywhere).  
  - ❌ Tightly coupled (client code directly depends on concrete classes).  

👉 You want a **centralized way** to decide which object to create.

---

## 2. Solution (Factory Method)

- Define a **common interface (abstract class)** for all products.  
- Let a **Factory Method** decide which object to create, based on input.  
- Client only calls the factory and works with the interface → no need to know about the exact class.  

---

## ✅ When to Use
- You don’t know which class object you’ll need until runtime.  
- You want to avoid repeating `new ClassName()` in many places.  

---

## 🎯 Advantages
- Loose coupling.  
- Centralized object creation.  
- Easy to extend.  

---

## 3. Example in Simple C++

```cpp
#include <iostream>
#include <memory>
using namespace std;

// Step 1: Product Interface
class Vehicle {
public:
    virtual void drive() = 0; // pure virtual function
    virtual ~Vehicle() {}
};

// Step 2: Concrete Products
class Car : public Vehicle {
public:
    void drive() override {
        cout << "Driving a Car 🚗" << endl;
    }
};

class Bike : public Vehicle {
public:
    void drive() override {
        cout << "Riding a Bike 🏍️" << endl;
    }
};

// Step 3: Factory
class VehicleFactory {
public:
    static unique_ptr<Vehicle> createVehicle(const string& type) {
        if (type == "car") return make_unique<Car>();
        if (type == "bike") return make_unique<Bike>();
        return nullptr;
    }
};

// Step 4: Client
int main() {
    auto v1 = VehicleFactory::createVehicle("car");
    auto v2 = VehicleFactory::createVehicle("bike");

    if (v1) v1->drive();
    if (v2) v2->drive();

    return 0;
}
````

---

## 4. Output

```
Driving a Car 🚗
Riding a Bike 🏍️
```

---

## ✅ In short:

**Factory Method = Define an interface for object creation, but let the factory decide which object to instantiate.**

```

Do you want me to also prepare a **diagram (UML-style) in markdown** to visually explain how the Factory Method works?
```
