#include <iostream>
#include <math.h>
#include <fstream> // For file I/O
#include <iomanip>
#include <vector>
#include <cctype>
#include <string>

using std::string;
using namespace std;

int main()
{
    std::string s = "scott>=tiger>=mushroom";
    std::string delimiter = ">=";

    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos)
    {
        token = s.substr(0, pos);
        std::cout << token << std::endl;
        s.erase(0, pos + delimiter.length());
    }
    std::cout << s << std::endl;
}