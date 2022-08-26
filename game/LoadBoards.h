//
// Created by Robert Twyman Skelly on 8/25/22.
//

#ifndef DOSUKO_LOADBOARDS_H
#define DOSUKO_LOADBOARDS_H


#include <iostream>
#include <vector>

struct ProblemSolutionSet {
  std::string problem;
  std::string solution;
};

class LoadBoards {  // LoadBoards is a class that loads boards from a file.
public:
  explicit LoadBoards(const std::string &File_name);
  ~LoadBoards() = default;

  std::vector<ProblemSolutionSet> load_next_problems_data_from_csv();
  static bool is_problem_solution_combo_valid(std::string problem, std::string solution);

  ProblemSolutionSet get_next_problems_set();

  int get_num_problems_loaded() const{
    return problem_solution_sets.size();
  };

  int get_current_set_num() const{
    return current_set_num;
  };

private:

public:
  std::vector<ProblemSolutionSet> problem_solution_sets;

private:
  std::string file_name;
  int current_set_num;
  int max_num_sets_per_fetch;

};




#endif//DOSUKO_LOADBOARDS_H
