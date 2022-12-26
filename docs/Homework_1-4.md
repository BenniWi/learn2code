---
marp: true
title: Programming 1 - Homework 2
author: Benjamin Wilking
theme: uncover
style: |
  section {
    font-size: 30px
  }
class: invert
paginate: false
---

# Homework #4

Requirements: *CMake*, *Basics in C #2*

---

## Grades Average

Write a program in **C** to calculate the average (rational number) of multiple grades (natural numbers). Output the result on the command line with one digit after the decimal point. Use an *array* for the grades and a *for* loop to calculate the average. Check that all grades are valid and that the number of grades is at least 1;

Example:
```
Values: 1, 2, 4, 1, 3
Average: 2.2  
```

---

## Leap Year Checker
Write a program in **C** to check if a given Year is a leap year (Schaltjahr). Create a corresponding output on the command line.
Example:
```
Year: 2020
2020 is a leap year!
```
:point_up: https://en.wikipedia.org/wiki/Leap_year

---

## Student Struct

1. Re-use your student structure defined in the former exercise. It was:
   - Define a new structure based type named student. An object of type student consist of:
2. Instantiate a new student
3. Create an output to the commandline to print the student structure. 
   1. The name shall be printed in magenta and shall be underlined.
   2. Print all grades using a *for loop*, where grades >= 4.0 shall be printed in red.

:point_up: to format your output you can use [ANSI escape sequences](https://stackoverflow.com/a/33206814)

## Student Struct CMake

1. Re-use your student structure code from above
2. Create a fully working *CMake* project for your student struct code
