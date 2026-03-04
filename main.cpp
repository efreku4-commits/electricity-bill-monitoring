#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
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

void loadFromFile(Appliance arr[], int &count) {
    count = 0;
    ifstream in(FILE_NAME);
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

int main() {
    Appliance appliances[MAX];
    int count = 0;
    int choice;

    loadFromFile(appliances, count);

    cout << "Loaded appliances: " << count << "\n";

    do {
        cout << "\n--- Electrical Load Monitoring ---\n";
        cout << "1. Add Appliance\n";
        cout << "2. Save\n";
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
            saveToFile(appliances, count);

            cout << "Appliance added and saved.\n";
        }
        else if (choice == 2) {
            saveToFile(appliances, count);
            cout << "Saved.\n";
        }

    } while (choice != 3);

    saveToFile(appliances, count);
    cout << "Goodbye.\n";
    return 0;
}