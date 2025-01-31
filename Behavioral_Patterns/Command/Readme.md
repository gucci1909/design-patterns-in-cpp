# Command Design Pattern - House Automation

## Overview
The **Command Design Pattern** is a behavioral design pattern that turns a request into a stand-alone object. This object contains all the details of the request, which can then be passed to an invoker. The invoker will decide when to execute the command, allowing for decoupling between the sender (client) and the receiver (the object that performs the action).

In simpler terms, you give a "command" to an invoker, and the invoker decides what action (business logic) needs to be performed. It's like a remote control that receives commands (like "Turn on the light") and passes them to the appropriate device (like a light) to perform the action.

### Example
Imagine a **house automation system** where you can control lights. You have a **remote control** that can send commands like "turn on the light" or "turn off the light". The **light** itself is the receiver of these commands, while the **remote control** acts as the invoker.

### Components of the Command Pattern
- **Command**: An abstract interface for all commands.
- **Concrete Command**: A class that implements the command interface and defines the action to be taken.
- **Invoker**: The object that receives the command and executes it.
- **Receiver**: The object that performs the actual work (e.g., turning the light on or off).

## Key Benefits
- **Decouples sender and receiver**: The sender doesn’t need to know anything about the receiver’s implementation.
- **Supports undo/redo**: Commands can be stored and reversed if needed.
- **Flexible and extensible**: New commands can easily be added without modifying existing code.