### 🚀 BASICS
- Class : A class is a blueprint for creating objects. It defines a set of properties and methods that will be shared by all objects created from that class.
- Object : An object is an instance of a class.


### Pillars of OOP
- Encapsulation
- Inheritance
- Polymorphism
- Abstraction


### 📌 Encapsulation
- Encapsulation is the process of hiding the implementation details of a class from the outside world and only exposing the necessary information through public methods.

```c++
class BankAccount {
    private:
        int balance;
        string accountNumber;

    public:
        void deposit(int amount) {
            balance += amount;
        }

        void withdraw(int amount) {
            balance -= amount;
        }

        int getBalance() {
            return balance;
        }
};
```

### 📌 Inheritance
- Inheritance is a mechanism that allows a class to inherit properties and methods from another class.

```c++
class Animal {
    public:
        void eat() {
            cout << "Eating..." << endl;
        }
};

class Dog : public Animal {
    public:
        void bark() {
            cout << "Barking..." << endl;
        }
};

main() {
    Dog dog;
    dog.eat();
    dog.bark();
}


```


### 📌 Polymorphism
- Polymorphism is a mechanism that allows a class to have multiple forms.
- Types of Polymorphism :
    - Compile-time Polymorphism (static): achieved through function overloading
    - Runtime Polymorphism (dynamic): achieved through function overriding

#### Runtime Polymorphism
- Function overriding

```c++
class Animal {
    public:
        void eat() {
            cout << "animal eating..." << endl;
        }
};

class Dog : public Animal {
    public:
        void eat() {
            cout << "🐶 dog eating..." << endl;
        }
};

class Cat : public Animal {
    public:
        void eat() {
            cout << "🐱cat eating..." << endl;
        }
};

main() {
    Dog dog;
    Cat cat;
    dog.eat();  // 🐶 dog eating...
    cat.eat();  // 🐱 cat eating...
}
```

- `eat()` is a virtual function, which means that it can be overridden in the derived class.
- `eat()` is called at runtime, which means that the correct version of the function is called based on the type of the object.

#### Compile-time Polymorphism
- Function overloading

```javascript
function greet(name, day) {
    if(day) {
        return `Hello ${name}, have a great ${day}!`;
    } else {
        return `Hello ${name}, have a great day!`;
    }
}

console.log(greet("Ayush", "Monday"));  // Hello Ayush, have a great Monday!
console.log(greet("Ayush"));            // Hello Ayush, have a great day!
```


### 📌 Abstraction
- Abtraction is the concept of showing only the necessary information and hiding the unnecessary information.
- We can achieve abstraction by using abstract classes and interfaces.

```c++
class Vehicle {   // Abstract class
    public:
        virtual void start() = 0;  // Pure virtual function
};

class Car : public Vehicle {
    public:
        void start() override {
            cout << "Car started" << endl;
        }
};

main() {
    Car car;
    car.start();
}
```

- `Vehicle` is an abstract class because it has a pure virtual function.
- `start()` is a virtual function forcing derived classes(Car) to implement it.
- we are hiding the implementation details of the `start()` function from the user.


##### 🚨 NOTE
- We can only create objects of concrete classes.
- If a class like `Car` inherits from an abstract class(`Vehicle`), it must implement all the pure virtual functions of the abstract class(`start()`). Otherwise, the class will also becomes abstract class.
- Abstract classes can not be instantiated.







