# Observer Design Pattern

## What is the Observer Design Pattern?

The Observer design pattern is a behavioral design pattern. It defines a one-to-many relationship between objects. In simple terms, when one object (called the _subject_) changes its state, all its dependent objects (called _observers_) are notified and updated automatically.

This pattern helps in scenarios where we need to keep multiple objects updated with the changes happening in another object without tightly coupling them.

### Example in this Code:

- **Station** acts as the _subject_ (observable). It holds the temperature and notifies its _observers_ when the temperature changes.
- **DisplayDevice** acts as the _observer_. It listens to the temperature changes from the _Station_ and updates its display accordingly.

## Key Concepts:

- **Subject (Station):** This class holds the main state (temperature in this case). It maintains a list of observers that need to be notified when its state changes.
- **Observer (DisplayDevice):** This class is designed to listen for state changes in the subject. When the state of the subject changes (like the temperature), the observer is notified, and it updates accordingly.

## How It Works:

1. You create a `Station` (subject) and two `DisplayDevice` (observers).
2. The `Station` holds the current temperature and notifies the `DisplayDevice` objects whenever the temperature changes.
3. Each `DisplayDevice` updates its display when it is notified of a temperature change.

## Benefits:

- **Loose Coupling:** The observer doesn't need to know anything about the subject other than how to get updates from it. This keeps the objects loosely connected.
- **Automatic Updates:** All registered observers are automatically updated when the subject’s state changes.

This pattern is useful when you have a scenario where many objects depend on a single subject, and you want to notify them of any changes automatically.
