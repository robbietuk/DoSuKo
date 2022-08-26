//
// Created by Robert Twyman Skelly on 8/25/22.
//

#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include "LoadBoards.h"

void tokenize(std::string const &str, const char delim,
              std::vector<std::string> &out)
{
  // construct a stream from the string
  std::stringstream ss(str);

  std::string s;
  while (std::getline(ss, s, delim)) {
    out.push_back(s);
  }
}





LoadBoards::
LoadBoards(const std::string &file_name){

  std::cout << "\nLoading Sudoko problems from file:\n\t" << file_name << "\n\n";
  this->file_name = file_name;
  this->current_set_num = 0;
  this->max_num_sets_per_fetch = 500;
  load_next_problems_data_from_csv();
}

std::vector<ProblemSolutionSet>
LoadBoards::
load_next_problems_data_from_csv() {

  problem_solution_sets.clear();

  std::ifstream myFile;
  myFile.open(this->file_name);
  if (!myFile.is_open()) {
      std::string error_message = "Could not open file: " + this->file_name + "\n";
      throw std::runtime_error(error_message);
  }

  std::string line;
  while(myFile.good()) {
    std::getline(myFile, line);
    if (line.empty() || line[0] == '#') {
      continue;
    }

    std::vector<std::string> tokens;
    tokenize(line, ',', tokens);
    if (tokens.size() > 2) {
      std::string error_message = "Invalid line in file: " + line + "\n"
                                  "Too many tokens: " + std::to_string(tokens.size()) + "\n";
      throw std::runtime_error(error_message);
    }

    if (is_problem_solution_combo_valid(tokens[0], tokens[1])) {
      ProblemSolutionSet problem_solution_set;
      problem_solution_set.problem = tokens[0];

      if (tokens.size() == 2) // There may not be a solution given
        problem_solution_set.solution = tokens[1];

      problem_solution_sets.push_back(problem_solution_set);
    } else {
      std::string error_message = "Solution does not match Problem:\n"
                                  "Problem : " +
                                  tokens[0] + " length " + std::to_string(tokens[0].size()) + "\n"
                                                                                              "Solution: " +
                                  tokens[1] + " length " + std::to_string(tokens[1].size()) + "\n";
      throw std::runtime_error(error_message);
    }
  }
  myFile.close();
  return problem_solution_sets;
}

bool LoadBoards::
is_problem_solution_combo_valid(std::string problem, std::string solution) {
  if (solution.empty())
    return true;

  if (problem.size() != solution.size())
    return false;

  for (int i = 0; i < problem.size(); i++) {
    if (problem[i] == '0') {
      continue;
    }
    if (problem[i] != solution[i]) {
      return false;
    }
  }
  return true;
}


ProblemSolutionSet
LoadBoards::
get_next_problems_set() {
  if (current_set_num >= problem_solution_sets.size()) {
//    load_next_problems_data_from_csv(file_name);
    current_set_num = 0;
  }
  current_set_num++;
  return problem_solution_sets[current_set_num - 1];
}
