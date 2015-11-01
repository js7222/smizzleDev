
add_executable(chess main.cc piece.cc)

target_link_libraries(chess ${Boost_LIBRARIES})

