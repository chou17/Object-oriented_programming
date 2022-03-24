#include <iostream>
#include <math.h>
#include <fstream> // For file I/O
#include <iomanip>
#include <vector>
#include <cctype>
#include <string>

using std::string;
using namespace std;

int highestPower(float coff[]);
void display(int highestPow, float coff[]);
void derivative(int highestPow, float coff[], float dev_coff[]);
int compute(int highestPow, float coff[], float x);

int main()
{
    string filename("polydata.txt");
    string line;

    ifstream input_file(filename);
    if (!input_file.is_open())
    {
        cerr << "Could not open the file - '"
             << filename << "'" << endl;
        return EXIT_FAILURE;
    }

    while (getline(input_file, line))
    {
        float x;
        cout << "The number x is : ";
        cin >> x;
        if (!isdigit(x))
        {
            cout << "This x is not a number!" << endl;
            return EXIT_FAILURE;
        }
        float coff[7], dev_coff[6];

        string delimiter = " ";
        size_t pos = 0;
        string token;
        int index = 0;
        while ((pos = line.find(delimiter)) != std::string::npos)
        {
            token = line.substr(0, pos);
            float num = std::stof(token);
            coff[index++] = num;
            line.erase(0, pos + delimiter.length());
        }
        float num = std::stof(line);
        coff[index] = num;
        //coff

        float highestPow = highestPower(coff);
        if (highestPow == -1)
        {
            cout << "This highestPow is not right!" << endl;
            return EXIT_FAILURE;
        }
        cout << "f(x) = ";
        display(highestPow, coff);
        derivative(highestPow, coff, dev_coff);
        cout << "f'(x) = ";
        display(highestPow, dev_coff);
        float result = compute(highestPow, coff, x);
        cout << "f(" << x << ") = " << result << ".";
        result = compute(highestPow, dev_coff, x);
        cout << "f'(" << x << ") = " << result << ".";
    }

    input_file.close();
    return EXIT_SUCCESS;
}

int highestPower(float coff[])
{

    if (coff[0] >= 0 && coff[0] <= 5)
        return coff[0];
    else
        return -1;
}

void display(int highestPow, float coff[])
{
    cout << coff[1];
    int n = 2;
    if (highestPow)
    {
        while (n <= highestPow + 1)
        {
            cout << "+" << coff[n];
            int index = n - 1;
            while (index)
            {
                cout << "*x";
                index--;
            }
            n++;
        }
    }
}

void derivative(int highestPow, float coff[], float dev_coff[])
{
    dev_coff[0] = highestPow - 1;
    for (int i = 1; i++; i <= highestPow)
        dev_coff[i] = coff[i + 1] * i;
} //微分

int compute(int highestPow, float coff[], float x)
{
    float result = coff[1];
    for (int i = 2; i++; i <= highestPow + 1)
    {
        float n = pow(x, i - 1);
        result = result + coff[i] * n;
    }
    return result;
} //帶入x計算值
