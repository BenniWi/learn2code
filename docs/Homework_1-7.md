---
marp: true
title: Programming 1 - Homework 7
author: Benjamin Wilking
theme: uncover
style: |
  section {
    font-size: 30px
  }
class: invert
paginate: false
---

# Homework #7

Requirements: *CMake*, *User Input*, *Basics in C #2*, *Functions*, *Libraries*, *TDD*

---

## Student Struct as Library

Modify the *student struct* from *homework 1-6* to create a **student struct library** and a **main** executable

---

## Testing the Student Struct

Exend the *student struct* project by adding some tests using **gtest**

- Add a ```<testfile>.cpp``` to the *test* subfolder.
- Extend the *CMakeLists.txt* to deal with **gtest** and *C++*
- Add some tests for the *student struct*
  - Create a [test fixture](https://developer.ibm.com/articles/au-googletestingframework/#understanding-test-fixtures)
  - Test the initialization of the student structure
  - Test adding some grades to the student structure
  - Test adding more grades than theoretically possible