# 🔹 Proxy Design Pattern

## What is it?

The **Proxy Design Pattern** (a structural design pattern) provides a placeholder (proxy) object that controls access to another object (the real subject).

- It acts like a middleman.
- You don’t talk to the real object directly; instead, you talk to the proxy.
- The proxy decides whether to forward the request, modify it, or block it.

## Why use it?

- To add extra logic before/after accessing the real object.
- To control expensive operations (e.g., database, API calls).
- To provide security, lazy initialization, caching, etc.

---

## 🔑 Real-world Analogy

**Think of a credit card 💳:**

- You don’t carry bags of cash everywhere.
- You give the card (proxy), which represents your real money in the bank.
- The bank (real object) is only accessed through the proxy (card + machine).

---

## 🔹 Problem Statement

Suppose we have an object that fetches videos from YouTube.

- Directly fetching videos is expensive (slow network, lots of data).
- We want a proxy that caches results, so repeated requests are faster.

---

## 🔹 Structure

- **Subject (Interface):** common methods.
- **RealSubject:** the actual object with heavy operations.
- **Proxy:** wraps RealSubject, adds caching/security.
- **Client:** uses Proxy instead of RealSubject directly.


---

## �🔹 Example in JavaScript
<details>
<summary>▶️ Click to see Code</summary>

```js
// Subject Interface
class VideoService {
	getVideo(id) {}
}

// Real Subject
class YouTubeVideoService extends VideoService {
	getVideo(id) {
		console.log(`Fetching video ${id} from YouTube...`);
		return { id, data: `Video data for ${id}` };
	}
}

// Proxy
class CachedVideoService extends VideoService {
	constructor() {
		super();
		this.realService = new YouTubeVideoService();
		this.cache = {};
	}

	getVideo(id) {
		if (this.cache[id]) {
			console.log(`Returning cached video ${id}`);
			return this.cache[id];
		}
		const video = this.realService.getVideo(id);
		this.cache[id] = video; // store in cache
		return video;
	}
}

// Client
const service = new CachedVideoService();

// First call → fetches from YouTube
console.log(service.getVideo("abc"));

// Second call → returns from cache
console.log(service.getVideo("abc"));

// Another video → fetched from YouTube
console.log(service.getVideo("xyz"));
```
</details>

### ✅ Output
```
Fetching video abc from YouTube...
{ id: 'abc', data: 'Video data for abc' }

Returning cached video abc
{ id: 'abc', data: 'Video data for abc' }

Fetching video xyz from YouTube...
{ id: 'xyz', data: 'Video data for xyz' }
```

---

## 🔑 When to Use Proxy

✅ **Use when you need:**
- Caching
- Lazy initialization (create object only when needed)
- Access control/security
- Logging/monitoring
- Remote proxy (accessing remote services)

❌ **Avoid if:**
- Performance overhead of proxy outweighs its benefits.
- Direct access is simpler and good enough.

