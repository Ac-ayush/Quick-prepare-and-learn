# 🔹 Prototype Design Pattern

## 1. What is the Prototype Pattern?

The **Prototype Pattern** is a **Creational Design Pattern** where you create new objects by **cloning (copying)** an existing object, instead of creating from scratch with `new`.

👉 **Idea:** If object creation is expensive, complex, or repetitive, just make a **clone** of an already existing object.

---

## 2. Why use Prototype? (The Problem)

- Some objects are **costly to create** (e.g., deep computation, database loading, network fetch).  
- Sometimes you need **many similar objects with small modifications**.  
- Writing new constructors or factories for each variation becomes repetitive.  

✅ **Solution:** Create one *prototype* object → clone it → modify as needed.  

---

## 3. Real-world Analogy

Think of a **resume template 📄**.  
Instead of writing a new resume from scratch every time, you **copy the template** and just update the name, skills, etc.  

- Template = **Prototype**  
- Each copied resume = **Clone**  

---

## 4. Structure (in simple words)

- **Prototype** → interface/abstract class that declares a `clone()` method.  
- **Concrete Prototypes** → implement `clone()` to copy themselves.  
- **Client** → uses `clone()` instead of `new`.  

---

## 5. Example in Simple C++

```cpp
#include <iostream>
#include <memory>

// ---- Prototype Interface ----
class Shape {
public:
    virtual std::unique_ptr<Shape> clone() = 0; // prototype method
    virtual void draw() = 0;
    virtual ~Shape() {}
};

// ---- Concrete Prototypes ----
class Circle : public Shape {
    int radius;
public:
    Circle(int r) : radius(r) {}
    std::unique_ptr<Shape> clone() override {
        return std::make_unique<Circle>(*this); // copy itself
    }
    void draw() override {
        std::cout << "Drawing Circle with radius " << radius << std::endl;
    }
};

class Rectangle : public Shape {
    int width, height;
public:
    Rectangle(int w, int h) : width(w), height(h) {}
    std::unique_ptr<Shape> clone() override {
        return std::make_unique<Rectangle>(*this); // copy itself
    }
    void draw() override {
        std::cout << "Drawing Rectangle " << width << "x" << height << std::endl;
    }
};

// ---- Client ----
int main() {
    // Create original prototypes
    std::unique_ptr<Shape> circlePrototype = std::make_unique<Circle>(10);
    std::unique_ptr<Shape> rectPrototype = std::make_unique<Rectangle>(4, 6);

    // Clone them
    auto circleCopy1 = circlePrototype->clone();
    auto circleCopy2 = circlePrototype->clone();
    auto rectCopy = rectPrototype->clone();

    // Use them
    circleCopy1->draw();  // Drawing Circle with radius 10
    circleCopy2->draw();  // Drawing Circle with radius 10
    rectCopy->draw();     // Drawing Rectangle 4x6
}

```

---

## 6. Output
```cpp
Drawing Circle with radius 10
Drawing Circle with radius 10
Drawing Rectangle 4x6
```

---

## 7. When to Use Prototype

✅ **Use when:**  
- Object creation is expensive/slow.  
- You need many similar objects.  
- You want to avoid writing lots of `new` or constructors.  

❌ **Avoid when:**  
- Objects are simple to create → factory or constructor is enough.  
- Cloning causes deep copy issues (complex object graphs).  

---

## 8. One-liner Definition

**Prototype Pattern = Create new objects by cloning existing ones, instead of instantiating from scratch.**
