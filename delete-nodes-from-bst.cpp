#include <bits/stdc++.h>

using namespace std;

class TreeNode {
public:
	int val;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int data) {
		val = data;
		left = NULL;
		right = NULL;
	}
};

void BSTinsert(TreeNode* &root,int d){
	if(root==NULL){
		root=new TreeNode(d);
	}
	else if(d<=root->val){
		BSTinsert(root->left,d);
	}
	else{
		BSTinsert(root->right,d);		
	}
}


void preOrder(TreeNode *root) {
	if(root == NULL)
		return;

	cout << root->val << " ";
	preOrder(root->left);
	preOrder(root->right);
}

TreeNode* minValueNode(TreeNode *root) {
	TreeNode *temp = root;
	while(temp and temp->left != NULL) {
		temp = temp->left;
	}
	return temp;
}

TreeNode* deleteNode(TreeNode *root, int el) {
	if(root == NULL)
		return NULL;

	if(el < root->val) 
		root->left = deleteNode(root->left, el);
	else if(el > root->val)
		root->right = deleteNode(root->right, el);
	else {
		if(!root->left and !root->right) {	//node with 0 child
			delete root;
			return NULL;
		}
		else if(root->right and !root->left) {	//node with 1 child
			TreeNode *node = root->right;
			delete root;
			return node;
		}
		else if(root->left and !root->right) {	//node with 1 child
			TreeNode *node = root->left;
			delete root;
			return node;
		}
		else {
			//node with 2 nodes
			TreeNode *nextNode = minValueNode(root->right);
			root->val = nextNode->val;
			root->right = deleteNode(root->right, nextNode->val);
		}
	}	

	return root;
}

int main() {
	int t, n, m;
	vector<int> arr;
	vector<int> v;
	cin >> t;
	while(t--) {
		cin >> n;
		arr.resize(n);
		for(int i=0; i<n; ++i) {
			cin >> arr[i];
		}

		cin >> m;
		v.resize(m);
		for(int i=0; i<m; ++i) {
			cin >> v[i];
		}

		TreeNode *root = NULL;
		for(int el: arr) {
			BSTinsert(root, el);
		}

		// preOrder(root);

		//deleting nodes in v
		for(int el: v) {
			root = deleteNode(root, el);
			// cout << el << "\t";
		}

		preOrder(root);
		cout << endl;

		arr.clear();
		v.clear();
	}
	return 0;
}
