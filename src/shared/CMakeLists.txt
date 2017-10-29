
add_executable(shared main.cc)

include_directories(${CMAKE_SOURCE_DIR}/src/pendulum ${CMAKE_SOURCE_DIR}/fmt)

target_link_libraries(shared fmt pendulum ${Boost_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT} rt)

