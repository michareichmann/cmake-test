cmake_minimum_required(VERSION 3.3 FATAL_ERROR)
# project name
project("CMake Test")

enable_testing()

# set compiler warnings
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    set(warnings "-Wall -Wextra -Werror")
endif()
if (NOT CONFIGURED_ONCE)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${warnings}" CACHE STRING "Flags used by compiler during all build types." FORCE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${warnings}" CACHE STRING "Flags used by compiler during all build types." FORCE)
endif ()

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_subdirectory(ToDoCore)

add_executable(toDo main.cc)
target_link_libraries(toDo toDoCore)

add_test(toDoTest toDo)

set(CONFIGURED_ONCE TRUE CACHE INTERNAL "A flag showing that CMake has configured at least once.")