#include "./solutions.h"

#define SOLUTION(x, y) \
  manager->AddProblem(std::unique_ptr<Problem>(new Problem_##x##_##y));

namespace cryptopals {
void add_solutions(ProblemManager *manager) {
  SOLUTION(1, 1);
  SOLUTION(1, 2);
  SOLUTION(1, 3);
  SOLUTION(1, 4);
}
}  // namespace cryptopals
