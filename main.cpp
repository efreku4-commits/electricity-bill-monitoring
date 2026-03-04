#include <iostream>
using namespace std;

const int MAX = 100;

struct Appliance {
    string name;
    double watts;
    double hours;
};

int main() {
    Appliance appliances[MAX];#include <iostream>
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
        cout << "1. Add Appliance\n";
        cout << "2. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            if (count >= MAX) {
                cout << "Limit reached.\n";
                continue;
            }

            cout << "Name: ";
            cin.ignore();
            getline(cin, appliances[count].name);

            cout << "Watts: ";
            cin >> appliances[count].watts;

            cout << "Hours per day: ";
            cin >> appliances[count].hours;

            count++;
            cout << "Appliance added.\n";
        }
        else if (choice != 2) {
            cout << "Invalid choice.\n";
        }

    } while (choice != 2);

    cout << "Goodbye.\n";
    return 0;
}
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
