# Strategy Design Pattern in Payment System

## Introduction

The **Strategy Design Pattern** is a behavioral design pattern that allows an algorithm or action to be selected at runtime. Instead of hardcoding different behaviors into a class, it lets you change the behavior dynamically by changing the strategy.

In this example, we demonstrate how the Strategy Pattern can be used to select and perform different payment methods (like Credit Card and PayTM) at runtime.

## How It Works

- **Payment Strategy**: We define an abstract `Payment` class, which has a method `pay()`. The concrete classes `CreditCard` and `PayTM` implement this method to perform the payment in their own way.
- **Helper Class**: The `Helper` class works as a context and can set the payment strategy (either `CreditCard` or `PayTM`) and execute the payment using the selected strategy.
- **Switching Strategies**: You can switch between the strategies dynamically by calling `setStrategy()` method of the `Helper` class.

## Key Benefits of the Strategy Pattern

1. **Flexibility**: You can change the behavior (payment method) at runtime. For example, switch between Credit Card or PayTM without changing the rest of the code.
2. **Separation of Concerns**: The different payment methods (CreditCard, PayTM) are encapsulated in separate classes, making the code cleaner and easier to maintain.
3. **Extensibility**: Adding new payment methods is easy (e.g., adding a new payment method like Bitcoin) without modifying existing code.

## When to Use the Strategy Pattern

- When you have multiple algorithms or behaviors and you want to make them interchangeable.
- When you want to change the behavior of an object at runtime.
- When you want to avoid large, complex conditional statements or if-else chains.
