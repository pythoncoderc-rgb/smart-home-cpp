#pragma once

#include <array>
#include <cstdint>
#include <string_view>

namespace smarthome {

enum class Device : std::uint8_t {
    Light = 0,
    Socket,
    Heating,
    AirConditioner,
    Alarm,
};

using State = std::uint8_t;

constexpr State mask(Device device) noexcept {
    return static_cast<State>(1u << static_cast<std::uint8_t>(device));
}

class SmartHome {
public:
    void enable(Device device) noexcept;
    void disable(Device device) noexcept;
    void toggle(Device device) noexcept;
    [[nodiscard]] bool isEnabled(Device device) const noexcept;
    [[nodiscard]] State state() const noexcept;
    void reset() noexcept;

    [[nodiscard]] static std::string_view name(Device device) noexcept;
    [[nodiscard]] static constexpr std::array<Device, 5> devices() noexcept {
        return {
            Device::Light,
            Device::Socket,
            Device::Heating,
            Device::AirConditioner,
            Device::Alarm,
        };
    }

private:
    State state_{0};
};

}  // namespace smarthome
