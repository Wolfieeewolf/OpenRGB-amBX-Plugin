# OpenRGB amBX Plugin

This OpenRGB plugin enables the use of amBX game effects with any OpenRGB-compatible device. It intercepts amBX lighting effects from games and redirects them to your RGB hardware through OpenRGB.

## Features

- Intercept amBX game effects without requiring physical amBX hardware
- Map amBX zones to any OpenRGB-compatible device
- Real-time effect translation with minimal latency
- Configurable mappings and effect adjustments
- Runs directly inside OpenRGB - no separate program needed

## Requirements

- OpenRGB (latest version recommended)
- Windows operating system (tested on Windows 10/11)
- Visual Studio 2019 or newer (for building)
- Qt 5.15 or newer
- CMake 3.15 or newer

## Building

1. Clone this repository into OpenRGB's `plugins` directory
2. Add to OpenRGB's CMake configuration
3. Build OpenRGB as normal

## Usage

1. Enable the plugin in OpenRGB's settings
2. Configure device mappings
3. Launch your amBX-compatible game
4. The plugin will automatically intercept and redirect effects

## Development

Contributions are welcome! Please feel free to submit pull requests or create issues for bugs and feature requests.

## License

This project is licensed under the GPL-2.0 License - see the LICENSE file for details.