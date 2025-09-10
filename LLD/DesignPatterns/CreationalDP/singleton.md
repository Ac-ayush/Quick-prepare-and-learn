# 🔹 Singleton Design Pattern

---

## 1. What is Singleton?

The **Singleton Pattern** is a **Creational Design Pattern** that ensures:

- Only **one instance** of a class exists throughout the program.  
- Provides a **global access point** to that instance.  

👉 **Analogy:** Think of it as a **government** — there should be only one government in a country, but everyone should be able to access it.  

---

## 2. Why Singleton? (The Problem it Solves)

- Some objects should exist **only once** (e.g., Logger, Configuration Manager, Database Connection, Cache).  
- If multiple copies exist, it causes **conflicts** (e.g., multiple DB connections, inconsistent configuration).  
- We want to **control object creation** and guarantee a single instance.  

✅ Singleton solves this by:  
- Hiding the **constructor**.  
- Providing a **static method** to get the instance.  

---

## 3. Real-world Analogy

- **OS Kernel** → only one kernel runs at a time.  
- **Print Spooler** → only one manages all printers.  
- **Database Connection Manager** → only one DB connection shared across modules.  

---

## 4. Structure (UML Style)

```scss
┌────────────────────┐
│     Singleton      │
│────────────────────│
│ - static instance  │
│ - private ctor()   │
│ + getInstance()    │
└────────────────────┘
```
- **Private constructor** → prevents direct creation with `new`.  
- **Static method** → provides access to the single instance. 

## 5. Example in C++ (Database Singleton)

```cpp
#include <iostream>
#include <string>
using namespace std;

class Database {
private:
    static Database* instance;
    string connectionString;

    // Private constructor
    Database() {
        connectionString = "Server=127.0.0.1;DB=AppDB;";
        cout << "Database Connection Created: " << connectionString << endl;
    }

public:
    // Delete copy constructor and assignment
    Database(const Database&) = delete;
    void operator=(const Database&) = delete;

    // Static method to get the single instance
    static Database* getInstance() {
        if (instance == nullptr) {
            instance = new Database(); // create only once
        }
        return instance;
    }

    void query(const string& sql) {
        cout << "Executing SQL: " << sql << endl;
    }
};

// Initialize static instance
Database* Database::instance = nullptr;

// ---- Client Code ----
int main() {
    // Module 1 uses DB
    Database* db1 = Database::getInstance();
    db1->query("SELECT * FROM users");

    // Module 2 uses DB (same instance!)
    Database* db2 = Database::getInstance();
    db2->query("INSERT INTO users VALUES (1, 'Ayush')");

    // Check if both are same instance
    cout << "Are db1 and db2 same? " << (db1 == db2) << endl;

    return 0;
}
```

---

## 🔹 Output
```cpp
Database Connection Created: Server=127.0.0.1;DB=AppDB;
Executing SQL: SELECT * FROM users
Executing SQL: INSERT INTO users VALUES (1, 'Ayush')
Are db1 and db2 same? 1

```


---

## 6. When to Use Singleton

✅ **Use when:**  
- You need **one global object** (e.g., Logger, Config, DB connection).  
- You want **controlled access** to shared resources.  

❌ **Avoid when:**  
- You need **multiple instances for scaling**.  
- It introduces **global state → harder to test & maintain**.  

---

## 7. One-liner Definition

**Singleton Pattern = Ensures only one instance of a class exists and provides a global point of access to it.**

## 8.  Steps to Implement a Singleton

---

### ✅ Step 1: Make the constructor private
- This prevents creating new objects using `new`. 
```cpp
class Singleton {
private:
    Singleton() {}  // private constructor
};
```

---

### ✅ Step 2: Delete copy constructor & assignment operator
- This prevents making a copy of the Singleton (important in C++).
```cpp
Singleton(const Singleton&) = delete;
void operator=(const Singleton&) = delete;
```  

---

### ✅ Step 3: Add a static pointer to instance
- This holds the **one and only instance** of the class.  
```cpp
static Singleton* instance;
```
---

### ✅ Step 4: Provide a static method (`getInstance`)
- This returns the same instance every time.  
- Create the instance only when first requested (**Lazy initialization**).
```cpp
static Singleton* getInstance() {
    if (instance == nullptr) {
        instance = new Singleton();
    }
    return instance;
}
```  

---

### ✅ Step 5: Use the Singleton in your program
- Instead of `new Singleton()`, always call `Singleton::getInstance()`.  

---

### 🔹 Complete Example
```cpp
#include <iostream>
using namespace std;

class Singleton {
private:
    static Singleton* instance;

    // Private constructor
    Singleton() {
        cout << "Singleton Instance Created" << endl;
    }

public:
    // Delete copy constructor & assignment
    Singleton(const Singleton&) = delete;
    void operator=(const Singleton&) = delete;

    // Static method to access single instance
    static Singleton* getInstance() {
        if (instance == nullptr) {
            instance = new Singleton();  // create only once
        }
        return instance;
    }

    void showMessage() {
        cout << "Hello from Singleton!" << endl;
    }
};

// Initialize static member
Singleton* Singleton::instance = nullptr;

// ---- Client Code ----
int main() {
    Singleton* s1 = Singleton::getInstance();
    s1->showMessage();

    Singleton* s2 = Singleton::getInstance();
    s2->showMessage();

    cout << "Are s1 and s2 same instance? " << (s1 == s2) << endl;
    return 0;
}
```

---

### 🔹 Output
```cpp
Singleton Instance Created
Hello from Singleton!
Hello from Singleton!
Are s1 and s2 same instance? 1
```
