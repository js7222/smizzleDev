add_executable(proto main.cc)

include_directories(${CMAKE_BINARY_DIR}/src/messages)

target_link_libraries(proto ${Boost_LIBRARIES} ${PROTOBUF_LIBRARY} messages)
