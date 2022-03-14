class stack;

class node
{
private:
    int item;
    node *next;

public:
    node() : item(0), next(0){};
    node(int a) : item(a), next(0){};

    friend class stack;
};
