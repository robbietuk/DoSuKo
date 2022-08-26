cmake_minimum_required(VERSION 3.24)
project(DoSuKo)

set(CMAKE_CXX_STANDARD 20)

add_executable(DoSuKo
        main.cpp
        game/SudokuBoard.h game/SudokuBoard.cpp
        game/LoadBoards.h game/LoadBoards.cpp
        Solvers/DumbOne.h Solvers/DumbOne.cpp
        )

target_include_directories(${PROJECT_NAME}
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/game
        )