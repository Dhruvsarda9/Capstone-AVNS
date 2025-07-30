#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <vector>
#include <map>
#include <string>
#include "Product.h"

class Warehouse {
    private:
        std::map<int, Product> products;
        int gridSize;

    public:
        Warehouse(int gridSize = 15);
        bool loadLayout(const std::string& filename);
        std::vector<std::pair<int, int> > getLocationsForProducts(const std::vector<int>& productIds) const;
        int getGridSize() const;
};

#endif // WAREHOUSE_H
