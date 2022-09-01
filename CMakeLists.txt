cmake_minimum_required(VERSION 3.10)
project(DoSuKo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(DoSuKo
        main.cpp
        game/SudokuBoard.cpp game/SudokuBoard.h
        game/LoadBoards.cpp game/LoadBoards.h
        solvers/DumbOne.cpp solvers/DumbOne.h
        )

target_include_directories(${PROJECT_NAME}
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/game
        ${CMAKE_CURRENT_SOURCE_DIR}/solvers
        )


enable_testing()
add_executable(test_functions
        test/test_functions.cpp
        game/SudokuBoard.cpp game/SudokuBoard.h
        game/LoadBoards.cpp game/LoadBoards.h
        Solvers/DumbOne.cpp Solvers/DumbOne.h
        )

target_include_directories(test_functions
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/game
        ${CMAKE_CURRENT_SOURCE_DIR}/Solvers
        )
add_test(test_functions test_functions )
