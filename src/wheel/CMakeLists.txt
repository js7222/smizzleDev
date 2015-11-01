
add_executable(wheel timer.cc)

add_executable(event event.c)

MESSAGE( STATUS "EVENT_LIBRARIES: " ${EVENT_LIBRARIES})
target_link_libraries(wheel ${Boost_LIBRARIES} ${EVENT_LIBRARIES})
target_link_libraries(event ${EVENT_LIBRARIES})
