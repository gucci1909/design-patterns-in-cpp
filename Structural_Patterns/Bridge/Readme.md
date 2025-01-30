# Bridge Design Pattern

This project demonstrates the **Bridge Design Pattern** using a house-building example.

---

## What is the Bridge Design Pattern?

The Bridge Design Pattern is a way to separate the **abstraction** (what to do) from its **implementation** (how to do it). It allows both to change independently without affecting each other.

This is useful when you want to use different versions or types of functionality without duplicating code.

---

## Example in This Code

- **Abstraction**: `House` represents a high-level blueprint for building a house. It defines what a house needs (land, walls, gate) but does not decide how to build it.
- **Implementation**: `HouseCompany` provides the actual construction details. We have two implementations:
  - `AHouse`: High-quality construction.
  - `BHouse`: Low-quality construction.
- **Bridge**: `HouseCompany` acts as a bridge between the `House` class and the different types of house implementations (`AHouse` and `BHouse`).

### Key Classes

1. **HouseCompany**: The interface that defines the steps to build a house (e.g., land, walls, gate).
2. **AHouse & BHouse**: Concrete implementations of `HouseCompany` that provide details for high-quality and low-quality houses.
3. **House**: The abstract class representing a generic house. It uses the `HouseCompany` bridge to construct houses.
4. **NewHouse**: A specific type of house that implements `constructHouse`.

---

## How It Works

1. **Create a Bridge**: The `HouseCompany` interface connects the `House` abstraction with specific implementations (`AHouse` and `BHouse`).
2. **Construct Houses**:
   - `AHouse` builds houses with high-quality materials.
   - `BHouse` builds houses with low-quality materials.
3. The `NewHouse` class constructs a house using any implementation of `HouseCompany`.

---
