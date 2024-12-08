project(amBXPlugin)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

add_library(amBXPlugin SHARED
    src/amBXPlugin.cpp
    src/amBXPlugin.h
    src/AMBXController.cpp
    src/AMBXController.h
    src/AMBXNativeWrapper.cpp
    src/AMBXNativeWrapper.h
)

target_include_directories(amBXPlugin PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/dependencies/amBXLib/amBXLib
    ${CMAKE_SOURCE_DIR}
)

target_link_libraries(amBXPlugin PRIVATE
    Qt5::Core
    Qt5::Widgets
)

if(WIN32)
    target_compile_definitions(amBXPlugin PRIVATE
        -DUNICODE
        -D_UNICODE
        -D_CRT_SECURE_NO_WARNINGS
    )
    
    set_property(TARGET amBXPlugin PROPERTY VS_GLOBAL_CLRSupport "true")
    set_target_properties(amBXPlugin PROPERTIES 
        COMMON_LANGUAGE_RUNTIME ""
        COMPILE_FLAGS "/clr /EHa"
    )

    target_link_libraries(amBXPlugin PRIVATE
        mscoree.lib
    )
endif()