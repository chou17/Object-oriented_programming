#include "Triangle.h"

Triangle ::Triangle(const string &input, const int &input_h, const int &input_b) : Shape(input), height(input_h), base(input_b){
    cout << "Triangle constructor" << endl;    
}

void Triangle ::print()
{
    Shape :: print();
    cout << " triangle, height " << height << ", base " << base << ", area " << get_area() << endl;
}
double Triangle ::get_area()
{
    return base * height / 2;
}
