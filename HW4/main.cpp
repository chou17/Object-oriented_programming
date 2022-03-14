#include <iostream>
#include <sys/time.h>

#include "ConvexHull.cpp"

void DrawPoints(int BorJ, vector<Point> &input, vector<Point> &output)
{
    ofstream output_f;
    if (BorJ == B)
    {
        output_f.open("Output_brutal.txt", ios::out);
    }
    else
    {
        output_f.open("Output_Javis.txt", ios::out);
    }
    output_f << input.size() - output.size() << endl;
    int is_output = 0;
    for (int i = 0; i < input.size(); i++)
    {
        for (int j = 0; j < output.size(); j++)
        {
            if (input[i] == output[j])
            {
                is_output = 1;
                break;
            }
        }
        if (!is_output)
        {
            output_f << input[i].get_x() << " " << input[i].get_y() << endl;
        }
        is_output = 0;
    }
    output_f << endl;
    output_f.close();
}

void DrawLines(int BorJ, vector<Point> &input)
{
    ofstream output_f;
    if (BorJ == B)
    {
        output_f.open("Output_brutal.txt", ios::app);
    }
    else
    {
        output_f.open("Output_Javis.txt", ios::app);
    }
    output_f << input.size() << endl;
    for (int i = 0; i < input.size(); i++)
    {
        output_f << input[i].get_x() << " " << input[i].get_y() << endl;
    }
    output_f.close();
}

int main()
{
    ifstream input;
    input.open("Input.txt", ios::in);
    int p_num;
    input >> p_num;
    if (p_num < 3)
    {
        cout << "This data is not correct." << endl;
        return 0;
    }
    vector<Point> point;

    for (int i = 0; i < p_num; i++)
    {
        double num_x, num_y;
        input >> num_x;
        input >> num_y;
        Point tmp(num_x, num_y);
        point.push_back(tmp);
    }
    input.close();

    vector<Point> output1;
    ConvexHull convexhull;
    struct timeval start;
    struct timeval end;
    unsigned long diff;
    gettimeofday(&start, NULL);
    convexhull.FindConvexHull(J, point, output1);
    DrawPoints(J, point, output1); // provide data to the first part of Output.txt
    DrawLines(J, output1);         // provide data to the second part of Output.txt
    gettimeofday(&end, NULL);
    diff = 1000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    cout << "Jarvis's march algorithm cost " << diff << " ms." << endl;

    vector<Point> output2;
    gettimeofday(&start, NULL);
    convexhull.FindConvexHull(B, point, output2);
    DrawPoints(B, point, output2); // provide data to the first part of Output.txt
    DrawLines(B, output2);
    gettimeofday(&end, NULL);
    diff = 1000 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
    cout << "Brute force algorithms cost " << diff << " ms." << endl;
}
