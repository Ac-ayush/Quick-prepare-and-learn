# 🔹 Strategy Design Pattern

## 1. What is Strategy Pattern?

The Strategy Pattern is a **behavioral design pattern** that lets you define a family of algorithms, put each into a separate class, and make them interchangeable at runtime.

👉 Instead of hardcoding an algorithm, you choose the algorithm dynamically.

---

## 2. Why Strategy? (The Problem it Solves)

- Sometimes you need different ways of doing the same thing.  
- If you put all algorithms inside one big **if-else block** → code becomes messy and hard to maintain.  
- Changing behavior at runtime becomes impossible without rewriting logic.  

✅ **Solution** → Put each algorithm in its own class (a strategy), and the main class uses a strategy dynamically.

---

## 3. Real-world Analogy

Imagine a **payment system** in an e-commerce app:

- You can pay with **Credit Card, UPI, or PayPal**.  
- The Checkout system doesn’t care which payment you use — it just uses the chosen strategy.  

So:

- **PaymentStrategy** = interface  
- **CreditCardPayment, UpiPayment, PayPalPayment** = concrete strategies  
- **Checkout** = context that uses the chosen strategy  

---

## 4. Structure (UML Style)

```scss
┌───────────────────────────────┐
│      Strategy (interface).    │
│ + execute()                   │
└───────────────────────────────┘
         ▲       ▲           ▲
         │       │           │
┌────────┴─┐ ┌───┴─────┐ ┌───┴──────┐
│StrategyA │ │StrategyB│ │StrategyC │
└──────────┘ └─────────┘ └──────────┘

┌─────────────────────────┐
│       Context           │
│ - strategy: Strategy    │
│ + setStrategy(s)        │
│ + doSomething()         │
└─────────────────────────┘

```

---

## 5. Example in Simple C++ (Payment System)

<details>
<summary>▶️ Click to view C++ Example</summary>

```cpp
#include <iostream>
#include <memory>
using namespace std;

// ---- Strategy Interface ----
class PaymentStrategy {
public:
    virtual void pay(int amount) = 0;
    virtual ~PaymentStrategy() {}
};

// ---- Concrete Strategies ----
class CreditCardPayment : public PaymentStrategy {
public:
    void pay(int amount) override {
        cout << "Paid " << amount << " using Credit Card 💳" << endl;
    }
};

class UpiPayment : public PaymentStrategy {
public:
    void pay(int amount) override {
        cout << "Paid " << amount << " using UPI 📱" << endl;
    }
};

class PayPalPayment : public PaymentStrategy {
public:
    void pay(int amount) override {
        cout << "Paid " << amount << " using PayPal 🌍" << endl;
    }
};

// ---- Context (Checkout System) ----
class Checkout {
private:
    unique_ptr<PaymentStrategy> strategy;
public:
    void setStrategy(unique_ptr<PaymentStrategy> s) {
        strategy = move(s);
    }
    void processOrder(int amount) {
        if (strategy)
            strategy->pay(amount);
        else
            cout << "No payment method selected!" << endl;
    }
};

// ---- Client ----
int main() {
    Checkout checkout;

    checkout.setStrategy(make_unique<CreditCardPayment>());
    checkout.processOrder(500);

    checkout.setStrategy(make_unique<UpiPayment>());
    checkout.processOrder(300);

    checkout.setStrategy(make_unique<PayPalPayment>());
    checkout.processOrder(1000);

    return 0;
}
```
</details>

### Output?
<details> 
<summary>▶️ Click to view Output</summary>

```cpp
Paid 500 using Credit Card 💳
Paid 300 using UPI 📱
Paid 1000 using PayPal 🌍
```
</details>
---

## 6. When to Use Strategy
### ✅ Use when:
- You need different algorithms for the same task.
- You want to switch algorithms at runtime.
- You want to avoid long if-else or switch statements.

### ❌ Avoid when:
- You don’t have multiple behaviors — simple code is enough.
- Too many strategies → might add complexity.

## 7. One-liner Definition
- Strategy Pattern = Encapsulates different algorithms inside separate classes, allowing you to switch them at runtime without changing the context.

---

## 8. 🔹 Steps to Implement Strategy Pattern

### 1. Define the Strategy Interface
- Create a common interface that all algorithms must implement.  
- Example: `PaymentStrategy` with a `pay()` method.
```cpp
class PaymentStrategy {
public:
    virtual void pay(int amount) = 0;
    virtual ~PaymentStrategy() {}
};
```
---

### 2. Create Concrete Strategies
- Each strategy implements the interface in its own way.  
- Example strategies:  
  - **CreditCardPayment** → pays using Credit Card 💳  
  - **UpiPayment** → pays using UPI 📱  
```cpp
class CreditCardPayment : public PaymentStrategy {
public:
    void pay(int amount) override {
        cout << "Paid " << amount << " using Credit Card 💳" << endl;
    }
};

class UpiPayment : public PaymentStrategy {
public:
    void pay(int amount) override {
        cout << "Paid " << amount << " using UPI 📱" << endl;
    }
};
```
---

### 3. Create the Context Class
- The **context** holds a reference to a strategy object.  
- It delegates the work to the chosen strategy.  
- Example: `Checkout` class that uses a `PaymentStrategy`.  
```cpp
class Checkout {
private:
    unique_ptr<PaymentStrategy> strategy;
public:
    void setStrategy(unique_ptr<PaymentStrategy> s) {
        strategy = move(s);
    }
    void processOrder(int amount) {
        if (strategy)
            strategy->pay(amount);
        else
            cout << "No payment method selected!" << endl;
    }
};
```
---

### 4. Use It in Client Code
- The **client** decides which strategy to use at runtime.  
- Example:  
  - Use `CreditCardPayment` for one order.  
  - Switch to `UpiPayment` for another order.  
```cpp
int main() {
    Checkout checkout;

    checkout.setStrategy(make_unique<CreditCardPayment>());
    checkout.processOrder(500);

    checkout.setStrategy(make_unique<UpiPayment>());
    checkout.processOrder(300);

    return 0;
}
```
---

## 9. Summary 
⚡ Strategy Design Pattern Summary
### 🔹 Problem
- You have multiple ways (algorithms) to do the same task.
- Without Strategy → you write big if-else/switch blocks → code becomes messy, hard to maintain, and cannot easily change behavior at runtime.

### 🔹 Solution
- Define a common interface (Strategy).
- Put each algorithm in its own class (Concrete Strategies).
- Let the Context (main class) use any strategy dynamically.
- Now you can switch behavior at runtime without touching existing code.

