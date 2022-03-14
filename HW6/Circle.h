#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape
{ //derived from Shape using public inheritance
private:
    int radius;

public:
    Circle(const string &input_c, const int &input_r);
    void print();
    double get_area() override;
};

#endif
