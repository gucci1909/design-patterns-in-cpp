# State Design Pattern - Simple Example

## Overview

The **State Design Pattern** is a behavioral design pattern that allows an object to change its behavior when its internal state changes. It looks like the object is changing its class. This pattern helps in managing state-dependent behavior and keeps the code simple and flexible.

In this example, we are using a **Fan** with different states: **Off**, **Low**, and **High** speed. The fan’s behavior changes based on its current state. Instead of writing complex if-else statements, the state pattern lets us separate the behavior of each state into different classes.

## Key Concepts

- **Context:**  
  The class that holds the current state. In this example, it is the `FanContext` class, which knows what state the fan is in and delegates the behavior to the current state.

- **State Interface:**  
  An interface (or abstract class) that declares a method for each state. It ensures that all concrete states implement the same behavior. For example, the `FanState` interface has a `handle()` method.

- **Concrete States:**  
  These are the classes that implement the behavior of a particular state. In our case, these are the `OffState`, `LowState`, and `HighState` classes, which define what happens when the fan is in each state.

## How It Works

- The **fan** starts in the **OffState**.
- When you call `request()`, the current state handles the action and transitions to the next state.
- Each state knows how to transition to the next state. For example:
  - From **OffState** to **LowState**,
  - From **LowState** to **HighState**, and
  - From **HighState** to **OffState**.

## Benefits of Using the State Pattern

- **Simplifies State Transitions:** The state pattern makes it easier to manage complex state transitions. You don't need to write complicated logic for each state change.
- **Encapsulation:** Each state has its own class and is responsible for its behavior. This helps in organizing the code better.