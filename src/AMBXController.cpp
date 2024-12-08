#include "AMBXController.h"
#include <cmath>

AMBXController::AMBXController()
    : ambx(std::make_unique<AMBXNativeWrapper>())
    , initialized(false)
    , current_mode(AMBX_MODE_DIRECT)
    , current_speed(0)
    , current_brightness(100)
{
    initialized = InitializeAMBX();
}

AMBXController::~AMBXController() = default;

bool AMBXController::InitializeAMBX()
{
    return ambx->Initialize();
}

void AMBXController::SetZoneColor(AMBXNativeWrapper::Direction direction, RGBColor color)
{
    if (!initialized)
        return;

    AMBXNativeWrapper::Color ambx_color;
    ambx_color.r = static_cast<unsigned char>((color.r * current_brightness) / 100);
    ambx_color.g = static_cast<unsigned char>((color.g * current_brightness) / 100);
    ambx_color.b = static_cast<unsigned char>((color.b * current_brightness) / 100);

    ambx->SetLightColor(direction, ambx_color);
}

void AMBXController::SetColors(std::vector<RGBColor>& colors)
{
    if(!initialized || colors.empty())
        return;

    current_colors = colors;

    if(current_mode == AMBX_MODE_DIRECT || current_mode == AMBX_MODE_STATIC)
    {
        AMBXNativeWrapper::Direction directions[] = {
            AMBXNativeWrapper::Direction::North,
            AMBXNativeWrapper::Direction::East,
            AMBXNativeWrapper::Direction::South,
            AMBXNativeWrapper::Direction::West,
            AMBXNativeWrapper::Direction::Center
        };

        for(std::size_t i = 0; i < colors.size() && i < 5; i++)
        {
            SetZoneColor(directions[i], colors[i]);
        }
    }
    else
    {
        UpdateEffects();
    }
}

void AMBXController::UpdateEffects()
{
    switch(current_mode)
    {
        case AMBX_MODE_BREATHING:
            SetBreathingEffect();
            break;
        case AMBX_MODE_SPECTRUM:
            SetSpectrumEffect();
            break;
        case AMBX_MODE_WAVE:
            SetWaveEffect();
            break;
    }
}

void AMBXController::SetMode(int mode, int speed, int brightness)
{
    current_mode = mode;
    current_speed = speed;
    current_brightness = brightness;
}

std::string AMBXController::GetDeviceLocation()
{
    return "AMBX";
}

std::string AMBXController::GetName()
{
    return "AMBX Lighting System";
}

std::string AMBXController::GetSerial()
{
    return "";
}

bool AMBXController::GetInitialized()
{
    return initialized;
}

void AMBXController::SetupZones()
{
}