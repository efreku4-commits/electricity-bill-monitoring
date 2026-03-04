#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const string FILE_NAME = "appliances.txt";
const int MAX = 100;

struct Appliance {
    string name;
    double watts;
    double hours;
};

double kwhPerDay(Appliance a) {
    return (a.watts / 1000.0) * a.hours;
}

void saveToFile(Appliance arr[], int count) {
    ofstream out(FILE_NAME);
    if (!out) {
        cout << "Error saving file.\n";
        return;
    }

    for (int i = 0; i < count; i++) {
        out << arr[i].name << "|"
            << arr[i].watts << "|"
            << arr[i].hours << "\n";
    }

    out.close();
}

int main() {
    Appliance appliances[MAX];
    int count = 0;
    int choice;

    do {
        cout << "\n--- Electrical Load Monitoring ---\n";
        cout << "1. Add Appliance\n";
        cout << "2. Billing\n";
        cout << "3. Save\n";
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
            saveToFile(appliances, count);

            cout << "Appliance added and saved.\n";
        }
        else if (choice == 3) {
            saveToFile(appliances, count);
            cout << "Saved.\n";
        }
        else if (choice == 4) {
            saveToFile(appliances, count);
        }
        else {
            cout << "Feature not implemented yet.\n";
        }

    } while (choice != 4);

    cout << "Goodbye.\n";
    return 0;
}
