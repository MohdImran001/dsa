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

TreeNode* buildBST(vector<int> arr, int start, int end) {
    if(start > end) {
        return NULL;
    }

    int mid = start + (end - start)/2;
    TreeNode *root = new TreeNode(arr[mid]);

    root->left = buildBST(arr, start, mid-1);
    root->right = buildBST(arr, mid+1, end);

    return root;
}


void preOrder(TreeNode *root) {
    if(root == NULL) {
        return;
    }
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right); 
}

void replaceNodes(TreeNode* &root, int &sum) {
    if(root == NULL) {
        return;
    }

    replaceNodes(root->right, sum);
    sum += root->val;
    root->val = sum;
    replaceNodes(root->left, sum);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; ++i) {
        cin >> arr[i];
    }

    TreeNode *root = NULL;
    root = buildBST(arr, 0, n-1);

    //replace nodes
    int sum = 0;
    replaceNodes(root, sum);

    preOrder(root);
    return 0;
}