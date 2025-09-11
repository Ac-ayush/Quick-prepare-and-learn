# 🔹 What is a Design Pattern?

A **design pattern** is a proven reusable solution to a common software problem.

👉 Think of it like a **blueprint or a recipe**.  
It’s not full code, but a structured way to solve problems in coding.

**Example:**  
If you want to build a house, you can use an architectural pattern like *"open kitchen design"* or *"2BHK plan"*.  
Similarly, in software, design patterns help you solve recurring coding problems in a clean, scalable, and maintainable way.

---

# 🔹 Why do we need Design Patterns?

- Avoid reinventing the wheel 🛞  
- Make code more readable & maintainable  
- Improve scalability & reusability  
- Provide standard solutions that many developers already understand  

---

# 🔹 Types of Design Patterns

Broadly classified into three categories:

## 1. Creational Patterns → *object creation made simple*
👉 How to create objects without exposing the creation logic.

**Examples:**
- **Singleton** → only one instance (like a single DB connection in app).  
- **Factory Method** → create objects without specifying exact class.  
- **Builder** → step-by-step construction (like making a burger 🍔 – bun → patty → cheese).  

---

## 2. Structural Patterns → *object relationships*
👉 How to combine objects to form flexible, large structures.

**Examples:**
- **Adapter** → convert one interface to another (like a charger adapter).  
- **Decorator** → add new features to an object without changing it (like adding cheese on pizza 🍕).  
- **Facade** → simplified interface for complex system (like TV remote for many internal operations).  

---

## 3. Behavioral Patterns → *object communication*
👉 How objects interact and communicate.

**Examples:**
- **Observer** → one-to-many dependency (like YouTube subscribe → notify all when new video comes).  
- **Strategy** → choose an algorithm at runtime (like choosing payment method: UPI, card, wallet).  
- **Command** → encapsulate actions (like undo/redo system).  

---

# ✅ In short:
**Design Patterns = Best practices to solve common coding problems.**  
They’re like **lego blocks 🧩 – reusable and easy to combine.**


## Learns priority wise
- Singleton (DB, config)
- Factory / Abstract Factory (object creation)
- Builder (complex object creation)
- Observer / Pub-Sub (events, state management)
- Strategy (switchable algorithms)
- Command (API calls, undo/redo, event handling
- Decorator (middleware, HOCs in React)
- Proxy (caching, lazy loading, security)
- Composite (UI trees, DOM, React components)
- State (FSM, React hooks/components)
- Chain of Responsibility