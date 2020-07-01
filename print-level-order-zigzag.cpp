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

void printZigZag(TreeNode *root) {
	queue<TreeNode *> q;
	q.push(root);
	
	int isEven = 1;

	while(!q.empty()) {
		isEven *= -1;
		int len = q.size();
		vector<int> ans;
		
		for(int i=1; i<=len; ++i) {
			TreeNode *node = q.front();
			q.pop();

			ans.push_back(node->val);

			if(node->left) {
				q.push(node->left);
			}
			if(node->right) {
				q.push(node->right);
			}
		}

		if(isEven == 1) {
			for(int i=ans.size()-1; i >= 0; --i) {
				cout << ans[i] << " ";
			}
		}
		else {
			for(auto el: ans) {
				cout << el << " ";
			}
		}
	}
}

int main() {
    TreeNode *root = build("true");

	printZigZag(root);
    
	return 0;
}
