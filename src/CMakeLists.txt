add_library(amBXPlugin SHARED
    amBXPlugin.cpp
    amBXPlugin.h
    AMBXController.cpp
    AMBXController.h
    AMBXNativeWrapper.cpp
    AMBXNativeWrapper.h
)

target_include_directories(amBXPlugin PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/dependencies
    ${CMAKE_SOURCE_DIR}
)

target_link_libraries(amBXPlugin PRIVATE
    Qt5::Core
    Qt5::Widgets
)

if(WIN32)
    set_target_properties(amBXPlugin PROPERTIES
        VS_GLOBAL_CLRSupport "true"
    )
endif()