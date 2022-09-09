//
// Created by Robert Twyman Skelly on 9/9/22.
//

#ifndef DOSUKO_EXAMPLEBOARDSTRINGS_H
#define DOSUKO_EXAMPLEBOARDSTRINGS_H

#include <string>

class ExampleBoardStrings {
public:
  ExampleBoardStrings() {
    // Problem and solution for problem boards
    example_problem_string = "070000043040009610800634900094052000358460020000800530080070091902100005007040802";
    example_solution_string = "679518243543729618821634957794352186358461729216897534485276391962183475137945862";

    // Create board with all zeros
    zeros_board_string = "";
    for (int i = 1; i < 82; i++)
      zeros_board_string += "0";

    // Construct simple board
    simple_board_string = zeros_board_string;
    simple_board_string[1] = '1';  // Add '1' to the 0th row, 1st column Cell (array starts at 0)
    simple_board_string[9] = '2';  // Add '2' to the 1st row, 0th column Cell (array starts at 0)
  }

  std::string example_problem_string;
  std::string example_solution_string;
  std::string zeros_board_string;
  std::string simple_board_string;

};
#endif//DOSUKO_EXAMPLEBOARDSTRINGS_H