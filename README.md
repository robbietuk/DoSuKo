# DoSuKo

## Introduction
DoSuKo is an attempt to build a Sudoku game in C++.
It is a work in progress.
The aim to to develop algorithms to solve the game.

## Installation
Uses CMAKE to build the project. Fairly standard. 

## Usage
Only the executable is available with arguments.
```
./DuSuKo <example_csv>
```

where `<example_csv>` indicates the path to a CSV file containing the game configs, 
see `DuSuKo/examples/example500.csv` or the Examples section below.

## Features
* Sudoku game
* Solving algorithm


### Examples
Example sudoku games can be found at: https://www.kaggle.com/datasets/rohanrao/sudoku


CURRENT AIMS
 - [ ] Implement a potential board. 
   Basically the same as the Sudoku board, but with a list of potential values for each cell.
 - [ ] Implement compute potential values method for each row, column and local box.
 - [ ] Add timing. 
   - [ ] How may times did the algorithm have to search, and 
   - [ ] Profile different algorithms.
 - [ ] Add a number of new run_test cases for the boards.
 - [ ] Add a number of new run_test cases for the basic functions
 - [x] Add base class for testing.
