#include "smart_home.hpp"

#include <cassert>
#include <iostream>

int main() {
    using smarthome::Device;
    using smarthome::SmartHome;

    SmartHome home;
    assert(home.state() == 0);
    assert(!home.isEnabled(Device::Light));

    home.enable(Device::Light);
    assert(home.isEnabled(Device::Light));

    home.enable(Device::Alarm);
    assert(home.isEnabled(Device::Alarm));
    assert(home.isEnabled(Device::Light));

    home.disable(Device::Light);
    assert(!home.isEnabled(Device::Light));
    assert(home.isEnabled(Device::Alarm));

    home.toggle(Device::Heating);
    assert(home.isEnabled(Device::Heating));
    home.toggle(Device::Heating);
    assert(!home.isEnabled(Device::Heating));

    assert(SmartHome::name(Device::AirConditioner) == "Air Conditioner");

    home.reset();
    assert(home.state() == 0);

    std::cout << "smart_home_tests: PASS\n";
    return 0;
}
