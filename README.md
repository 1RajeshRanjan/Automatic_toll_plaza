# Automatic_toll_plaza
Project Overview

This project is an implementation of an Automatic Toll Plaza System based on the Producer–Consumer problem from Operating Systems. The main goal is to simulate how vehicle data can be generated, stored temporarily, and processed efficiently using synchronization techniques.

The project demonstrates how Operating System concepts like shared buffer, semaphores, mutex locks, and multithreading can be applied to a real-world scenario such as a toll plaza.

Problem Statement

In a toll plaza, a large number of vehicles may arrive within a short period of time. If vehicle data is not handled properly, it can lead to system overload, data loss, or delays in toll processing.

This project solves the problem by using the Producer–Consumer model, where:

Vehicles act as producers generating data

The toll system acts as a consumer processing the data

A shared buffer is used to manage data flow safely

System Modules
1. Producer Module

Simulates vehicle arrival at the toll plaza

Generates vehicle data

Inserts data into the shared buffer

2. Buffer Management Module

Acts as temporary storage between producer and consumer

Has limited size

Prevents buffer overflow and underflow using synchronization

3. Consumer Module

Retrieves vehicle data from the buffer

Processes toll information

Displays processing status

Technologies Used

Programming Languages: C, C++, Python

Operating System Concepts:

Producer–Consumer Problem

Semaphores

Mutex Locks

Multithreading

Libraries & Tools:

pthread / threading

Version Control:

Git & GitHub

Flow of the System

Vehicle arrives at the toll plaza

Producer generates vehicle data

Data is stored in a shared buffer

Consumer retrieves data from buffer

Toll is calculated and processed

Processing status is displayed

Features

Efficient handling of multiple vehicles

Proper synchronization to avoid race conditions

Prevention of data loss and system overload

Real-world simulation of OS concepts

How to Run

Clone the repository

Compile and run the source code using a suitable compiler or interpreter

Observe producer and consumer operations in the output

Future Enhancements

Support for multiple toll booths

Real-time online payment integration

AI-based traffic monitoring and control

Database integration for vehicle records

Author

Rajesh Ranjan
GitHub: https://github.com/1RajeshRanjan

License

This project is created for academic and learning purposes.
