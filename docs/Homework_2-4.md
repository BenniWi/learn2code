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

# Homework #4

Requirements: *TDD*, *Inheritance*, *Polymorphism*, *static*

---

## Spiders & Mammals II

Re-use the code from the [Homework_2-3](https://github.com/BenniWi/learn2code/blob/main/docs/Homework_2-3.md) and extend the *Spiders & Mammals* code by:

1. Add members for *speed* and *position* to the base class. Extend the constructor of *Spider* and *Mammal* to receive a *speed* parameter.
2. Add a method *move* which receives the *time* it moved as parameter
   - Make it pure virtual in the base class
   - For both, *Spider* and *Mammal*, implement the *move* method. Let the method make some "noise" as text on the command-line and calculate the new position after moving for the given time.
3. Add a static function *die* which prints some text on the command-line

---

<!-- markdownlint-disable-next-line MD029 -->
4. Implement the virtual destructor of *Animal*. The destructor should call the *die* method;
<!-- markdownlint-disable-next-line MD029 -->
5. Create a small for loop in the main to move an instance of *Spider* and *Mammal* for several times
<!-- markdownlint-disable-next-line MD029 -->
6. Implement a test using a test-fixture to check if the *move* method is working as expected
