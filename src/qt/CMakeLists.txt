
find_package (Qt5 REQUIRED Core Widgets)
include_directories(${Qt5Core_INCLUDE_DIRS})
include_directories(${Qt5Widgets_INCLUDE_DIRS})


set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC" ) 
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC" )

file (GLOB Resources *.qrc)

set(HW_GUI_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../gui)

QT5_ADD_RESOURCES (ResourceSources ${Resources})

#qt5_wrap_ui(UIS_HDRS dialog.ui)
qt5_wrap_ui(UIS_HDRS ${HW_GUI_DIR}/dialog.ui)
add_executable (Test main.cpp mainwindow.cpp smizzleGraphicsView.cpp ${UIS_HDRS})
target_link_libraries(Test Qt5::Core Qt5::Widgets)
