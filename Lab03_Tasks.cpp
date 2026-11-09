Task 01:

cpp
#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
using namespace std;

const int MAX_ITEMS = 10;

struct InventoryItem {
    string code;
    string name;
    double cost;
    double sellingPrice;
};

int runningNumber = 3122;

InventoryItem insertItem() {
    InventoryItem item;
    cout << "Enter item name: ";
    cin >> ws;
    getline(cin, item.name);
    cout << "Enter item cost: ";
    cin >> item.cost;

    string prefix = item.name.substr(0, 3);
    for (char &c : prefix)
        c = toupper(c);
    item.code = prefix + "_" + to_string(++runningNumber);

    item.sellingPrice = item.cost * 1.40;
    return item;
}

void displayStock(const InventoryItem* items) {
    cout << "\n" << left
         << setw(12) << "Code"
         << setw(20) << "Name"
         << setw(12) << "Cost"
         << setw(12) << "Price" << endl;
    cout << string(56, '-') << endl;

    for (int i = 0; i < MAX_ITEMS; i++) {
        cout << left
             << setw(12) << items[i].code
             << setw(20) << items[i].name
             << setw(12) << fixed << setprecision(2) << items[i].cost
             << setw(12) << items[i].sellingPrice << endl;
    }
}

int main() {
    InventoryItem stock[MAX_ITEMS];
    for (int i = 0; i < MAX_ITEMS; i++) {
        cout << "\nItem " << i + 1 << ":\n";
        stock[i] = insertItem();
    }
    displayStock(stock);
    return 0;
}

Task 02:

cpp
#include <iostream>
using namespace std;

const double PRICE_PER_SQ_FOOT = 18.0;

struct FeetInches {
    int feet;
    int inches;
};

struct RoomDimension {
    FeetInches length;
    FeetInches width;
};

double toFeet(const FeetInches& f) {
    return f.feet + f.inches / 12.0;
}

int computeTheCarpetingCost(const RoomDimension& room) {
    double area = toFeet(room.length) * toFeet(room.width);
    return static_cast<int>(area * PRICE_PER_SQ_FOOT);
}

int main() {
    int numRooms;
    cout << "Enter number of rooms: ";
    cin >> numRooms;

    RoomDimension* rooms = new RoomDimension[numRooms];

    for (int i = 0; i < numRooms; i++) {
        cout << "\nRoom " << i + 1 << ":\n";
        cout << "Length (feet inches): ";
        cin >> rooms[i].length.feet >> rooms[i].length.inches;
        cout << "Width  (feet inches): ";
        cin >> rooms[i].width.feet >> rooms[i].width.inches;
    }

    int choice;
    do {
        cout << "\n===== MENU =====\n"
             << "1. Total carpeting cost of the house\n"
             << "2. Carpeting cost of each room\n"
             << "3. Exit\n"
             << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            int total = 0;
            for (int i = 0; i < numRooms; i++)
                total += computeTheCarpetingCost(rooms[i]);
            cout << "Total cost: Rs. " << total << endl;
        } else if (choice == 2) {
            for (int i = 0; i < numRooms; i++)
                cout << "Room " << i + 1 << ": Rs. "
                     << computeTheCarpetingCost(rooms[i]) << endl;
        } else if (choice != 3) {
            cout << "Invalid choice, try again." << endl;
        }
    } while (choice != 3);

    delete[] rooms;
    rooms = nullptr;
    return 0;
}
