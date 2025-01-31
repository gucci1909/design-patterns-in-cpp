# Memento Design Pattern

## What is the Memento Design Pattern?

The **Memento Design Pattern** is a way to save the state of an object so that you can restore it later. It allows you to store snapshots of an object's state at different points in time. This is very useful when you need features like undo/redo.

---

## Key Points:

1. **Why Use It?**  
   - To save the current state of an object.
   - To restore the saved state whenever needed.
   - Useful for implementing undo/redo functionality in applications.

2. **How Does It Work?**  
   - The **Memento** stores the state of the object (like a snapshot).
   - The **Originator** is the object whose state needs to be saved and restored.
   - The **Caretaker** manages the saved states and helps in retrieving them.

---

## Example Explanation:

This example demonstrates a simple **Text Editor**:  
- You can write text into the editor.
- At different points, the editor's state (text) is saved.
- Later, you can restore the editor to any saved state.

---

## Definition of the Memento Design Pattern:

The **Memento Design Pattern** provides a way to capture and save an object's current state so that it can be restored to that state later, without exposing its internal details.

---

## Why It’s Useful?

- Helps in maintaining history (e.g., undo/redo in editors).
- Keeps the internal details of the object private while providing a way to save and restore states.
- Simple to use and understand.
