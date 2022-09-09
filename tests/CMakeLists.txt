


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
        ${GAME_INCLUDE_DIRS}
        ${SOLVERS_DIR}
        ${TESTS_DIR}
        )

add_test(test_functions test_functions)

### test_basic_cell_boards
add_executable(test_basic_cell_boards
        test_basic_cell_boards.cpp
        ${GAME_FILES}
        ${SOLVERS_FILES}
        ${TESTS_FILES}
        ExampleBoardStrings.h
        )

target_include_directories(test_basic_cell_boards
        PUBLIC
        ${GAME_INCLUDE_DIRS}
        ${SOLVERS_DIR}
        ${TESTS_DIR}
        )

add_test(test_basic_cell_boards test_basic_cell_boards)


### test_possible_cell_boards
add_executable(test_potential_cell_boards
        test_potential_cell_boards.cpp
        ${GAME_FILES}
        ${SOLVERS_FILES}
        ${TESTS_FILES}
        )

target_include_directories(test_potential_cell_boards
        PUBLIC
        ${GAME_INCLUDE_DIRS}
        ${SOLVERS_DIR}
        ${TESTS_DIR}
        )

add_test(test_potential_cell_boards test_potential_cell_boards)
