#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

class Triangle : public Shape
{ //derived from Shape using public inheritance
private:
    int height;
    int base;

public:
    Triangle(const string &input_c, const int &input_h, const int &input_b);
    void print();
    double get_area() override;
};

#endif