#include "smart_home.hpp"

#include <iostream>
#include <limits>

namespace {

void showStatus(const smarthome::SmartHome& home) {
    std::cout << "\n--- Smart Home Status ---\n";
    for (const auto device : smarthome::SmartHome::devices()) {
        std::cout << smarthome::SmartHome::name(device) << ": "
                  << (home.isEnabled(device) ? "ON" : "OFF") << '\n';
    }
}

bool readChoice(int& choice) {
    if (std::cin >> choice) {
        return true;
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return false;
}

}  // namespace

int main() {
    smarthome::SmartHome home;
    const auto devices = smarthome::SmartHome::devices();

    while (true) {
        std::cout << "\nSmart Home Menu\n"
                  << "1 - Toggle Light\n"
                  << "2 - Toggle Socket\n"
                  << "3 - Toggle Heating\n"
                  << "4 - Toggle AC\n"
                  << "5 - Toggle Alarm\n"
                  << "6 - Show Status\n"
                  << "7 - Reset all devices\n"
                  << "0 - Exit\n"
                  << "Choice: ";

        int choice = -1;
        if (!readChoice(choice)) {
            std::cout << "Invalid input. Enter a number from 0 to 7.\n";
            continue;
        }

        if (choice == 0) {
            break;
        }
        if (choice >= 1 && choice <= 5) {
            home.toggle(devices.at(static_cast<std::size_t>(choice - 1)));
        } else if (choice == 6) {
            showStatus(home);
        } else if (choice == 7) {
            home.reset();
            std::cout << "All devices are OFF.\n";
        } else {
            std::cout << "Unknown option.\n";
        }
    }

    return 0;
}
