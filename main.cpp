#include <iostream>
using namespace std;

int main() {
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