## 🔹 What is the State Design Pattern?

The **State Pattern** allows an object to change its behavior when its internal state changes.

Instead of using big `if/else` or `switch` statements, each state is put into a separate class.

The object delegates work to its current state object.

---

## 🔹 Why use it?

- Avoids complex conditional logic (`if state == A do this else if state == B do that`).
- Makes code clean, extensible, and maintainable.
- Adding new states = just add new classes, no need to touch existing logic.

---

## 🔹 Real-world Analogy

Think of a **Vending Machine**:

- In “No Coin” state → you can insert a coin.
- In “Has Coin” state → you can select a product.
- In “Sold Out” state → you can’t buy.

👉 The machine’s behavior changes depending on its state.

---

## 🔹 Problem Statement

We want to model a **Media Player**.

- If it’s in Playing state → pressing play should pause.
- If it’s in Paused state → pressing play should resume.
- If it’s in Stopped state → pressing play should start fresh.

Instead of writing one giant `if/else`, we’ll use State Pattern.

### Click to view CODE without using State pattern
<details>
<summary>▶️ Click to see Code</summary>

```js
class MediaPlayer {
  constructor() {
    this.state = "stopped"; // could be "playing", "paused"
  }

  pressPlay() {
    if (this.state === "stopped") {
      console.log("▶️ Starting the music...");
      this.state = "playing";
    } else if (this.state === "playing") {
      console.log("⏸ Pausing the music...");
      this.state = "paused";
    } else if (this.state === "paused") {
      console.log("▶️ Resuming the music...");
      this.state = "playing";
    }
  }
}

// Usage
const player = new MediaPlayer();
player.pressPlay(); // Starting
player.pressPlay(); // Pausing
player.pressPlay(); // Resuming

```

</details>

---

## 🔹 Implementation in JavaScript

```js
// Context
class MediaPlayer {
	constructor() {
		this.state = new StoppedState(); // initial state
	}

	setState(state) {
		this.state = state;
	}

    //BUTTTON
	pressPlay() {
		this.state.pressPlay(this);
	}
}

// State Interface
class State {
	pressPlay(player) {
		throw new Error("pressPlay must be implemented");
	}
}

// Concrete States
class PlayingState extends State {
	pressPlay(player) {
		console.log("⏸ Pausing the music...");
		player.setState(new PausedState());
	}
}

class PausedState extends State {
	pressPlay(player) {
		console.log("▶️ Resuming the music...");
		player.setState(new PlayingState());
	}
}

class StoppedState extends State {
	pressPlay(player) {
		console.log("▶️ Starting the music...");
		player.setState(new PlayingState());
	}
}

// Usage
const player = new MediaPlayer();

player.pressPlay(); // Starting
player.pressPlay(); // Pausing
player.pressPlay(); // Resuming
```

**✅ Output:**
```
▶️ Starting the music...
⏸ Pausing the music...
▶️ Resuming the music...
```

---

## 🔑 When to Use

✅ **Use State Pattern when:**

- An object has many conditional behaviors based on its state.
- You want to remove large if/else or switch statements.
- You want to make adding new states easy.

❌ **Avoid when:**

- Object has very few states → a simple if/else is enough.
- Too many tiny state classes make code over-engineered.
