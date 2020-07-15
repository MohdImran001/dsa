#include <bits/stdc++.h>

using namespace std;

class Node  {
public:
	Node *left;
	Node *right;

	Node() {
		left = NULL;
		right = NULL;
	}
};


class Trie {
	Node *root;
public:
	Trie() {
		root = new Node();
	}

	void insert(int n) {
		Node *temp = root;
		for(int i=31; i>=0; --i) {

			int bit = (n >> i) & 1;

			if(bit == 0) {
				if(temp->left == NULL) {
					temp->left = new Node();
				}

				temp = temp->left;
			}
			else {
				if(temp->right == NULL) {
					temp->right = new Node();
				}

				temp = temp->right;
			}

		}
	}

	int max_xor_helper(int n) {
		Node *temp = root;
		int currentAns = 0;

		for(int i=31; i>=0; --i) {

			int bit = (n >> i) & 1;
			if(bit == 0) {
				//find complementary bit
				if(temp->right != NULL) {
					temp = temp->right;
					currentAns += (1<<i);
				}
				else {
					temp = temp->left;
				}
			}
			else {
				//current bit is 1
				if(temp->left != NULL) {
					temp = temp->left;
					currentAns += (1<<i);
				}
				else {
					temp = temp->right;
				}
			}

		}
 		
 		return currentAns;
	}

	int max_xor(int *input, int n) {
		int max_xor_value = INT_MIN;
		for(int i=0; i<n; ++i) {

			int value = input[i];
			insert(value);
			int current_max_xor = max_xor_helper(value);
			cout << current_max_xor << " ";
			max_xor_value = max(current_max_xor, max_xor_value);

		}

		return max_xor_value;
	}
};

int main() {
	int input[] = {3, 10, 5, 25, 2, 8};
	Trie t;
	cout << t.max_xor(input, 6);
	return 0;
}
