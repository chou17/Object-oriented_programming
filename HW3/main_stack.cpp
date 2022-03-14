#include <iostream>
#include "Stack.cpp"

using namespace std;

int main()
{
    stack d;
    while (1)
    {
        int command;
	cout << "Please enter the command : ";
        cin >> command;

        if (command == -1){
	    d.d_stack();
            break;
	}

        else if (command == 1)
        {
	    cout << "Please enter the element : ";
            int element;
            cin >> element;
            d.push(element);
        }
        else if (command == 2)
        {
            cout << "Pop the stack : " << d.pop() << endl;
        }
        else if (command == 3)
        {
	    cout << "Check the stack, if it is empty, print true, or print fail."<<endl;
            d.empty();
        }
    }
    return 0;
}
