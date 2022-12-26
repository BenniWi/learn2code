---
marp: true
title: Programming 1 - Homework 3
author: Benjamin Wilking
theme: uncover
style: |
  section {
    font-size: 30px
  }
class: invert
paginate: false
---

# Homework #3

Requirements: *Basics in C #1*

---

## Student Struct

1. Define a new structure based type named student. An object of type student consist of:
   1. matriculation number
   2. name
   3. list of grades (array)
   4. Use *defines* to specify the maximum name lenght and the maximum mount of grades
2. Instantiate a new student
3. Create an output to the commandline to print the student name and matriculation number. 

---

## Pointer Swap

Write a **C** program where you 
- initialize two *int*s
- define two pointers pointing to these *int*s
- use the two pointers to swap the content of the two *int*s

Example:
```
int x = 5; int y = 4;
printf(“x: %d, y: %d“, x, y); // x: 5, y: 4
// pointers are swaped 
printf(“x: %d, y: %d“, x, y); // x: 4, y: 5 
```

