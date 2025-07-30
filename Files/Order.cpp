#include "Order.h"

Order::Order(int id, int productId, int quantity)
: id(id), productId(productId), quantity(quantity) {}

int Order::getId() const {
    return id;
}

int Order::getProductId() const {
    return productId;
}

int Order::getQuantity() const {
    return quantity;
}
