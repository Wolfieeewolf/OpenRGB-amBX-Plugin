#include "AMBXNativeWrapper.h"
#include <Windows.h>

#pragma managed

#include "dependencies/amBXLib/amBXLib/amBXLib.h"
#include "dependencies/amBXLib/amBXLib/amBXLight.h"
#include <msclr/marshal_cppstd.h>

using namespace System;

private ref class ManagedImpl
{
public:
    amBXLib::amBX^ ambx;
    array<amBXLib::amBXLight^>^ lights;

    ManagedImpl() : ambx(nullptr)
    {
        lights = gcnew array<amBXLib::amBXLight^>(5);
    }

    ~ManagedImpl()
    {
        if (ambx != nullptr)
            delete ambx;
    }
};

class AMBXNativeWrapper::Impl
{
private:
    gcroot<ManagedImpl^> managed;

public:
    Impl() : managed(gcnew ManagedImpl()) {}

    bool Initialize()
    {
        try
        {
            managed->ambx = gcnew amBXLib::amBX(1, 0, "OpenRGB", "1.0");

            for (int i = 0; i < 5; i++)
            {
                managed->lights[i] = managed->ambx->CreateLight(
                    static_cast<amBXLib::CompassDirection>(i), 
                    amBXLib::RelativeHeight::Middle);
            }

            return true;
        }
        catch (Exception^ ex)
        {
            return false;
        }
    }

    bool SetLightColor(AMBXNativeWrapper::Direction direction, const AMBXNativeWrapper::Color& color)
    {
        try
        {
            int index = static_cast<int>(direction);
            if (index >= 0 && index < 5 && managed->lights[index] != nullptr)
            {
                amBXLib::amBXColor managed_color;
                managed_color.R = color.r;
                managed_color.G = color.g;
                managed_color.B = color.b;

                managed->lights[index]->Color = managed_color;
                return true;
            }
        }
        catch (Exception^ ex)
        {
            return false;
        }
        return false;
    }

    void SetFadeTime(AMBXNativeWrapper::Direction direction, int milliseconds)
    {
        try
        {
            int index = static_cast<int>(direction);
            if (index >= 0 && index < 5 && managed->lights[index] != nullptr)
            {
                managed->lights[index]->FadeTime = milliseconds;
            }
        }
        catch (Exception^ ex)
        {
        }
    }
};

#pragma unmanaged

AMBXNativeWrapper::AMBXNativeWrapper()
    : pImpl(std::make_unique<Impl>())
    , initialized(false)
{
}

AMBXNativeWrapper::~AMBXNativeWrapper() = default;

bool AMBXNativeWrapper::Initialize()
{
    initialized = pImpl->Initialize();
    return initialized;
}

bool AMBXNativeWrapper::SetLightColor(Direction direction, const Color& color)
{
    if (!initialized)
        return false;

    return pImpl->SetLightColor(direction, color);
}

void AMBXNativeWrapper::SetFadeTime(Direction direction, int milliseconds)
{
    if (!initialized)
        return;

    pImpl->SetFadeTime(direction, milliseconds);
}