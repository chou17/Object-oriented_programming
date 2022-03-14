#include <iostream>
#include "Node.cpp"

using namespace std;

class stack
{
private:
    node *top;

public:
    stack() : top(0){};
    void empty() const
    {
        if (top == 0)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    void push(int element)
    {
        node *newNode = new node(element); // 配置新的記憶體
	cout << "New node built." << endl;
        if (top == 0)
        {
            top = newNode;
            return;
        }

        newNode->next = top;
        top = newNode;
    }

    int pop()
    {
	int pop_element = top->item;
        node *curr = top;
        top = top->next;
        delete curr;
	return pop_element;
    }

    void d_stack(){
        while (top != 0)
        { // Traversal
            node *curr = top;
            top = top->next;
            delete curr;
            curr = 0;
        }
    }
};
