```cpp
#include <iostream>
#include <cstdint>

using namespace std;

// Device bit positions
const uint8_t LIGHT        = 1 << 0;
const uint8_t SOCKET       = 1 << 1;
const uint8_t HEATING      = 1 << 2;
const uint8_t AC           = 1 << 3;
const uint8_t ALARM        = 1 << 4;

void showStatus(uint8_t state) {
    cout << "\n--- Smart Home Status ---\n";
    cout << "Light: "        << ((state & LIGHT)   ? "ON" : "OFF") << endl;
    cout << "Socket: "       << ((state & SOCKET)  ? "ON" : "OFF") << endl;
    cout << "Heating: "      << ((state & HEATING) ? "ON" : "OFF") << endl;
    cout << "AC: "           << ((state & AC)      ? "ON" : "OFF") << endl;
    cout << "Alarm: "        << ((state & ALARM)   ? "ON" : "OFF") << endl;
}

int main() {
    uint8_t homeState = 0;
    int choice;

    do {
        cout << "\nSmart Home Menu\n";
        cout << "1 - Toggle Light\n";
        cout << "2 - Toggle Socket\n";
        cout << "3 - Toggle Heating\n";
        cout << "4 - Toggle AC\n";
        cout << "5 - Toggle Alarm\n";
        cout << "6 - Show Status\n";
        cout << "0 - Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: homeState ^= LIGHT; break;
            case 2: homeState ^= SOCKET; break;
            case 3: homeState ^= HEATING; break;
            case 4: homeState ^= AC; break;
            case 5: homeState ^= ALARM; break;
            case 6: showStatus(homeState); break;
        }

    } while (choice != 0);

    return 0;
}
