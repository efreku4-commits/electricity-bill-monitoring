#include <iostream>
using namespace std;

const int MAX = 100;

struct Appliance {
    string name;
    double watts;
    double hours;
};

int main() {
    Appliance appliances[MAX];
    int count = 0;
    int choice;

    do {
        cout << "\n--- Electrical Load Monitoring ---\n";
        cout << "1. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice != 1)
            cout << "Invalid choice.\n";

    } while (choice != 1);

    cout << "Goodbye.\n";
    return 0;
}
