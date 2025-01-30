# Proxy Design Pattern Example

## What is Proxy Design Pattern?

The **Proxy Design Pattern** is a pattern that acts as a placeholder for another object. Instead of accessing the **real object** directly, the user interacts with the **proxy**. The proxy controls access to the real object and can perform actions like security checks, logging, or validation before allowing the real object to be used.

## About the Code

In this example, we simulate a **database access** scenario using the Proxy Design Pattern:

- The **RealDatabase** class represents a real database that fetches data.
- The **ProxyDatabase** class is used to control access to the **RealDatabase**. Before accessing the real database, it checks if the user is authorized (in this case, the username must be "admin").
- The **Client** (user) tries to access the database, but the proxy handles the authentication check before allowing access to the real database.

## How It Works:

1. The client requests to access the database via the **ProxyDatabase**.
2. The **ProxyDatabase** asks for a username.
3. If the username is "admin", access is granted, and the **RealDatabase** fetches the data.
4. If the username is anything else, access is denied.

