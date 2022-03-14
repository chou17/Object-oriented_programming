#include <iostream>
#include <vector>

#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
using namespace std;

int main()
{
    vector<Shape *> shape;
    vector<string> type;
    const string s = "yellow";
    const int x = 10, y = 20;
    Shape *circle = new Circle(s, x);
    Shape *a = new Triangle(s, x, y);
    Shape *b = new Rectangle(s, x, y);
    Shape *c = new Triangle("red", 3, 5);

    Shape *d = new Circle("green", 5);
    Shape *e = new Rectangle("white", 3, 8);

    shape.push_back(circle);
    type.push_back("circle");
    shape.push_back(a);
    type.push_back("triangle");
    shape.push_back(b);
    type.push_back("rectangle");
    shape.push_back(c);
    type.push_back("triangle");
    shape.push_back(d);
    type.push_back("circle");
    shape.push_back(e);
    type.push_back("rectangle");

    cout << "Printing all shapes:" << endl;
    for (Shape *p : shape)
    {
        p->print();
    }
    cout << "Print all circle:" << endl;
    for (size_t i = 0; i < shape.size(); i++)
    {
        if (type[i] == "circle")
        {
            shape[i]->print();
        }
    }
    for (size_t i = 0; i < shape.size(); i++)
    {
        delete shape[i];
        shape[i] = NULL;
        type[i] = "";
    }
    return 0;
}
