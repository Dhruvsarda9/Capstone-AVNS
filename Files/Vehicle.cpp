#include "Vehicle.h"
#include <climits>
#include <cmath>

Vehicle::Vehicle(int capacity, std::pair<int, int> startPosition)
: capacity(capacity), position(startPosition) {}

int Vehicle::getCapacity() const {
    return capacity;
}

std::pair<int, int> Vehicle::getPosition() const {
    return position;
}

void Vehicle::setPosition(const std::pair<int, int>& newPosition) {
    position = newPosition;
}

int Vehicle::calculateManhattanDistance(int x1, int y1, int x2, int y2) const {
    return std::abs(x2 - x1) + std::abs(y2 - y1);
}

void Vehicle::findOptimalPath(const std::vector<std::pair<int, int> >& locations, std::vector<int>& path) const {
    int n = static_cast<int>(locations.size());
    if (n == 0) return;

    path.resize(n);
    std::vector<bool> visited(n, false);

    path[0] = 0; // Start at the first location
    visited[0] = true;

    for (int i = 1; i < n; ++i) {
        int current = path[i - 1];
        int nearest = -1;
        int minDistance = INT_MAX;//maximum value

        for (int j = 0; j < n; ++j) {
            if (!visited[j]) {
                int distance = calculateManhattanDistance(
                    locations[current].first, locations[current].second,
                    locations[j].first, locations[j].second
                );
                if (distance < minDistance) {
                    minDistance = distance;
                    nearest = j;
                }
            }
        }
        path[i] = nearest;
        visited[nearest] = true;
    }
}

int Vehicle::displayPath(const std::vector<std::pair<int, int> >& locations, const std::vector<int>& path, const std::vector<int>& originalOrders, const std::vector<int>& selectedIndices, int gridSize) const {
    std::vector<std::vector<char> > grid(gridSize, std::vector<char>(gridSize, '.'));
    grid[position.first][position.second] = 'S'; // Start position
    int totalSteps = 0;
    std::vector<std::pair<int, int> > fullPath;
    fullPath.push_back(position);
    for (std::vector<int>::size_type i = 0; i < path.size(); ++i) {
        int row = locations[path[i]].first;
        int col = locations[path[i]].second;
        grid[row][col] = 'P';
        fullPath.push_back(std::make_pair(row, col));
    }
    fullPath.push_back(position);
    for (std::vector<std::pair<int, int> >::size_type i = 0; i < fullPath.size() - 1; ++i) {
        int row1 = fullPath[i].first;
        int col1 = fullPath[i].second;
        int row2 = fullPath[i + 1].first;
        int col2 = fullPath[i + 1].second;
        while (row1 != row2 || col1 != col2) {
            if (row1 < row2) row1++;
            else if (row1 > row2) row1--;
            else if (col1 < col2) col1++;
            else if (col1 > col2) col1--;
            if (grid[row1][col1] != 'P' && grid[row1][col1] != 'S') grid[row1][col1] = 'T';
            totalSteps++;
        }
    }
    // Display the grid
    for (std::vector<std::vector<char> >::size_type i = 0; i < grid.size(); ++i) {
        for (std::vector<char>::size_type j = 0; j < grid[i].size(); ++j) {
            std::cout << std::setw(2) << grid[i][j];
        }
        std::cout << std::endl;
    }
    return totalSteps;
}
