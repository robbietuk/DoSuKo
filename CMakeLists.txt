cmake_minimum_required(VERSION 3.24)
project(DoSuKo)

set(CMAKE_CXX_STANDARD 20)

add_executable(DoSuKo
        main.cpp
        game/SudokuBoard.h game/SudokuBoard.cpp
        game/LoadBoards.h game/LoadBoards.cpp
        )
