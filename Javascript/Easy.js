/*
Polyfills : 
Closures : 
Hoisting :
Object prototyping :
OOps :
Event loop:
Call, Bind & Apply
Promises :
Async JS :
How browser works :
DOM :
virtual DOM :
Web Components :
CI/CD :
React vs vanilla JS :
Javascript Delegation Model :
Add and Delete properties in JS :
Cookies :
Localstorage and Sessionstorage :
Event Bubbling and Event Capturing
Web workers and Service workers
PWAs
Why wrap the content of a JS source file in a function block?
What are the advantages and disadvantages of monolithic and microservice architectures?
Module.exports and exports
Use strict
Javascript BOM
InstanceOf
Throttling and Debouncing
*/


/**
 * @description Closures
 1. Closures in JavaScript are a fundamental and powerful concept that let you remember and access variables from an outer function even after that function has finished executing.


Use Cases
(1)- Data privacy / Encapsulation
(2)- Callbacks and Event Handlers Closures are often used in asynchronous code like setTimeout, addEventListener, etc.
(3)- Partial Application and Currying

 function outerFunction() {
    let outerVariable = "I'm from outer!";
  
    function innerFunction() {
      console.log(outerVariable); // Accesses outerVariable
    }
  
    return innerFunction;
  }
  
  const closureFn = outerFunction(); // outerFunction finishes execution
  closureFn(); // Still logs: "I'm from outer!"

*/




/**
 * @description Prototypes
 2. In JavaScript, every object has a hidden property called [[Prototype]] (can be accessed via .prototype or __proto__) that links to another object — called its prototype.

This is how JavaScript objects can inherit properties and methods from other objects.



// Example 1
  function Car(make) {
    this.make = make;
  }
  
  Car.prototype.honk = function () {
    console.log(`${this.make} says honk!`);
  };
  
  const myCar = new Car("Tesla");
  myCar.honk(); // "Tesla says honk!"
  

// Example 2
  function User(name, role) {
    this.name = name;
    this.role = role;
  }
  
  // Shared methods via prototype
  User.prototype.login = function () {
    console.log(`${this.name} has logged in.`);
  };
  
  User.prototype.logout = function () {
    console.log(`${this.name} has logged out.`);
  };
  
  // Create users
  const admin = new User("Ayush", "admin");
  const guest = new User("Ravi", "guest");
  
  admin.login();  // "Ayush has logged in."
  guest.logout(); // "Ravi has logged out."
  
 */


/**
 * @description Virtual DOM
 The Virtual DOM (VDOM) is a lightweight in-memory representation of the real DOM used primarily by libraries like React to optimize UI rendering performance.

🔍 What It Is:
  It's not a browser feature — it's an abstraction created by JavaScript frameworks (e.g., React).
  It's a copy of the real DOM stored in memory.
  Updates are made to the virtual DOM first, not directly to the real DOM.

⚙️ How It Works:
You write code (e.g., in React JSX).
React creates a virtual DOM tree based on your component.
When data/state changes:

A new virtual DOM is created.

It's diffed (compared) with the previous virtual DOM.

React calculates the minimal set of changes.

Only those minimal changes are applied to the real DOM, improving efficiency.
 */




/**
 * @description Call, Bind & Apply
In JavaScript, the value of "this" inside a function depends on how the function is called — not where it was defined.

These three methods let you manually set "this" for any function.



1. 🔹 call()
- Immediately invokes the function.
- Passes arguments individually.

const person = {
  name: "Ayush",
};

function sayHi(greeting) {
  console.log(`${greeting}, I'm ${this.name}`);
}

sayHi.call(person, "Hello"); // Hello, I'm Ayush


2. 🔹 apply()
- Immediately invokes the function. (like call)
- Passes arguments as an array.

sayHi.apply(person, ["Hi"]); // Hi, I'm Ayush

🆚 Use apply when you already have an array of arguments.



3. 🔹 bind()
- Returns a new function with "this" permanently bound.
- You have to call it manually.

const boundFn = sayHi.bind(person, "Hey");
boundFn(); // Hey, I'm Ayush

🆚USE: Perfect for event handlers, callbacks, or delaying execution.

*/



/**
 * @description Promises : the bread and butter of modern async code 🍞⚡
 🧠 What is a Promise?
    A Promise is an object representing the eventual completion or failure of an asynchronous operation.
    It can be in one of three states:
    - Pending (initial state)
    - Fulfilled (operation completed successfully)
    - Rejected (operation failed) 

==> BASIC SYNTAX
const promise = new Promise((resolve, reject) => {
  // async work
  const success = true;

  if (success) {
    resolve("Data received ✅");
  } else {
    reject("Something went wrong ❌");
  }
});

==> CONSUMING PROMISES
promise
  .then((data) => {
    console.log(data); // "Data received ✅"
  })
  .catch((error) => {
    console.error(error); // "Something went wrong ❌"
  })
  .finally(() => {
    console.log("Promise settled (either fulfilled or rejected)");
  });

*/



