#ifndef KNAPSACK_SOLVER_H
#define KNAPSACK_SOLVER_H

#include <vector>
#include <utility>

class KnapsackSolver {
public:
static std::pair<int, std::vector<int> > solve(int capacity, const std::vector<int>& weights,
const std::vector<int>& values, int n);
};

#endif // KNAPSACK_SOLVER_H
