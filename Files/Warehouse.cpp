#include "Warehouse.h"
#include <fstream>
#include <iostream>
#include <cstring>
#include <cstdlib>

Warehouse::Warehouse(int gridSize) : gridSize(gridSize) {}

bool Warehouse::loadLayout(const std::string& filename) {
    std::ifstream inputFile(filename.c_str());

    if (!inputFile.is_open()) {
        std::cerr << "Unable to open warehouse layout file: " << filename << std::endl;
        return false;
    }

    char line[256];
    while (inputFile.getline(line, 256)) {
        char* lineCopy = strdup(line);
        int productId = 0;
        int weight = 0;
        int x = 0;
        int y = 0;

        // Parse comma-separated values
        char* token = strtok(lineCopy, ",");
        if (token != NULL) {
            productId = atoi(token);
            token = strtok(NULL, ",");

            if (token != NULL) {
                weight = atoi(token);
                token = strtok(NULL, ",");

                if (token != NULL) {
                    x = atoi(token);
                    token = strtok(NULL, ",");

                    if (token != NULL) {
                        y = atoi(token);
                        products.insert(std::make_pair(productId, Product(productId, weight, x, y)));
                    }
                }
            }
        }
        free(lineCopy);
    }

    inputFile.close();
    std::cout << "Successfully read warehouse layout from: " << filename << std::endl;
    return true;
}
std::vector<std::pair<int, int> > Warehouse::getLocationsForProducts(const std::vector<int>& productIds) const {
    std::vector<std::pair<int, int> > locations;
    for (size_t i = 0; i < productIds.size(); i++) {
        int productId = productIds[i];
        std::map<int, Product>::const_iterator it = products.find(productId);

        if (it != products.end()) {
            locations.push_back(std::make_pair(it->second.getX(), it->second.getY()));
        } 
        else {
            std::cerr << "Warning: No location found for product ID " << productId << " in warehouse layout. Using default (0,0)." << std::endl;
            locations.push_back(std::make_pair(0, 0));
        }
    }
    return locations;
}

int Warehouse::getGridSize() const {
    return gridSize;
}

