#ifndef VEHICLE_H
#define VEHICLE_H

#include <vector>
#include <utility>
#include <iostream>
#include <iomanip>

class Vehicle {
    private:
        int capacity;
        std::pair<int, int> position;
    public:
        Vehicle(int capacity = 50, std::pair<int, int> startPosition = std::make_pair(0, 0));
        int getCapacity() const;
        std::pair<int, int> getPosition() const;
        void setPosition(const std::pair<int, int>& newPosition);
        int calculateManhattanDistance(int x1, int y1, int x2, int y2) const;
        void findOptimalPath(const std::vector<std::pair<int, int> >& locations, std::vector<int>& path) const;
        int displayPath(const std::vector<std::pair<int, int> >& locations, const std::vector<int>& path,
        const std::vector<int>& originalOrders, const std::vector<int>& selectedIndices, int gridSize) const;
};

#endif // VEHICLE_H
