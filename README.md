# OpenRGB amBX Plugin

This OpenRGB plugin enables the use of amBX game effects with any OpenRGB-compatible device. It intercepts amBX lighting effects from games and redirects them to your RGB hardware through OpenRGB.

## Features

- Intercept amBX game effects without requiring physical amBX hardware
- Map amBX zones to any OpenRGB-compatible device
- Real-time effect translation with minimal latency
- Configurable mappings and effect adjustments

## Building

1. Clone this repository into OpenRGB's `plugins` directory
2. Build using CMake
3. Enable plugin in OpenRGB

## Requirements

- OpenRGB
- Windows 10/11
- Visual Studio 2019 or newer
- Qt 5.15
- CMake 3.15+