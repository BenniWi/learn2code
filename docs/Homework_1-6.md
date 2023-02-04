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

<style scoped>
  section{
  font-size: 20px;
  }
</style>

# Homework #6

Requirements: *CMake*, *User Input*, *Basics in C #2*, *Functions*, *Const Correctness*

In Homework 1-4 we implemented the student struct. We want to re-use this struct here and extend it a bit.

1. Create a dedicated *include* and *src* folder
2. Create a CMake project
3. Define the student struct in a dedicated header file.
4. Declare three functions to interact with the student struct: *init, print, add_grade*
   - use a pointer to the student struct as interface
   - take care of const correctness
5. Define the functions in a dedicated source file
6. Implement a *main*. Therein: add two students, initialize them, add some grades, and print them to the console
