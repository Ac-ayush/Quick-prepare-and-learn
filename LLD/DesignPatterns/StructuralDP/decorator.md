# 🔹 1. What is the Decorator Pattern?

**Decorator** is a structural design pattern that lets you attach new behaviors to objects by placing these objects inside special wrapper objects that contain the behaviors.

👉 Instead of subclassing (which creates many classes), you “wrap” objects with decorators.

---

# 🔹 2. Why do we need it? (Problem)

- If you want to add features to a class (e.g., Coffee → add sugar, milk, cream).  
- If you use inheritance, you end up with class explosion:  
  `SimpleCoffee`, `CoffeeWithMilk`, `CoffeeWithSugar`, `CoffeeWithMilkAndSugar`, etc.  
- Hard to maintain, not flexible, violates **Open-Closed Principle (OCP)**.  

✅ **Solution** → Use **Decorator**: wrap the object and add behavior dynamically.

---

# 🔹 3. Real-world Analogy

Think of a **coffee shop ☕**:
- You order a simple coffee.  
- You can add milk, sugar, or cream.  
- Instead of creating a new subclass for every combination, you just **wrap** the coffee object with decorators.  

---

# 🔹 4. Structure (UML Idea)

```scss
Component (interface)
    ↑
ConcreteComponent (base object)
    ↑
Decorator (abstract wrapper, has a Component reference)
    ↑
ConcreteDecorators (add features)
```


---

# 🔹 5. Example Idea (Coffee System)

- **Component** → Coffee interface  
- **ConcreteComponent** → SimpleCoffee  
- **Decorator (abstract)** → CoffeeDecorator  
- **ConcreteDecorators** → MilkDecorator, SugarDecorator  

<details>
<summary>▶️ Click to see Code</summary>

```cpp
#include <iostream>
#include <memory>
using namespace std;

// ---- Component ----
class Coffee {
public:
    virtual string getDescription() = 0;
    virtual double getCost() = 0;
    virtual ~Coffee() {}
};

// ---- Concrete Component ----
class SimpleCoffee : public Coffee {
public:
    string getDescription() override { return "Simple Coffee"; }
    double getCost() override { return 50.0; }
};

// ---- Decorator (abstract wrapper) ----
class CoffeeDecorator : public Coffee {
protected:
    unique_ptr<Coffee> coffee;
public:
    CoffeeDecorator(unique_ptr<Coffee> c) : coffee(move(c)) {}
};

// ---- Concrete Decorators ----
class MilkDecorator : public CoffeeDecorator {
public:
    MilkDecorator(unique_ptr<Coffee> c) : CoffeeDecorator(move(c)) {}
    string getDescription() override { return coffee->getDescription() + ", Milk"; }
    double getCost() override { return coffee->getCost() + 10.0; }
};

class SugarDecorator : public CoffeeDecorator {
public:
    SugarDecorator(unique_ptr<Coffee> c) : CoffeeDecorator(move(c)) {}
    string getDescription() override { return coffee->getDescription() + ", Sugar"; }
    double getCost() override { return coffee->getCost() + 5.0; }
};
```
</details>
---

# 🔹 6. Client Usage

- Start with a **Simple Coffee**.  
- Wrap it with **MilkDecorator**.  
- Wrap it further with **SugarDecorator**.  
- Each wrapper adds cost & description dynamically.  
```cpp
int main() {
    unique_ptr<Coffee> myCoffee = make_unique<SimpleCoffee>();
    cout << myCoffee->getDescription() << " = Rs." << myCoffee->getCost() << endl;

    myCoffee = make_unique<MilkDecorator>(move(myCoffee));   // add milk
    cout << myCoffee->getDescription() << " = Rs." << myCoffee->getCost() << endl;

    myCoffee = make_unique<SugarDecorator>(move(myCoffee));  // add sugar
    cout << myCoffee->getDescription() << " = Rs." << myCoffee->getCost() << endl;

    return 0;
}
```

---

## 🔹Sample Output
```cpp
Simple Coffee = Rs.50
Simple Coffee, Milk = Rs.60
Simple Coffee, Milk, Sugar = Rs.65
```


---

# 7. 🔹 Steps to Implement a Decorator

---

