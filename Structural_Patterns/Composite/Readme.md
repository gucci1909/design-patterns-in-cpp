# Composite Design Pattern in C++

This project demonstrates the **Composite Design Pattern** using a simple structure of a city, colonies, and houses.

---

## What is the Composite Design Pattern?

The **Composite Design Pattern** is used to treat individual objects and groups of objects uniformly. It is ideal for hierarchical structures like a tree, where objects can contain other objects of the same type.

- **Key Idea**: Treat single objects (e.g., `House`) and composite objects (e.g., `Colony`) in the same way.
- **Why Use It?** It simplifies complex hierarchical structures by allowing clients to interact with individual and composite objects through the same interface.

---

## Structure in This Code

1. **House**: Represents a single unit (leaf of the hierarchy).
2. **Colony**: Represents a group of `House` objects or even other `Colony` objects.
3. **City**: The main colony that contains sub-colonies and houses.

Each of these components implements the same `HouseComponent` interface, allowing them to be treated the same way.

---

## How It Works

1. A **City** (`Colony`) contains multiple colonies and houses.
2. Each **Colony** can have:
   - Houses (`House` objects)
   - Sub-colonies (other `Colony` objects)
3. The `showDetailsOfCity` function is used to display the details of all colonies and houses.
