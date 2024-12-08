#pragma once

#include "RGBController.h"
#include "AMBXNativeWrapper.h"
#include <memory>

#define AMBX_MODE_DIRECT      0
#define AMBX_MODE_STATIC      1
#define AMBX_MODE_BREATHING   2
#define AMBX_MODE_SPECTRUM    3
#define AMBX_MODE_WAVE        4

class AMBXController
{
public:
    AMBXController();
    ~AMBXController();

    std::string     GetDeviceLocation();
    std::string     GetName();
    std::string     GetSerial();
    bool            GetInitialized();
    
    void            SetColors(std::vector<RGBColor>& colors);
    void            SetupZones();
    void            SetMode(int mode, int speed, int brightness);

private:
    bool            InitializeAMBX();
    void            SetZoneColor(AMBXNativeWrapper::Direction direction, RGBColor color);
    void            UpdateEffects();
    
    void            SetBreathingEffect();
    void            SetSpectrumEffect();
    void            SetWaveEffect();

    std::unique_ptr<AMBXNativeWrapper> ambx;
    bool            initialized;
    int             current_mode;
    int             current_speed;
    int             current_brightness;
    std::vector<RGBColor> current_colors;
};