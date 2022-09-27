
#include "LoadBoards.h"
#include "SudokuBoard.h"
#include "DumbOne.h"
#include <iostream>


int main(int argc, char **argv) {
  if (argc != 2) {
    std::cout << "Usage: " << argv[0] << " <file_name>\n";
    return 1;
  }

  int num_solved_boards = 0;

  LoadBoards board_configs(argv[1]);

  const int num_problems_loaded = board_configs.get_num_problems_loaded();
  for (int i = 0; i < num_problems_loaded; i++) {
    ProblemSolutionSet problem_solution_set = board_configs.get_next_problems_set();

    SudokuBoard<PotentialCell> board(problem_solution_set.problem);

    if (!board_configs.is_problem_solution_combo_valid(problem_solution_set.problem,
                                                       problem_solution_set.solution)) {
      std::cerr << "WARNING: The solution does not represent the problem!\n"
                   "Problem  "
                << i << ": " << problem_solution_set.problem << "\n"
                                                                "Solution "
                << i << ": " << problem_solution_set.solution << "\n";
      continue;
    }
    DumbOne dumb_one(&board);
    dumb_one.solve_board();

    if (dumb_one.is_board_marked_as_solved()) {
      if (board_configs.is_problem_solution_combo_valid(dumb_one.get_board_ptr()->encode(),
                                                        problem_solution_set.solution)) {
        num_solved_boards++;
        std::cout << i << ": Solved!\n";
      } else {
        std::cerr << "WARNING: The board is marked as solved but the solution does not represent the problem!\n"
                     "Problem  "
                  << i << ": " << problem_solution_set.problem << "\n"
                                                                  "Solution "
                  << i << ": " << problem_solution_set.solution << "\n";
        dumb_one.get_board_ptr()->print_board_2D_visualisation();
      }
    } else {
      std::cerr << "WARNING: Board is not solved!\n"
                   "Problem  "
                << i << ": " << problem_solution_set.problem << "\n"
                                                                "Solution "
                << i << ": " << problem_solution_set.solution << "\n";
    }
  }
  std::cout << "Solved " << num_solved_boards << " / " << num_problems_loaded << " boards.\n";
  return 0;

}