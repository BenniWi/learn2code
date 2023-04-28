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

# Homework #2

---

## Testing Code with Github Actions

In [Part I: Continuous Integration, Delivery & Deployment](https://github.com/BenniWi/learn2code/blob/main/docs/slides_learn2code_1.md#continuous-integration-delivery--deployment) we got a rough overview about *continuous integration* and [Github Actions](https://github.com/features/actions).

Use your code from [Homework #1](https://github.com/BenniWi/learn2code/blob/main/docs/Homework_2-1.md), and create a *GitHub* workflow. For every *commit* on *main*:

- compile your code
- run the main executable
- run the *tests*

:point_up: You can start from scratch or you can take a look into the workflow files from [learn2code](https://github.com/BenniWi/learn2code/blob/main/.github/workflows/build_and_test_code.yml) and [learn2code_1_demo_project](https://github.com/BenniWi/learn2code_1_demo_project/blob/main/.github/workflows/build_and_test_code.yml) and simplify it.
