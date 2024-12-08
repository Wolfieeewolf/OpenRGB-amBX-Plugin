#pragma once

#include <QWidget>
#include <QTimer>
#include "OpenRGBPluginInterface.h"

class amBXPlugin : public QObject, public OpenRGBPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.OpenRGB.amBXPlugin" FILE "amBXPlugin.json")
    Q_INTERFACES(OpenRGBPluginInterface)

public:
    ~amBXPlugin();

    OpenRGBPluginInfo   GetPluginInfo() override;
    unsigned int        GetPluginAPIVersion() override;
    void                Load(bool dark_theme, ResourceManager* resource_manager_ptr) override;
    QWidget*            GetConfigurationWidget() override;
    void                UnLoad() override;

private slots:
    void OnEffectUpdate();

private:
    ResourceManager*    resource_manager;
    QTimer             effect_timer;
    bool               running;
};