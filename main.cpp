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
        cout << "3. Search Appliance\n";
        cout << "4. Billing\n";
        cout << "5. Exit\n";
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
        else if (choice == 4) {
            if (count == 0) {
                cout << "No appliances available.\n";
                continue;
            }

            double tariff;
            cout << "Tariff per kWh: ";
            cin >> tariff;

            double totalDay = 0;
            for (int i = 0; i < count; i++)
                totalDay += kwhPerDay(appliances[i]);

            double totalMonth = totalDay * 30;
            double costDay = totalDay * tariff;
            double costMonth = totalMonth * tariff;

            cout << fixed << setprecision(2);
            cout << "\nDaily Energy: " << totalDay << " kWh\n";
            cout << "Daily Cost:   " << costDay << "\n";
            cout << "30-Day Energy: " << totalMonth << " kWh\n";
            cout << "30-Day Cost:   " << costMonth << "\n";
        }
        else if (choice != 5) {
            cout << "Feature not implemented yet.\n";
        }

    } while (choice != 5);

    cout << "Goodbye.\n";
    return 0;
}