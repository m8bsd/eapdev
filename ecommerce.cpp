#include <iostream>
#include <vector>
using namespace std;

struct Product {
    int id;
    string name;
    double price;
};

struct CartItem {
    Product product;
    int quantity;
};

void showProducts(const vector<Product>& products) {
    cout << "\nAvailable Products:\n";
    for (const auto& p : products) {
        cout << p.id << ". " << p.name << " - $" << p.price << endl;
    }
}

void showCart(const vector<CartItem>& cart) {
    if (cart.empty()) {
        cout << "\nYour cart is empty.\n";
        return;
    }
    cout << "\nYour Cart:\n";
    double total = 0;
    for (const auto& item : cart) {
        double itemTotal = item.product.price * item.quantity;
        cout << item.product.name << " x" << item.quantity << " - $" << itemTotal << endl;
        total += itemTotal;
    }
    cout << "Total: $" << total << endl;
}

void addToCart(vector<CartItem>& cart, const vector<Product>& products) {
    int productId, quantity;
    cout << "Enter product ID to add: ";
    cin >> productId;
    cout << "Enter quantity: ";
    cin >> quantity;

    if (quantity <= 0) {
        cout << "Quantity must be greater than 0.\n";
        return;
    }

    bool found = false;
    for (const auto& p : products) {
        if (p.id == productId) {
            found = true;
            bool inCart = false;
            for (auto& item : cart) {
                if (item.product.id == productId) {
                    item.quantity += quantity; // combine quantities
                    inCart = true;
                    break;
                }
            }
            if (!inCart) {
                cart.push_back({p, quantity});
            }
            cout << "Added " << p.name << " x" << quantity << " to cart.\n";
            break;
        }
    }
    if (!found) cout << "Product not found.\n";
}

void removeFromCart(vector<CartItem>& cart) {
    if (cart.empty()) {
        cout << "Your cart is empty.\n";
        return;
    }

    int productId;
    cout << "Enter product ID to remove: ";
    cin >> productId;

    for (size_t i = 0; i < cart.size(); ++i) {
        if (cart[i].product.id == productId) {
            cart.erase(cart.begin() + i);
            cout << "Product removed from cart.\n";
            return;
        }
    }
    cout << "Product not found in cart.\n";
}

int main() {
    vector<Product> products = {
        {1, "Laptop", 800.0},
        {2, "Smartphone", 500.0},
        {3, "Headphones", 50.0},
        {4, "Keyboard", 30.0},
        {5, "Mouse", 20.0}
    };

    vector<CartItem> cart;
    int choice;

    do {
        cout << "\n===== E-Commerce App =====\n";
        cout << "1. Show Products\n";
        cout << "2. Add to Cart\n";
        cout << "3. Remove from Cart\n";
        cout << "4. View Cart\n";
        cout << "5. Checkout\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                showProducts(products);
                break;
            case 2:
                addToCart(cart, products);
                break;
            case 3:
                removeFromCart(cart);
                break;
            case 4:
                showCart(cart);
                break;
            case 5:
                showCart(cart);
                cout << "Thank you for your purchase!\n";
                cart.clear();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
