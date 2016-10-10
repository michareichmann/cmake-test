#set(GMOCK_DIR ")

add_subdirectory(${CMAKE_BINARY_DIR}/gmock)

add_executable(ToDoTest ToDoTest.cc)

target_link_libraries(ToDoTest toDoCore
        )

add_test(ToDoTest ToDoTest)