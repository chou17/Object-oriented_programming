
#ifndef SHAPE_H
#define SHAPE_H
#include <string>
#include <iostream>
using namespace std;

class Shape
{
private:
    string color;

public:
    Shape(const string &);
    virtual ~Shape() = default;

    virtual void print();
    virtual double get_area() = 0;
};

#endif