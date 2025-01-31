# Mediator Design Pattern

## What is the Mediator Design Pattern?

The **Mediator Design Pattern** is used to simplify communication between multiple objects or components. Instead of these objects talking directly to each other, they communicate through a central object called the **Mediator**. This helps to reduce the complexity of connections between objects.

### Key Points:
- The **Mediator** acts as a central hub for communication.
- Participants (objects) do not talk directly to each other but instead communicate through the mediator.
- This makes the system easier to maintain and reduces dependencies between objects.

## Example in This Code:
We have a simple **chatroom** example:
1. The **ChatRoom** is the mediator that handles all messages between users.
2. The **User** objects (like Suresh, Mahesh, and Vikram) send their messages to the chatroom.
3. The chatroom then displays the messages, acting as the central point of communication.

### How it Works:
- Users (Suresh, Mahesh, and Vikram) send messages using the chatroom.
- The chatroom takes care of showing the messages, so the users don't need to communicate with each other directly.

### Benefits of This Pattern:
- **Simplifies communication**: All messages go through a central controller.
- **Decouples objects**: Users are not dependent on each other for communication.
- **Easy to manage**: Adding or removing participants is simple as they only rely on the mediator.
