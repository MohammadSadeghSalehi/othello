cmake_minimum_required(VERSION 3.8)
project(Othello)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_PREFIX_PATH /home/mss/Qt5.9.0/5.9/gcc_64)

find_package(Qt5 REQUIRED COMPONENTS Core Widgets Gui Network)

set(SOURCE_FILES main.cpp GamePlay.h MainWindow.h MainWindow.cpp GamePlay.cpp cpu.h)
add_executable(Othello ${SOURCE_FILES} GamePlay.h MainWindow.h MainWindow.cpp GamePlay.cpp cpu.h)
target_link_libraries(Othello Qt5::Core Qt5::Widgets Qt5::Gui Qt5::Network)