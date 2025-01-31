# Complaint Handling System - Chain of Responsibility Design Pattern

## What is the Chain of Responsibility Pattern?

The **Chain of Responsibility** is a design pattern used to handle requests or actions in a chain, where each handler in the chain gets a chance to process the request. If one handler cannot process the request, it passes the request to the next handler in the chain until the issue is resolved or the end of the chain is reached.

In this example, a user submits a complaint, and the request is passed through various handlers (Customer Support, Technical Support, and Manager) until it is handled by the right person.

## Components in this Example:

1. **ComplaintHandler** - This is the base class that provides a common structure for all handlers in the chain. It has a method to pass the complaint to the next handler.
  
2. **CustomerSupport** - This handler handles simple issues like general inquiries.
  
3. **TechnicalSupport** - This handler handles technical issues or problems.

4. **Manager** - This handler handles escalated complaints that need to be addressed by higher management.

## How It Works:

1. The user submits a complaint.
2. The complaint is first passed to the **Customer Support** team.
3. If the issue isn't resolved, it is passed to the **Technical Support** team.
4. If necessary, the issue is finally handled by the **Manager**.
5. If no handler can resolve the issue, the complaint remains unresolved.

## Why Use the Chain of Responsibility Pattern?

This pattern helps in:
- Simplifying the request-handling process by breaking it down into smaller, manageable steps.
- Allowing handlers to be added or modified without changing the structure of the entire system.
- Making the system more flexible and adaptable to future changes.

## Example:

- A user submits a "General Inquiry" -> Handled by **Customer Support**.
- A user submits a "Technical Problem" -> Handled by **Technical Support**.
- A user submits an "Escalated Complaint" -> Handled by **Manager**.

This pattern allows complaints to flow through different levels of support, ensuring the right person handles the issue.

## Conclusion:

The Chain of Responsibility pattern helps in organizing request handling, making systems more modular and scalable, as each handler only needs to focus on its specific role.
