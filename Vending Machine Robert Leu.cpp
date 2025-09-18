#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Item {
public:
    string name;
    double price;
    int stock;

    Item(string n, double p, int s) {
        name = n;
        price = p;
        stock = s;
    }
};

class VendingMachine {
private:
    Item* items[5]; 
    int itemCount;

public:
    VendingMachine() {
        items[0] = new Item("Sprite", 2.50, 2);
        items[1] = new Item("Crisps", 2.50, 4);
        items[2] = new Item("Biscuits", 1.20, 3);
        items[3] = new Item("Fruits Juice", 2.20, 2);
        items[4] = new Item("Coffee", 2.50, 3);
        itemCount = 5;
    }

    void displayItems() {
        cout << left << setw(5) << "Code" 
             << setw(15) << "Item" 
             << setw(7) << "Price" 
             << "Stock" << endl;

        for (int i = 0; i < itemCount; i++) {
            cout << left << setw(5) << (i + 1)
                 << setw(15) << items[i]->name
                 << "£" << setw(6) << items[i]->price
                 << items[i]->stock << endl;
        }
    }

    void buyItem() {
        int choice;
        double money;

        cout << "\nEnter the number of the item you want to buy: ";
        cin >> choice;

        if (choice < 1 || choice > itemCount) {
            cout << "The selection made is not valid! Try again.\n";
            return;
        }

        Item* selected = items[choice - 1];

        if (selected->stock <= 0) {
            cout << "Sorry, " << selected->name << " is not in stock anymore!\n";
            return;
        }

        cout << "Insert the money: £";
        cin >> money;

        if (money < selected->price) {
            cout << "Not enough money! You need to insert £" << selected->price << endl;
            return;
        }

        double change = money - selected->price;
        cout << fixed << setprecision(2); 
        cout << "Loading " << selected->name << "...\n";
        cout << "Your change: £" << change << endl;

        selected->stock--; 

       
        if (selected->name == "Sprite") {
            cout << "Crisps go well with your Sprite, try it!\n";
        } else if (selected->name == "Tea" || selected->name == "Coffee") {
            cout << "Recommendation: Biscuits go well with your " << selected->name << "!\n";
        }
    }
};

int main() {
    VendingMachine machine;  
    int shopping = 1;

    cout << "Welcome to CodeLab Vending Machine!\n";

    while (shopping == 1) {
        cout << "\nAvailable items:\n";
        machine.displayItems();

        machine.buyItem();

        cout << "\nDo you want to buy something else? Press (1 for Yes, 0 for No): ";
        cin >> shopping;
    }

    cout << "Thank you for using the CodeLab vending machine!\n";
    return 0;
}