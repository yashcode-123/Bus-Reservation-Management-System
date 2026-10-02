# Bus-Reservation-Management-System
A C++ console-based Bus Reservation Management System using OOPS and file handling.
# 🚌 Bus Reservation Management System

A console-based **Bus Reservation Management System** developed in **C++** using Object-Oriented Programming concepts.

The system allows users to book bus seats, search reservations, modify passenger/seat details, cancel reservations, and store reservation data using file handling.

---

## 📌 Project Overview

The **Bus Reservation Management System** is designed to manage bus reservations in a simple and user-friendly console environment.

The project demonstrates important C++ and OOP concepts such as:

- Classes and Objects
- Encapsulation
- Inheritance
- Abstract Classes
- Pure Virtual Functions
- Runtime Polymorphism
- Arrays
- Functions
- File Handling

---

## ✨ Features

### 🚌 Bus Management
- Display available buses
- Display bus number
- Display route
- Display bus type
- Display total seats
- Supports different bus types

### 🎫 Reservation Management
- Book a reservation
- Generate a unique Reservation ID
- Select bus and seat number
- Store passenger name and age
- Prevent duplicate seat booking

### 🔍 Search & Display
- Search reservation using Reservation ID
- Display all reservations
- Display complete passenger and bus details

### ✏️ Modify Reservation
- Modify passenger name
- Modify passenger age
- Modify both name and age
- Modify seat number
- Prevent changing to an already booked seat
- Validate seat number

### ❌ Cancel Reservation
- Cancel reservation using Reservation ID
- Automatically remove the cancelled reservation
- Make the cancelled seat available again

### 💾 File Handling
- Reservation data is stored in `reservations.txt`
- Data is automatically saved after booking, modification, and cancellation
- Existing reservations are loaded when the program starts
- Reservations remain available even after closing and reopening the program

---

## 🧠 OOP Concepts Used

### 1. Class and Object

Classes are used to represent buses, reservations, and the reservation system.

### 2. Inheritance

Different bus types inherit common properties and functions from the `Bus` base class.

3. Abstract Class
Bus is an abstract class because it contains a pure virtual function:
virtual string getBusType() = 0;
4. Pure Virtual Function
The getBusType() function is implemented by derived bus classes according to their bus type.
5. Runtime Polymorphism
A base class pointer is used to refer to derived bus objects:
Bus *selectedBus;
This allows the program to work with different bus types through the common Bus interface.
6. Encapsulation
Data members of the Reservation class are kept private and accessed through member functions.

🏗️ Class Structure
                    Bus
                     |
          -----------------------
          |                     |
       ACBus                SleeperBus
          |
          |
    Reservation
          |
          |
  ReservationSystem
Main Classes
Bus
Stores common bus information such as:
*Bus Number
*Route
*Total Seats
It also contains the pure virtual function getBusType().
ACBus
Derived class representing an AC bus.
SleeperBus
Derived class representing a sleeper bus.
Reservation

Stores:
*Reservation ID
*Passenger Name
*Passenger Age
*Bus Number
*Route
*Bus Type
*Seat Number

ReservationSystem
Controls the complete reservation system, including:
*Booking
*Searching
*Displaying
*Modifying
*Cancelling
*File handling

💾 File Handling
The project uses a text file to store reservation records.
File used:
reservations.txt
Reservation data is written to the file after:
*New booking
*Passenger modification
*Seat modification
*Cancellation
When the program starts, previously stored reservations are loaded automatically.

📂 Project Structure
BUS RESERVATION MANAGEMENT SYSTEM/
│
├── main.cpp
├── reservations.txt
├── README.md
└── .gitignore
            

File                  ||                                Description
main.cpp              ||                            Main C++ source code
reservations.txt      ||                           Stores reservation data
README.md             ||                           Project documentation
.gitignore            ||                           Prevents unnecessary compiled files from being uploaded

⚙️ Requirements
To run this project, you need:
⇒C++ compiler
⇒GCC / MinGW
⇒VS Code or any C++ compatible IDE
⇒Windows PowerShell / Command Prompt

▶️ How to Run
1. Clone the Repository
git clone https://github.com/yashcode-123/Bus-Reservation-Management-System.git
2. Open the Project Folder
cd Bus-Reservation-Management-System
3. Compile the Program
g++ main.cpp -o busreservation.exe
4. Run the Program
PowerShell:
.\busreservation.exe
Command Prompt:
busreservation.exe

🎮 Main Operations
The system provides options for:
1. Display Available Buses
2. Book Reservation
3. Search Reservation
4. Display All Reservations
5. Modify Reservation
6. Cancel Reservation
7. Exit
   
🔐 Reservation ID
Each reservation receives a unique Reservation ID.
Example:
Reservation ID : 1001
The next reservation receives the next available ID.
🚌 Available Buses
The system currently contains two bus types:
Bus Type
Bus Number
Route
Total Seats
AC Bus
101
Miraj to Pune
40
Sleeper Bus
102
Miraj to Mumbai
30
🧪 Testing
The system has been tested for:
   •Successful reservation booking
   •Duplicate seat booking
   •Invalid seat numbers
   •Reservation searching
   •Displaying all reservations
   •Passenger modification
   •Seat modification
   •Invalid Reservation ID
   •Reservation cancellation
   •Reusing cancelled seats
   •Saving reservation data
   •Loading reservation data after restarting the program
   
🎯 Project Objectives
The main objectives of this project are:
  ➢To develop a basic bus reservation system using C++.
  ➢To apply Object-Oriented Programming concepts.
  ➢To demonstrate inheritance and runtime polymorphism.
  ➢To manage passenger and seat reservation details.
  ➢To implement file handling for permanent data storage.
  ➢To provide a simple console-based reservation interface.

  
🚀 Future Improvements
Possible future improvements include:
   ◉More bus routes
   ◉More bus types
   ◉Date and time-based reservations
   ◉Online payment integration
   ◉Graphical User Interface
   ◉Database integration
   ◉Admin login and management
   ◉Automatic seat layout

   
👨‍💻 Developer
  Yash
GitHub: https://github.com/yashcode-123
⁠
📜 License
This project is developed for educational and academic purposes.

