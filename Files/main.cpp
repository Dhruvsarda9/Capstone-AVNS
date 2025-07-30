#include "WarehouseSystem.h"
#include <iostream>

int main() {
    WarehouseSystem system1;
    if (!system1.initialize("orders.csv", "warehouse_layout.csv")) {
       std::cerr << "Failed to initialize the warehouse system" << std::endl;
       return 1;
    }
    int requiredCycles = system1.processOrders();
    std::cout << "Total cycles required: " << requiredCycles << std::endl;

    // system("PAUSE");
    return 0;
}
