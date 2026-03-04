#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const string APPLIANCE_FILE = "appliances.txt";
const string BILLING_FILE   = "billing_summary.txt";
const int MAX = 100;

struct Appliance {
    string name;
    double watts;
    double hours;
};

// ---------- Utility ----------
double kwhPerDay(Appliance a) {
    return (a.watts / 1000.0) * a.hours;
}

void saveToFile(Appliance arr[], int count) {
    ofstream out(APPLIANCE_FILE);
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

void loadFromFile(Appliance arr[], int &count) {
    count = 0;
    ifstream in(APPLIANCE_FILE);
    if (!in) return;

    string line;
    while (getline(in, line)) {
        int p1 = line.find("|");
        int p2 = line.find("|", p1 + 1);
        if (p1 == -1 || p2 == -1) continue;

        arr[count].name = line.substr(0, p1);
        arr[count].watts = stod(line.substr(p1 + 1, p2 - p1 - 1));
        arr[count].hours = stod(line.substr(p2 + 1));
        count++;
        if (count >= MAX) break;
    }

    in.close();
}

// ---------- Features ----------
void addAppliance(Appliance arr[], int &count) {
    if (count >= MAX) {
        cout << "Limit reached.\n";
        return;
    }

    cout << "Name: ";
    cin.ignore();
    getline(cin, arr[count].name);

    cout << "Watts: ";
    cin >> arr[count].watts;

    cout << "Hours per day: ";
    cin >> arr[count].hours;

    count++;
    saveToFile(arr, count);

    cout << "Appliance added.\n";
}

void viewAppliances(Appliance arr[], int count) {
    if (count == 0) {
        cout << "No appliances.\n";
        return;
    }

    cout << fixed << setprecision(2);
    cout << left << setw(4) << "#"
         << setw(20) << "Name"
         << setw(10) << "Watts"
         << setw(10) << "Hours"
         << setw(10) << "kWh/day" << "\n";

    for (int i = 0; i < count; i++) {
        cout << left << setw(4) << i + 1
             << setw(20) << arr[i].name
             << setw(10) << arr[i].watts
             << setw(10) << arr[i].hours
             << setw(10) << kwhPerDay(arr[i]) << "\n";
    }
}

void searchAppliance(Appliance arr[], int count) {
    if (count == 0) {
        cout << "No appliances.\n";
        return;
    }

    string search;
    cout << "Search name: ";
    cin.ignore();
    getline(cin, search);

    bool found = false;
    for (int i = 0; i < count; i++) {
        if (arr[i].name.find(search) != string::npos) {
            cout << arr[i].name << " | "
                 << arr[i].watts << "W | "
                 << arr[i].hours << " hrs | "
                 << kwhPerDay(arr[i]) << " kWh/day\n";
            found = true;
        }
    }

    if (!found)
        cout << "No match found.\n";
}

void billing(Appliance arr[], int count) {
    if (count == 0) {
        cout << "No appliances available.\n";
        return;
    }

    double tariff;
    cout << "Tariff per kWh: ";
    cin >> tariff;

    double totalDay = 0;
    for (int i = 0; i < count; i++)
        totalDay += kwhPerDay(arr[i]);

    double totalMonth = totalDay * 30;
    double costDay = totalDay * tariff;
    double costMonth = totalMonth * tariff;

    cout << fixed << setprecision(2);
    cout << "\nDaily Energy: " << totalDay << " kWh\n";
    cout << "Daily Cost:   " << costDay << "\n";
    cout << "30-Day Energy: " << totalMonth << " kWh\n";
    cout << "30-Day Cost:   " << costMonth << "\n";

    cout << "Save summary? (y/n): ";
    char c;
    cin >> c;

    if (c == 'y' || c == 'Y') {
        ofstream out(BILLING_FILE, ios::app);
        out << "------ BILLING SUMMARY ------\n";
        out << "Tariff: " << tariff << "\n";
        out << "Daily kWh: " << totalDay << "\n";
        out << "Daily cost: " << costDay << "\n";
        out << "30-day kWh: " << totalMonth << "\n";
        out << "30-day cost: " << costMonth << "\n";
        out << "-----------------------------\n\n";
        out.close();

        cout << "Saved.\n";
    }
}

// ---------- Main ----------
int main() {
    Appliance appliances[MAX];
    int count = 0;

    loadFromFile(appliances, count);

    int choice;

    do {
        cout << "\n--- Electrical Load Monitoring ---\n";
        cout << "1. Add Appliance\n";
        cout << "2. View Appliances\n";
        cout << "3. Search Appliance\n";
        cout << "4. Billing\n";
        cout << "5. Save\n";
        cout << "6. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addAppliance(appliances, count); break;
            case 2: viewAppliances(appliances, count); break;
            case 3: searchAppliance(appliances, count); break;
            case 4: billing(appliances, count); break;
            case 5: saveToFile(appliances, count); cout << "Saved.\n"; break;
            case 6: saveToFile(appliances, count); cout << "Goodbye.\n"; break;
            default: cout << "Invalid choice.\n";
        }

    } while (choice != 6);

    return 0;
}