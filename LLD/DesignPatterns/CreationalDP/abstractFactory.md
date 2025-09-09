# Abstract Factory Design Pattern

---

## 🔹 1. What is Abstract Factory?

The **Abstract Factory Pattern** is a **Creational Design Pattern** that provides an interface to create families of related objects **without specifying their concrete classes**.


👉 Instead of a single factory (like in Factory Method), you have a **factory of factories**.  
Each concrete factory can create a group (family) of related objects.  
The client just uses the abstract factory → doesn’t know (or care) about exact classes.

---

## 🔹 2. Why do we need it?

- Sometimes we don’t just need one object, but a **set of related objects** that must work together.  
- If you let the client directly decide which objects to create, it may **mix incompatible objects**.  
- **Abstract Factory ensures consistency** in families of objects and hides creation details.

---

## 🔹 3. Real-world Analogy

Think of **Furniture Factory 🛋️**:

- IKEA has a **Modern Furniture Factory** → makes modern chairs, sofas, tables.  
- Another factory makes **Victorian style furniture**.  

👉 The client just says: *“Give me a Modern factory”* or *“Give me a Victorian factory.”*  
👉 The factory will produce all furniture in the same style (**consistency**).

---

## 🔹 4. Problem Statement it Solves

Suppose you are designing a **cross-platform GUI library**:

- For **Windows** → buttons and checkboxes look different.  
- For **Mac** → buttons and checkboxes look different.  

If you directly instantiate (`new WindowsButton()`, `new MacCheckbox()`),  
client code will be full of **if/else** and messy.  

➡️ **Abstract Factory solves this** by providing a factory that creates the **whole family of UI components** for a given platform.

---

## 🔹 5. Structure

- **Abstract Factory** → declares methods for creating related products.  
- **Concrete Factories** → implement these methods to create specific product families.  
- **Abstract Products** → common interfaces for product types.  
- **Concrete Products** → actual implementations.  
- **Client** → uses factory interface only (doesn’t know which concrete class is being used).  

---

## 🔹 6. Pseudocode (Generic)

```cpp
// Abstract Products
interface Button { render(); }
interface Checkbox { render(); }

// Concrete Products
class WindowsButton implements Button { render() { ... } }
class MacButton implements Button { render() { ... } }
class WindowsCheckbox implements Checkbox { render() { ... } }
class MacCheckbox implements Checkbox { render() { ... } }

// Abstract Factory
interface GUIFactory {
    Button createButton();
    Checkbox createCheckbox();
}

// Concrete Factories
class WindowsFactory implements GUIFactory {
    Button createButton() { return new WindowsButton(); }
    Checkbox createCheckbox() { return new WindowsCheckbox(); }
}

class MacFactory implements GUIFactory {
    Button createButton() { return new MacButton(); }
    Checkbox createCheckbox() { return new MacCheckbox(); }
}

// Client
factory = getFactory("Windows");
button = factory.createButton();
checkbox = factory.createCheckbox();
button.render();
checkbox.render();
```


---

## 🔹 7. Example

```cpp
#include <iostream>
#include <memory>

// ----- Abstract Products -----
class Button {
public:
    virtual void render() = 0;
    virtual ~Button() {}
};

class Checkbox {
public:
    virtual void render() = 0;
    virtual ~Checkbox() {}
};

// ----- Concrete Products (Windows) -----
class WindowsButton : public Button {
public:
    void render() override { std::cout << "Windows Button 🪟" << std::endl; }
};

class WindowsCheckbox : public Checkbox {
public:
    void render() override { std::cout << "Windows Checkbox 🪟" << std::endl; }
};

// ----- Concrete Products (Mac) -----
class MacButton : public Button {
public:
    void render() override { std::cout << "Mac Button 🍏" << std::endl; }
};

class MacCheckbox : public Checkbox {
public:
    void render() override { std::cout << "Mac Checkbox 🍏" << std::endl; }
};

// ----- Abstract Factory -----
class GUIFactory {
public:
    virtual std::unique_ptr<Button> createButton() = 0;
    virtual std::unique_ptr<Checkbox> createCheckbox() = 0;
    virtual ~GUIFactory() {}
};

// ----- Concrete Factories -----
class WindowsFactory : public GUIFactory {
public:
    std::unique_ptr<Button> createButton() override {
        return std::make_unique<WindowsButton>();
    }
    std::unique_ptr<Checkbox> createCheckbox() override {
        return std::make_unique<WindowsCheckbox>();
    }
};

class MacFactory : public GUIFactory {
public:
    std::unique_ptr<Button> createButton() override {
        return std::make_unique<MacButton>();
    }
    std::unique_ptr<Checkbox> createCheckbox() override {
        return std::make_unique<MacCheckbox>();
    }
};

// ----- Client -----
int main() {
    std::unique_ptr<GUIFactory> factory;

    // Choose OS (runtime decision)
    std::string os = "mac";
    if (os == "windows") factory = std::make_unique<WindowsFactory>();
    else factory = std::make_unique<MacFactory>();

    auto button = factory->createButton();
    auto checkbox = factory->createCheckbox();

    button->render();
    checkbox->render();

    return 0;
}
```

## 🔹 9. Output (if os = mac)
```cpp
Mac Button 🍏
Mac Checkbox 🍏
```


## 🔹 8. When to Use / Avoid

### ✅ Use Abstract Factory when:
- You need to create **families of related objects** (UI kits, themes, database drivers).  
- You want to **enforce consistency** (all products belong to same family).  
- You want to **hide object creation details** from the client.  

### ❌ Avoid when:
- You only need **one type of product** → use **Factory Method** instead.  
- You add **new products frequently** → Abstract Factory becomes bulky (every factory must update).  

## ✅ In short:

- Factory Method → Creates one type of object at a time.
- Abstract Factory → Creates families of related objects at once (ensures consistency).