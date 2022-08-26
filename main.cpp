#include <iostream>
#include "SudokuBoard.h"
#include "LoadBoards.h"




int main() {
  std::string input = "070000043040009610800634900094052000358460020000800530080070091902100005007040802";
  std::string solution = "679518243543729618821634957794352186358461729216897534485276391962183475137945862";

  LoadBoards board_configs("/Users/rts/devel/DoSuKo/examples/boards_and_solutions.csv");


  for (int i = 0; i < board_configs.get_num_problems_loaded(); i++) {
    ProblemSolutionSet problem_solution_set = board_configs.get_next_problems_set();
    std::cout << "Problem  " << i << ": " << problem_solution_set.problem << "\n"
                 "Solution " << i << ": " << problem_solution_set.solution << "\n";
    SudokuBoard board(problem_solution_set.problem);
  }
  return 0;
}
