# SimpleShoppingAPp

# C++ Console Shopping System – README

## Overview

This C++ Console Shopping System is a simple command-line application that simulates a basic online shopping experience. The program allows users to view available products, add items to a shopping cart, review their cart contents, and complete a checkout process. It demonstrates object-oriented programming (OOP) principles such as encapsulation, class design, and separation of responsibilities.

The system is entirely console-based and uses standard C++ libraries. It is designed as an educational example to showcase how a small-scale shopping application can be structured using classes and STL containers.

---

## Features

* View available products
* Add items to a shopping cart with quantity
* Display cart contents with subtotals
* Calculate and display total amount
* Checkout confirmation system
* Menu-driven interface
* Input validation for item selection and quantity

---

## Program Structure

The application is organized into three main classes:

### 1. `Item`

Represents a single product in the store.

**Attributes:**

* `name` (string) – Product name
* `price` (double) – Product price

**Key Methods:**

* `getName()` – Returns the product name
* `getPrice()` – Returns the product price

This class encapsulates product details and ensures controlled access through getter methods.

---

### 2. `CartItem`

Represents an item in the shopping cart along with its quantity.

**Attributes:**

* `item` (Item) – The product being added
* `quantity` (int) – Number of units selected

**Key Methods:**

* `getItem()` – Returns the product
* `getQuantity()` – Returns the quantity
* `getSubTotal()` – Calculates price × quantity

This class separates cart logic from inventory logic and provides subtotal calculations.

---

### 3. `ShoppingSystem`

Controls the overall flow of the application.

**Private Members:**

* `inventory` (vector<Item>) – Stores available products
* `cart` (vector<CartItem>) – Stores selected items

**Private Methods:**

* `initializeInventory()` – Preloads products
* `displayInventory()` – Shows available products
* `addToCart()` – Adds selected items to cart
* `viewCart()` – Displays cart contents and total
* `checkout()` – Confirms and clears cart

**Public Methods:**

* `run()` – Main application loop

The constructor automatically initializes the inventory when a `ShoppingSystem` object is created.

---

## How It Works

1. The program starts in `main()` by creating a `ShoppingSystem` object.
2. The `run()` method displays a menu in a loop.
3. Users select options by entering a number (1–5).
4. Items are stored in vectors using the C++ Standard Template Library.
5. The program continues running until the user selects Exit.

---

## Compilation & Execution

To compile using g++:

```
g++ shopping_system.cpp -o shopping_system
```

To run:

```
./shopping_system
```

(Windows users may run `shopping_system.exe`.)

---

## Concepts Demonstrated

* Object-Oriented Programming
* Encapsulation
* Class Composition
* Vectors (STL containers)
* Input/Output formatting (`iomanip`)
* Menu-driven program design

---

## Limitations

* No persistent storage (data resets when program ends)
* No input type validation (e.g., non-numeric input may cause errors)
* Duplicate items are not merged in cart
* No removal of individual cart items
* No real payment processing

---

## Future Improvements

* Add file-based persistence
* Improve input validation
* Merge duplicate cart items automatically
* Implement item removal functionality
* Add tax and discount calculations
* Convert to a GUI-based application

---

## Conclusion

This C++ Shopping System is a beginner-friendly example that demonstrates how to build a structured, menu-driven application using object-oriented design. It provides a solid foundation for expanding into more advanced e-commerce simulations or full-scale applications.
