#ifndef PRODUCT_H
#define PRODUCT_H

class Product {
    private:
        int id;
        int weight;
        int x;
        int y;
    public:
        // Add default constructor
        Product() : id(0), weight(0), x(0), y(0) {}
        Product(int id, int weight, int x, int y);
        int getId() const;
        int getWeight() const;
        int getX() const;
        int getY() const;
};

#endif // PRODUCT_H
