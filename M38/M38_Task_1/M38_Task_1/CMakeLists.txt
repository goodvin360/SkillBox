cmake_minimum_required(VERSION 3.14)

project(M38_Task_1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Widgets Multimedia MultimediaWidgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets Multimedia MultimediaWidgets)

add_executable(M38_Task_1
  main.cpp
)
target_link_libraries(M38_Task_1 Qt5::Core Qt5::Widgets Qt5::Multimedia Qt5::MultimediaWidgets)

include(GNUInstallDirs)
install(TARGETS M38_Task_1
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
