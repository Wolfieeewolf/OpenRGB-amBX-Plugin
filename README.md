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

1. Clone this repository into OpenRGB's `plugins` directory:
```bash
cd [OpenRGB Directory]/plugins
git clone https://github.com/Wolfieeewolf/OpenRGB-amBX-Plugin.git
```

2. Add the plugin to OpenRGB's CMake configuration:
```cmake
# In OpenRGB's root CMakeLists.txt
add_subdirectory(plugins/OpenRGB-amBX-Plugin)
```

3. Build OpenRGB as normal

## Usage

1. Enable the plugin in OpenRGB's settings
2. Configure device mappings:
   - Map amBX zones (North, East, South, West, Center) to your devices
   - Adjust effect settings like brightness and color balance
3. Launch your amBX-compatible game
4. The plugin will automatically intercept and redirect effects

## Configuration

### Device Mapping
- Each amBX zone can be mapped to one or more OpenRGB devices/zones
- Supported zones:
  - North
  - East
  - South
  - West
  - Center

### Effect Settings
- Brightness adjustment
- Color balance
- Effect speed/intensity
- Zone priority

## Development

### Project Structure
```
├── src/
│   ├── amBXController/     # amBX interface and effect capture
│   ├── effects/           # Effect processing and translation
│   ├── ui/               # Configuration interface
│   └── plugin/           # OpenRGB plugin integration
├── include/              # Public headers
├── deps/                # Dependencies
└── cmake/               # CMake configuration
```

### Key Components

1. **amBX Interface**
   - Initializes amBX library
   - Captures game effects
   - Manages amBX state

2. **Effect Processor**
   - Translates amBX effects to OpenRGB commands
   - Handles color space conversion
   - Manages device mapping

3. **Configuration UI**
   - Device mapping interface
   - Effect settings
   - Profile management

## Contributing

Contributions are welcome! Please feel free to submit pull requests or create issues for bugs and feature requests.

## License

This project is licensed under the GPL-2.0 License - see the LICENSE file for details.

## Acknowledgments

- OpenRGB team for the fantastic RGB control software
- Original amBX developers for the effect system
- All contributors and testers

## Support

For support, please:
1. Check the [Issues](https://github.com/Wolfieeewolf/OpenRGB-amBX-Plugin/issues) section
2. Join the OpenRGB Discord
3. Create a new issue if needed