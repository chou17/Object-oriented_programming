class Point
{ //representing a point in 2D, (x, y)
private:
    double x;
    double y;

public:
    Point() : x(0), y(0){};
    Point(double ix, double iy) : x(ix), y(iy){};
    Point(const Point &p) : x(p.x), y(p.y){};
    bool operator==(const Point &p) { return (x == p.x) && (y == p.y); }
    double get_x() { return x; }
    double get_y() { return y; }
};
