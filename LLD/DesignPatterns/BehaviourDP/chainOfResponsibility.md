## 🔹 **What is Chain of Responsibility?**

The Chain of Responsibility is a behavioral design pattern that lets you pass requests along a chain of handlers.
- Each handler decides either to process the request or pass it along to the next handler.
- The sender doesn’t know which handler will handle it.

## 🔹 **Why do we need it?**

- Without CoR → you usually end up with long if/else or switch blocks checking conditions.
- With CoR → you separate logic into different handlers, and requests flow naturally.

## 🔹 **Real-world Analogy**

👉 Imagine customer support service:

- Tier 1 support answers simple questions.
- If not solved, request goes to Tier 2.
- If still not solved, goes to Tier 3 specialist.

Each level only handles what it can and forwards the rest.

![alt text](image.png)

## 🔹 Problem Statement

Suppose you’re building an API server.
Every request should go through multiple checks:

- Authentication – Is the user logged in?
- Authorization – Does the user have permission?
- Validation – Is the request data valid?

Handler – Finally process the request.

❌ Without CoR → You’d write nested if/else checks in one big function → messy and hard to extend.

✅ With CoR → Each step is a handler. If one fails, it stops. Otherwise, it passes to the next handler.

<details>
<summary>Click to view the Code</summary>

```js
// Base Handler
class Handler {
  setNext(handler) {
    this.nextHandler = handler;
    return handler; // allows chaining
  }

  handle(request) {
    if (this.nextHandler) {
      return this.nextHandler.handle(request);
    }
    return true; // if no handler, success
  }
}

// Concrete Handlers
class AuthHandler extends Handler {
  handle(request) {
    if (!request.user) {
      console.log("❌ Authentication failed: No user.");
      return false;
    }
    console.log("✅ Authentication passed.");
    return super.handle(request);
  }
}

class PermissionHandler extends Handler {
  handle(request) {
    if (!request.user.isAdmin) {
      console.log("❌ Authorization failed: Not an admin.");
      return false;
    }
    console.log("✅ Authorization passed.");
    return super.handle(request);
  }
}

class ValidationHandler extends Handler {
  handle(request) {
    if (!request.body || !request.body.data) {
      console.log("❌ Validation failed: Missing data.");
      return false;
    }
    console.log("✅ Validation passed.");
    return super.handle(request);
  }
}

class BusinessLogicHandler extends Handler {
  handle(request) {
    console.log("🎯 Business Logic executed with data:", request.body.data);
    return true;
  }
}

// ---- Client Code ----
const auth = new AuthHandler();
const permission = new PermissionHandler();
const validation = new ValidationHandler();
const business = new BusinessLogicHandler();

// Build the chain: auth → permission → validation → business
auth.setNext(permission).setNext(validation).setNext(business);

// Test Requests
console.log("---- Test 1: Missing user ----");
auth.handle({}); 

console.log("\n---- Test 2: Normal user, not admin ----");
auth.handle({ user: { name: "John", isAdmin: false }, body: { data: "Hello" } });

console.log("\n---- Test 3: Admin but missing data ----");
auth.handle({ user: { name: "Alice", isAdmin: true }, body: {} });

console.log("\n---- Test 4: Admin with valid data ----");
auth.handle({ user: { name: "Bob", isAdmin: true }, body: { data: "Important Task" } });

```

</details>

### Output
```js
---- Test 1: Missing user ----
❌ Authentication failed: No user.

---- Test 2: Normal user, not admin ----
✅ Authentication passed.
❌ Authorization failed: Not an admin.

---- Test 3: Admin but missing data ----
✅ Authentication passed.
✅ Authorization passed.
❌ Validation failed: Missing data.

---- Test 4: Admin with valid data ----
✅ Authentication passed.
✅ Authorization passed.
✅ Validation passed.
🎯 Business Logic executed with data: Important Task
```


## 🔹 When to Use

- ✅ When multiple handlers can process a request.
- ✅ When you want to decouple request sender & receiver.
- ✅ When you want to dynamically change processing order.

## 🔹 When to Avoid

- ❌ When request should be handled always by a specific object.
- ❌ If the chain becomes too long → debugging is harder.