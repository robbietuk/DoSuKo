cmake_minimum_required(VERSION 3.10)
project(DoSuKo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

### GAME DIR and FILES VARIABLES ###
set(GAME_DIR ${CMAKE_CURRENT_SOURCE_DIR}/game)
list(APPEND GAME_FILES
        ${GAME_DIR}/SudokuBoard.cpp ${GAME_DIR}/SudokuBoard.h
        ${GAME_DIR}/LoadBoards.cpp ${GAME_DIR}/LoadBoards.h
        ${GAME_DIR}/Cell.h)

### SOLVERS DIR and FILES VARIABLES ###
set(SOLVERS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/solvers)
list(APPEND SOLVERS_FILES
        ${SOLVERS_DIR}/DumbOne.cpp ${SOLVERS_DIR}/DumbOne.h
        ${SOLVERS_DIR}/solver_functions.cpp ${SOLVERS_DIR}/solver_functions.h)

### TESTS DIR ###
set(TESTS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/tests)



### DoSuKo executable ###
add_executable(${PROJECT_NAME}
        main.cpp
        ${GAME_FILES}
        ${SOLVERS_FILES}
        )

target_include_directories(${PROJECT_NAME}
        PUBLIC
        ${GAME_DIR}
        ${SOLVERS_DIR}
        )

### TESTS ###
enable_testing()
add_subdirectory(tests)