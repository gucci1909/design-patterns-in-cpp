# Builder Design Pattern Example - Building a House

## Overview

This project demonstrates the **Builder Design Pattern** using a simple example of building a **House**.

### What is the Builder Design Pattern?

The **Builder Design Pattern** is a creational pattern used to construct complex objects step by step. It separates the construction process from the actual object representation. This allows for creating different representations of the same type of object. 

Instead of creating an object all at once, we build it part by part. This pattern is useful when an object needs to be created with many optional and mandatory components.

---

## Key Points

1. **House Class**:
   - Represents the final product.
   - It has attributes like `gate`, `rooms`, `windows`, and `doors`.

2. **HouseBuilder Interface**:
   - Provides the blueprint for building a house.
   - Contains methods like:
     - `buildGate()`
     - `buildRooms()`
     - `buildWindows()`
     - `buildDoors()`

3. **FirstHouseBuilder & SecondHouseBuilder**:
   - These are the actual builders that implement the `HouseBuilder` interface.
   - Each builder sets the specific values for the house attributes.

4. **Main Function**:
   - The client creates the house by calling the builder's methods (`buildGate`, `buildRooms`, etc.).
   - The final `House` object is retrieved using the `getHouse()` method.

---

## How It Works

- Each builder (`FirstHouseBuilder` and `SecondHouseBuilder`) constructs a different type of house.
- The client (in `main()`) chooses which builder to use and calls the necessary methods to set the house attributes.
- Once the construction is complete, the final house object is retrieved and displayed.

---

## Why Use the Builder Design Pattern?

- **Step-by-Step Construction**: Helps build objects in parts rather than all at once.
- **Customization**: You can skip steps (e.g., only building rooms and doors without windows).
- **Flexible Design**: Makes it easy to create different types of objects (e.g., a wooden house vs. a brick house).

---
