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

# Homework #5

Requirements: *CMake*, *User Input*, *Basics in C #2*

---

## Decimal to Binary Converter

Create an executable to convert a decimal number to a binary number

- read in a decimal number from the user on the command prompt
- convert the number into a binary number. 
- the binary number is represented as an *unsigned long long*
- us a **while** loop for your calculation
- print the binary number to the console

---

## Print Triangles

Create an executable to print two triangles to the console

- read in the height for the triangles form the user on the command prompt
- use two **for** loops to create two prints 
  ```sh
  Enter height: 5
  *
  **
  ***
  ****
  *****

      *
     ***
    *****
   *******
  *********
  ```

---

## Create a CMake Project

Create a *single* CMake project to create two independent executables for the **binary converter** and the **triangle printer** from above.
