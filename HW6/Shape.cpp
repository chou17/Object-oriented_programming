#include "Shape.h"

Shape ::Shape(const string &input) : color(input){};

void Shape ::print()
{
    cout << color;
}
