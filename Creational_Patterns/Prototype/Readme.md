# Prototype Design Pattern in C++

## What is the Prototype Design Pattern?

The **Prototype Design Pattern** allows you to create new objects by copying an existing object. Instead of building objects from scratch, you can **clone** an existing object and make changes to it. This is helpful when object creation is expensive or time-consuming.

## How it works:
- **Prototype**: The original object that will be cloned.
- **Clone**: A method that allows copying the prototype object.
- **Concrete Prototypes**: Classes that implement the prototype and provide actual cloning.

## Why use it?
- When you need many similar objects, but creating them from scratch is inefficient.
- When you want to avoid complex creation logic and simply copy existing objects.

## Example: Building Houses

In this example, we create a base `House` class and then extend it to create specific types of houses like `FirstHouse`. These houses can be cloned to create new ones.

### Key Points:
- **Cloning an Object**: We create a new house by cloning an existing one, instead of building a new house from scratch.
- **Prototype Object**: The base house type that other houses clone.
