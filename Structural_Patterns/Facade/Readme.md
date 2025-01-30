# Zomato Facade Example

## Facade Design Pattern

The **Facade Design Pattern** is a structural pattern that provides a simplified interface to a complex system. It hides the complexity of the system behind a single interface, making it easier for the user to interact with.

In simple words, the Facade pattern is like a "wrapper" that combines multiple parts of a system into a single interface. Instead of interacting with each individual part, you only need to interact with the facade, which will handle the complexity internally.

## Zomato Example

In this example, we simulate the process of ordering food using Zomato. The `Zomato` class acts as the **Facade** for two different systems:

1. **Restaurant**: Prepares the food.
2. **Delivery Service**: Delivers the food to the user.

When the user places an order, they only need to interact with the `Zomato` class. The `Zomato` class will handle the interaction with the restaurant and delivery services internally.

The user doesn’t need to know how the food is prepared or delivered. They simply request an order, and Zomato takes care of everything.

## How It Works

1. The user places an order via Zomato.
2. Zomato calls the restaurant to prepare the food.
3. Once prepared, Zomato contacts the delivery service to deliver the food.
4. Zomato completes the order and informs the user.
