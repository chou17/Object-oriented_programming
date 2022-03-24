#include <iostream>
#include <math.h>
#include <fstream>// For file I/O
#include <iomanip>

using namespace std;

int main(){
	
    double length1 = 0.0, length2 = 0.0, length3 = 0.0;
	double semiperimeter = 0.0, area = 0.0;
	double result = 0.0;
    
    int n=1;

    ofstream outFile;// File with the results
    outFile.open("cpp_result.txt", ios::app);// Open the output file

    while(1){
    	std::cout << "Please enter the lengths of the triangle:" ;
        std::cin >> length1 >> length2 >> length3;
        if(length1 == -1 && length2 == -1 && length3 == -1)
        	break;
		else if( (length1<=0 || length2<=0 || length3<=0) ||
		         !(length1+length2>length3 && length2+length3>length1 && length3+length1>length2) ){
			std::cout << "The input is not legal." << endl;
			outFile << "Question "<< n++ << " inputs are, length1 = " << length1 << ", length2 = "<< length2 << ", length3 = " << length3 << ". The input is not legal." << endl;
			continue;
		}
        semiperimeter = ((length1 + length2 + length3) / 2);
        area = sqrt(semiperimeter * (semiperimeter - length1) * (semiperimeter - length2) * (semiperimeter - length3));
        result = round(area * 10000.0) / 10000.0;
        std::cout << "The area of this triangle is: "  << result << endl;
        outFile << "Question "<< n++ << " inputs are, length1 = " << length1 << ", length2 = "<< length2 << ", length3 = " << length3 << ". The area of this triangle is " << result <<"."<< endl;
    	
	}
	outFile.close();// Close the file
	return 0;
}
