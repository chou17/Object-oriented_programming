#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape
{ //derived from Shape using public inheritance
private:
    int height;
    int width;

public:
    Rectangle(const string &input_c, const int &input_h, const int &input_w);
    void print();
    double get_area() override;
};

#endif