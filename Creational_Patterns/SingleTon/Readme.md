# Singleton Design Pattern Example

## Overview
This is a simple example demonstrating the **Singleton design pattern** using C++. In this case, we are creating a `HouseBuilder` class, and only one instance of the class should exist, even if multiple threads are trying to access it at the same time.

## Singleton Pattern
The **Singleton pattern** ensures that a class has only one instance and provides a global point of access to it. This pattern is particularly useful when you want to control access to a shared resource, like a configuration or a database connection, without creating multiple instances.

### Key Points:
- **Single Instance:** Only one instance of the class is created.
- **Global Access:** The instance is accessed globally via a static method.
- **Thread-Safety:** In multithreaded environments, we need to ensure that only one thread can create the instance. This is achieved using a `mutex` to lock the instance creation process.

## How It Works:
1. We have multiple threads (`t1` and `t2`) calling the `getInstance()` method.
2. The `mutex` ensures that only one thread can create the `HouseBuilder` instance.
3. Once the instance is created, other threads will use the same instance and continue with the task (building the house).
