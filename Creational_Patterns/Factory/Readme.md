# Factory Design Pattern Example - Building a House

## Overview

This project demonstrates the **Factory Design Pattern** using a simple example of building a **House**.

### What is the Factory Design Pattern?

The **Factory Design Pattern** is a creational pattern that provides a way to create objects without specifying the exact class of the object that will be created. Instead of creating objects directly, you use a factory class to create them for you. 

In simple terms, it helps decide which type of object to create based on certain conditions, like choosing which house to build based on user input.

---
   - The factory returns the object, and the client calls the `build()` method to show which type of house is being built.
---

## Why Use the Factory Design Pattern?

- **Simplifies Object Creation**: You don't need to know the exact class (main logic, use behind the User Input/Output Operations) or how to create a house. The factory does that for you.
- **Keeps Code Clean**: The logic for creating different types of houses is centralized in the factory, making it easier to manage and add new house types in the future.
- **Flexibility**: You can easily add new house types by creating new classes and updating the factory method.

---

