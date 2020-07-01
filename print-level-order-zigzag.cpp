#include <bits/stdc++.h>

using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int d)
    {
        val = d;
        left = NULL;
        right = NULL;
    }
};

TreeNode *build(string s)
{
    if (s == "true")
    {
        int d;
        cin >> d;
        TreeNode *root = new TreeNode(d);
        string l;
        cin >> l;
        if (l == "true")
        {
            root->left = build(l);
        }
        string r;
        cin >> r;
        if (r == "true")
        {
            root->right = build(r);
        }
        return root;
    }
    return NULL;
}

void preOrder(TreeNode *root) {
    if(root == NULL) {
        return;
    }
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right); 
}

int main() {
    
    return 0;
}