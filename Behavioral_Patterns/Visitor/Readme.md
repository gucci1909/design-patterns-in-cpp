# Visitor Design Pattern - Simple Explanation

## What is the Visitor Design Pattern?

The **Visitor Design Pattern** is a way to add new operations or functionalities to an object structure without changing the classes of the objects. Instead of modifying the objects directly, you define a visitor class that performs the operation.

### Key Concepts:

1. **Visitor**: A class that defines the operations to be performed on the elements. It has a `visit` method for each element type.
2. **Element**: A class that represents an object in the structure. It contains an `accept()` method that allows a visitor to perform an operation.
3. **Concrete Visitor**: A subclass of the visitor that implements specific operations for each element type.
4. **Concrete Element**: An object that accepts the visitor and calls its corresponding `visit` method.

### How It Works:

- The **Shape** class has a method `accept()`, which takes a visitor object.
- **Circle** and **Rectangle** are concrete elements that implement the `accept()` method to allow the visitor to perform operations on them.
- **DrawVisitor** is a concrete visitor that performs a specific operation, like drawing shapes.

### Advantages:

- **Open/Closed Principle**: You can add new operations without changing the element classes.
- **Separation of Concerns**: The operations are separated from the objects on which they operate.
- **Extensibility**: Easily add new operations by adding more visitors.

### When to Use:
Use the **Visitor Pattern** when:
- You have a set of related objects and want to perform operations on them without modifying the objects themselves.
- You need to add new operations without changing existing code.
