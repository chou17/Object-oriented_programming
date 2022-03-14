class Line
{ // representing a line in 2D, a*x + b*y + c = 0
private:
    double a;
    double b;
    double c;

public:
    Line() : a(0), b(0), c(0){};
    Line(double ia, double ib, double ic) : a(ia), b(ib), c(ic){};
    Line(const Line &p) : a(p.a), b(p.b), c(p.c){};
    bool operator==(const Line &p) { return (a == p.a) && (b == p.b) && (c == p.c); }
};