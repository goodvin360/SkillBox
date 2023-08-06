cmake_minimum_required(VERSION 3.14)

project(M38_Task_2 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Widgets WebEngineWidgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets WebEngineWidgets)

add_executable(M38_Task_2
  main.cpp
)
target_link_libraries(M38_Task_2 Qt5::Core Qt5::Widgets Qt5::WebEngineCore Qt5::WebEngineWidgets)

include(GNUInstallDirs)
install(TARGETS M38_Task_2
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
