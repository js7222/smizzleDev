
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(Boost_USE_STATIC_LIBS       OFF) # only find static libs
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)
set(CMAKE_INCLUDE_CURRENT_DIR    ON)
find_package(Boost 1.57.0 REQUIRED COMPONENTS system chrono)
include_directories(${Boost_INCLUDE_DIR})
find_package(LibEvent REQUIRED)


MESSAGE( STATUS "CMAKE_MODULE_PATH: " ${CMAKE_MODULE_PATH} )
MESSAGE( STATUS "CMAKE_SYSTEM: " ${CMAKE_SYSTEM} )
add_subdirectory(main)
add_subdirectory(pendulum)
add_subdirectory(qt)
add_subdirectory(openGl)
add_subdirectory(wheel)
add_subdirectory(chess)
add_subdirectory(test)
