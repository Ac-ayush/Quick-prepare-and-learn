## 🧠 Why we need design principles?

- Design principles that make software
  - Easy to understand
  - Easy to maintain
  - Easy to extend
  - Easy to test
  - Easy to scale
  - Easy to optimize

## SOLID Principles

- Single Responsibility Principle (SRP)
- Open/Closed Principle (OCP)
- Liskov Substitution Principle (LSP)
- Interface Segregation Principle (ISP)
- Dependency Inversion Principle (DIP)

### 📌 Single Responsibility Principle

- A class should have a single responsibility.
- A class should have only one reason to change.
- It should do only one thing.

##### ❌ Bad Example

```c++
class User {
    public:
        void saveToDB(string email, string password) {
            // code logic
        }
        void sendEmail(string email, string message) {
            // code logic
        }
};
```

##### ✅ Good Example

```c++
class User {
    //user data
};

class EmailService {
   public:
        void sendEmail(User user, string message) {
            // code logic
        }
};

class UserRepository {
    public:
        void saveToDB(User user) {
            // code logic
        }
};
```

#### What it solves?

- makes code more maintainable
- reduce side effects when making changes

### 📌 Open/Closed Principle

- Software entities (classes, modules, functions, etc.) should be open for extension, but closed for modification.
- We should be able to extend the behavior of a class without modifying it.

##### ❌ Bad Example

```c++
class PaymentProcessor {
    public:
        void pay(string type) {
            if(type == "credit") {
                // code logic
            } else if(type == "debit") {
                // code logic
            } else if(type == "upi") {
                // code logic
            }
        }
};
```

##### ✅ Good Example

```c++
class Payment {
    public:
        virtual void pay() = 0;

};

class UpiPayment : public Payment {
    public:
        void pay() override {
            // code logic
        }
};

class CreditCardPayment : public Payment {
    public:
        void pay() override {
            // code logic
        }
};
class PaymentProcessor {
    public:
        void processPayment(Payment payment) {
            payment.pay();
        }
};


main() {
    PaymentProcessor paymentProcessor;
    paymentProcessor.processPayment(new UpiPayment());
    paymentProcessor.processPayment(new CreditCardPayment());
}
```

#### What it solves?

- Avoid touching/modifying existing tested code when adding new features.
- Helps to scale the codebase.

### 📌 Liskov Substitution Principle

- Objects of a superclass(parent class) should be replaceable with objects of a subclass(child class) without breaking the code.
- The `child` class should be able to process the same request and deliver the same result as the `parent` class.

##### ❌ Bad Example

```c++
class Bird {
    public:
        virtual void fly() = 0;
};

class Ostrich : public Bird {
    public:
        void fly() override {
            cout << "Ostrich can't fly" << endl;
        }
};
```

##### ✅ Good Example

- split the hierarchy

```c++
class Bird {
    public:
        virtual void eat() = 0;
};

class FlyingBird : public Bird {
    public:
        virtual void fly() = 0;
};

class Ostrich : public Bird {
    public:
        void eat() override {
            // code logic
        }
};

class Sparrow : public FlyingBird {
    public:
        void fly() override {
            // code logic
        }
};
```

#### What it solves?

- Prevent unexpected behavior when using the `inheritance` concept.
- Keeps your object hierarchy logical and safe.
- This principle aims to enforce consistency so that the parent class or its child can be used in the same way without any errors.

### 📌 Interface Segregation Principle

- A client should not be forced to depend on interfaces they do not use.

##### ❌ Bad Example

```c++
class Machine {
    public:
        virtual void print() = 0;
        virtual void scan() = 0;
        virtual void fax() = 0;
};

class Printer : public Machine {
    public:
        void print() override {
            // code logic
        }
        void scan() override {
            // code logic
        }
        void fax() override {
            // code logic
        }
};
```

- `Printer` class is forced to implement `scan` and `fax` method which it doesn't need.

##### ✅ Good Example

```c++
class Printer {
    public:
        void print() = 0;
};

class Scanner {
    public:
        void scan() = 0;
};

class Fax {
    public:
        void fax() = 0;
};

class SimplePrinter : public Printer {
    public:
        void print() override {
            // code logic
        }
};

class PrinterScanner : public Printer, public Scanner {
    public:
        void print() override {
            // code logic
        }
        void scan() override {
            // code logic
        }
};
```

#### What it solves?

- This principle aims at a set of actions into smaller sets so that the client can depend on the interface they need.
- It helps to avoid the `dependency inversion` principle.
- Make classes more modular and easier to maintain.

### 📌 Dependency Inversion Principle

- High-level modules should not depend on low-level modules. Both should depend on abstractions.
- Abstractions should not depend on details. Details should depend on abstractions.

##### ❌ Bad Example

```javascript
class MySQLDatabase {
  connect() {
    console.log("Connected to MySQL");
  }
}

class UserRepository {
  constructor() {
    this.database = new MySQLDatabase();
  }

  getUsers() {
    this.database.connect();
    console.log("Getting users from MySQL");
  }
}

const userRepository = new UserRepository();
userRepository.getUsers();
```

#### Problems:

- `UserRepository` class is dependent on `MySQLDatabase` class.
- If we want to use another database, we need to modify the `UserRepository` class.

##### ✅ Good Example

```javascript
class Database {
    connect() {
        console.log("Connected to database");
    }
}

class MySQLDatabase : public Database {
    connect() {
        console.log("Connected to MySQL");
    }
}

class MongoDBDatabase : public Database {
    connect() {
        console.log("Connected to MongoDB");
    }
}

class UserRepository {
    constructor(database) {
        this.database = database;
    }

    getUsers() {
        this.database.connect();
        console.log("Getting users from database");
    }
}

const userInMySQL = new UserRepository(new MySQLDatabase());
userInMySQL.getUsers();

const userInMongoDB = new UserRepository(new MongoDBDatabase());
userInMongoDB.getUsers();
```

#### What it solves?

- Promotes flexibility and testability.
- make it eady to swap implementations.
- loose coupling between modules.
  - Coupling is the degree of interdependency between software modules.
