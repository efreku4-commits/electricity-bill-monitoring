#include <iostream>
#include <iomanip>
using namespace std;

const int MAX = 100;

struct Appliance {
    string name;
    double watts;
    double hours;
};

double kwhPerDay(Appliance a) {
    return (a.watts / 1000.0) * a.hours;
}

int main() {
    Appliance appliances[MAX];
    int count = 0;
    int choice;

    do {
        cout << "\n--- Electrical Load Monitoring ---\n";
        cout << "1. Add Appliance\n";
        cout << "2. View Appliances\n";
        cout << "3. Exit\n";
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
        else if (choice == 2) {
            if (count == 0) {
                cout << "No appliances.\n";
                continue;
            }

            cout << fixed << setprecision(2);
            cout << left << setw(4) << "#"
                 << setw(20) << "Name"
                 << setw(10) << "Watts"
                 << setw(10) << "Hours"
                 << setw(10) << "kWh/day" << "\n";

            for (int i = 0; i < count; i++) {
                cout << left << setw(4) << i + 1
                     << setw(20) << appliances[i].name
                     << setw(10) << appliances[i].watts
                     << setw(10) << appliances[i].hours
                     << setw(10) << kwhPerDay(appliances[i]) << "\n";
            }
        }
        else if (choice != 3) {
            cout << "Invalid choice.\n";
        }

    } while (choice != 3);

    cout << "Goodbye.\n";
    return 0;
}