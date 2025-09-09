# Builder Design Pattern

## 1. What is the Builder Pattern?
The **Builder Pattern** is a *Creational Design Pattern* that lets you construct complex objects step by step.  
👉 Instead of creating an object in one go (constructor with too many parameters), Builder lets you incrementally build it.

---

## 2. Why do we need Builder? (The Problem)
Imagine creating a **House** object like this:

```cpp 
House house(true, true, false, true, false, true);
```

This is ugly 😖 → too many parameters → hard to read & maintain.  

Sometimes we need different variations (House with garden, House without garage, etc.).  

If we use constructors or factories, the code becomes messy.  

✅ Builder solves this by:  
- Constructing an object step by step.  
- Making object creation clear and flexible.  
- Allowing the same construction process to create different representations.  

---

## 3. Real-world Analogy
Think of ordering a **Burger 🍔 at McDonald's**:  

- You don’t get everything at once.  
- The cook adds **bun → patty → cheese → sauces → toppings** step by step.  
- In the end, you get a burger.  

👉 That’s Builder Pattern in action.

---

## 4. Structure (in simple words)
- **Product** → The final object we want to build (House).  
- **Builder (interface)** → Declares building steps (buildWalls, buildRoof, etc.).  
- **Concrete Builder** → Implements steps for specific versions.  
- **Director (optional)** → Controls the building process (decides order of steps).  
- **Client** → Uses builder to get the product.  

---

## 5. Pseudocode (Generic)
```cpp
// Product
class House {
    bool hasGarage, hasGarden, hasSwimmingPool;
}

// Builder
class HouseBuilder {
    setGarage();
    setGarden();
    setSwimmingPool();
    getResult();
}

// Concrete Builder
class LuxuryHouseBuilder : HouseBuilder { ... }
class SimpleHouseBuilder : HouseBuilder { ... }

// Director (optional)
class Engineer {
    constructLuxuryHouse(builder);
    constructSimpleHouse(builder);
}

// Client
builder = new LuxuryHouseBuilder();
engineer.constructLuxuryHouse(builder);
House house = builder.getResult();

```

---

## 6. Example
```cpp
#include <iostream>
#include <string>

// ----- Product -----
class House {
public:
    bool hasGarage = false;
    bool hasGarden = false;
    bool hasSwimmingPool = false;

    void showHouse() {
        std::cout << "House with: "
                  << (hasGarage ? "Garage " : "")
                  << (hasGarden ? "Garden " : "")
                  << (hasSwimmingPool ? "Swimming Pool " : "")
                  << std::endl;
    }
};

// ----- Builder Interface -----
class HouseBuilder {
public:
    virtual void buildGarage() = 0;
    virtual void buildGarden() = 0;
    virtual void buildSwimmingPool() = 0;
    virtual House getResult() = 0;
    virtual ~HouseBuilder() {}
};

// ----- Concrete Builder -----
class SimpleHouseBuilder : public HouseBuilder {
    House house;
public:
    void buildGarage() override { house.hasGarage = true; }
    void buildGarden() override { /* no garden in simple house */ }
    void buildSwimmingPool() override { /* no pool in simple house */ }
    House getResult() override { return house; }
};

class LuxuryHouseBuilder : public HouseBuilder {
    House house;
public:
    void buildGarage() override { house.hasGarage = true; }
    void buildGarden() override { house.hasGarden = true; }
    void buildSwimmingPool() override { house.hasSwimmingPool = true; }
    House getResult() override { return house; }
};

// ----- Director (optional) -----
class Engineer {
public:
    House constructSimpleHouse(HouseBuilder& builder) {
        builder.buildGarage();
        return builder.getResult();
    }
    House constructLuxuryHouse(HouseBuilder& builder) {
        builder.buildGarage();
        builder.buildGarden();
        builder.buildSwimmingPool();
        return builder.getResult();
    }
};

// ----- Client -----
int main() {
    Engineer engineer;

    SimpleHouseBuilder simpleBuilder;
    LuxuryHouseBuilder luxuryBuilder;

    House simpleHouse = engineer.constructSimpleHouse(simpleBuilder);
    House luxuryHouse = engineer.constructLuxuryHouse(luxuryBuilder);

    simpleHouse.showHouse();   // House with: Garage
    luxuryHouse.showHouse();   // House with: Garage Garden Swimming Pool

    return 0;
}

```

---

## 7. Output
```js
- House with: Garage  
- House with: Garage Garden Swimming Pool  
```
---

## 8. When to Use Builder
✅ **Use when**:  
- You need to build complex objects step by step.  
- You want different variations of the same object.  
- Constructors have too many parameters (telescoping constructor problem).  

❌ **Avoid when**:  
- Object creation is simple (a factory is enough).  
- You don’t need step-by-step construction.  

---

## 9. One-liner Definition
**Builder Pattern = Construct complex objects step by step, allowing different representations using the same construction process.**



---
---

## Example 2


### 🔹 Step 1: Imagine this problem

You want to make a **Pizza 🍕** object in C++. A pizza can have:

* cheese (yes/no)
* pepperoni (yes/no)
* mushrooms (yes/no)
* olives (yes/no)

**Without Builder:**
You might try a constructor with many booleans.
```cpp
class Pizza {
public:
    Pizza(bool cheese, bool pepperoni, bool mushrooms, bool olives) {
        // set ingredients
    }
};
```

Now you creates a Pizza

```cpp
Pizza p1(true, false, true, false); 
```

**❌ Problems:**

* Hard to read: what does `true, false, true, false` mean?
* Error-prone: easy to swap the order by mistake.
* Not scalable: adding more toppings makes the constructor messy.

---

### 🔹 Step 2: With Builder

Instead of passing everything at once, you **build the pizza step by step** using a `PizzaBuilder` that has methods like:

```cpp
class Pizza {
public:
    bool cheese, pepperoni, mushrooms, olives;

    void showPizza() {
        std::cout << "Pizza with: "
                  << (cheese ? "Cheese " : "")
                  << (pepperoni ? "Pepperoni " : "")
                  << (mushrooms ? "Mushrooms " : "")
                  << (olives ? "Olives " : "")
                  << std::endl;
    }
};

// ---- Builder ----
class PizzaBuilder {
    Pizza pizza;
public:
    PizzaBuilder& addCheese() { pizza.cheese = true; return *this; }
    PizzaBuilder& addPepperoni() { pizza.pepperoni = true; return *this; }
    PizzaBuilder& addMushrooms() { pizza.mushrooms = true; return *this; }
    PizzaBuilder& addOlives() { pizza.olives = true; return *this; }
    Pizza build() { return pizza; }
};

// ---- Client ----
int main() {
    Pizza p1 = PizzaBuilder().addCheese().addOlives().build();
    Pizza p2 = PizzaBuilder().addCheese().addPepperoni().addMushrooms().build();

    p1.showPizza();  // Pizza with: Cheese Olives 
    p2.showPizza();  // Pizza with: Cheese Pepperoni Mushrooms 
}

```

### 🔹 Step 3: The Use Case becomes clear

**✅ With Builder:**
```cpp
PizzaBuilder().addCheese().addOlives().build();
```
→ Easy to read & understand.

**❌ Without Builder:**
```cpp
Pizza(true, false, false, true);
```
→ Confusing & error-prone.

---

### 🔹 So the Use Case is

Use the **Builder Pattern** when:

* You need to create an object with many **optional configurations**.
* **Constructors/factories** become too messy.
* You want to **build step by step** with clear, readable intent.
