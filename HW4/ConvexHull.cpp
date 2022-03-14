#include <vector>
#include <math.h>
#include <fstream>
#include <unistd.h>
#include "Point.cpp"
#include "Line.cpp"

using namespace std;

#define MAX 1024
#define B 0
#define J 1
#define PI 3.1415926535897931

class ConvexHull
{ // a class for finding convex hull of a set of points. Input is a const pass by reference vector<Point>, output is a pass by reference vector<Point>

private:
    Line FindLine(Point &p, Point &q)
    {
        double a = (p.get_y() - q.get_y()) / (p.get_x() - q.get_x());
        double b = -1;
        double c = p.get_y() - a * p.get_x();
        Line line(a, b, c);
        return line;
    } // return a directed line pq from point p to q
    bool isOnRight(Point &p, Point &q, Point &r)
    {
        double x1 = p.get_x();
        double x2 = q.get_x();
        double x3 = r.get_x();
        double y1 = p.get_y();
        double y2 = q.get_y();
        double y3 = r.get_y();
        double result = (x1 - x2) * (y3 - y1) - (x3 - x1) * (y1 - y2);
        if (result < 0)
        {
            return false;
        }
        else if (result == 0)
        {
            if ((x3 > x1 && x3 > x2) || (x3 < x1 && x3 < x2) || (y3 > y1 && y3 > y2) || (y3 < y1 && y3 < y2))
            {
                return false;
            }
        }
        return true;

    } // return true if r is on the right side of the line from p to q. If pq is horizontal, return true only if r is above it.
    Point FindLowestPoint(vector<Point> &input)
    {
        double ymin = input[0].get_y();
        int min = 0;
        for (int i = 1; i < input.size(); i++)
        {
            int y = input[i].get_y();
            if ((y < ymin) || (ymin == y && input[i].get_x() < input[min].get_x()))
            {
                ymin = input[i].get_y();
                min = i;
            }
        }
        Point tmp = input[0];
        input[0] = input[min];
        input[min] = tmp;
        return input[0];
    } // find the lowest point(the point with the smallest y-coordinate)
    double ComputeAngle(Point &p, Point &q, Point &r)
    {
        double cosfi, fi, norm;

        double x1 = p.get_x();
        double x2 = q.get_x();
        double x3 = r.get_x();
        double y1 = p.get_y();
        double y2 = q.get_y();
        double y3 = r.get_y();

        double dsx = x2 - x1;
        double dsy = y2 - y1;
        double dex = x3 - x1;
        double dey = y3 - y1;
        cosfi = dsx * dex + dsy * dey;
        norm = (dsx * dsx + dsy * dsy) * (dex * dex + dey * dey);
        cosfi /= sqrt(norm);
        if (cosfi >= 1.0)
            return 0;
        if (cosfi <= -1.0)
            return PI;
        fi = acos(cosfi);
        if (dsx * dey - dsy * dex > 0)
            return fi; // 說明向量os 在向量 oe的順時針方向
        return fi;
    } // find the angle pqr of three points

public:
    void FindConvexHull(int BorJ, vector<Point> &input, vector<Point> &output)
    {
        if (BorJ == J)
        {
            Point p = input[1];
            Point q;
            Point r;
            Point max_p;

            q = FindLowestPoint(input);
            output.push_back(q);
            for (int i = 2; i < input.size(); i++)
            {
                if (isOnRight(input[0], p, input[i]))
                {
                    p = input[i];
                }
            }
            output.push_back(p);
            double max = 0;
            while (1)
            {
                for (int i = 0; i < input.size(); i++)
                {
                    r = input[i];
                    double c = ComputeAngle(p, q, r);
                    if (c > max)
                    {
                        max = c;
                        max_p = r;
                    }
                }
                if (max_p == input[0])
                    break;
                q = p;
                p = max_p;
                output.push_back(max_p);
                max = 0;
            }
        }
        else if (BorJ == B)
        {
            Point p;
            Point q;
            Point r;
            int allr_in_right = 1;
            int p_repeat = 0;
            int q_repeat = 0;
            for (int a = 0; a < input.size(); a++)
            {
                p = input[a];
                for (int i = 0; i < input.size(); i++)
                {
                    q = input[i];
                    if (p == q)
                        continue;
                    allr_in_right = 1;
                    for (int j = 0; j < input.size(); j++)
                    {
                        r = input[j];
                        if (r == q || r == p)
                            continue;
                        if (!isOnRight(p, q, r))
                        {
                            allr_in_right = 0;
                            break;
                        }
                    }
                    if (allr_in_right == 1)
                    {
                        for (int k = 0; k < output.size(); k++)
                        {
                            if (p == output[k])
                                p_repeat = 1;
                            if (q == output[k])
                                q_repeat = 1;
                        }
                        if (!p_repeat)
                            output.push_back(p);
                        if (!q_repeat)
                            output.push_back(q);
                        p_repeat = 0;
                        q_repeat = 0;
                    }
                }
            }
            int most_right = 1;
            for (int i = 1; i < output.size(); i++)
            {
                for (int j = 1; j < output.size(); j++)
                {
                    if (isOnRight(p, input[i], input[j]))
                    {
                        Point tmp = output[i];
                        output[i] = output[j];
                        output[j] = tmp;
                    }
                }
            }
        }

    } // find the convex hull of input points
};