#ifndef ORDER_H
#define ORDER_H

#include <vector>

class Order {
    private:
        int id;
        int productId;
        int quantity;
    public:
        Order(int id, int productId, int quantity);
        int getId() const;
        int getProductId() const;
        int getQuantity() const;
};

#endif // ORDER_H
