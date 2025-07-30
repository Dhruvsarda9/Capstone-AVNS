#include "OrderManager.h"
#include <fstream>
#include <iostream>
#include <cstring>
#include <cstdlib>

bool OrderManager::loadOrdersFromFile(const std::string& filename) {
    std::ifstream inputFile(filename.c_str());
    if (!inputFile.is_open()) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return false;
    }
    orders.clear();
    char line[256];
    int orderId = 1;
    while (inputFile.getline(line, 256)) {
        char* copy = strdup(line);//duplicate string
        char* token = strtok(copy, ",");//retrive string based on delimiter
        while (token != NULL) {
            int productId = atoi(token);
            token = strtok(NULL, ",");
            if (token != NULL) {
                int quantity = atoi(token);
                orders.push_back(Order(orderId++, productId, quantity));
                token = strtok(NULL, ",");
            }
        }
        free(copy);
    }
    inputFile.close();
    return true;
}

std::vector<int> OrderManager::getProductIds() const {
    std::vector<int> productIds;
    for (size_t i = 0; i < orders.size(); i++) {
        productIds.push_back(orders[i].getProductId());
    }
    // Print the vectors for verification
    std::cout << "Keys (val): ";
    for (size_t i = 0; i < productIds.size(); ++i) {
        std::cout << productIds[i] << " ";
    }
    std::cout << std::endl;

    return productIds;
}

std::vector<int> OrderManager::getQuantities() const {
    std::vector<int> quantities;
    for (size_t i = 0; i < orders.size(); i++) {
        quantities.push_back(orders[i].getQuantity());
    }


    // Print the vectors for verification
    std::cout << "Values (wt): ";
    for (size_t i = 0; i < quantities.size(); ++i) {
        std::cout << quantities[i] << " ";
    }
    std::cout << std::endl;
    return quantities;
}