## ✅ Step 1: Define the Component Interface
- This is the base interface that both the **main object** and **decorators** will implement.  
- Example: `Coffee` interface with methods like `getDescription()` and `getCost()`.
<details>
<summary>▶️ Click to see Code</summary>

```cpp
class Coffee {
public:
    virtual string getDescription() = 0;
    virtual double getCost() = 0;
    virtual ~Coffee() {}
};
```
</details>
---

## ✅ Step 2: Create a Concrete Component (Base Object)
- This is the **class we want to decorate** (add features to).  
- Example: `SimpleCoffee` returns `"Simple Coffee"` and base cost.
<details>
<summary>▶️ Click to see Code</summary>

```cpp
class SimpleCoffee : public Coffee {
public:
    string getDescription() override { return "Simple Coffee"; }
    double getCost() override { return 50.0; }
};

```

</details>
---

## ✅ Step 3: Create an Abstract Decorator
- The **decorator wraps** the base component and **forwards calls** to it.  
- Holds a reference to a `Coffee` object.  
- Example: `CoffeeDecorator` class.
<details>
<summary>▶️ Click to see Code</summary>

```cpp
class CoffeeDecorator : public Coffee {
protected:
    unique_ptr<Coffee> coffee;  // wrapped object
public:
    CoffeeDecorator(unique_ptr<Coffee> c) : coffee(move(c)) {}
};

```
</details>
---

## ✅ Step 4: Create Concrete Decorators (Features)
- Each decorator **adds its own behavior** on top of the wrapped object.  
- Example:  
  - `MilkDecorator` → adds milk description & cost.  
  - `SugarDecorator` → adds sugar description & cost.  
<details>
<summary>▶️ Click to see Code</summary>

```cpp
class MilkDecorator : public CoffeeDecorator {
public:
    MilkDecorator(unique_ptr<Coffee> c) : CoffeeDecorator(move(c)) {}
    string getDescription() override { return coffee->getDescription() + ", Milk"; }
    double getCost() override { return coffee->getCost() + 10.0; }
};

class SugarDecorator : public CoffeeDecorator {
public:
    SugarDecorator(unique_ptr<Coffee> c) : CoffeeDecorator(move(c)) {}
    string getDescription() override { return coffee->getDescription() + ", Sugar"; }
    double getCost() override { return coffee->getCost() + 5.0; }
};
```
</details>
---

## ✅ Step 5: Client Chooses Decorations at Runtime
- Start with a **Simple Coffee**.  
- Wrap it with **MilkDecorator** (adds milk).  
- Wrap again with **SugarDecorator** (adds sugar).  
- Each wrapper **adds cost & description dynamically**.  
<details>
<summary>▶️ Click to see Code</summary>

```cpp
int main() {
    unique_ptr<Coffee> myCoffee = make_unique<SimpleCoffee>();
    cout << myCoffee->getDescription() << " = Rs." << myCoffee->getCost() << endl;

    myCoffee = make_unique<MilkDecorator>(move(myCoffee));   // add milk
    cout << myCoffee->getDescription() << " = Rs." << myCoffee->getCost() << endl;

    myCoffee = make_unique<SugarDecorator>(move(myCoffee));  // add sugar
    cout << myCoffee->getDescription() << " = Rs." << myCoffee->getCost() << endl;

    return 0;
}
```
</details>
---

## 🔹 Recap (Steps in Short)
1. **Component Interface** → defines contract (`getDescription`, `getCost`).  
2. **Concrete Component** → base object (`SimpleCoffee`).  
3. **Abstract Decorator** → wraps component, forwards calls.  
4. **Concrete Decorators** → add features (`Milk`, `Sugar`).  
5. **Client** → dynamically wraps base object with decorators.  


# 🔹 8. When to Use vs Avoid

✅ **Use when**:  
- You want to add behavior dynamically.  
- You want to avoid subclass explosion.  
- You want to follow **Open-Closed Principle** (extend without modifying).  

❌ **Avoid when**:  
- Too many nested decorators → debugging becomes hard.  
- If features can be handled with simple inheritance or parameters.  

---

# 🔹 9. One-liner Definition

**Decorator Pattern** = Wraps an object to add new functionality dynamically without altering its structure.  

