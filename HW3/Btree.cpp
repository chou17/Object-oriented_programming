#include "Tnode.cpp"


class Btree{
private:
    Tnode *root;
    bool areMirrors(Tnode *root1,Tnode *root2){
        if(root1->left  && root2->right ){
            if(root1->left->val != root2->right->val)
                return false;
            if (!areMirrors(root1->left, root2->right))
                return false;
        }
        else if(root1->right  && root2->left ){
            if(root1->right->val != root2->left->val)
                return false;
            if (!areMirrors(root1->right, root2->left))
                return false;
        }
        else if(root1->left || root1->right || root2->left|| root2->right)
            return false;

        return true;
    }

public:
    bool isPalindromicTree(){
        return areMirrors(root, root);
    }
    Btree(Tnode *node){
        root = node;
    }
};

