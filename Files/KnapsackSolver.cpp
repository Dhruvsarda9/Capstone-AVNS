#include "KnapsackSolver.h"

std::pair<int, std::vector<int> > KnapsackSolver::solve(int capacity, const std::vector<int>& weights, const std::vector<int>& values, int n) {
    if (n == 0 || capacity == 0) {//base case
        std::vector<int> emptyVector;
        return std::make_pair(0, emptyVector);
    }
    if (weights[n - 1] > capacity) {
        return solve(capacity, weights, values, n - 1);
    }
    //recursion
    std::pair<int, std::vector<int> > exclude = solve(capacity, weights, values, n - 1);
    std::pair<int, std::vector<int> > include = solve(capacity - weights[n - 1], weights, values, n - 1);
    include.first += values[n - 1];
    if (include.first > exclude.first) {
        include.second.push_back(n - 1);
        return include;
    }
    else {
        return exclude;
    }
}
