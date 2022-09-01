

enable_testing()
add_executable(test_functions
        test_functions.cpp
        ${GAME_FILES}
        ${SOLVERS_FILES}
        )

target_include_directories(test_functions
        PUBLIC
        ${GAME_DIR}
        ${SOLVERS_DIR}
        )
add_test(test_functions test_functions)
