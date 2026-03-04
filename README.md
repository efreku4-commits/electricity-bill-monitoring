# Electrical Load Monitoring & Billing System (C++)

A simple console-based C++ program for monitoring electrical appliance usage and estimating electricity bills.

This project allows users to register appliances, calculate energy consumption, estimate electricity costs, and store results using basic text file handling.

---

## Features

- Add new appliances (name, watts, hours per day)
- View registered appliances
- Search appliances by name
- Calculate daily and 30-day electricity costs
- Save appliance data to file
- Load saved appliances automatically on startup
- Export billing summaries to a separate file

---

## How It Works

Each appliance stores:

- Name
- Power rating in watts
- Usage hours per day

Energy consumption is calculated using:

Energy (kWh) = (Watts / 1000) × Hours

Billing is calculated based on a user-provided tariff per kWh.

---

## Files Used

The program works with two text files:

- appliances.txt  
  Stores all registered appliances in the format:  
  name|watts|hours

- billing_summary.txt  
  Stores saved billing reports.

If these files do not exist, they are created automatically when the program runs.

---

## How to Compile and Run

Using g++:

g++ main.cpp -o monitor  
./monitor

Or compile and run using any C++ IDE (CodeBlocks, Visual Studio, etc.).

---

## Project Structure

main.cpp  
appliances.txt  
billing_summary.txt

---

## Notes

- Maximum number of appliances: 100
- Usage hours must be between 0 and 24
- Tariff must be greater than 0
- Data is stored using standard C++ file handling (fstream)
- The program is written using simple C++ constructs without advanced libraries

---

## Purpose

This project demonstrates:

- Struct usage
- Arrays
- Functions
- File handling
- Basic billing calculations
- Menu-driven program design

---

## Author

Emmanuel

Electrical Load Monitoring & Billing System  
Student C++ Project
