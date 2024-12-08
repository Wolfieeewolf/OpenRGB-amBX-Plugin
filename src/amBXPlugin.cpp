#include "amBXPlugin.h"
#include <QLayout>

static const char* PLUGIN_NAME = "amBX Support";
static const char* PLUGIN_DESCRIPTION = "Redirects amBX game effects to OpenRGB devices";
static const char* PLUGIN_VERSION = "1.0.0";

amBXPlugin::~amBXPlugin()
{
    UnLoad();
}

OpenRGBPluginInfo amBXPlugin::GetPluginInfo()
{
    OpenRGBPluginInfo info;
    info.Name = PLUGIN_NAME;
    info.Description = PLUGIN_DESCRIPTION;
    info.Version = PLUGIN_VERSION;
    info.Type = OPENRGB_PLUGIN_TYPE_PROTOCOL;
    return info;
}

unsigned int amBXPlugin::GetPluginAPIVersion()
{
    return OPENRGB_PLUGIN_API_VERSION;
}

void amBXPlugin::Load(bool dark_theme, ResourceManager* resource_manager_ptr)
{
    resource_manager = resource_manager_ptr;
    effect_timer.setInterval(16);
    connect(&effect_timer, &QTimer::timeout, this, &amBXPlugin::OnEffectUpdate);
    effect_timer.start();
    running = true;
}

void amBXPlugin::UnLoad()
{
    if(running)
    {
        effect_timer.stop();
        running = false;
    }
}

void amBXPlugin::OnEffectUpdate()
{
    // Poll and update effects
}

QWidget* amBXPlugin::GetConfigurationWidget()
{
    QWidget* config = new QWidget();
    return config;
}