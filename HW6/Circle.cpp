#include "Circle.h"

Circle ::Circle(const string &input, const int &input_r) : Shape(input), radius(input_r){
    cout << "Circle constructor" << endl;
}
void Circle ::print()
{
    Shape ::print();
    cout << " circle, radius " << radius << ", area " << get_area() << endl;
}

double Circle ::get_area()
{
    return radius * radius * 3.14159;
}
