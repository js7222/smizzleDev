
# Download and unpack gtest at configure time
configure_file(gtest-CMakeLists.txt gtest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/src/test/gtest-download )
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/src/test/gtest-download )
 
# Add gtest directly to our build
add_subdirectory(${CMAKE_BINARY_DIR}/src/test/gtest-src
                 ${CMAKE_BINARY_DIR}/src/test/gtest-build
                 EXCLUDE_FROM_ALL )
 
# Add the gtest include directory, since gtest
# doesn't add that dependency to its gtest target
target_include_directories(gtest INTERFACE
  "${CMAKE_BINARY_DIR}/src/test/gtest-src/include" )

add_executable(mytest mytest.cc)
include_directories(${CMAKE_SOURCE_DIR}/src/pendulum)
target_link_libraries(mytest pendulum gtest_main)
add_test(NAME mytest COMMAND mytest)