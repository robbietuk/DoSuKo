
#include "DumbOne.h"
#include "LoadBoards.h"
#include "SudokuBoard.h"
#include <iostream>


int main(int argc, char **argv) {
  if (argc != 2) {
    std::cout << "Usage:\n\t" << argv[0] << " <file_name>\n";
    return 1;
  }

  int num_solved_boards = 0;
  LoadBoards board_configs(argv[1]);
  const int num_problems_loaded = board_configs.get_num_problems_loaded();
  
  for (int i = 0; i < num_problems_loaded; i++) {
    ProblemSolutionSet pss = board_configs.get_next_problems_set();

    SudokuBoard<PotentialCell> board(pss.problem);

    if (!board_configs.is_problem_solution_combo_valid(pss.problem, pss.solution)) {
      std::cerr << i << " WARNING: The solution does not represent the initial loaded problem!\n"
                        "Problem:  " << pss.problem << "\n"
                        "Solution: " << pss.solution << "\n";
      continue;
    }

    // Solve the board using DumbOne
    DumbOne dumb_one(&board);
    dumb_one.solve_board();

    if (dumb_one.is_board_marked_as_solved()) {
      if (board_configs.is_problem_solution_combo_valid(dumb_one.get_board_ptr()->encode(), pss.solution)) {
        num_solved_boards++;
        std::cout << i << ": Solved!\n";
      } 
      else 
      { 
        std::cerr << i << " WARNING: The board is marked as solved but the solution does not represent the problem!\n"
                            "Problem:  " << pss.problem << "\n"
                            "Solution: " << pss.solution << "\n";
        dumb_one.get_board_ptr()->print_board_2D_visualisation();
      }
    } 
    else
    {
      std::cerr << i << " WARNING: Board is not solved!\n"
                        "Problem:  " << pss.problem << "\n"
                        "Solution: " << pss.solution << "\n";
    }
  }
  std::cout << "\nSolved " << num_solved_boards << " / " << num_problems_loaded << " boards.\n";
  return 0;
}