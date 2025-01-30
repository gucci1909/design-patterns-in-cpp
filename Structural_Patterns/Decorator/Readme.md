# Decorator Design Pattern Example: House Features

## What is the Decorator Design Pattern?

The **Decorator Design Pattern** is used to add new features or behaviors to an object **dynamically**, without changing its base implementation. This pattern wraps an object with layers of additional functionality, allowing for flexible and reusable code.

---

### How It Works in Simple Words

- Start with a **basic object** (e.g., a "Basic House").
- Use **decorators** (wrappers) to add new features to the object.
- Each decorator adds a specific feature or functionality to the object (e.g., a garden or a pool).

---

### Example in This Code

We have:
1. **Basic House**: A simple house with no extra features.
2. **House Decorators**: Special wrappers that add features like:
   - **Garden**: Adds a garden to the house.
   - **Pool**: Adds a pool to the house.

You can stack these decorators (e.g., a basic house can have a garden and a pool). This makes it flexible to build objects with custom combinations of features.

---

## Difference Between Bridge and Decorator Patterns

| **Aspect**                | **Decorator**                                                                                                    | **Bridge**                                                                                                 |
|---------------------------|------------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------|
| **Purpose**               | Add extra features dynamically to an object without modifying its base class.                                   | Decouple an abstraction (e.g., house type) from its implementation (e.g., material quality).              |
| **Relationship**          | Focuses on extending the behavior of an individual object.                                                      | Separates abstraction (logic) from implementation (details).                                              |
| **How It Works**          | Wrap an object with layers of features (decorators).                                                            | Uses composition to allow abstraction and implementation to evolve independently.                         |
| **Example**               | Adding features like a garden or a pool to a house dynamically.                                                 | A `LuxuryHouse` and an `AffordableHouse` using different materials like `Wood` or `Brick`.               |
| **When to Use**           | When you want to dynamically add or modify behavior for specific objects.                                        | When you want to create flexibility between high-level logic and implementation details.                  |
| **Structure**             | Adds features as layers around a single object in the same hierarchy.                                           | Splits hierarchies into two: abstraction and implementation.                                              |

---

## Why Use the Decorator Pattern?

- **Flexibility**: Easily add or remove features without modifying the original object.
- **Reusability**: Decorators can be reused across different objects.
- **Separation of Concerns**: Each decorator has a specific responsibility, making code easier to understand.

---

This example demonstrates how to build a flexible house object by adding features dynamically. You can create combinations like:
- A basic house
- A house with a garden
- A house with both a garden and a pool