/**
 * @description Async/Await
  JavaScript is single-threaded, but it’s asynchronous and non-blocking thanks to:
    - The Event Loop
    - The Call Stack
    - The Web APIs (like setTimeout, fetch, etc.)
    - The Microtask Queue

  This allows JS to do things like API calls, timers, and animations without freezing the page or blocking other code.

=====CODE:

async function fetchData() {
  try {
    let response = await fetch('https://api.example.com/data');
    if (!response.ok) throw new Error('Network response was not ok');
    let data = await response.json();
    console.log(data);
  } catch (error) {
    console.error('There was an error:', error);
  }
}

fetchData();

 */




/**
 * @description COOKIES (4KB limit)
 A cookie is a small piece of data (a key-value pair) that a browser stores and sends with every HTTP request to the same origin.

Used for:
- Authentication
- User preferences
- Session management
- Tracking (analytics, ads)

✍️ Setting Cookies (Client-side JS)
document.cookie = "username=Ayush";
You can also add more:

document.cookie = "theme=dark; expires=Fri, 31 Dec 2025 23:59:59 GMT; path=/";


🔍 Reading Cookies
console.log(document.cookie);
// Output: "username=Ayush; theme=dark"

🧠 Note: It's just a string, so you might want to parse it for easier access.

❌ Deleting Cookies
To delete a cookie, set its expiration date in the past:
document.cookie = "username=; expires=Thu, 01 Jan 1970 00:00:00 GMT";
 */


/**
 * @description LOCAL STORAGE (5MB limit) and SESSION STORAGE (5MB limit)
 * 
  Local Storage:
  - Stores data with no expiration time (untill manually clear it).
  - Data persists even after the browser is closed and reopened.
  - Accessible from any tab or window of the same origin.

  Session Storage:
  - Stores data for one session (until the tab/window is closed).
  - Data is not shared across tabs/windows.
  - Useful for temporary data that doesn't need to persist.

✅ Set Item
localStorage.setItem("username", "Ayush");
sessionStorage.setItem("sessionId", "12345");

🧠 Get Item
const username = localStorage.getItem("username");
const sessionId = sessionStorage.getItem("sessionId");

❌ Remove Item
localStorage.removeItem("username");


🧹 Clear All
sessionStorage.clear();
*/




/**
 * @description Event Bubbling and Event Capturing
- Event Bubbling and Event Capturing are two phases in the way events flow through the DOM when you interact with it — like clicking a button inside a div inside the body.

📊 The Event Flow Phases
When an event (like click) occurs, it flows through three phases:
- Capture Phase (top → down)
- Target Phase (actual clicked element)
- Bubble Phase (bottom → up)

1) Event Bubbling (default behavior)
  - Event goes from the target element → up to the root.
  - Most events in JS bubble by default.

USE CASE: 1) Click Outside to Close Modal

EXXAMPLE:
    //HTML
    <div id="outer">
        <button id="inner">Click Me</button>
    </div>

    //JS
    document.getElementById("outer").addEventListener("click", () => {
        console.log("Outer clicked");
    });

    document.getElementById("inner").addEventListener("click", () => {
        console.log("Inner clicked");
    });


    // Output:
    Inner clicked
    Outer clicked



2) Event Capturing
- Happens before bubbling, from root → down to the target.
- You can listen during this phase by passing true as the third argument.


EXAMPLE:
    document.getElementById("outer").addEventListener("click",
        () => {
            console.log("Outer capture");
        },
        true // <- capturing phase
    );

// Output:
    Outer capture
    Inner clicked
    Outer clicked

 */





/**
 * @description Throttling and Debouncing in js
- Throttling and Debouncing are two important techniques in JavaScript for optimizing performance, especially when dealing with events that fire repeatedly (like scroll, resize, keypress, or mousemove)

🔁 Debouncing(DELAY): Debouncing ensures a function is only called after a specified delay since the last time it was invoked.
***Use case: 
    - Search bar suggestions
    - Form field validation
    - Window resize handler

How it works: If the event keeps firing, the function call is delayed until the event has stopped firing for the given time.
CODE:

function debounce(func, delay) {
  let timer;
  return function (...args) {
    clearTimeout(timer);
    timer = setTimeout(() => {
      func.apply(this, args);
    }, delay);
  };
}

// Example: search input
const handleSearch = debounce((e) => {
  console.log("Searching for:", e.target.value);
}, 300);

document.getElementById("search").addEventListener("input", handleSearch);



🧭 Throttling(INTERVAL): Throttling ensures a function is called at most once in every specified time interval, regardless of how many times the event occurs.
***Use case:
    - Scroll event listener
    - Button spamming
    - Window resize performance


How it works: It limits the number of times a function can be executed over time.

CODE:
function throttle(func, interval) {
  let lastTime = 0;
  return function (...args) {
    const now = Date.now();
    if (now - lastTime >= interval) {
      lastTime = now;
      func.apply(this, args);
    }
  };
}

// Example: scroll tracking
const handleScroll = throttle(() => {
  console.log("Scrolled at", Date.now());
}, 500);

window.addEventListener("scroll", handleScroll);

*/


