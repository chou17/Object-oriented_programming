#include "Rectangle.h"

Rectangle ::Rectangle(const string &input, const int &input_h, const int &input_w) : Shape(input), height(input_h), width(input_w){
   cout <<  "Rectangle constructor" <<endl;
}
void Rectangle ::print()
{
    Shape ::print();
    cout << " rectangle, height " << height << ",width " << width << ", area " << get_area() << endl;
}
double Rectangle ::get_area()
{
    return height * width;
}
