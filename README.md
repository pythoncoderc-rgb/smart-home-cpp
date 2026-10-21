# Smart Home Controller — C++17

[![build-and-test](https://github.com/pythoncoderc-rgb/smart-home-cpp/actions/workflows/build.yml/badge.svg)](https://github.com/pythoncoderc-rgb/smart-home-cpp/actions/workflows/build.yml)

A compact C++17 console project that models five smart-home devices inside a single bitmask while keeping the state logic separate from the menu UI.

This repository began as a one-file bitmask prototype and was rebuilt into a focused C++17 utility with a reusable class, CMake, tests, and CI.

## Devices

- Light
- Power Socket
- Heating
- Air Conditioner
- Alarm

## What the project demonstrates

- `std::uint8_t` bitmask state storage
- `enum class` for type-safe device identifiers
- bitwise enable / disable / toggle operations
- separation of domain logic from console input/output
- input validation
- CMake targets for library, app, and tests
- CTest verification
- GitHub Actions on Windows and Linux

## Build

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --config Release
```

## Test

```bash
ctest --test-dir build -C Release --output-on-failure
```

## Run

Single-config generators such as Makefiles/Ninja:

```bash
./build/smart_home
```

Visual Studio multi-config build:

```text
build\\Release\\smart_home.exe
```

## Structure

```text
include/smart_home.hpp    public state API
src/smart_home.cpp        bitmask implementation
src/main.cpp              console UI
tests/                    core behavior tests
.github/workflows/        CI
```

## Scope

This is a focused console utility, not a real home-automation controller. It does not connect to physical devices or networks.

## License

MIT
