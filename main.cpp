#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <iomanip>

using namespace std;

// Class to represent a single item in the store
class Item {
private:
    string name;
    double price;
public:
    Item() : name(""), price(0.0) {}
    Item(string n, double p) : name(n), price(p) {}

    string getName() const { return name; }
    double getPrice() const { return price; }
};

// Class to represent an item in the shopping cart (with quantity)
class CartItem {
private:
    Item item;
    int quantity;
public:
    CartItem(Item i, int q) : item(i), quantity(q) {}

    Item getItem() const { return item; }
    int getQuantity() const { return quantity; }
    double getSubTotal() const { return item.getPrice() * quantity; }
};

// Class to manage the shopping process
class ShoppingSystem {
private:
    vector<Item> inventory;
    vector<CartItem> cart;

    void initializeInventory() {
        // Add some predefined items to the inventory
        inventory.push_back(Item("Laptop", 999.99));
        inventory.push_back(Item("Mobile", 499.50));
        inventory.push_back(Item("Keyboard", 75.00));
        inventory.push_back(Item("Mouse", 25.00));
    }

    void displayInventory() {
        cout << "\n--- Available Products ---" << endl;
        cout << "ID | Name          | Price" << endl;
        cout << "---------------------------" << endl;
        for (size_t i = 0; i < inventory.size(); ++i) {
            cout << left << setw(3) << i + 1 << " | "
                 << left << setw(13) << inventory[i].getName() << " | $"
                 << fixed << setprecision(2) << inventory[i].getPrice() << endl;
        }
        cout << "---------------------------" << endl;
    }

    void addToCart() {
        int itemId, quantity;
        displayInventory();
        cout << "Enter the ID of the item you want to add (0 to cancel): ";
        cin >> itemId;

        if (itemId == 0) return;

        if (itemId >= 1 && itemId <= static_cast<int>(inventory.size())) {
            cout << "Enter quantity: ";
            cin >> quantity;
            if (quantity > 0) {
                cart.push_back(CartItem(inventory[itemId - 1], quantity));
                cout << quantity << "x " << inventory[itemId - 1].getName() << " added to cart." << endl;
            } else {
                cout << "Quantity must be positive." << endl;
            }
        } else {
            cout << "Invalid item ID." << endl;
        }
    }

    void viewCart() {
        cout << "\n--- Your Shopping Cart ---" << endl;
        if (cart.empty()) {
            cout << "Cart is empty." << endl;
            return;
        }

        double total = 0;
        cout << "Quantity | Item Name     | Subtotal" << endl;
        cout << "-----------------------------------" << endl;
        for (const auto& item : cart) {
            cout << left << setw(8) << item.getQuantity() << " | "
                 << left << setw(13) << item.getItem().getName() << " | $"
                 << fixed << setprecision(2) << item.getSubTotal() << endl;
            total += item.getSubTotal();
        }
        cout << "-----------------------------------" << endl;
        cout << "Total Amount: $" << fixed << setprecision(2) << total << endl;
    }

    void checkout() {
        viewCart();
        if (!cart.empty()) {
            cout << "Please enter 'y' to confirm your checkout, or press any other key to cancel." << endl;
            char choice;
            cin >> choice;
            switch(choice) {
                case 'y':
                    cout << "\nThank you for shopping with us!" << endl;
                    cart.clear(); // Empty the cart after checkout
                    break;
                default:
                    cout << "Payment canceled." << endl;
                    break;
            }

        }
    }

public:
    ShoppingSystem() {
        initializeInventory();
    }

    void run() {
        int choice;
        do {
            cout << "\n========== C++ Shopping System Menu ==========" << endl;
            cout << "1. View Products" << endl;
            cout << "2. Add Item to Cart" << endl;
            cout << "3. View Cart" << endl;
            cout << "4. Checkout" << endl;
            cout << "5. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    displayInventory();
                    break;
                case 2:
                    addToCart();
                    break;
                case 3:
                    viewCart();
                    break;
                case 4:
                    checkout();
                    break;
                case 5:
                    cout << "Goodbye!" << endl;
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        } while (choice != 5);
    }
};

int main() {
    ShoppingSystem app;
    app.run();
    return 0;
}
