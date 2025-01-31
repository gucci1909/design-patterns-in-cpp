# Iterator Design Pattern Example

## What is Iterator Design Pattern?

The **Iterator Design Pattern** is a pattern that allows you to access elements of a collection (like a list or an array) one by one without exposing the internal structure of the collection. This means you can traverse a collection without needing to know how it is implemented behind the scenes.

## How does it work?

- **Iterator**: An interface that defines two main methods:
  - `hasNext()`: Checks if there are more elements in the collection.
  - `next()`: Returns the next element in the collection.

- **ConcreteIterator**: This class implements the `Iterator` interface and works with the collection to retrieve each element.

- **ConcreteAggregate**: This class holds the collection of items and has a method to create an iterator. The iterator will allow you to traverse through the collection one item at a time.

## Why use Iterator Pattern?

The main benefit of using the Iterator Design Pattern is that it hides the internal structure of the collection from the outside world. You can access the elements of the collection without needing to know how it’s stored or managed.

## Example

In this example, we have an array of numbers, and instead of accessing them directly, we use an iterator to go through each number one by one, printing them in order.

The Iterator pattern helps keep the code neat, clean, and flexible.
