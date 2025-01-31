# Template Method Design Pattern

## Definition:
The **Template Method Design Pattern** is a behavioral design pattern that defines the **skeleton of an algorithm** in a method, called the **template method**, allowing subclasses to implement certain steps of the algorithm without changing its structure.

## Concept:
- The **template method** defines a basic structure for a process in a **base class**.
- Specific steps of the process (that might change) are implemented in the **subclasses**.
- The base class ensures the process stays the same, but the details can differ.

## Why Use the Template Method Pattern?
- **Code Reusability**: The general algorithm is shared across subclasses, but specific steps are customizable.
- **Consistency**: The base class controls the overall flow of the algorithm, ensuring that all subclasses follow the same process.
- **Flexibility**: Subclasses can modify specific steps of the process without changing the structure defined in the base class.

