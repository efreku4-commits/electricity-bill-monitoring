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
        cout << "4. Exit\n";
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
            for (int i = 0; i < count; i++) {
                cout << appliances[i].name << " | "
                     << appliances[i].watts << "W | "
                     << appliances[i].hours << " hrs | "
                     << kwhPerDay(appliances[i]) << " kWh/day\n";
            }
        }
        else if (choice == 3) {
            if (count == 0) {
                cout << "No appliances.\n";
                continue;
            }

            string search;
            cout << "Search name: ";
            cin.ignore();
            getline(cin, search);

            bool found = false;

            for (int i = 0; i < count; i++) {
                if (appliances[i].name.find(search) != string::npos) {
                    cout << appliances[i].name << " | "
                         << appliances[i].watts << "W | "
                         << appliances[i].hours << " hrs | "
                         << kwhPerDay(appliances[i]) << " kWh/day\n";
                    found = true;
                }
            }

            if (!found)
                cout << "No match found.\n";
        }
        else if (choice != 4) {
            cout << "Invalid choice.\n";
        }

    } while (choice != 4);

    cout << "Goodbye.\n";
    return 0;
}