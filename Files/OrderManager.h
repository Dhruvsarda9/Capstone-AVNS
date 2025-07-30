#ifndef ORDER_MANAGER_H
#define ORDER_MANAGER_H

#include <vector>
#include <string>
#include <map>
#include "Order.h"

class OrderManager {
    private:
        std::vector<Order> orders;
    public:
        bool loadOrdersFromFile(const std::string& filename);
        std::vector<int> getProductIds() const;
        std::vector<int> getQuantities() const;
};

#endif // ORDER_MANAGER_H
