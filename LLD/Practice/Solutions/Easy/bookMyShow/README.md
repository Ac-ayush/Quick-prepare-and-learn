# 🎬 BookMyShow - Movie Ticket Booking System

A complete C++ implementation of a movie ticket booking system similar to BookMyShow, demonstrating object-oriented programming principles and design patterns.

## 📋 Project Overview

BookMyShow is a console-based movie ticket booking application that allows users to:
- Select from multiple cities (Bangalore, Mumbai, Chennai, Delhi)
- Browse available movies (Barbie, Oppenheimer)
- Choose show times at different theatres
- Book seats (1-100)
- Process payments
- Generate ticket confirmations

## 🏗️ Architecture & Design Patterns

### **Design Patterns Used:**
- **Singleton Pattern**: `BookingService` ensures only one instance exists
- **Factory Pattern**: `MovieFactory` and `TheatreFactory` for object creation
- **Controller Pattern**: `MovieController` and `TheatreController` for business logic

### **Project Structure:**
```
bookMyShow/
├── controllers/          # Business logic controllers
│   ├── MovieController.cpp
│   └── TheatreController.cpp
├── enums/               # Enumeration definitions
│   ├── city.cpp
│   └── seatCategory.cpp
├── movie/               # Movie-related classes
│   ├── movie.cpp
│   └── MovieFactory.cpp
├── services/            # Core services
│   ├── BookingService.cpp
│   └── PaymentService.cpp
├── theatre/             # Theatre-related classes
│   ├── screen.cpp
│   ├── seat.cpp
│   ├── show.cpp
│   ├── theatre.cpp
│   └── TheatreFactory.cpp
├── utils/               # Utility classes
│   └── BookingDataFactory.cpp
├── main.cpp             # Entry point
├── Makefile             # Build configuration
├── run.sh               # Quick run script
└── README.md            # This file
```

## 🚀 How to Run

### **Prerequisites:**
- C++17 compatible compiler (g++, clang++)
- Make (optional, for using Makefile)

### **Method 1: Quick Run Script (Recommended)**
```bash
./run.sh
```

### **Method 2: Using Makefile**
```bash
make run
```

### **Method 3: Manual Compilation**
```bash
g++ -std=c++17 -o bookMyShow main.cpp
./bookMyShow
```

### **Method 4: VS Code Code Runner**
1. Open `main.cpp` in VS Code
2. Click the Code Runner icon ▶️ or press `Ctrl+Alt+N`
3. The project will compile and run automatically

## 🎯 Features

### **Core Functionality:**
- ✅ **City Selection**: Choose from 4 major cities
- ✅ **Movie Selection**: Browse available movies by city
- ✅ **Show Selection**: View show times at different theatres
- ✅ **Seat Booking**: Select from 100 available seats
- ✅ **Payment Processing**: Simulated payment system
- ✅ **Ticket Generation**: Beautiful ticket confirmation with booking ID
- ✅ **Multiple Bookings**: Book multiple tickets in one session

### **Sample Data:**
- **Cities**: Bangalore, Mumbai, Chennai, Delhi
- **Movies**: Barbie (128 min), Oppenheimer (180 min)
- **Theatres**: INOX (Bangalore), PVR (Delhi)
- **Show Times**: 10:00, 14:00, 18:00, 20:00

## 🎮 Usage Example

```
🔧 Initializing BookMyShow system...
✅ System initialized successfully!

══════════════════════════════════════════
          🎬 Welcome to BookMyShow 🎟️
══════════════════════════════════════════

🔹 🏙️ Select Your City
──────────────────────────────────────────
   1. Bangalore
   2. Mumbai
   3. Chennai
   4. Delhi
👉 Enter choice (1-4): 1

🔹 🎥 Available Movies in Bangalore
──────────────────────────────────────────
   1. BARBIE
   2. OPPENHEIMER
👉 Enter choice (1-2): 1

🔹 🎭 Available Shows for BARBIE in Bangalore
──────────────────────────────────────────
   1. 10 at 🎦 INOX
👉 Enter choice (1-1): 1

🔹 💺 Select Your Seat (1-100)
──────────────────────────────────────────
👉 Enter choice (1-100): 34
💳 Processing payment of ₹250...
🎉 ✅ Booking Successful! Enjoy your movie! 🍿

========================================
🎟️       MOVIE TICKET CONFIRMATION       🎟️
========================================
🎬 Movie: BARBIE
⏰ Show Time: 10:00
💺 Seat Number: 34
----------------------------------------
📅 Date: 2025-09-27
🆔 Booking ID: 719a288e-3d85-c237-7184-f1d585b68792
========================================
🎉 Enjoy your movie! 🍿 Have a great time!
========================================
```

## 🔧 Technical Details

### **Key Classes:**
- **BookingService**: Main service class (Singleton)
- **MovieController**: Manages movies by city
- **TheatreController**: Manages theatres and shows
- **Movie**: Represents a movie with ID, name, duration
- **Theatre**: Represents a theatre with screens and shows
- **Show**: Represents a movie show with timing and seats
- **PaymentService**: Handles payment processing

### **Memory Management:**
- Dynamic allocation for theatres to avoid scope issues
- Proper include guards to prevent redefinition errors
- RAII principles for resource management

### **Error Handling:**
- Input validation for user choices
- Empty vector checks
- Graceful handling of invalid selections

## 🛠️ Build Configuration

### **Makefile Commands:**
```bash
make          # Compile the project
make run      # Compile and run
make clean    # Remove compiled files
```

### **Compiler Flags:**
- `-std=c++17`: Use C++17 standard
- `-Wall -Wextra`: Enable warnings
- `-o bookMyShow`: Output executable name

## 📝 Development Notes

### **Recent Fixes:**
- ✅ Fixed multiple redefinition errors with include guards
- ✅ Resolved memory management issues with theatre creation
- ✅ Added proper error handling for empty vectors
- ✅ Implemented dynamic allocation for theatres
- ✅ Added comprehensive input validation

### **Code Quality:**
- Clean separation of concerns
- Proper encapsulation
- Consistent naming conventions
- Comprehensive error handling

## 🤝 Contributing

1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Test thoroughly
5. Submit a pull request

## 📄 License

This project is part of a learning exercise and is available for educational purposes.

## 🎓 Learning Outcomes

This project demonstrates:
- Object-Oriented Programming principles
- Design patterns (Singleton, Factory, Controller)
- C++ best practices
- Memory management
- Error handling
- Project structure and organization

---

**Happy Coding! 🎬🍿**
