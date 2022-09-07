


message(STATUS "Adding CTests")

list(APPEND TESTS_FILES testing.h testing.cpp)

### test_functions
add_executable(test_functions
        test_functions.cpp
        ${GAME_FILES}
        ${SOLVERS_FILES}
        ${TESTS_FILES}
        )

target_include_directories(test_functions
        PUBLIC
        ${GAME_DIR}
        ${SOLVERS_DIR}
        ${TESTS_DIR}
        )

add_test(test_functions test_functions)

### test_boards
add_executable(test_boards
        test_boards.cpp
        ${GAME_FILES}
        ${SOLVERS_FILES}
        ${TESTS_FILES}
        )

target_include_directories(test_boards
        PUBLIC
        ${GAME_DIR}
        ${SOLVERS_DIR}
        ${TESTS_DIR}
        )

add_test(test_boards test_boards)
