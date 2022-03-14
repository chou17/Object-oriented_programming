#include <iostream>
#include <fstream>

#include "Btree.cpp"

using namespace std;

void deleteTree(Tnode* node)
{
    if (node == NULL) return;

    /* first delete both subtrees */
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

Tnode *construct(ifstream &input);
int main() {
    ifstream inputFile;
    inputFile.open("treeNode.txt",ios::in);
    int tree_num =  1;
    while(1) {
        if(inputFile.eof()){
            inputFile.close();
            break;
        }
        cout<<"tree"<<tree_num<<" : "<<endl;
        Tnode *root = construct(inputFile);
        if(root==0)
            break;
        Btree *tree = new Btree(root);
        if (tree->isPalindromicTree())
            cout << "This tree is a PalindromicTree." << endl;
        else
            cout << "This tree is not a PalindromicTree." << endl;

        tree_num++;
         
        deleteTree(root);
        delete tree;
    }
    return 0;
}
Tnode *construct(ifstream &input) {
    int val;
    input>>val;
    if(val == -1) {
        cout << "This is a null pointer."<<endl;
        return 0;
    }
    Tnode *root = new Tnode(val);
    cout << "New node built. ";
    cout << "The value is "<< val << endl;
    root->left = construct(input);
    root->right = construct(input);
    return root;

}
