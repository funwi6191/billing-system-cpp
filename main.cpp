#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class Item{
public:
    string name;
    double price;
    int quantity;

    Item(string n, double p, int q){
        name = n;
        price = p;
        quantity = q;

    }
    double getSubtotal(){
        return price * quantity;
    }
};

class Bill{
private:
    vector<Item> items;
    double taxRate = 0.15;

public:
    void addItem(string name, double price, int quantity){
        Item newItem(name, price, quantity);
        items.push_back(newItem);
        cout << "Added: " << name << " x " << quantity<<endl;
    }

    double calculateTotal(){
        double subtotal = 0;
        for(int i = 0; i < items.size(); i++){
            subtotal += items[i].getSubtotal();
        }
        double tax = subtotal * taxRate;
        return subtotal + tax;
    }
    void printReceipt(){
        cout << "\n========== RECEIPT ==========\n";
        cout << left << setw(15) << "Item"
             << right << setw(8) << "Qty"
             << setw(10) << "Price"
             << setw(12) << "Subtotal" << "\n";
        cout << "--------------------------------------------------\n";

        double subtotal = 0;
        for (int i = 0; i < items.size(); i++) {
            Item& it = items[i];
            cout << left << setw(15) << it.name
                 << right << setw(8) << it.quantity
                 << setw(10) << fixed << setprecision(2) << it.price
                 << setw(12) << it.getSubtotal() << "\n";
            subtotal += it.getSubtotal();
        }

        double tax = subtotal * taxRate;
        double total = subtotal + tax;

        cout << "--------------------------------------------------\n";
        cout << right << setw(33) << "Subtotal: " << fixed << setprecision(2) << subtotal << "\n";
        cout << right << setw(33) << "Tax (15%): " << tax << "\n";
        cout << right << setw(33) << "TOTAL: " << total << "\n";
        cout << "=====================================\n";

    }
};

int main()
{
    Bill myBill;
    int choice;

    do{
        cout << "\n ===== Billing System ===== \n";
        cout << "1. Add Item"<<endl;
        cout << "2. View Receipt"<<endl;
        cout << "3. Exit"<<endl;
        cout << "Enter choice: ";
        cin >> choice;

        if(choice == 1){
            string name;
            double price;
            int quantity;

            cout << "Item Name: ";
            cin >> name;
            cout << "Price: ";
            cin >> price;
            cout << "Quantity: ";
            cin >> quantity;

            myBill.addItem(name, price, quantity);
        }else if(choice == 2){
            myBill.printReceipt();
        }else if(choice == 3){
            cout << "GoodBye!"<<endl;
        }else{
            cout << "Invalid choice, Try Again"<<endl;
        }


    }while(choice != 3);

    return 0;
}
