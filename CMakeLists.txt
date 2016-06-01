#cmake_minimum_required(VERSION 3.5)
#project(sfmltest)
#
#set(EXECUTABLE_NAME ${PROJECT_NAME})
#set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/SFML-2.3.2/cmake/Modules/" ${CMAKE_MODULE_PATH})
#set(SFML_ROOT "${CMAKE_SOURCE_DIR}/SFML-2.3.2/")
#
#set(SFML_LIBRARIES "${CMAKE_SOURCE_DIR}/SFML-2.3.2/lib")
#set(SFML_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/SFML-2.3.2/include")
#
#set(SOURCE_FILES main.cpp)
#add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES})
#
#set(SFML_STATIC_LIBRARIES TRUE)
#find_package(SFML COMPONENTS graphics window network audio system REQUIRED)
#include_directories(${SFML_INCLUDE_DIR})
#message("${EXECUTABLE_NAME} ${SMFL_DEPENDENCIES}")
#target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})

# General settings
cmake_minimum_required(VERSION 2.8.4)
set(PROJECT_NAME SoM)
project(${PROJECT_NAME})
set (CMAKE_CXX_STANDARD 11)

# Enable debug symbols by default
if (CMAKE_BUILD_TYPE STREQUAL "")
    set(CMAKE_BUILD_TYPE Debug)
endif()

# Define sources and executable
set(EXECUTABLE_NAME ${PROJECT_NAME})
set(SOURCE_FILES main.cpp Model/Character.cpp Model/Character.h View/Character_view.cpp View/Character_view.h Model/Game.cpp Model/Game.h Model/Map.cpp Model/Map.h View/Map_view.cpp View/Map_view.h View/Layer.cpp View/Layer.h View/Layer_component.cpp View/Layer_component.h Util/util.h Util/Global.h Model/Hitbox.cpp Model/Hitbox.h View/Hitbox_view.cpp View/Hitbox_view.h View/Game_view.cpp View/Game_view.h Model/Player.cpp Model/Player.h Model/Npc.cpp Model/Npc.h Model/Monster.cpp Model/Monster.h Model/PlayableChar.cpp Model/PlayableChar.h Model/Dialog.cpp Model/Dialog.h)
add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES})

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/SFML-2.3.2/cmake/Modules/" ${CMAKE_MODULE_PATH})
set(SFML_ROOT "" CACHE FILEPATH "Path to SFML library.")
set(SFML_ROOT "${CMAKE_SOURCE_DIR}/SFML-2.3.2/")
set(SFML_STATIC_LIBRARIES ON)
find_package(SFML 2 REQUIRED graphics window network audio system)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_DEPENDENCIES})
else()
    message(SEND_ERROR "SFML library not found. Please set SFML_ROOT.")
endif()