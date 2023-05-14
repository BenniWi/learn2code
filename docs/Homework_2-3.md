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

# Homework #3

Requirements: *TDD*, *Inheritance*

---

## Spiders & Mammals

Create a small *C++* project using *CMake* and with our typical folder structure. This project should implement:

1. A base class called *Animal*
   - the only member of *Animal* is a variable for the number of feet
   - the only method of *Animal* returns the number of feet (a so called *getter*-method)
2. A child class called *Spider* (a spider has always 8 feet)
3. A child class called *Mammal* (a mammal can have a different amount of feet)
4. A short main to instantiate a *tarantula* and a *groundhog*.
   - print out the amount of feet for the *tarantula* and the *groundhog*.
5. Write two tests using *gtest* to verify that the number of feet is correctly initialized for spiders and mammals.
