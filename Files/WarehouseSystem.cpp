#include "WarehouseSystem.h"
#include <iostream>
#include <algorithm>
//class
WarehouseSystem::WarehouseSystem(int vehicleCapacity) : vehicle(vehicleCapacity) {}

bool WarehouseSystem::initialize(const std::string& ordersFile, const std::string& warehouseFile) {
    bool ordersLoaded = orderManager.loadOrdersFromFile(ordersFile);//read orders file
    bool warehouseLoaded = warehouse.loadLayout(warehouseFile); //read warehouse layout file
    return ordersLoaded && warehouseLoaded;
}

int WarehouseSystem::processOrders() {
    std::vector<int> productIds = orderManager.getProductIds();//get all prod_id from orders
    std::vector<int> quantities = orderManager.getQuantities();//get quantity(weights)
    std::vector<std::pair<int, int> > productLocations = warehouse.getLocationsForProducts(productIds);
    int cycles = 0;
    std::vector<int> originalOrders;

    for (std::vector<int>::size_type i = 0; i < quantities.size(); i++) {
        originalOrders.push_back(static_cast<int>(i) + 1);
    }

    while (!quantities.empty()) {
        std::pair<int, std::vector<int> > result = KnapsackSolver::solve(vehicle.getCapacity(), quantities, productIds, static_cast<int>(quantities.size()));

        std::vector<int> selectedIndices = result.second;
        cycles++;//size of knapsack vectors

        std::cout << "Cycle " << cycles << ": ";
        std::vector<std::pair<int, int> > locations;

        for (std::vector<int>::size_type i = 0; i < selectedIndices.size(); i++) {
            std::cout << originalOrders[selectedIndices[i]] << " ";
            locations.push_back(productLocations[originalOrders[selectedIndices[i]] - 1]);
        }

        std::cout << std::endl;

        std::vector<int> tspPath;
        vehicle.findOptimalPath(locations, tspPath);

        std::cout << "  Path Taken: ";
        for (std::vector<int>::size_type i = 0; i < tspPath.size(); i++) {
            std::cout << originalOrders[selectedIndices[tspPath[i]]] << " ";
        }

        std::cout << std::endl;

        int totalSteps = vehicle.displayPath(locations, tspPath, originalOrders, selectedIndices, warehouse.getGridSize());

        std::cout << "Total steps in this cycle: " << totalSteps << std::endl;

        // Remove processed orders
        std::sort(selectedIndices.begin(), selectedIndices.end(), std::greater<int>());
        for (std::vector<int>::size_type i = 0; i < selectedIndices.size(); i++) {
            quantities.erase(quantities.begin() + selectedIndices[i]);
            productIds.erase(productIds.begin() + selectedIndices[i]);
            originalOrders.erase(originalOrders.begin() + selectedIndices[i]);
        }
    }
    return cycles;
}
