# Adapter Pattern

---

## 🔹 What is the Adapter Pattern?

The Adapter Pattern is a structural design pattern that allows incompatible interfaces to work together.

👉 It acts like a bridge (translator) between two different systems or classes.

---

## 🔹 Why do we need it?

Sometimes you want to use a class with an existing interface but its methods don’t match what your code expects.

Instead of modifying the original class (which may not be possible), you wrap it with an adapter.

---

## 🔹 Real-world Analogy

Imagine your laptop charger:

- Your laptop accepts only a USB-C port.
- The wall socket is 3-pin.
- You use an adapter that converts the 3-pin plug into USB-C.

The charger didn’t change, the laptop didn’t change → but the adapter allows them to connect.

---

## 🔹 Problem Statement

Suppose you have a system that works with a new payment gateway interface, but you must also support an old payment system.

The old payment system has a different method name.

Instead of rewriting everything, you use an Adapter to make it compatible.

---

## 🔹 Structure

- **Target (Expected Interface)** → defines what the client expects.
- **Adaptee (Existing Incompatible Class)** → has a different interface.
- **Adapter (Translator)** → wraps the adaptee and makes it compatible with the target.

---

## 🔹 Example in C++ (Payment System)

```cpp
// Target interface (what client expects)
class PaymentProcessor {
  processPayment(amount) {
    throw new Error("processPayment() must be implemented");
  }
}

// Adaptee (existing old system with different interface)
class OldPaymentSystem {
  makePayment(money) {
    console.log(`Payment of $${money} made using OLD system.`);
  }
}

// Adapter (wraps OldPaymentSystem to match new interface)
class PaymentAdapter extends PaymentProcessor {
  constructor(oldSystem) {
    super();
    this.oldSystem = oldSystem;
  }

  processPayment(amount) {
    // translate call
    this.oldSystem.makePayment(amount);
  }
}

// ---- Client Code ----
const oldSystem = new OldPaymentSystem();
const processor = new PaymentAdapter(oldSystem);

// Client uses the new interface, but internally old system is used
processor.processPayment(100);

```

**🔹 Output**
```
Payment of $100 made using OLD system.
```

---

## 🔑 When to Use

✅ When you have an existing class but its interface doesn’t match what the client expects.

✅ When you want to reuse legacy code in a new system.

✅ When working with third-party libraries.

---

## 🔑 When to Avoid

❌ When you can simply modify the original class/interface (adapter adds unnecessary complexity).

❌ When there are too many adapters (system gets hard to maintain).

---

## ⚡ One-liner

The Adapter Pattern lets classes with incompatible interfaces work together by wrapping one class with an adapter that provides the expected interface.

