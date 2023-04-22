---
marp: true
title: Programming 2 - Homework 1
author: Benjamin Wilking
theme: uncover
style: |
  section {
    font-size: 30px
  }
class: invert
paginate: false
---

# Homework #1

Requirements: *TDD*

---

## Testing the Student Struct

Extend the *student struct* project from [homework 7 in part I](https://github.com/BenniWi/learn2code/blob/main/docs/Homework_1-7.md) by adding some tests using **gtest**

- Add a ```<testfile>.cpp``` to the *test* subfolder.
- Extend the *CMakeLists.txt* to deal with **gtest** and *C++*
- Add some tests for the *student struct*
  - Create a [test fixture](https://developer.ibm.com/articles/au-googletestingframework/#understanding-test-fixtures)
  - Test the initialization of the student structure
  - Test adding some grades to the student structure
  - Test adding more grades than theoretically possible

(You can find the code for this solution in the [code for home homework 7 in part I](https://github.com/BenniWi/learn2code/tree/main/code/part_1/homework_1-7))
