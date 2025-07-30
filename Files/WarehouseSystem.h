#ifndef WAREHOUSE_SYSTEM_H
#define WAREHOUSE_SYSTEM_H

#include "Warehouse.h"
#include "Vehicle.h"
#include "OrderManager.h"
#include "KnapsackSolver.h"
#include <vector>

class WarehouseSystem {
    private:
        Warehouse warehouse;
        Vehicle vehicle;
        OrderManager orderManager;
    public:
        WarehouseSystem(int vehicleCapacity = 50);
        bool initialize(const std::string& ordersFile, const std::string& warehouseFile);
        int processOrders();
};
#endif // WAREHOUSE_SYSTEM_H
