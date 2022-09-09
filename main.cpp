
#include "LoadBoards.h"
#include "SudokuBoard.h"
#include "DumbOne.h"
#include <iostream>


int main(int argc, char** argv) {
  if (argc != 2) {
      std::cout << "Usage: " << argv[0] << " <file_name>\n";
      return 1;
  }

  LoadBoards board_configs(argv[1]);

  const int num_problems_loaded = board_configs.get_num_problems_loaded();
  for (int i = 0; i < num_problems_loaded; i++) {
    ProblemSolutionSet problem_solution_set = board_configs.get_next_problems_set();

    SudokuBoard<Cell> board(problem_solution_set.problem);

    if (!board_configs.is_problem_solution_combo_valid(problem_solution_set.problem,
                                                      problem_solution_set.solution)) {
      std::cerr << "WARNING: The solution does not represent the problem!\n"
                   "Problem  " << i << ": " << problem_solution_set.problem << "\n"
                   "Solution " << i << ": " << problem_solution_set.solution << "\n";
      continue;
    }
    DumbOne dumb_one(&board);
  }
  return 0;
}
