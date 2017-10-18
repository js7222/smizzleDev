

add_library(pendulum pendulum.cc bst.cc)

target_link_libraries(pendulum ${Boost_LIBRARIES})

