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
<!-- markdownlint-disable MD033 MD025 -->

# Homework #1

Requirements: *TDD*

---

## Testing the Student Struct

Extend the *student struct* project from [homework 7 in part I](https://github.com/BenniWi/learn2code/blob/main/docs/Homework_1-7.md) by adding some tests using **gtest**

- Add a ```<testfile>.cpp``` to the *test* subfolder.
- Extend the *CMakeLists.txt* to deal with **gtest** and *C++*
- Add some tests for the *student struct*
  - Create a [test fixture](https://developer.ibm.com/articles/au-googletestingframework/#understanding-test-fixtures) (and find out, what it is)
  - Test the initialization of the student structure
  - Test adding some grades to the student structure
  - Test adding more grades than theoretically possible

(You can find the code for this solution in the [code for home homework 7 in part I](https://github.com/BenniWi/learn2code/tree/main/code/part_1/homework_1-7))

---

:point_up: If you are working on a *C++* file and you want to include a *C*-header, you have to use ```extern C```

```C
extern "C"
{  // include all C headers
#include "my_c_header.h"
}
```
