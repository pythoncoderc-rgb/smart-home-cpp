#include "smart_home.hpp"

namespace smarthome {

void SmartHome::enable(Device device) noexcept {
    state_ = static_cast<State>(state_ | mask(device));
}

void SmartHome::disable(Device device) noexcept {
    state_ = static_cast<State>(state_ & static_cast<State>(~mask(device)));
}

void SmartHome::toggle(Device device) noexcept {
    state_ = static_cast<State>(state_ ^ mask(device));
}

bool SmartHome::isEnabled(Device device) const noexcept {
    return (state_ & mask(device)) != 0;
}

State SmartHome::state() const noexcept {
    return state_;
}

void SmartHome::reset() noexcept {
    state_ = 0;
}

std::string_view SmartHome::name(Device device) noexcept {
    switch (device) {
        case Device::Light: return "Light";
        case Device::Socket: return "Power Socket";
        case Device::Heating: return "Heating";
        case Device::AirConditioner: return "Air Conditioner";
        case Device::Alarm: return "Alarm";
    }
    return "Unknown";
}

}  // namespace smarthome
