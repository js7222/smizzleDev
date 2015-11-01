
add_executable(main main.cc)

include_directories(${CMAKE_SOURCE_DIR}/src/pendulum)

target_link_libraries(main pendulum ${Boost_LIBRARIES})

