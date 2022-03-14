class Tnode{
public:
    Tnode *left;
    Tnode *right;
    int val;
    Tnode():left(0), right(0),val(0){};
    Tnode(int val):val (val),left (0),right(0){};
};
