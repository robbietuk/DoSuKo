cmake_minimum_required(VERSION 3.10)
project(DoSuKo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

### GAME DIR and FILES VARIABLES ###
set(GAME_DIR ${CMAKE_CURRENT_SOURCE_DIR}/game)
list(APPEND GAME_INCLUDE_DIRS
        ${GAME_DIR}
        ${GAME_DIR}/Cell
        )
list(APPEND GAME_FILES
        ${GAME_DIR}/SudokuBoard.inl ${GAME_DIR}/SudokuBoard.h
        ${GAME_DIR}/LoadBoards.cpp ${GAME_DIR}/LoadBoards.h
        ${GAME_DIR}/Cell/BasicCell.h ${GAME_DIR}/Cell/PotentialCell.h)

### SOLVERS DIR and FILES VARIABLES ###
set(SOLVERS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/solvers)
list(APPEND SOLVERS_FILES

        ${SOLVERS_DIR}/DumbOne.cpp ${SOLVERS_DIR}/DumbOne.h
        ${SOLVERS_DIR}/solver_functions.cpp ${SOLVERS_DIR}/solver_functions.h)

### TESTS DIR ###
set(TESTS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/tests)



### DoSuKo DumbOneSolving executable ###
add_executable(DumbOneSolving
        DumbOneSolving.cpp
        ${GAME_FILES}
        ${SOLVERS_FILES}
        )

target_include_directories(DumbOneSolving
        PUBLIC
        ${GAME_INCLUDE_DIRS}
        ${SOLVERS_DIR}
)

### DoSuKo DumbTwoSolving executable ###
add_executable(DumbTwoSolving
        DumbTwoSolving.cpp
        ${GAME_FILES}
        ${SOLVERS_FILES}
)

target_include_directories(DumbTwoSolving
        PUBLIC
        ${GAME_INCLUDE_DIRS}
        ${SOLVERS_DIR}
        )



### TESTS ###
enable_testing()
add_subdirectory(tests)