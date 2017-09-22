
add_executable(main main.cc forward.cc)

include_directories(${CMAKE_SOURCE_DIR}/src/pendulum ${CMAKE_SOURCE_DIR}/fmt)

target_link_libraries(main fmt pendulum ${Boost_LIBRARIES})

