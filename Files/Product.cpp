#include "Product.h"

Product::Product(int id, int weight, int x, int y)
: id(id), weight(weight), x(x), y(y) {}

int Product::getId() const {
    return id;
}

int Product::getWeight() const {
    return weight;
}

int Product::getX() const {
    return x;
}

int Product::getY() const {
    return y;
}
